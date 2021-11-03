#ifndef __USECASES_STENCIL_STORAGED_H__ 
#define __USECASES_STENCIL_STORAGED_H__ 
#include "../../Runtime/C/fsharp.h"
#include <stdio.h>
#include <math.h>
#include "linalg_storaged.h"

card_t TOP_LEVEL_usecases_stencil_seidel2D_new_value_shp(matrix_shape_t image_shp, card_t row_shp, card_t col_shp) {
	
	return 0;
}


number_t TOP_LEVEL_usecases_stencil_seidel2D_new_value_dps(storage_t stgVar532, array_array_number_t image_dps, index_t row_dps, index_t col_dps, matrix_shape_t image_shp, card_t row_shp, card_t col_shp) {
	card_t sum_shp = 0;
	card_t size561 = width_card_t(image_shp.elem);
	array_number_t stgVar534 = storage_alloc(size561);
	number_t macroDef552;
	macroDef552 = image_dps->arr[(row_dps) - (1)]->arr[(col_dps) - (1)];;
	storage_free(stgVar534, size561);
	card_t size562 = width_card_t(image_shp.elem);
	array_number_t stgVar536 = storage_alloc(size562);
	number_t macroDef553;
	macroDef553 = image_dps->arr[(row_dps) - (1)]->arr[col_dps];;
	storage_free(stgVar536, size562);
	card_t size563 = width_card_t(image_shp.elem);
	array_number_t stgVar538 = storage_alloc(size563);
	number_t macroDef554;
	macroDef554 = image_dps->arr[(row_dps) - (1)]->arr[(col_dps) + (1)];;
	storage_free(stgVar538, size563);
	card_t size564 = width_card_t(image_shp.elem);
	array_number_t stgVar540 = storage_alloc(size564);
	number_t macroDef555;
	macroDef555 = image_dps->arr[row_dps]->arr[(col_dps) - (1)];;
	storage_free(stgVar540, size564);
	card_t size565 = width_card_t(image_shp.elem);
	array_number_t stgVar542 = storage_alloc(size565);
	number_t macroDef556;
	macroDef556 = image_dps->arr[row_dps]->arr[col_dps];;
	storage_free(stgVar542, size565);
	card_t size566 = width_card_t(image_shp.elem);
	array_number_t stgVar544 = storage_alloc(size566);
	number_t macroDef557;
	macroDef557 = image_dps->arr[row_dps]->arr[(col_dps) + (1)];;
	storage_free(stgVar544, size566);
	card_t size567 = width_card_t(image_shp.elem);
	array_number_t stgVar546 = storage_alloc(size567);
	number_t macroDef558;
	macroDef558 = image_dps->arr[(row_dps) + (1)]->arr[(col_dps) - (1)];;
	storage_free(stgVar546, size567);
	card_t size568 = width_card_t(image_shp.elem);
	array_number_t stgVar548 = storage_alloc(size568);
	number_t macroDef559;
	macroDef559 = image_dps->arr[(row_dps) + (1)]->arr[col_dps];;
	storage_free(stgVar548, size568);
	card_t size569 = width_card_t(image_shp.elem);
	array_number_t stgVar550 = storage_alloc(size569);
	number_t macroDef560;
	macroDef560 = image_dps->arr[(row_dps) + (1)]->arr[(col_dps) + (1)];;
	storage_free(stgVar550, size569);
	number_t sum_dps = ((((((((macroDef552) + (macroDef553)) + (macroDef554)) + (macroDef555)) + (macroDef556)) + (macroDef557)) + (macroDef558)) + (macroDef559)) + (macroDef560);
	return (sum_dps) / ((double)(9));
}

matrix_shape_t TOP_LEVEL_usecases_stencil_seidel2D_shp(matrix_shape_t image_shp) {
	
	return nested_shape_card_t(TOP_LEVEL_linalg_cols_shp(image_shp), TOP_LEVEL_linalg_rows_shp(image_shp));
}


