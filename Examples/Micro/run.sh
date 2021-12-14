#!/bin/bash

. ../helper.sh --source-only

iter=100

echo "CROSS.."

clang cross.c -O3 -DCROSS -DDPS -DHOIST -DFUSED -DBUMP &> /dev/null
echo "cross fsharp dbump"
run $iter

clang cross.c -O3 -DCROSS -DDPS -DHOIST -DFUSED &> /dev/null
echo "cross fsharp"
run $iter

clang++ ./CPP/cross.cpp -O3 &> /dev/null
echo "cross cpp"
run $iter

echo "ADD3.."

clang add3.c -O3 -DCROSS -DDPS -DHOIST -DFUSED -DBUMP &> /dev/null
echo "add fsharp dbump "
run 10

clang add3.c -O3 -DCROSS -DDPS -DHOIST -DFUSED &> /dev/null
echo "add fsharp"
run 10

clang++ ./CPP/benchmark_micro.cpp -O3 &> /dev/null
echo "add cpp"
run 10
