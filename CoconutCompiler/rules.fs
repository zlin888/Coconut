﻿module rules

open Microsoft.FSharp.Quotations
open ruleengine
open metaVars
open corelang
open types
open cardinality


let divide2Mult        = <@ (%a / %b) / %c                <==>   %a / (%b * %c)      @>
let distrMult          = <@ %a * (%b + %c)                <==>   %a * %b + %a * %c   @>
let constFold0         = <@ %a + 0.0                      <==>   %a                  @>
let constFold1         = <@ %a * 1.0                      <==>   %a                  @>
let subSame            = <@ %a - %a                       <==>   0.0                 @>
let multDivide         = <@ %a * (%b / %a)                <==>   %b                  @>
let assocAddSub        = <@ (%a + %b) - %c                <==>   %a + (%b - %c)      @>
let assocAddAdd        = <@ (%a + %b) + %c                <==>   %a + (%b + %c)      @>
let assocSubSub        = <@ (%a - %b) - %c                <==>   %a - (%b + %c)      @>
let comAddIndex        = <@ %i + %j                       <==>   %j + %i             @>
let assocAddSubIndex   = <@ (%i + %j) - %k                <==>   %i + (%j - %k)      @>
let assocSubAddIndex   = <@ (%i - %j) + %k                <==>   %i - (%j - %k)      @>
let assocSubSubIndex   = <@ (%i - %j) - %k                <==>   %i - (%j + %k)      @>
let subSameIndex       = <@ %i - %i                       <==>   0                   @>
let constFold0Index    = <@ %i + 0                        <==>   %i                  @>
let constFoldN0Index   = <@ %i - 0                        <==>   %i                  @>
let constFoldCardAdd   = <@ (Card %i) .+ (Card %j)        <==>   Card (%i + %j)      @>
let constFoldCardSub   = <@ (Card %i) .- (Card %j)        <==>   Card (%i - %j)      @>
let indexToDoubleToInt = <@ int (double %k)               <==>   %k                  @>
let vectorBuildGet     = <@ (build<Number> %c1 %F).[%i]   <==>   (%F) %i             @>
let vectorBuildLength  = <@ (build<Number> %c2 %F).Length <==>   %k                  @>
let dce                = <@ ( let x = %E1 in %E2: T1 )    <==>   %E2                 @>

let vectorBuildToStorage = 
                             <@ build<Number> (%c1) (%F)      
                                                           <==>
                                (let s = vectorAlloc (%c1) in vectorBuildGivenStorage s (%F))
                                                                                      @>


let letVectorBuildLength = 
                             <@ ( let x = (build<Number> %c1 %F) in ((%B1) (length x) x): T1 )
                                                           <==>
                                ( let x = (build<Number> %c1 %F) in (%B1) %c1 x )
                                                                                      @>

let letVectorBuildGet = 
                             <@ ( let x = (build<Number> %c1 %F) in ((%B1) (x.[%i]) x): T1 )
                                                           <==>
                                ( let x = (build<Number> %c1 %F) in (%B1) ((%F) %i) x )
                                                                                      @>

let letBuild = 
                             <@ ( let x = (build<Number> %c1 %F) in ((%B1) x): T1 )
                                                           <==>
                                ( (%B1) (build<Number> %c1 %F) )
                                                                                      @>

let letInliner         = <@ ((let x = %E1 in (%B1) x): T1)
                                                           <==> (%B1) %E1             @>

let letMerging         = <@ ( let x: T1 = %E1 in let y: T1 = %E1 in ((%B1) x y): T2 )
                                                           <==>
                                let x: T1 = %E1 in (%B1) x x
                                                                                      @>

let letCommutingConversion 
                           = <@ ( let x: T1 = (let y: T2 = %E1 in (%B1) y) in ((%B2) x): T3 )
                                                           <==>
                                let y: T2 = %E1 in let x: T1 = (%B1) y in (%B2) x
                                                                                      @>

