#define DPS
#include "../../outputs/C/usecases_stencil_storaged.h"
#include "../test.h"

#define LEN (1 << 10)
#define STEP 10
#define N 10

int main() {
    array_array_number_t A = get_mat(LEN, LEN);
    srand(SEED);
    populate_mat_rand(A);

    double total = 0;
	storage_t s = storage_alloc(sizeof(double) * LEN * LEN * 100);
    TIC();
    for(int i = 0; i < N; i++) {
        A->arr[5]->arr[5] += i / N;
        array_array_number_t r = TOP_LEVEL_usecases_stencil_jacobi2D_dps(s, A, matrix_shape(A)); 
        for (int j = 0; j < N - 1; j++) {
            r = TOP_LEVEL_usecases_stencil_jacobi2D_dps(s, r, matrix_shape(r)); 
        }
        total += r->arr[5]->arr[5];
    }
    TOC();

    printf("%f", total);
}
