#!/bin/bash

. ../helper.sh --source-only

iter=10

echo "HT.."

clang ht.c -O3 -lm -DCROSS -DDPS -DHOIST -DFUSED -DBUMP &> /dev/null
echo "ht fsharp dbump"
run $iter

clang cross.c -O3 -lm -DCROSS -DDPS -DHOIST -DFUSED &> /dev/null
echo "ht fsharp"
run $iter

clang++ ./CPP/ht.cpp -O3 -lm &> /dev/null
echo "ht cpp"
run $iter
