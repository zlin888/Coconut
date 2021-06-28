#define DPS
#define FUSED
#define HOIST
#define ADD3

#include "../../outputs/C/linalg_opt_storaged.h"
const size_t DIM = 100;


array_array_number_t matrix_fill(card_t rows, card_t cols, number_t value) {
#ifdef DPS
  return TOP_LEVEL_linalg_matrixFill_dps(storage_alloc(MATRIX_ROWS_OFFSET(rows, cols, rows)), rows, cols, value, rows, cols, 0);
#else
  return TOP_LEVEL_linalg_matrixFill(rows, cols, value);
#endif
}

array_number_t vector_fill(card_t rows, number_t value) {
  return matrix_fill(1, rows, value)->arr[0];
}

double dist(int seed) {
  return ((double)rand()/(double)RAND_MAX);
}

number_t vectorSum(array_number_t v) {
	number_t macroDef26 = 0;
	for(int cur_idx = 0; cur_idx < v->length; cur_idx++){
		number_t cur = v->arr[cur_idx];
		
		macroDef26 = (macroDef26) + (cur);
	}
	return macroDef26;
}

int main(int argc, char** argv)
{
	if(argc != 2) {
		printf("You should use the following format for running this program: %s <Number of Iterations>\n", argv[0]);
		exit(1);
	}
	int N = atoi(argv[1]);
	int rng = 42;
    srand(rng);

	array_number_t vec1 = vector_fill(DIM, 0.0);
	array_number_t vec2 = vector_fill(DIM, 0.0);
	array_number_t vec3 = vector_fill(DIM, 0.0);
	for(int i=0; i<DIM; i++) {
		vec1->arr[i] = dist(rng);
		vec2->arr[i] = dist(rng);
		vec3->arr[i] = dist(rng);
	}

	storage_t s = storage_alloc(VECTOR_ALL_BYTES(DIM));
	
    // timer_t t = tic();
    clock_t start_time = clock();

    double total = 0;
    for (int count = 0; count < N; ++count) {
        total += vectorSum(TOP_LEVEL_linalg_vectorAdd3_dps(s, vec1, vec2, vec3, DIM, DIM, DIM));
    }
    clock_t end_time = clock();
    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("%f milliseconds\n", elapsed_time * 1000);

    // float elapsed = toc2(t);
    // printf("total =%f, time per call = %f ms\n, %f", total, elapsed / (double)(N), elapsed);
	return 0;
}
