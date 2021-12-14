
#define DPS
#include "../../outputs/C/usecases_jacobi1d_storaged.h"
#include "../test.h"

#define LEN (1 << 24)
#define N 1

int main() {
    array_number_t A = get_vec(LEN);
    srand(SEED);
    populate_vec_rand(A);

	storage_t s0 = storage_alloc(sizeof(double) * LEN);
    double total = 0;
    array_number_t buf0;
    TIC();
    for(int i = 0; i < N; i++) {
        A->arr[5] += i / N;
        buf0 = TOP_LEVEL_usecases_jacobi1d_Jacobi1D_dps(s0, A, vector_shape(A)); 
        total += buf0->arr[2];
    }
    TOC();

    printf("%f", total);
}