array_array_number_t TOP_LEVEL_usecases_stencil_seidel2D_dps(storage_t stgVar570, array_array_number_t image_dps, matrix_shape_t image_shp) {
	card_t n_shp = TOP_LEVEL_linalg_rows_shp(image_shp);
	card_t size592 = width_card_t(n_shp);
	array_number_t stgVar571 = storage_alloc(size592);
	array_array_number_t macroDef588;card_t n_dps = TOP_LEVEL_linalg_rows_dps(stgVar571, image_dps, image_shp);
	card_t m_shp = TOP_LEVEL_linalg_cols_shp(image_shp);
	card_t size591 = width_card_t(m_shp);
	array_number_t stgVar573 = storage_alloc(size591);
	array_array_number_t macroDef587;card_t m_dps = TOP_LEVEL_linalg_cols_dps(stgVar573, image_dps, image_shp);
	array_array_number_t macroDef586 = (array_array_number_t)stgVar570;
		macroDef586->length=n_dps;
		macroDef586->arr=(array_number_t*)(STG_OFFSET(macroDef586, VECTOR_HEADER_BYTES));
		storage_t stgVar575 = (STG_OFFSET(macroDef586, MATRIX_HEADER_BYTES(n_dps)));
		for(int row_dps = 0; row_dps < macroDef586->length; row_dps++){
			array_number_t macroDef585 = (array_number_t)stgVar575;
		macroDef585->length=m_dps;
		macroDef585->arr=(number_t*)(STG_OFFSET(macroDef585, VECTOR_HEADER_BYTES));
		storage_t stgVar576 = macroDef585;
		for(int col_dps = 0; col_dps < macroDef585->length; col_dps++){
			number_t ite589 = 0;
	if(false) {
		
		ite589 = TOP_LEVEL_usecases_stencil_seidel2D_new_value_dps(stgVar576, image_dps, row_dps, col_dps, image_shp, 0, 0);;
	} else {
		card_t size590 = width_card_t(image_shp.elem);
	array_number_t stgVar580 = storage_alloc(size590);
	number_t macroDef584;
	macroDef584 = image_dps->arr[row_dps]->arr[col_dps];;
	storage_free(stgVar580, size590);
		ite589 = macroDef584;;
	}
			macroDef585->arr[col_dps] = ite589;;
			stgVar576 = STG_OFFSET(stgVar576, sizeof(number_t));
		}
			macroDef586->arr[row_dps] = macroDef585;;
			stgVar575 = STG_OFFSET(stgVar575, VECTOR_ALL_BYTES(macroDef586->arr[row_dps]->length));
		}
	macroDef587 = macroDef586;;
	storage_free(stgVar573, size591);
	macroDef588 = macroDef587;;
	storage_free(stgVar571, size592);
	return macroDef588;
}

card_t TOP_LEVEL_usecases_stencil_jacobi2D_new_value_shp(matrix_shape_t image_shp, card_t row_shp, card_t col_shp) {
	
	return 0;
}


number_t TOP_LEVEL_usecases_stencil_jacobi2D_new_value_dps(storage_t stgVar593, array_array_number_t image_dps, index_t row_dps, index_t col_dps, matrix_shape_t image_shp, card_t row_shp, card_t col_shp) {
	card_t sum_shp = 0;
	card_t size610 = width_card_t(image_shp.elem);
	array_number_t stgVar595 = storage_alloc(size610);
	number_t macroDef605;
	macroDef605 = image_dps->arr[(row_dps) - (1)]->arr[col_dps];;
	storage_free(stgVar595, size610);
	card_t size611 = width_card_t(image_shp.elem);
	array_number_t stgVar597 = storage_alloc(size611);
	number_t macroDef606;
	macroDef606 = image_dps->arr[row_dps]->arr[(col_dps) - (1)];;
	storage_free(stgVar597, size611);
	card_t size612 = width_card_t(image_shp.elem);
	array_number_t stgVar599 = storage_alloc(size612);
	number_t macroDef607;
	macroDef607 = image_dps->arr[row_dps]->arr[col_dps];;
	storage_free(stgVar599, size612);
	card_t size613 = width_card_t(image_shp.elem);
	array_number_t stgVar601 = storage_alloc(size613);
	number_t macroDef608;
	macroDef608 = image_dps->arr[row_dps]->arr[(col_dps) + (1)];;
	storage_free(stgVar601, size613);
	card_t size614 = width_card_t(image_shp.elem);
	array_number_t stgVar603 = storage_alloc(size614);
	number_t macroDef609;
	macroDef609 = image_dps->arr[(row_dps) + (1)]->arr[col_dps];;
	storage_free(stgVar603, size614);
	number_t sum_dps = ((((macroDef605) + (macroDef606)) + (macroDef607)) + (macroDef608)) + (macroDef609);
	return (sum_dps) / ((double)(5));
}

