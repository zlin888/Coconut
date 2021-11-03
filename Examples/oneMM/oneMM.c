#define DPS
#include "../../outputs/C/usecases_oneMM_storaged.h"
#include "../test.h"

#define P 1024
#define Q 1024
#define R 1024
#define N 1

int main() {
    srand(SEED);
	array_array_number_t A = get_mat(P, Q);
	array_array_number_t B = get_mat(Q, R);

	storage_t s = storage_alloc(sizeof(double) * P * Q * 1.1);
	double total = 0;
	TIC();
	for (int i = 0; i < N; i++)
	{
        A->arr[0]->arr[0] = 1 / i;
		array_array_number_t r = TOP_LEVEL_usecases_oneMM_oneMM_dps(s, A, B, matrix_shape(A), matrix_shape(B));
		total += r->arr[0]->arr[1];
	}
	TOC();
	printf("%f", total);
}