let letReorder         = <@ ( let x: T1 = %E1 in let y: T2 = %E2 in ((%B1) x y): T3 )
                                                           <==>
                                let y: T2 = %E2 in let x: T1 = %E1 in ((%B1) x y): T3
                                                                                      @>

let copyLet            = <@ ( vectorCopy %stg1 (let x = %E1 in (%B1) x) )
                                                           <==>
                                ( let x = %E1 in vectorCopy %stg1 ((%B1) x) )
                                                                                      @>

// FIXME doesn't work
(*
let vectorSliceToBuild_exp = <@
    (%V).[(%i)..(%j)]
    <==>
    vectorBuild (%j - %i + 1) (fun i -> (%V).[i])
  @>
*)


// TODO does not take into account the preconditions
let allocToCPS_exp =
  <@
    (
      let s = vectorAlloc %c1
      ((%B1) s): T1
    )
    <==>
    (
      alloc %c1 (fun s -> (%B1) s)
    )
  @>

// FIXME does not work
let letFloatOutwards_exp = <@
    (
      //((%B1) (let x: T1 = %E1 in x)): T2
      (%B1) (%E1: T1): T2
    )
    <==>
    (
      let x: T1 = %E1
      (%B1) x
    )
  @>



let allocToCPS: Rule = compilePatternWithNameToRule allocToCPS_exp "allocToCPS"

let algebraicRulesScalar = 
  [ compilePatternToRule <@ divide2Mult @>; compilePatternToRule <@ distrMult @>; 
  compilePatternToRule <@ constFold0 @>; compilePatternToRule <@ constFold1 @>; 
  compilePatternToRule <@ subSame @> ; compilePatternToRule <@ multDivide @>; 
  compilePatternToRule <@ assocAddSub @>; compilePatternToRule <@ assocAddAdd @>; 
  compilePatternToRule <@ assocSubSub @> ]

//let algebraicRulesVector_exp = [ <@ vectorBuildGet_exp @>; <@ vectorSliceToBuild_exp @>]

//let algebraicRulesVector: Rule List = List.map compilePatternToRule algebraicRulesVector_exp

open transformer
open FSharp.Quotations.Evaluator
open types

let methodDefToLambda: Rule = 
  (fun (e: Expr) ->
    match e with
    | ExistingCompiledMethodWithLambda(methodName, moduleName, args, lam) -> 
        [Expr.Applications(lam, List.map (fun x -> [x]) args)]
    | _ -> []
  ), "methodDefToLambda"

let lambdaAppToLet: Rule = 
  (fun (e: Expr) ->
    match e with
    | AppN(LambdaN(inputs, body), args) when (List.length inputs) = (List.length args) -> 
        [LetN(List.zip inputs args, body)]
    | _ -> []
  ), "lambdaAppToLet"

/// This rule is composition of one application of lambdaAppToLet and several applications of letInliner
let betaReduction: Rule = 
  (fun (e: Expr) ->
    match e with
    | AppN(LambdaN(inputs, body), args) when (List.length inputs) = (List.length args) -> 
        let inputsAndArgs = List.zip inputs args
        let renamedBody = captureAvoidingSubstitution body inputsAndArgs
        [renamedBody]
    | _ -> []
  ), "betaReduction"

/// This rule is composition of one application of methodDefToLambda and lambdaAppToLet followed
/// by several applications of letInliner.
let methodDefInliner: Rule = 
  (fun (e: Expr) ->
    match e with
    | ExistingCompiledMethodWithLambda(methodName, moduleName, args, LambdaN(inputs, body)) when (List.length inputs) = (List.length args) -> 
      let inputsAndArgs = List.zip inputs args
      let renamedBody = captureAvoidingSubstitution body inputsAndArgs
      [renamedBody]
    | _ -> []
  ), "methodDefInliner"

// TODO requires support for unacceptable cases
let letIntroduction: Rule =
  (fun (e: Expr) ->
    match e with
    | Patterns.Let(x, e1, e2) -> []
    | Patterns.Lambda(_, _) -> []
    | Patterns.Var(_) -> []
    | Patterns.Value(_, _) -> []
    | _ -> 
      let nv = new Var(utils.newVar "xi_", e.Type)
      [Expr.Let(nv, e, Expr.Var(nv))]
  ), "letIntroduction"

