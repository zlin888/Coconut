#define DPS
#include "../../outputs/C/usecases_jacobi2d_storaged.h"
#include "../test.h"

#define LEN 100
#define STEP 10
#define N 100

int main() {
    array_array_number_t A = get_mat(LEN, LEN);
    srand(SEED);
    populate_mat_rand(A);

    double total = 0;
	storage_t s = storage_alloc(1 << 17);
    TIC();
    for(int i = 0; i < N; i++) {
        A->arr[5]->arr[5] += i / N;
        array_array_number_t r = TOP_LEVEL_usecases_jacobi2d_recJacobi2D_dps(s, A, 10, matrix_shape(A), 0); 
        total += r->arr[5]->arr[5];
    }
    TOC();

    printf("%f", total);
}
