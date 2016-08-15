﻿module transformer

open Microsoft.FSharp.Quotations
open types

let assembly = System.Reflection.Assembly.GetExecutingAssembly()

let (|OperatorName|_|) methodName =
  match methodName with
    | "op_Addition" -> Some("+")
    | "op_Multiply" -> Some("*")
    | "op_Subtraction" -> Some("-")
    | "op_Division" -> Some("/")
    | "op_Modulus" -> Some("%")
    | "op_Inequality" -> Some("!=")
    | "op_Equality" -> Some("==")
    | "op_UnaryNegation" -> Some("-")
    | "op_LessThan" -> Some("<")
    | "op_GreaterThan" -> Some(">")
    | _ -> None

let (|LambdaN|_|) (e: Expr): (Var List * Expr) Option = 
  (* TODO implement in a tail recursive way *)
  let rec lambdaNExtract exp = 
    match exp with
    | Patterns.Lambda(x, body) -> 
      let (inputs, newBody) = lambdaNExtract body
      (x :: inputs, newBody)
    | _ -> ([], exp)
  match lambdaNExtract e with 
  | ([], _) -> None
  | (inputs, body) -> Some(inputs, body)

let (|AppN|_|) (e: Expr): (Expr * Expr list) Option = 
  let rec appNExtract exp args = 
    match exp with 
    | Patterns.Application(f, e) -> appNExtract f (e :: args) 
    | _ -> (exp, args)
  match appNExtract e [] with 
  | (_, []) -> None
  | (func, args) -> Some(func, args)

let (|StripedAppN|) (e: Expr): Expr * Expr list = 
  match e with
  | AppN(e1, args) -> e1, args
  | _              -> e, [] 

let (|LetN|_|) (e: Expr): ((Var * Expr) List * Expr) Option = 
  let rec letNExtract exp statements = 
    match exp with 
    | Patterns.Let(x, e1, e2) -> letNExtract e2 (List.append statements [(x, e1)]) 
    | _ -> (statements, exp)
  match letNExtract e [] with 
  | ([], _) -> None
  | (statements, body) -> Some(statements, body)

let (|TopLevelFunction|) (e: Expr): (Var List * Expr) = 
  match e with 
  | LambdaN(inputs, body) -> (inputs, body) 
  | _ -> ([], e)

let (|MakeClosure|_|) (e: Expr): (Var * Expr * ((System.Type * string * string) List)) Option = 
  match e with 
  | Patterns.Call (None, op, [Patterns.Lambda(envVar, body); Patterns.Call (None, opEnv, list)]) when 
      op.Name = "makeClosure" && opEnv.Name = "makeEnv" -> 
    let envList = 
      let rec extractElems l = 
        match l with
        (* The pattern `Patterns.Call (_, _, [e])` performs an additional level of specialization.
           This specialization results in not using a union type for the variables in the enviroment 
           of a closure. *)
        | [ Patterns.NewUnionCase(_, 
             [ Patterns.NewTuple([Patterns.Value(v, _); 
                                  Patterns.Call (_, _, [e]) as makeAnyNumericCall]); tl]) ] ->
          let variableName = 
            match makeAnyNumericCall with
            | DerivedPatterns.SpecificCall <@ cruntime.makeAnyNumeric @> (_, _, [Patterns.Var(v)]) -> v.Name
            | _ -> failwithf "Expected makeAnyNumeric but provided %A" e
          (e.Type, v.ToString(), variableName) :: extractElems([tl])
        | _ -> []
      extractElems list
    Some (envVar, body, envList)
  | _ -> None

let (|ApplyClosure|_|) (e: Expr): Var Option = 
  match e with 
  | Patterns.Lambda(arg, Patterns.Call (None, op, [Patterns.Var(closure); Patterns.Var(arg2)])) when 
     (op.Name = "applyClosure") && (arg = arg2) ->
     Some (closure)
  | _ -> None

let (|EnvRef|_|) (e: Expr): (Expr * string) Option = 
  match e with 
  | Patterns.Call(None, getOp, [Patterns.Call (None, op, [env; Patterns.Value(s, _)])]) when 
      getOp.Name.StartsWith("get") && op.Name = "envRef" -> 
      Some (env, s.ToString())
  | _ -> None

let mutable existingMethods: (string * string) List = []

let (|ExistingCompiledMethod|_|) (e: Expr): (string * string * Expr List) Option = 
  match e with 
  | Patterns.Call (None, op, argList) -> 
    match (op.Name, op.DeclaringType.Name) with
    | (methodName, moduleName) when 
        (List.exists (fun (x, y) -> x = moduleName && y = methodName) existingMethods) -> 
        Some(methodName, moduleName, argList)
    | _ -> None
  | _ -> None

let (|ExistingCompiledMethodWithLambda|_|) (e: Expr): (string * string * Expr List * Expr) Option = 
  match e with
  | ExistingCompiledMethod(methodName, moduleName, args) -> 
    let moduleInfo = assembly.GetType(moduleName)
    let methodInfo = moduleInfo.GetMethod(methodName)
    let reflDefnOpt = Microsoft.FSharp.Quotations.Expr.TryGetReflectedDefinition(methodInfo)
    let attrs = (methodInfo.GetMethodImplementationFlags())
    match reflDefnOpt with
    | None -> failwith (sprintf "fatal error! Extracting lambda definition from a non-inlinable method: %s.%s!" moduleName methodName)
    | Some(lam) ->
      Some(methodName, moduleName, args, lam)
  | _ -> None

