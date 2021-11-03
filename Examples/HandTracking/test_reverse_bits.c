#include<stdio.h>
#include "../../outputs/C/reverse_bits.h"

int main() {
    int j = 0;
    reverse_bits(3, 10, &j);
    printf("%d\n", j);
}