// TODO requires meta programming facilities to be expressible in the rewrite engine.
let constantFold: Rule = 
  (fun (e: Expr) ->
    match e with
    | Patterns.Call(None, op, args) ->
      let staticArgs = 
        List.collect (fun arg -> 
          match arg with
          | Patterns.Value(v, vp) -> [v]
          | _ -> []
        ) args
      
      if (List.length staticArgs) = (List.length args) then
        let resultObject = e.EvaluateUntyped()
        let resultExpression = Expr.Value(resultObject, e.Type)
        [resultExpression]
      else
        []
    | _ -> []
  ), "constantFold"

// TODO quotation syntax requires supproting certain corner cases on pattern matching in quotations
let vectorSliceToBuild: Rule = 
  (fun (e: Expr) ->
    match e with
    | Patterns.Call (None, op, elist) -> 
      match op.Name with
      | "GetArraySlice" when e.Type = typeof<Vector> -> 
        let args = 
          List.map (fun x -> 
            match x with 
            | Patterns.NewUnionCase(_, [v]) -> v
            | _ -> x) elist
        let vec = Expr.Cast<Vector>(args.[0])
        let s = Expr.Cast<Index>(args.[1])
        let e = Expr.Cast<Index>(args.[2])
        [ <@ build<Number> (((Card %e) .- (Card %s)) .+ (Card 1)) (fun i -> (%vec).[i + %s]) @>.Raw]
      | _ -> []
    | _ -> []
  ), "vectorSliceToBuild"

// TODO quotation syntax requires supproting handling a list of arguments and accessing their size
///  [| e1; ...; eN |].length --> N
let newArrayLength: Rule = 
  (fun (e: Expr) ->
    match e with
    | Patterns.PropertyGet(Some(Patterns.NewArray(tp, elems)), prop, []) when prop.Name = "Length"  -> 
      [Expr.Value(elems.Length)]
    | _ -> []
  ), "newArrayLength"

// TODO quotation syntax requires checking conditions whether something is constant or not
/// vectorAlloc size --> vectorAllocOnStack size (if size is statically known is < 10)
let allocToAllocOnStack: Rule = 
  (fun (e: Expr) ->
    match e with
    | DerivedPatterns.SpecificCall <@ corelang.vectorAlloc @> (_, _, [Patterns.Value(v, _) as value])  ->
      let lengthValue = unbox<int> v
      if lengthValue < 10 then
        [ <@@ corelang.vectorAllocOnStack (%%value) @@> ]
      else
        []
    | _ -> []
  ), "allocToAllocOnStack"

// TODO quotation syntax requires supporting conditionals rewrite rules
/// (\x1...xN e0) e1 ... eN ---> (\s0 x1...xN copy s0 e0) e1 ... eN (let s1 = e0.length in s1))
let lambdaAppStoraged: Rule = 
  (fun (e: Expr) ->
    match e with
    // TODO add support for matrix
    | AppN(LambdaN(inputs, body), args) when (List.length inputs) = (List.length args) && (List.head inputs).Type <> typeof<Storage> && 
       (e.Type = typeof<Vector> || e.Type = typeof<Matrix>) -> 
      let storageVarForLambda = new Var(utils.newVar "stg_input", typeof<Storage>)
      let storageVarForLambdaExp = Expr.Var(storageVarForLambda)
      let storageVarForApply = new Var(utils.newVar "stg", typeof<Storage>)
      let storageVarForApplyExp = Expr.Var(storageVarForApply)
      // TODO fix
      let sizeExpr = 
        // <@@ (%%e: Vector).Length @@>
        <@@ 1000 @@> 
      [AppN(LambdaN(storageVarForLambda :: inputs, <@@ vectorCopy %%storageVarForLambdaExp %%body @@>), (Expr.Let(storageVarForApply, <@@ vectorAlloc %%sizeExpr @@>, storageVarForApplyExp)) :: args) ]
    | _ -> []
  ), "lambdaAppStoraged"