let (|ArraySlice|_|) (e: Expr): (Expr * Expr * Expr) option = 
  match e with 
  | Patterns.Call (None, op, argList) -> 
    match (op.Name, op.DeclaringType.Name) with
    | ("GetArraySlice", "OperatorIntrinsics") -> 
      let args = 
        List.map (fun x -> 
          match x with 
          | Patterns.NewUnionCase(_, [v]) -> v
          | _ -> x) argList
      Some(args.[0], args.[1], args.[2])
    | _ -> None
  | _ -> None

let (|LibraryCall|_|) (e: Expr): (string * Expr List) Option = 
  match e with 
  | ExistingCompiledMethod (methodName, moduleName, argList) ->
      Some(sprintf "%s_%s" moduleName methodName, argList)
  | Patterns.Call (None, op, argList) -> 
    match (op.Name, op.DeclaringType.Name) with
    | (methodName, "ArrayModule") -> 
      failwith (sprintf "The generic version of the method Array.%s is not supported!" methodName)
    | ("Sqrt", "Operators") -> Some("sqrt", argList)
    | ("Sin", "Operators") -> Some("sin", argList)
    | ("Cos", "Operators") -> Some("cos", argList)
    | ("Log", "Operators") -> Some("log", argList)
    | ("Exp", "Operators") -> Some("exp", argList)
    | ("Pow", "Math") -> Some("pow", argList)
    | ("GammaLn", "SpecialFunctions") -> Some("gamma_ln", argList)
    | ("ToInt", "Operators") -> Some("(int)", argList)
    | ("ToDouble", "Operators") -> Some("(double)", argList)
    | ("ToDouble", "ExtraTopLevelOperators") -> Some("(double)", argList)
    | ("GetArraySlice", "OperatorIntrinsics") -> // TODO rewrite using the `ArraySlice` active pattern
      let args = 
        List.map (fun x -> 
          match x with 
          | Patterns.NewUnionCase(_, [v]) -> v
          | _ -> x) argList
      let prefix = 
        match (List.head args).Type with 
        | tp when tp = typeof<Vector> -> "array"
        | tp when tp = typeof<Matrix> -> "matrix"
        | tp when tp = typeof<Matrix3D> -> "matrix3d"
        | tp -> failwith (sprintf "Array slice not supported for the type %s" (tp.Name))
      Some(prefix + "_slice", args)
    | _ when not(Seq.isEmpty (op.GetCustomAttributes(typeof<CMirror>, true))) -> 
        let attr = Seq.head (op.GetCustomAttributes(typeof<CMirror>, true)) :?> CMirror
        Some(attr.Method, argList)
    | _ -> None 
  | _ -> None

let LambdaN (inputs: Var List, body: Expr): Expr =
  List.fold (fun acc cur -> Expr.Lambda(cur,  acc)) body (List.rev inputs)

let AppN (e1: Expr, args: Expr list): Expr =
  Expr.Applications(e1, List.map (fun x -> [x]) args)

let LetN (inputs: (Var * Expr) List, body: Expr): Expr =
  List.fold (fun acc (curv, cure) -> Expr.Let(curv,  cure, acc)) body (List.rev inputs)

open utils

let rec variableRenaming (e: Expr) (renamings: (Var * Var) list): Expr =
  let alreadyExistingVariable(v: Var) = 
    renamings |> List.exists (fun (v1, v2) -> v1.Name = v.Name || v2.Name = v.Name)
  match e with 
  | Patterns.Let(v, e1, e2) ->
    let ne1 = variableRenaming e1 renamings
    let (nv, newRenamings) = 
      if alreadyExistingVariable v then
        let nv = new Var(newVar (v.Name), v.Type)
        nv, (v, nv) :: renamings
      else
        v, (v, v) :: renamings
    let ne2 = variableRenaming e2 newRenamings
    Expr.Let(nv, ne1, ne2)
  | ExprShape.ShapeLambda(x, e) ->
    let (nx, newRenamings) = 
      if alreadyExistingVariable x then
        let nx = new Var(newVar (x.Name), x.Type)
        nx, (x, nx) :: renamings
      else
        x, (x, x) :: renamings
    let ne = variableRenaming e newRenamings
    Expr.Lambda(nx, ne)
  | ExprShape.ShapeVar(x) ->
    let nx = Option.fold (fun s (v, nv) -> nv) x (List.tryFind (fun (v, nv) -> v = x) renamings)
    Expr.Var(nx)
  | ExprShape.ShapeCombination(op, args) ->
    ExprShape.RebuildShapeCombination(op, List.map (fun arg -> variableRenaming arg renamings) args)

let captureAvoidingSubstitution (e: Expr) (mapping: (Var * Expr) list): Expr = 
  let substitutedE = e.Substitute(fun v2 -> mapping |> List.tryFind (fun (v, a) -> v = v2) |> Option.map snd)
  variableRenaming substitutedE []
  // let renamedE = mapping |> List.map (fun (v, _) -> v, v) |> variableRenaming e
  // renamedE.Substitute(fun v2 -> mapping |> List.tryFind (fun (v, a) -> v = v2) |> Option.map snd)