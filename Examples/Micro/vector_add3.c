#include "../../Runtime/C/fsharp.h"
#include <stdio.h>
#include <math.h>
#include "../../outputs/C/linalg_opt_storaged.h"
#include <time.h>
#include <stdlib.h>

card_t DIM = 3;

array_number_t fill() {
	card_t size = width_card_t(DIM);
	// array_number_t a = (array_number_t)storage_alloc(size);
	array_number_t stgVarA = storage_alloc(size);
	array_number_t a = (array_number_t)stgVarA;

	a->length=DIM;
	a->arr=(number_t*)(STG_OFFSET(stgVarA, VECTOR_HEADER_BYTES));

	for (int i = 0; i < DIM; i++) {
		a->arr[i] = i+1;
	}
	
	return a;
}

card_t TOP_LEVEL_linalg_vectorMap2_shp(closure_t f_shp, card_t v1_shp, card_t v2_shp) {
	return v1_shp;
}

typedef empty_env_t env_t_193;

value_t lambda193(env_t_193* env190, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}

card_t TOP_LEVEL_linalg_vectorAdd_shp(card_t x_shp, card_t y_shp) {
	env_t_193 env_t_193_value = make_empty_env(); closure_t closure192 = make_closure(lambda193, &env_t_193_value);
	return TOP_LEVEL_linalg_vectorMap2_shp(closure192, x_shp, y_shp);
}


card_t TOP_LEVEL_linalg_vectorAdd3_shp(card_t x_shp, card_t y_shp, card_t z_shp) {
	
	return TOP_LEVEL_linalg_vectorAdd_shp(TOP_LEVEL_linalg_vectorAdd_shp(x_shp, y_shp), z_shp);
}


int main() {
    srand(time(NULL));
    int r = rand();
    int n = 1000000;

    array_number_t a = fill();
    array_number_t b = fill();
    array_number_t c = fill();

    card_t g_shp = TOP_LEVEL_linalg_vectorAdd3_shp(DIM, DIM, DIM);
    card_t size663 = width_card_t(g_shp);
    array_number_t stgVar553 = storage_alloc(size663);
    array_number_t g_dps = TOP_LEVEL_linalg_vectorAdd3_dps(stgVar553, a, b, c, DIM, DIM, DIM);

    // card_t c_shp = TOP_LEVEL_linalg_cross_shp(DIM, DIM);
    // card_t size667 = width_card_t(c_shp);
    // array_number_t stgVar541 = storage_alloc(size667);
    // b->arr[1] = 6;
    // array_number_t c_dps = TOP_LEVEL_linalg_cross_dps(stgVar541, a, b, DIM, DIM);
	
    timer_t t = tic();
    for (int i = 0; i < n ; i++) {
        TOP_LEVEL_linalg_vectorAdd3_dps(stgVar553, a, b, c, DIM, DIM, DIM);
    }
    float elapsed = toc2(t);
    printf("total =%f\n", elapsed);

    // t = tic();
    // for (int i = 0; i < n ; i++) {
	// TOP_LEVEL_linalg_cross_dps(stgVar541, a, b, DIM, DIM);
    // }
    // elapsed = toc2(t);
    // printf("total =%f\n", elapsed);



    return 0;
} 
