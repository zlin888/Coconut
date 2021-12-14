[<ReflectedDefinition>]
module usecases_oneMM

open corelang
open linalg
open types
open utils
open cardinality

let oneMM(A: Matrix)(B: Matrix): Matrix = 
    matrixMult A B
