#!/bin/bash

run() {
    total=0
    for ((i = 0 ; i < $1 ; i++)); do
        out=$(./a.out)
        line=$(echo "$out" | grep mill)
        t=$(echo $line | cut -d " " -f 1)
        total=$(echo "$total + $t" | bc)
    done
    python -c "print($total / ($1 * 1.0))"
}
