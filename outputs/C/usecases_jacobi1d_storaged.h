#ifndef __USECASES_JACOBI1D_STORAGED_H__ 
#define __USECASES_JACOBI1D_STORAGED_H__ 
#include "../../Runtime/C/fsharp.h"
#include <stdio.h>
#include <math.h>
#include "linalg_storaged.h"

card_t TOP_LEVEL_usecases_jacobi1d_jacobi1D_new_value_shp(card_t image_shp, card_t row_shp) {
	
	return 0;
}


number_t TOP_LEVEL_usecases_jacobi1d_jacobi1D_new_value_dps(storage_t stgVar532, array_number_t image_dps, index_t row_dps, card_t image_shp, card_t row_shp) {
	card_t sum_shp = 0;
	number_t sum_dps = ((image_dps->arr[(row_dps) - (1)]) + (image_dps->arr[row_dps])) + (image_dps->arr[(row_dps) + (1)]);
	return (sum_dps) / ((double)(3));
}

card_t TOP_LEVEL_usecases_jacobi1d_Jacobi1D_shp(card_t image_shp) {
	
	return image_shp;
}


array_number_t TOP_LEVEL_usecases_jacobi1d_Jacobi1D_dps(storage_t stgVar537, array_number_t image_dps, card_t image_shp) {
	card_t n_shp = image_shp;
	card_t macroDef544 = image_dps->length;
	card_t n_dps = macroDef544;
	array_number_t macroDef545 = (array_number_t)stgVar537;
		macroDef545->length=n_dps;
		macroDef545->arr=(number_t*)(STG_OFFSET(macroDef545, VECTOR_HEADER_BYTES));
		storage_t stgVar540 = macroDef545;
		for(int row_dps = 0; row_dps < macroDef545->length; row_dps++){
			number_t ite546 = 0;
	if(row_dps > 0 && row_dps < n_dps - 1) {
		
		ite546 = TOP_LEVEL_usecases_jacobi1d_jacobi1D_new_value_dps(stgVar540, image_dps, row_dps, image_shp, 0);;
	} else {
		
		ite546 = image_dps->arr[row_dps];;
	}
			macroDef545->arr[row_dps] = ite546;;
			stgVar540 = STG_OFFSET(stgVar540, sizeof(number_t));
		}
	return macroDef545;
}
#endif
