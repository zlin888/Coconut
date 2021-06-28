#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>
#include <stdio.h>
#include "vector.h"
#include <time.h>

int* get_vec(int len) {
    return (int*)malloc(sizeof(int) * len);
}


int* populate_vec_inc(int* v, int len) {
    for(int i = 0; i < len; i++) {
        v[i] = i;
    }
    return v;
}

int* populate_vec_rand(int* v, int len) {
    srand(time(NULL));
    for(int i = 0; i < len; i++) {
        v[i] = rand();
    }
    return v;
}

void print_vec(int* v, int len) {
    for(int i = 0; i < len; i++) {
        printf("%d", v[i]);
    }
}

#endif