let copyStoragedElimination: Rule = 
  (fun (e: Expr) ->
    let STORAGE_POSTFIX = "GivenStorage"
    match e with
    | DerivedPatterns.SpecificCall <@ corelang.vectorCopy @> (_, _, [s1; Patterns.Call(None, op, s2 :: args)]) when op.Name.EndsWith(STORAGE_POSTFIX) ->
      [Expr.Call(op, s1 :: args)]
    | _ -> []
  ), "copyStoragedElimination"

// c.f.  "Let-floating: moving bindings to give faster programs", SPJ et. al., ICFP'96
//  specially section 3.2 (full laziness)
let foldInvariantCodeMotion: Rule = 
  (fun (e: Expr) ->
    match e with
    // TODO generalize
    | DerivedPatterns.SpecificCall <@ corelang.foldOnRange @> (_, _, [f; z; st; en]) ->
      match f with
      | LambdaN(inputs, body) ->
        match body with
        | Patterns.Let(x, e1, e2) ->
          if(not (List.exists (fun e -> List.exists (fun y -> e = y) inputs) (List.ofSeq (e1.GetFreeVars())))) then
            let (Patterns.Call(_, mi, _)) = e
            [ Expr.Let(x, e1, Expr.Call(mi, [LambdaN(inputs, e2); z; st; en])) ]
          else
            []
        | _ -> []
      | _ -> failwithf "The first argument of a fold function should be a lambda expression, but is `%A` instead." f
    | _ -> []
  ), "foldInvariantCodeMotion"

// TODO this one and the previous can be merged
// c.f.  "Let-floating: moving bindings to give faster programs", SPJ et. al., ICFP'96
//  specially section 3.2 (full laziness)
let letFloatOutwards: Rule = 
  (fun (e: Expr) ->
    match e with
    | ExprShape.ShapeCombination(op, args) ->
      let transformedArg = 
        args 
        |>  List.mapi (fun idx a -> 
              match a with
              | Patterns.Let(x, e1, e2) ->
                Some(idx, x, e1, e2)
              | _ ->
                None
            )
        |>  List.tryPick id
      transformedArg
        |>  Option.map (fun (idx, x, e1, e2) ->
              let transformedArgs = 
                args
                |>  List.mapi (fun idx2 arg ->
                      if idx = idx2 then
                        e2
                      else
                        arg
                    )
              Expr.Let(x, e1, ExprShape.RebuildShapeCombination(op, transformedArgs))
            )
          |> Option.toList
    | ExprShape.ShapeLambda(x, Patterns.Let(y, e1, e2)) when e1.GetFreeVars() |> Seq.exists (fun fv -> fv = x) |> not ->
      [ Expr.Let(y, e1, Expr.Lambda(x, e2)) ]
    | _ -> []
  ), "letFloatOutwards"

let foldPartiallyDCE: Rule = 
  (fun (e: Expr) ->
    match e with
    // TODO generalize
    | DerivedPatterns.SpecificCall <@ snd @> (_, _, [DerivedPatterns.SpecificCall <@ corelang.foldOnRange @> (_, _, [f; z; st; en])]) ->
      match (f, z) with
      // TODO still needs more check! Currently it's a little bit unsafe!
      | (LambdaN([acc; idx], LetN([a1; a2], Patterns.NewTuple([fs;sn]))), Patterns.NewTuple([zfs;zsn])) ->
        if((getFreeVariables sn) |> List.forall (fun v -> v <> (fst a1))) then
          printfn "foldPartiallyDCE kicked in!"
          let newF = LambdaN([fst a2; idx], sn)
          let res = MakeCall <@ foldOnRange @> [newF; zsn; st; en] [zsn.Type]
          [res]
        else
          []
      | _ -> []
    | _ -> []
  ), "foldPartiallyDCE"