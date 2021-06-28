#include "vector_add_3.h"
#include "vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
    int len = 100;
    int *v0 = populate_vec_rand(get_vec(len), len);
    int *v1 = populate_vec_rand(get_vec(len), len);
    int *v2 = populate_vec_rand(get_vec(len), len);
    // int *v0 = populate_vec_inc(get_vec(len), len);
    // int *v1 = populate_vec_inc(get_vec(len), len);
    // int *v2 = populate_vec_inc(get_vec(len), len);
    int *r = get_vec(len);

    int f[1000000];
    clock_t start_time = clock();
    for (int i = 0; i < 1000000; i++)
    {
        vector_add_3_opt(v0, v1, v2, r);
        f[i] = r[1];
    }
    clock_t end_time = clock();
    double elapsed_time = (double)(end_time - start_time) * 1000 / CLOCKS_PER_SEC;
    printf("Done in %f miliseconds\n", elapsed_time);
    printf("%d\n", f[12]);

    // print_vec(r, len);
    free(v0);
    free(v1);
    free(v2);
    free(r);
    return 0;
}
