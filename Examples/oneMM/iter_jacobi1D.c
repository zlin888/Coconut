#define DPS
#include "../../outputs/C/usecases_jacobi1d_storaged.h"
#include "../test.h"

#define LEN (1 << 17)
#define STEP 4
#define N 1000

int main() {
    array_number_t A = get_vec(LEN);
    srand(SEED);
    populate_vec_rand(A);

	storage_t s0 = storage_alloc(sizeof(double) * LEN);
	storage_t s1 = storage_alloc(sizeof(double) * LEN);
    double total = 0;
    array_number_t buf0;
    array_number_t buf1;
    TIC();
    for(int i = 0; i < N; i++) {
        A->arr[5] += i / N;
        buf0 = TOP_LEVEL_usecases_jacobi1d_Jacobi1D_dps(s0, A, vector_shape(A)); 
        for (int j = 0; j < (STEP - 2) / 2; j++) {
            buf1 = TOP_LEVEL_usecases_jacobi1d_Jacobi1D_dps(s1, buf0, vector_shape(A)); 
            buf0 = TOP_LEVEL_usecases_jacobi1d_Jacobi1D_dps(s0, buf1, vector_shape(A)); 
        }
        buf1 = TOP_LEVEL_usecases_jacobi1d_Jacobi1D_dps(s1, buf0, vector_shape(A)); 
        total += buf1->arr[3];
    }
    TOC();

    printf("%f", total);
}