matrix_shape_t TOP_LEVEL_usecases_stencil_jacobi2D_shp(matrix_shape_t image_shp) {
	
	return nested_shape_card_t(TOP_LEVEL_linalg_cols_shp(image_shp), TOP_LEVEL_linalg_rows_shp(image_shp));
}


array_array_number_t TOP_LEVEL_usecases_stencil_jacobi2D_dps(storage_t stgVar615, array_array_number_t image_dps, matrix_shape_t image_shp) {
	card_t n_shp = TOP_LEVEL_linalg_rows_shp(image_shp);
	card_t size637 = width_card_t(n_shp);
	array_number_t stgVar616 = storage_alloc(size637);
	array_array_number_t macroDef633;card_t n_dps = TOP_LEVEL_linalg_rows_dps(stgVar616, image_dps, image_shp);
	card_t m_shp = TOP_LEVEL_linalg_cols_shp(image_shp);
	card_t size636 = width_card_t(m_shp);
	array_number_t stgVar618 = storage_alloc(size636);
	array_array_number_t macroDef632;card_t m_dps = TOP_LEVEL_linalg_cols_dps(stgVar618, image_dps, image_shp);
	array_array_number_t macroDef631 = (array_array_number_t)stgVar615;
		macroDef631->length=n_dps;
		macroDef631->arr=(array_number_t*)(STG_OFFSET(macroDef631, VECTOR_HEADER_BYTES));
		storage_t stgVar620 = (STG_OFFSET(macroDef631, MATRIX_HEADER_BYTES(n_dps)));
		for(int row_dps = 0; row_dps < macroDef631->length; row_dps++){
			array_number_t macroDef630 = (array_number_t)stgVar620;
		macroDef630->length=m_dps;
		macroDef630->arr=(number_t*)(STG_OFFSET(macroDef630, VECTOR_HEADER_BYTES));
		storage_t stgVar621 = macroDef630;
		for(int col_dps = 0; col_dps < macroDef630->length; col_dps++){
			number_t ite634 = 0;
	if(row_dps > 0 && row_dps < macroDef631->length - 1 && col_dps > 0 && col_dps < macroDef630->length - 1) {
		ite634 = TOP_LEVEL_usecases_stencil_jacobi2D_new_value_dps(stgVar621, image_dps, row_dps, col_dps, image_shp, 0, 0);;
	} else {
		card_t size635 = width_card_t(image_shp.elem);
	array_number_t stgVar625 = storage_alloc(size635);
	number_t macroDef629;
	macroDef629 = image_dps->arr[row_dps]->arr[col_dps];;
	storage_free(stgVar625, size635);
		ite634 = macroDef629;;
	}
			macroDef630->arr[col_dps] = ite634;;
			stgVar621 = STG_OFFSET(stgVar621, sizeof(number_t));
		}
			macroDef631->arr[row_dps] = macroDef630;;
			stgVar620 = STG_OFFSET(stgVar620, VECTOR_ALL_BYTES(macroDef631->arr[row_dps]->length));
		}
	macroDef632 = macroDef631;;
	storage_free(stgVar618, size636);
	macroDef633 = macroDef632;;
	storage_free(stgVar616, size637);
	return macroDef633;
}
#endif
