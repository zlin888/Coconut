#ifndef __USECASES_JACOBI2D_STORAGED_H__ 
#define __USECASES_JACOBI2D_STORAGED_H__ 
#include "../../Runtime/C/fsharp.h"
#include <stdio.h>
#include <math.h>
#include "linalg_storaged.h"

card_t TOP_LEVEL_usecases_jacobi2d_jacobi2D_new_value_shp(matrix_shape_t image_shp, card_t row_shp, card_t col_shp) {
	
	return 0;
}


number_t TOP_LEVEL_usecases_jacobi2d_jacobi2D_new_value_dps(storage_t stgVar1, array_array_number_t image_dps, index_t row_dps, index_t col_dps, matrix_shape_t image_shp, card_t row_shp, card_t col_shp) {
	card_t sum_shp = 0;
	card_t size18 = width_card_t(image_shp.elem);
	array_number_t stgVar3 = storage_alloc(size18);
	number_t macroDef13;
	macroDef13 = image_dps->arr[(row_dps) - (1)]->arr[col_dps];;
	storage_free(stgVar3, size18);
	card_t size19 = width_card_t(image_shp.elem);
	array_number_t stgVar5 = storage_alloc(size19);
	number_t macroDef14;
	macroDef14 = image_dps->arr[row_dps]->arr[(col_dps) - (1)];;
	storage_free(stgVar5, size19);
	card_t size20 = width_card_t(image_shp.elem);
	array_number_t stgVar7 = storage_alloc(size20);
	number_t macroDef15;
	macroDef15 = image_dps->arr[row_dps]->arr[col_dps];;
	storage_free(stgVar7, size20);
	card_t size21 = width_card_t(image_shp.elem);
	array_number_t stgVar9 = storage_alloc(size21);
	number_t macroDef16;
	macroDef16 = image_dps->arr[row_dps]->arr[(col_dps) + (1)];;
	storage_free(stgVar9, size21);
	card_t size22 = width_card_t(image_shp.elem);
	array_number_t stgVar11 = storage_alloc(size22);
	number_t macroDef17;
	macroDef17 = image_dps->arr[(row_dps) + (1)]->arr[col_dps];;
	storage_free(stgVar11, size22);
	number_t sum_dps = ((((macroDef13) + (macroDef14)) + (macroDef15)) + (macroDef16)) + (macroDef17);
	return (sum_dps) / ((double)(5));
}

matrix_shape_t TOP_LEVEL_usecases_jacobi2d_recJacobi2D_shp(matrix_shape_t image_shp, card_t count_shp) {
	
	return nested_shape_card_t(TOP_LEVEL_linalg_cols_shp(image_shp), TOP_LEVEL_linalg_rows_shp(image_shp));
}

typedef struct env_t_56 {
	card_t m_shp;
} env_t_56;
env_t_56 make_env_t_56(card_t m_shp) {
	env_t_56 env;
	env.m_shp = m_shp;
	return env;
}

value_t lambda56(env_t_56* env45, card_t row_shp) {
	card_t m_shp44 = env45->m_shp;
	value_t res;
	res.card_t_value = m_shp44;
	return res;
}
array_array_number_t TOP_LEVEL_usecases_jacobi2d_recJacobi2D_dps(storage_t stgVar23, array_array_number_t image_dps, index_t count_dps, matrix_shape_t image_shp, card_t count_shp) {
	card_t n_shp = TOP_LEVEL_linalg_rows_shp(image_shp);
	card_t size60 = width_card_t(n_shp);
	array_number_t stgVar24 = storage_alloc(size60);
	array_array_number_t macroDef53;card_t n_dps = TOP_LEVEL_linalg_rows_dps(stgVar24, image_dps, image_shp);
	card_t m_shp = TOP_LEVEL_linalg_cols_shp(image_shp);
	card_t size59 = width_card_t(m_shp);
	array_number_t stgVar26 = storage_alloc(size59);
	array_array_number_t macroDef52;card_t m_dps = TOP_LEVEL_linalg_cols_dps(stgVar26, image_dps, image_shp);
	env_t_56 env_t_56_value = make_env_t_56(m_shp); closure_t closure47 = make_closure(lambda56, &env_t_56_value);
	matrix_shape_t ret_shp = nested_shape_card_t(closure47.lam(closure47.env, 0).card_t_value, n_shp);
	card_t size58 = width_matrix_shape_t(ret_shp);
	array_number_t stgVar28 = storage_alloc(size58);
	array_array_number_t macroDef51;array_array_number_t macroDef50 = (array_array_number_t)stgVar28;
		macroDef50->length=n_dps;
		macroDef50->arr=(array_number_t*)(STG_OFFSET(macroDef50, VECTOR_HEADER_BYTES));
		storage_t stgVar29 = (STG_OFFSET(macroDef50, MATRIX_HEADER_BYTES(n_dps)));
		for(int row_dps = 0; row_dps < macroDef50->length; row_dps++){
			array_number_t macroDef49 = (array_number_t)stgVar29;
		macroDef49->length=m_dps;
		macroDef49->arr=(number_t*)(STG_OFFSET(macroDef49, VECTOR_HEADER_BYTES));
		storage_t stgVar30 = macroDef49;
		for(int col_dps = 0; col_dps < macroDef49->length; col_dps++){
			number_t ite54 = 0;
	if(row_dps > 0 && row_dps < macroDef50->length - 1 && col_dps > 0 && col_dps < macroDef50->length - 1) {
		ite54 = TOP_LEVEL_usecases_jacobi2d_jacobi2D_new_value_dps(stgVar30, image_dps, row_dps, col_dps, image_shp, 0, 0);;
	} else {
		card_t size57 = width_card_t(image_shp.elem);
	array_number_t stgVar34 = storage_alloc(size57);
	number_t macroDef48;
	macroDef48 = image_dps->arr[row_dps]->arr[col_dps];;
	storage_free(stgVar34, size57);
		ite54 = macroDef48;;
	}
			macroDef49->arr[col_dps] = ite54;;
			stgVar30 = STG_OFFSET(stgVar30, sizeof(number_t));
		}
			macroDef50->arr[row_dps] = macroDef49;;
			stgVar29 = STG_OFFSET(stgVar29, VECTOR_ALL_BYTES(macroDef50->arr[row_dps]->length));
		}
	array_array_number_t ret_dps = macroDef50;
	array_array_number_t ite55 ;
    // printf("%d\n ",  count_dps);
	if((count_dps) == (0)) {
		ite55 = ret_dps;;
	} else {
		ite55 = TOP_LEVEL_usecases_jacobi2d_recJacobi2D_dps(stgVar23, ret_dps, (count_dps) - (1), ret_shp, 0);;
	}
    printf("%f %d\n ", ite55->arr[5]->arr[5], count_dps);
	macroDef51 = ite55;;
	//storage_free(stgVar28, size58);
	macroDef52 = macroDef51;;
	storage_free(stgVar26, size59);

    printf("%f %d\n ", ite55->arr[5]->arr[5], count_dps);
	return macroDef53;
}
#endif
