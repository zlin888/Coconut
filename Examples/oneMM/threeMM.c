#define DPS
#include "../../outputs/C/usecases_twoMM_storaged.h"
#include "../test.h"

#define ALPHA 10
#define BETA 10
#define P 10
#define Q 10
#define R 10
#define S 10
#define N 100000

int main() {
    srand(SEED);
    array_array_number_t A = get_mat(P, Q);
    array_array_number_t B = get_mat(Q, R);
    array_array_number_t C = get_mat(R, S);
    array_array_number_t D = get_mat(P, S);

    populate_mat_rand(A);
    populate_mat_rand(B);
    populate_mat_rand(C);
    populate_mat_rand(D);

	storage_t s = storage_alloc(sizeof(double) * P * S * 5);
	double total = 0;
	TIC();
	for (int i = 0; i < N; i++)
	{
        A->arr[0]->arr[0] = 1 / i;
		array_array_number_t r = TOP_LEVEL_usecases_twoMM_threeMM_dps(s, A, B, C, D, matrix_shape(A), matrix_shape(B), matrix_shape(C), matrix_shape(D));
		total += r->arr[0]->arr[1];
	}
	TOC();
	printf("%f", total);
}
