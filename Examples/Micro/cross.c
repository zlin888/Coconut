#define DPS
#define FUSED
#define HOIST

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
#include "../test.h"
const size_t DIM = 3;
#define N 10000000

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
    srand(42);
	array_number_t vec1 = vector_fill(DIM, 0.0);
	array_number_t vec2 = vector_fill(DIM, 0.0);
	for(int i=0; i<DIM; i++) {
		vec1->arr[i] = dist();
	}
	for(int i=0; i<DIM; i++) {
		vec2->arr[i] = dist();
	}

#ifdef HOIST
	storage_t s = storage_alloc(VECTOR_ALL_BYTES(DIM));
#endif
    array_print(vec1);
    array_print(vec2);

    double total = 0;
    TIC();
    for (int count = 0; count < N; ++count) {
        vec1->arr[0] += 1.0 / (2.0 + vec1->arr[0]);
        vec2->arr[2] += 1.0 / (2.0 + vec2->arr[2]);
#ifdef DPS
#ifndef HOIST
	storage_t s = storage_alloc(VECTOR_ALL_BYTES(DIM));
#endif
#endif
    #ifdef DPS
        total += vectorSum(TOP_LEVEL_linalg_cross_dps(s, vec1, vec2, DIM, DIM));
    //array_number_t arr = TOP_LEVEL_linalg_cross_dps(s, vec1, vec2, DIM, DIM);
         //total += arr->arr[0];
	#else
        total += vectorSum(TOP_LEVEL_linalg_cross(vec1, vec2));
	#endif
#ifdef DPS
#ifndef HOIST
	storage_free(s, VECTOR_ALL_BYTES(DIM));
#endif
#endif
    }
    TOC();
    printf("%f", total);

    // float elapsed = toc2(t);
    // printf("total =%f, time per call = %f ms\n, %f", total, elapsed / (double)(N), elapsed);
	return 0;
}
