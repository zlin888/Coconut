#ifndef __USECASES_BLUR_STORAGED_H__ 
#define __USECASES_BLUR_STORAGED_H__ 
#include "../../Runtime/C/fsharp.h"
#include <stdio.h>
#include <math.h>
#include "linalg_storaged.h"

card_t TOP_LEVEL_usecases_blur_new_value_shp(matrix_shape_t image_shp, card_t row_shp, card_t col_shp) {
	
	return 0;
}


number_t TOP_LEVEL_usecases_blur_new_value_dps(storage_t stgVar1, array_array_number_t image_dps, index_t row_dps, index_t col_dps, matrix_shape_t image_shp, card_t row_shp, card_t col_shp) {
	card_t sum_shp = 0;
	card_t size30 = width_card_t(image_shp.elem);
	array_number_t stgVar3 = storage_alloc(size30);
	number_t macroDef21;
	macroDef21 = image_dps->arr[(row_dps) - (1)]->arr[(col_dps) - (1)];;
	storage_free(stgVar3, size30);
	card_t size31 = width_card_t(image_shp.elem);
	array_number_t stgVar5 = storage_alloc(size31);
	number_t macroDef22;
	macroDef22 = image_dps->arr[(row_dps) - (1)]->arr[col_dps];;
	storage_free(stgVar5, size31);
	card_t size32 = width_card_t(image_shp.elem);
	array_number_t stgVar7 = storage_alloc(size32);
	number_t macroDef23;
	macroDef23 = image_dps->arr[(row_dps) - (1)]->arr[(col_dps) + (1)];;
	storage_free(stgVar7, size32);
	card_t size33 = width_card_t(image_shp.elem);
	array_number_t stgVar9 = storage_alloc(size33);
	number_t macroDef24;
	macroDef24 = image_dps->arr[row_dps]->arr[(col_dps) - (1)];;
	storage_free(stgVar9, size33);
	card_t size34 = width_card_t(image_shp.elem);
	array_number_t stgVar11 = storage_alloc(size34);
	number_t macroDef25;
	macroDef25 = image_dps->arr[row_dps]->arr[col_dps];;
	storage_free(stgVar11, size34);
	card_t size35 = width_card_t(image_shp.elem);
	array_number_t stgVar13 = storage_alloc(size35);
	number_t macroDef26;
	macroDef26 = image_dps->arr[row_dps]->arr[(col_dps) + (1)];;
	storage_free(stgVar13, size35);
	card_t size36 = width_card_t(image_shp.elem);
	array_number_t stgVar15 = storage_alloc(size36);
	number_t macroDef27;
	macroDef27 = image_dps->arr[(row_dps) + (1)]->arr[(col_dps) - (1)];;
	storage_free(stgVar15, size36);
	card_t size37 = width_card_t(image_shp.elem);
	array_number_t stgVar17 = storage_alloc(size37);
	number_t macroDef28;
	macroDef28 = image_dps->arr[(row_dps) + (1)]->arr[col_dps];;
	storage_free(stgVar17, size37);
	card_t size38 = width_card_t(image_shp.elem);
	array_number_t stgVar19 = storage_alloc(size38);
	number_t macroDef29;
	macroDef29 = image_dps->arr[(row_dps) + (1)]->arr[(col_dps) + (1)];;
	storage_free(stgVar19, size38);
	number_t sum_dps = ((((((((macroDef21) + (macroDef22)) + (macroDef23)) + (macroDef24)) + (macroDef25)) + (macroDef26)) + (macroDef27)) + (macroDef28)) + (macroDef29);
	return (sum_dps) / ((double)(9));
}

matrix_shape_t TOP_LEVEL_usecases_blur_blur_forward_shp(matrix_shape_t image_shp) {
	
	return nested_shape_card_t(TOP_LEVEL_linalg_cols_shp(image_shp), TOP_LEVEL_linalg_rows_shp(image_shp));
}


array_array_number_t TOP_LEVEL_usecases_blur_blur_forward_dps(storage_t stgVar39, array_array_number_t image_dps, matrix_shape_t image_shp) {
	card_t n_shp = TOP_LEVEL_linalg_rows_shp(image_shp);
	card_t size61 = width_card_t(n_shp);
	array_number_t stgVar40 = storage_alloc(size61);
	array_array_number_t macroDef57;card_t n_dps = TOP_LEVEL_linalg_rows_dps(stgVar40, image_dps, image_shp);
	card_t m_shp = TOP_LEVEL_linalg_cols_shp(image_shp);
	card_t size60 = width_card_t(m_shp);
	array_number_t stgVar42 = storage_alloc(size60);
	array_array_number_t macroDef56;card_t m_dps = TOP_LEVEL_linalg_cols_dps(stgVar42, image_dps, image_shp);
	array_array_number_t macroDef55 = (array_array_number_t)stgVar39;
		macroDef55->length=n_dps;
		macroDef55->arr=(array_number_t*)(STG_OFFSET(macroDef55, VECTOR_HEADER_BYTES));
		storage_t stgVar44 = (STG_OFFSET(macroDef55, MATRIX_HEADER_BYTES(n_dps)));
		for(int row_dps = 0; row_dps < macroDef55->length; row_dps++){
			array_number_t macroDef54 = (array_number_t)stgVar44;
		macroDef54->length=m_dps;
		macroDef54->arr=(number_t*)(STG_OFFSET(macroDef54, VECTOR_HEADER_BYTES));
		storage_t stgVar45 = macroDef54;
		for(int col_dps = 0; col_dps < macroDef54->length; col_dps++){
			number_t ite58 = 0;
	if(ERROR[IfThenElse (IfThenElse (IfThenElse (Call (None, op_GreaterThan,
                                          [row_dps, Value (0)]),
                                    Call (None, op_LessThan,
                                          [row_dps,
                                           Call (None, op_Subtraction,
                                                 [Call (None, cardToInt, [n_dps]),
                                                  Value (1)])]), Value (false)),
                        Call (None, op_GreaterThan, [col_dps, Value (0)]),
                        Value (false)),
            Call (None, op_LessThan,
                  [col_dps,
                   Call (None, op_Subtraction,
                         [Call (None, cardToInt, [m_dps]), Value (1)])]),
            Value (false))]) {
		
		ite58 = TOP_LEVEL_usecases_blur_new_value_dps(stgVar45, image_dps, row_dps, col_dps, image_shp, 0, 0);;
	} else {
		card_t size59 = width_card_t(image_shp.elem);
	array_number_t stgVar49 = storage_alloc(size59);
	number_t macroDef53;
	macroDef53 = image_dps->arr[row_dps]->arr[col_dps];;
	storage_free(stgVar49, size59);
		ite58 = macroDef53;;
	}
			macroDef54->arr[col_dps] = ite58;;
			stgVar45 = STG_OFFSET(stgVar45, sizeof(number_t));
		}
			macroDef55->arr[row_dps] = macroDef54;;
			stgVar44 = STG_OFFSET(stgVar44, VECTOR_ALL_BYTES(macroDef55->arr[row_dps]->length));
		}
	macroDef56 = macroDef55;;
	storage_free(stgVar42, size60);
	macroDef57 = macroDef56;;
	storage_free(stgVar40, size61);
	return macroDef57;
}
#endif
