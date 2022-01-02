#define DPS
#define FUSED
#define HOIST
#define ADD3

#ifdef DPS
#ifdef FUSED
#include "../../outputs/C/linalg_opt_storaged.h"
#else
#include "../../outputs/C/linalg_storaged.h"
#endif
#else
#ifdef FUSED
#include "../../outputs/C/linalg_opt.h"
#else
#include "../../outputs/C/linalg.h"
#endif
#endif 
#ifdef ADD3
    const size_t DIM = 100;
#elif DOT
    const size_t DIM = 100;
#elif CROSS
    const size_t DIM = 3;
#endif
#define N 1000000


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

card_t comp_c(card_t v1_c, card_t v2_c, card_t v3_c) {
	
	return v1_c;
}

array_number_t comp_s(storage_t stgVar97, array_number_t v1_s, array_number_t v2_s, array_number_t v3_s, card_t v1_c, card_t v2_c, card_t v3_c) {
	card_t macroDef103 = v1_s->length;
	array_number_t macroDef104 = (array_number_t)stgVar97;
		macroDef104->length=macroDef103;
		macroDef104->arr=(number_t*)(STG_OFFSET(macroDef104, VECTOR_HEADER_BYTES));
		storage_t stgVar99 = macroDef104;
		for(int i_s = 0; i_s < macroDef104->length; i_s++){
			
			macroDef104->arr[i_s] = (v1_s->arr[i_s]) + ((v2_s->arr[i_s]) + (v3_s->arr[i_s]));;
			stgVar99 = STG_OFFSET(stgVar99, sizeof(number_t));
		}
	return macroDef104;
}


int main(int argc, char** argv)
{
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

#ifdef HOIST
	storage_t s = storage_alloc(VECTOR_ALL_BYTES(DIM));
#endif
	
    // timer_t t = tic();
    clock_t start_time = clock();

    double total = 0;
    for (int count = 0; count < N; ++count) {
        total += vectorSum(comp_s(s, vec1, vec2, vec3, DIM, DIM, DIM));
    }
    clock_t end_time = clock();
    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("%f milliseconds\n", elapsed_time * 1000);
    printf("%f\n", total);

    // float elapsed = toc2(t);
    // printf("total =%f, time per call = %f ms\n, %f", total, elapsed / (double)(N), elapsed);
	return 0;
}
