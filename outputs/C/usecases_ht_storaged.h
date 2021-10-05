#ifndef __USECASES_HT_STORAGED_H__ 
#define __USECASES_HT_STORAGED_H__ 
#include "../../Runtime/C/fsharp.h"
#include <stdio.h>
#include <math.h>
#include "linalg_storaged.h"

matrix3d_shape_t TOP_LEVEL_usecases_ht_matrix3DUpdate_shp(matrix3d_shape_t m_shp, card_t s_shp, card_t e_shp, matrix3d_shape_t nm_shp) {
	
	return nested_shape_matrix_shape_t(nm_shp.elem, m_shp.card);
}


array_array_array_number_t TOP_LEVEL_usecases_ht_matrix3DUpdate_dps(storage_t stgVar1, array_array_array_number_t m_dps, index_t s_dps, index_t e_dps, array_array_array_number_t nm_dps, matrix3d_shape_t m_shp, card_t s_shp, card_t e_shp, matrix3d_shape_t nm_shp) {
	card_t macroDef7 = m_dps->length;
	array_array_array_number_t macroDef8 = (array_array_array_number_t)stgVar1;
		macroDef8->length=macroDef7;
		macroDef8->arr=(array_array_number_t*)(STG_OFFSET(macroDef8, VECTOR_HEADER_BYTES));
		storage_t stgVar3 = (STG_OFFSET(macroDef8, MATRIX_HEADER_BYTES(macroDef7)));
		for(int i_dps = 0; i_dps < macroDef8->length; i_dps++){
			card_t isInRange_shp = 0;
			bool_t isInRange_dps = 0;
	if((i_dps) >= (s_dps)) {
		
		isInRange_dps = (i_dps) < (e_dps);;
	} else {
		
		isInRange_dps = false;;
	}
			array_array_number_t ite9 ;
	if(isInRange_dps) {
		
		ite9 = nm_dps->arr[(i_dps) - (s_dps)];;
	} else {
		
		ite9 = m_dps->arr[i_dps];;
	}
			macroDef8->arr[i_dps] = ite9;;
			stgVar3 = STG_OFFSET(stgVar3, VECTOR_ALL_BYTES(macroDef8->arr[i_dps]->length));
		}
	return macroDef8;
}

matrix_shape_t TOP_LEVEL_usecases_ht_to_pose_params_shp(card_t theta_shp, card_t n_bones_shp) {
	
	return TOP_LEVEL_linalg_matrixConcat_shp(nested_shape_card_t(TOP_LEVEL_linalg_vectorSlice_shp(3, 0, theta_shp), 5), TOP_LEVEL_linalg_matrixConcat_shp(nested_shape_card_t(3, 4), TOP_LEVEL_linalg_matrixConcat_shp(nested_shape_card_t(3, 4), TOP_LEVEL_linalg_matrixConcat_shp(nested_shape_card_t(3, 4), TOP_LEVEL_linalg_matrixConcat_shp(nested_shape_card_t(3, 4), nested_shape_card_t(3, 4))))));
}


array_array_number_t TOP_LEVEL_usecases_ht_to_pose_params_dps(storage_t stgVar10, array_number_t theta_dps, card_t n_bones_dps, card_t theta_shp, card_t n_bones_shp) {
	card_t row1_shp = TOP_LEVEL_linalg_vectorSlice_shp(3, 0, theta_shp);
	card_t size418 = width_card_t(row1_shp);
	array_number_t stgVar11 = storage_alloc(size418);
	array_array_number_t macroDef404;array_number_t row1_dps = TOP_LEVEL_linalg_vectorSlice_dps(stgVar11, 3, 0, theta_dps, 3, 0, theta_shp);
	card_t row2_shp = 3;
	card_t size417 = width_card_t(row2_shp);
	array_number_t stgVar15 = storage_alloc(size417);
	array_array_number_t macroDef403;array_number_t macroDef363 = (array_number_t)stgVar15;
	macroDef363->length=3;
	macroDef363->arr=(number_t*)(STG_OFFSET(stgVar15, VECTOR_HEADER_BYTES));
	

	macroDef363->arr[0] = 1;;

	macroDef363->arr[1] = 1;;

	macroDef363->arr[2] = 1;;;
	array_number_t row2_dps = macroDef363;
	card_t row3_shp = TOP_LEVEL_linalg_vectorSlice_shp(3, 0, theta_shp);
	card_t size416 = width_card_t(row3_shp);
	array_number_t stgVar19 = storage_alloc(size416);
	array_array_number_t macroDef402;array_number_t row3_dps = TOP_LEVEL_linalg_vectorSlice_dps(stgVar19, 3, 3, theta_dps, 3, 0, theta_shp);
	card_t zeroRow_shp = 3;
	card_t size415 = width_card_t(zeroRow_shp);
	array_number_t stgVar23 = storage_alloc(size415);
	array_array_number_t macroDef401;array_number_t macroDef364 = (array_number_t)stgVar23;
	macroDef364->length=3;
	macroDef364->arr=(number_t*)(STG_OFFSET(stgVar23, VECTOR_HEADER_BYTES));
	

	macroDef364->arr[0] = 0;;

	macroDef364->arr[1] = 0;;

	macroDef364->arr[2] = 0;;;
	array_number_t zeroRow_dps = macroDef364;
	matrix_shape_t pose_params_shp = nested_shape_card_t(row1_shp, 5);
	card_t size414 = width_matrix_shape_t(pose_params_shp);
	array_number_t stgVar27 = storage_alloc(size414);
	array_array_number_t macroDef400;array_array_number_t macroDef365 = (array_array_number_t)stgVar27;
	macroDef365->length=5;
	macroDef365->arr=(array_number_t*)(STG_OFFSET(stgVar27, VECTOR_HEADER_BYTES));
	int stgVar27_offsetVar = 0;storage_t stgVar28 = STG_OFFSET(stgVar27, MATRIX_HEADER_BYTES(5) + stgVar27_offsetVar);

	macroDef365->arr[0] = row1_dps;;stgVar27_offsetVar += VECTOR_ALL_BYTES(macroDef365->arr[0]->length);storage_t stgVar29 = STG_OFFSET(stgVar27, MATRIX_HEADER_BYTES(5) + stgVar27_offsetVar);

	macroDef365->arr[1] = row2_dps;;stgVar27_offsetVar += VECTOR_ALL_BYTES(macroDef365->arr[1]->length);storage_t stgVar30 = STG_OFFSET(stgVar27, MATRIX_HEADER_BYTES(5) + stgVar27_offsetVar);

	macroDef365->arr[2] = row3_dps;;stgVar27_offsetVar += VECTOR_ALL_BYTES(macroDef365->arr[2]->length);storage_t stgVar31 = STG_OFFSET(stgVar27, MATRIX_HEADER_BYTES(5) + stgVar27_offsetVar);

	macroDef365->arr[3] = zeroRow_dps;;stgVar27_offsetVar += VECTOR_ALL_BYTES(macroDef365->arr[3]->length);storage_t stgVar32 = STG_OFFSET(stgVar27, MATRIX_HEADER_BYTES(5) + stgVar27_offsetVar);

	macroDef365->arr[4] = zeroRow_dps;;stgVar27_offsetVar += VECTOR_ALL_BYTES(macroDef365->arr[4]->length);;
	array_array_number_t pose_params_dps = macroDef365;
	card_t i1_shp = 0;
	index_t i1_dps = 5;
	matrix_shape_t finger1_shp = nested_shape_card_t(3, 4);
	card_t size413 = width_matrix_shape_t(finger1_shp);
	array_number_t stgVar34 = storage_alloc(size413);
	array_array_number_t macroDef399;array_array_number_t macroDef370 = (array_array_number_t)stgVar34;
	macroDef370->length=4;
	macroDef370->arr=(array_number_t*)(STG_OFFSET(stgVar34, VECTOR_HEADER_BYTES));
	int stgVar34_offsetVar = 0;storage_t stgVar35 = STG_OFFSET(stgVar34, MATRIX_HEADER_BYTES(4) + stgVar34_offsetVar);array_number_t macroDef366 = (array_number_t)stgVar35;
	macroDef366->length=3;
	macroDef366->arr=(number_t*)(STG_OFFSET(stgVar35, VECTOR_HEADER_BYTES));
	

	macroDef366->arr[0] = theta_dps->arr[i1_dps];;

	macroDef366->arr[1] = theta_dps->arr[(i1_dps) + (1)];;

	macroDef366->arr[2] = 0;;;

	macroDef370->arr[0] = macroDef366;;stgVar34_offsetVar += VECTOR_ALL_BYTES(macroDef370->arr[0]->length);storage_t stgVar41 = STG_OFFSET(stgVar34, MATRIX_HEADER_BYTES(4) + stgVar34_offsetVar);array_number_t macroDef367 = (array_number_t)stgVar41;
	macroDef367->length=3;
	macroDef367->arr=(number_t*)(STG_OFFSET(stgVar41, VECTOR_HEADER_BYTES));
	

	macroDef367->arr[0] = theta_dps->arr[(i1_dps) + (2)];;

	macroDef367->arr[1] = 0;;

	macroDef367->arr[2] = 0;;;

	macroDef370->arr[1] = macroDef367;;stgVar34_offsetVar += VECTOR_ALL_BYTES(macroDef370->arr[1]->length);storage_t stgVar46 = STG_OFFSET(stgVar34, MATRIX_HEADER_BYTES(4) + stgVar34_offsetVar);array_number_t macroDef368 = (array_number_t)stgVar46;
	macroDef368->length=3;
	macroDef368->arr=(number_t*)(STG_OFFSET(stgVar46, VECTOR_HEADER_BYTES));
	

	macroDef368->arr[0] = theta_dps->arr[(i1_dps) + (3)];;

	macroDef368->arr[1] = 0;;

	macroDef368->arr[2] = 0;;;

	macroDef370->arr[2] = macroDef368;;stgVar34_offsetVar += VECTOR_ALL_BYTES(macroDef370->arr[2]->length);storage_t stgVar51 = STG_OFFSET(stgVar34, MATRIX_HEADER_BYTES(4) + stgVar34_offsetVar);array_number_t macroDef369 = (array_number_t)stgVar51;
	macroDef369->length=3;
	macroDef369->arr=(number_t*)(STG_OFFSET(stgVar51, VECTOR_HEADER_BYTES));
	

	macroDef369->arr[0] = 0;;

	macroDef369->arr[1] = 0;;

	macroDef369->arr[2] = 0;;;

	macroDef370->arr[3] = macroDef369;;stgVar34_offsetVar += VECTOR_ALL_BYTES(macroDef370->arr[3]->length);;
	array_array_number_t finger1_dps = macroDef370;
	card_t i2_shp = 0;
	index_t i2_dps = (i1_dps) + (4);
	matrix_shape_t finger2_shp = nested_shape_card_t(3, 4);
	card_t size412 = width_matrix_shape_t(finger2_shp);
	array_number_t stgVar56 = storage_alloc(size412);
	array_array_number_t macroDef398;array_array_number_t macroDef375 = (array_array_number_t)stgVar56;
	macroDef375->length=4;
	macroDef375->arr=(array_number_t*)(STG_OFFSET(stgVar56, VECTOR_HEADER_BYTES));
	int stgVar56_offsetVar = 0;storage_t stgVar57 = STG_OFFSET(stgVar56, MATRIX_HEADER_BYTES(4) + stgVar56_offsetVar);array_number_t macroDef371 = (array_number_t)stgVar57;
	macroDef371->length=3;
	macroDef371->arr=(number_t*)(STG_OFFSET(stgVar57, VECTOR_HEADER_BYTES));
	

	macroDef371->arr[0] = theta_dps->arr[i2_dps];;

	macroDef371->arr[1] = theta_dps->arr[(i2_dps) + (1)];;

	macroDef371->arr[2] = 0;;;

	macroDef375->arr[0] = macroDef371;;stgVar56_offsetVar += VECTOR_ALL_BYTES(macroDef375->arr[0]->length);storage_t stgVar63 = STG_OFFSET(stgVar56, MATRIX_HEADER_BYTES(4) + stgVar56_offsetVar);array_number_t macroDef372 = (array_number_t)stgVar63;
	macroDef372->length=3;
	macroDef372->arr=(number_t*)(STG_OFFSET(stgVar63, VECTOR_HEADER_BYTES));
	

	macroDef372->arr[0] = theta_dps->arr[(i2_dps) + (2)];;

	macroDef372->arr[1] = 0;;

	macroDef372->arr[2] = 0;;;

	macroDef375->arr[1] = macroDef372;;stgVar56_offsetVar += VECTOR_ALL_BYTES(macroDef375->arr[1]->length);storage_t stgVar68 = STG_OFFSET(stgVar56, MATRIX_HEADER_BYTES(4) + stgVar56_offsetVar);array_number_t macroDef373 = (array_number_t)stgVar68;
	macroDef373->length=3;
	macroDef373->arr=(number_t*)(STG_OFFSET(stgVar68, VECTOR_HEADER_BYTES));
	

	macroDef373->arr[0] = theta_dps->arr[(i2_dps) + (3)];;

	macroDef373->arr[1] = 0;;

	macroDef373->arr[2] = 0;;;

	macroDef375->arr[2] = macroDef373;;stgVar56_offsetVar += VECTOR_ALL_BYTES(macroDef375->arr[2]->length);storage_t stgVar73 = STG_OFFSET(stgVar56, MATRIX_HEADER_BYTES(4) + stgVar56_offsetVar);array_number_t macroDef374 = (array_number_t)stgVar73;
	macroDef374->length=3;
	macroDef374->arr=(number_t*)(STG_OFFSET(stgVar73, VECTOR_HEADER_BYTES));
	

	macroDef374->arr[0] = 0;;

	macroDef374->arr[1] = 0;;

	macroDef374->arr[2] = 0;;;

	macroDef375->arr[3] = macroDef374;;stgVar56_offsetVar += VECTOR_ALL_BYTES(macroDef375->arr[3]->length);;
	array_array_number_t finger2_dps = macroDef375;
	card_t i3_shp = 0;
	index_t i3_dps = (i2_dps) + (4);
	matrix_shape_t finger3_shp = nested_shape_card_t(3, 4);
	card_t size411 = width_matrix_shape_t(finger3_shp);
	array_number_t stgVar78 = storage_alloc(size411);
	array_array_number_t macroDef397;array_array_number_t macroDef380 = (array_array_number_t)stgVar78;
	macroDef380->length=4;
	macroDef380->arr=(array_number_t*)(STG_OFFSET(stgVar78, VECTOR_HEADER_BYTES));
	int stgVar78_offsetVar = 0;storage_t stgVar79 = STG_OFFSET(stgVar78, MATRIX_HEADER_BYTES(4) + stgVar78_offsetVar);array_number_t macroDef376 = (array_number_t)stgVar79;
	macroDef376->length=3;
	macroDef376->arr=(number_t*)(STG_OFFSET(stgVar79, VECTOR_HEADER_BYTES));
	

	macroDef376->arr[0] = theta_dps->arr[i3_dps];;

	macroDef376->arr[1] = theta_dps->arr[(i3_dps) + (1)];;

	macroDef376->arr[2] = 0;;;

	macroDef380->arr[0] = macroDef376;;stgVar78_offsetVar += VECTOR_ALL_BYTES(macroDef380->arr[0]->length);storage_t stgVar85 = STG_OFFSET(stgVar78, MATRIX_HEADER_BYTES(4) + stgVar78_offsetVar);array_number_t macroDef377 = (array_number_t)stgVar85;
	macroDef377->length=3;
	macroDef377->arr=(number_t*)(STG_OFFSET(stgVar85, VECTOR_HEADER_BYTES));
	

	macroDef377->arr[0] = theta_dps->arr[(i3_dps) + (2)];;

	macroDef377->arr[1] = 0;;

	macroDef377->arr[2] = 0;;;

	macroDef380->arr[1] = macroDef377;;stgVar78_offsetVar += VECTOR_ALL_BYTES(macroDef380->arr[1]->length);storage_t stgVar90 = STG_OFFSET(stgVar78, MATRIX_HEADER_BYTES(4) + stgVar78_offsetVar);array_number_t macroDef378 = (array_number_t)stgVar90;
	macroDef378->length=3;
	macroDef378->arr=(number_t*)(STG_OFFSET(stgVar90, VECTOR_HEADER_BYTES));
	

	macroDef378->arr[0] = theta_dps->arr[(i3_dps) + (3)];;

	macroDef378->arr[1] = 0;;

	macroDef378->arr[2] = 0;;;

	macroDef380->arr[2] = macroDef378;;stgVar78_offsetVar += VECTOR_ALL_BYTES(macroDef380->arr[2]->length);storage_t stgVar95 = STG_OFFSET(stgVar78, MATRIX_HEADER_BYTES(4) + stgVar78_offsetVar);array_number_t macroDef379 = (array_number_t)stgVar95;
	macroDef379->length=3;
	macroDef379->arr=(number_t*)(STG_OFFSET(stgVar95, VECTOR_HEADER_BYTES));
	

	macroDef379->arr[0] = 0;;

	macroDef379->arr[1] = 0;;

	macroDef379->arr[2] = 0;;;

	macroDef380->arr[3] = macroDef379;;stgVar78_offsetVar += VECTOR_ALL_BYTES(macroDef380->arr[3]->length);;
	array_array_number_t finger3_dps = macroDef380;
	card_t i4_shp = 0;
	index_t i4_dps = (i3_dps) + (4);
	matrix_shape_t finger4_shp = nested_shape_card_t(3, 4);
	card_t size410 = width_matrix_shape_t(finger4_shp);
	array_number_t stgVar100 = storage_alloc(size410);
	array_array_number_t macroDef396;array_array_number_t macroDef385 = (array_array_number_t)stgVar100;
	macroDef385->length=4;
	macroDef385->arr=(array_number_t*)(STG_OFFSET(stgVar100, VECTOR_HEADER_BYTES));
	int stgVar100_offsetVar = 0;storage_t stgVar101 = STG_OFFSET(stgVar100, MATRIX_HEADER_BYTES(4) + stgVar100_offsetVar);array_number_t macroDef381 = (array_number_t)stgVar101;
	macroDef381->length=3;
	macroDef381->arr=(number_t*)(STG_OFFSET(stgVar101, VECTOR_HEADER_BYTES));
	

	macroDef381->arr[0] = theta_dps->arr[i4_dps];;

	macroDef381->arr[1] = theta_dps->arr[(i4_dps) + (1)];;

	macroDef381->arr[2] = 0;;;

	macroDef385->arr[0] = macroDef381;;stgVar100_offsetVar += VECTOR_ALL_BYTES(macroDef385->arr[0]->length);storage_t stgVar107 = STG_OFFSET(stgVar100, MATRIX_HEADER_BYTES(4) + stgVar100_offsetVar);array_number_t macroDef382 = (array_number_t)stgVar107;
	macroDef382->length=3;
	macroDef382->arr=(number_t*)(STG_OFFSET(stgVar107, VECTOR_HEADER_BYTES));
	

	macroDef382->arr[0] = theta_dps->arr[(i4_dps) + (2)];;

	macroDef382->arr[1] = 0;;

	macroDef382->arr[2] = 0;;;

	macroDef385->arr[1] = macroDef382;;stgVar100_offsetVar += VECTOR_ALL_BYTES(macroDef385->arr[1]->length);storage_t stgVar112 = STG_OFFSET(stgVar100, MATRIX_HEADER_BYTES(4) + stgVar100_offsetVar);array_number_t macroDef383 = (array_number_t)stgVar112;
	macroDef383->length=3;
	macroDef383->arr=(number_t*)(STG_OFFSET(stgVar112, VECTOR_HEADER_BYTES));
	

	macroDef383->arr[0] = theta_dps->arr[(i4_dps) + (3)];;

	macroDef383->arr[1] = 0;;

	macroDef383->arr[2] = 0;;;

	macroDef385->arr[2] = macroDef383;;stgVar100_offsetVar += VECTOR_ALL_BYTES(macroDef385->arr[2]->length);storage_t stgVar117 = STG_OFFSET(stgVar100, MATRIX_HEADER_BYTES(4) + stgVar100_offsetVar);array_number_t macroDef384 = (array_number_t)stgVar117;
	macroDef384->length=3;
	macroDef384->arr=(number_t*)(STG_OFFSET(stgVar117, VECTOR_HEADER_BYTES));
	

	macroDef384->arr[0] = 0;;

	macroDef384->arr[1] = 0;;

	macroDef384->arr[2] = 0;;;

	macroDef385->arr[3] = macroDef384;;stgVar100_offsetVar += VECTOR_ALL_BYTES(macroDef385->arr[3]->length);;
	array_array_number_t finger4_dps = macroDef385;
	card_t i5_shp = 0;
	index_t i5_dps = (i4_dps) + (4);
	matrix_shape_t finger5_shp = nested_shape_card_t(3, 4);
	card_t size409 = width_matrix_shape_t(finger5_shp);
	array_number_t stgVar122 = storage_alloc(size409);
	array_array_number_t macroDef395;array_array_number_t macroDef390 = (array_array_number_t)stgVar122;
	macroDef390->length=4;
	macroDef390->arr=(array_number_t*)(STG_OFFSET(stgVar122, VECTOR_HEADER_BYTES));
	int stgVar122_offsetVar = 0;storage_t stgVar123 = STG_OFFSET(stgVar122, MATRIX_HEADER_BYTES(4) + stgVar122_offsetVar);array_number_t macroDef386 = (array_number_t)stgVar123;
	macroDef386->length=3;
	macroDef386->arr=(number_t*)(STG_OFFSET(stgVar123, VECTOR_HEADER_BYTES));
	

	macroDef386->arr[0] = theta_dps->arr[i5_dps];;

	macroDef386->arr[1] = theta_dps->arr[(i5_dps) + (1)];;

	macroDef386->arr[2] = 0;;;

	macroDef390->arr[0] = macroDef386;;stgVar122_offsetVar += VECTOR_ALL_BYTES(macroDef390->arr[0]->length);storage_t stgVar129 = STG_OFFSET(stgVar122, MATRIX_HEADER_BYTES(4) + stgVar122_offsetVar);array_number_t macroDef387 = (array_number_t)stgVar129;
	macroDef387->length=3;
	macroDef387->arr=(number_t*)(STG_OFFSET(stgVar129, VECTOR_HEADER_BYTES));
	

	macroDef387->arr[0] = theta_dps->arr[(i5_dps) + (2)];;

	macroDef387->arr[1] = 0;;

	macroDef387->arr[2] = 0;;;

	macroDef390->arr[1] = macroDef387;;stgVar122_offsetVar += VECTOR_ALL_BYTES(macroDef390->arr[1]->length);storage_t stgVar134 = STG_OFFSET(stgVar122, MATRIX_HEADER_BYTES(4) + stgVar122_offsetVar);array_number_t macroDef388 = (array_number_t)stgVar134;
	macroDef388->length=3;
	macroDef388->arr=(number_t*)(STG_OFFSET(stgVar134, VECTOR_HEADER_BYTES));
	

	macroDef388->arr[0] = theta_dps->arr[(i5_dps) + (3)];;

	macroDef388->arr[1] = 0;;

	macroDef388->arr[2] = 0;;;

	macroDef390->arr[2] = macroDef388;;stgVar122_offsetVar += VECTOR_ALL_BYTES(macroDef390->arr[2]->length);storage_t stgVar139 = STG_OFFSET(stgVar122, MATRIX_HEADER_BYTES(4) + stgVar122_offsetVar);array_number_t macroDef389 = (array_number_t)stgVar139;
	macroDef389->length=3;
	macroDef389->arr=(number_t*)(STG_OFFSET(stgVar139, VECTOR_HEADER_BYTES));
	

	macroDef389->arr[0] = 0;;

	macroDef389->arr[1] = 0;;

	macroDef389->arr[2] = 0;;;

	macroDef390->arr[3] = macroDef389;;stgVar122_offsetVar += VECTOR_ALL_BYTES(macroDef390->arr[3]->length);;
	array_array_number_t finger5_dps = macroDef390;
	card_t size408 = width_matrix_shape_t(TOP_LEVEL_linalg_matrixConcat_shp(finger1_shp, TOP_LEVEL_linalg_matrixConcat_shp(finger2_shp, TOP_LEVEL_linalg_matrixConcat_shp(finger3_shp, TOP_LEVEL_linalg_matrixConcat_shp(finger4_shp, finger5_shp)))));
	array_number_t stgVar144 = storage_alloc(size408);
	array_array_number_t macroDef394;card_t size407 = width_matrix_shape_t(TOP_LEVEL_linalg_matrixConcat_shp(finger2_shp, TOP_LEVEL_linalg_matrixConcat_shp(finger3_shp, TOP_LEVEL_linalg_matrixConcat_shp(finger4_shp, finger5_shp))));
	array_number_t stgVar146 = storage_alloc(size407);
	array_array_number_t macroDef393;card_t size406 = width_matrix_shape_t(TOP_LEVEL_linalg_matrixConcat_shp(finger3_shp, TOP_LEVEL_linalg_matrixConcat_shp(finger4_shp, finger5_shp)));
	array_number_t stgVar148 = storage_alloc(size406);
	array_array_number_t macroDef392;card_t size405 = width_matrix_shape_t(TOP_LEVEL_linalg_matrixConcat_shp(finger4_shp, finger5_shp));
	array_number_t stgVar150 = storage_alloc(size405);
	array_array_number_t macroDef391;
	macroDef391 = TOP_LEVEL_linalg_matrixConcat_dps(stgVar148, finger3_dps, TOP_LEVEL_linalg_matrixConcat_dps(stgVar150, finger4_dps, finger5_dps, finger4_shp, finger5_shp), finger3_shp, TOP_LEVEL_linalg_matrixConcat_shp(finger4_shp, finger5_shp));;
	storage_free(stgVar150, size405);
	macroDef392 = TOP_LEVEL_linalg_matrixConcat_dps(stgVar146, finger2_dps, macroDef391, finger2_shp, TOP_LEVEL_linalg_matrixConcat_shp(finger3_shp, TOP_LEVEL_linalg_matrixConcat_shp(finger4_shp, finger5_shp)));;
	storage_free(stgVar148, size406);
	macroDef393 = TOP_LEVEL_linalg_matrixConcat_dps(stgVar144, finger1_dps, macroDef392, finger1_shp, TOP_LEVEL_linalg_matrixConcat_shp(finger2_shp, TOP_LEVEL_linalg_matrixConcat_shp(finger3_shp, TOP_LEVEL_linalg_matrixConcat_shp(finger4_shp, finger5_shp))));;
	storage_free(stgVar146, size407);
	macroDef394 = TOP_LEVEL_linalg_matrixConcat_dps(stgVar10, pose_params_dps, macroDef393, pose_params_shp, TOP_LEVEL_linalg_matrixConcat_shp(finger1_shp, TOP_LEVEL_linalg_matrixConcat_shp(finger2_shp, TOP_LEVEL_linalg_matrixConcat_shp(finger3_shp, TOP_LEVEL_linalg_matrixConcat_shp(finger4_shp, finger5_shp)))));;
	storage_free(stgVar144, size408);
	macroDef395 = macroDef394;;
	storage_free(stgVar122, size409);
	macroDef396 = macroDef395;;
	storage_free(stgVar100, size410);
	macroDef397 = macroDef396;;
	storage_free(stgVar78, size411);
	macroDef398 = macroDef397;;
	storage_free(stgVar56, size412);
	macroDef399 = macroDef398;;
	storage_free(stgVar34, size413);
	macroDef400 = macroDef399;;
	storage_free(stgVar27, size414);
	macroDef401 = macroDef400;;
	storage_free(stgVar23, size415);
	macroDef402 = macroDef401;;
	storage_free(stgVar19, size416);
	macroDef403 = macroDef402;;
	storage_free(stgVar15, size417);
	macroDef404 = macroDef403;;
	storage_free(stgVar11, size418);
	return macroDef404;
}

matrix_shape_t TOP_LEVEL_usecases_ht_euler_angles_to_rotation_matrix_shp(card_t xzy_shp) {
	
	return TOP_LEVEL_linalg_matrixMult_shp(nested_shape_card_t(3, 3), TOP_LEVEL_linalg_matrixMult_shp(nested_shape_card_t(3, 3), nested_shape_card_t(3, 3)));
}


array_array_number_t TOP_LEVEL_usecases_ht_euler_angles_to_rotation_matrix_dps(storage_t stgVar419, array_number_t xzy_dps, card_t xzy_shp) {
	card_t tx_shp = 0;
	number_t tx_dps = xzy_dps->arr[0];
	card_t ty_shp = 0;
	number_t ty_dps = xzy_dps->arr[2];
	card_t tz_shp = 0;
	number_t tz_dps = xzy_dps->arr[1];
	matrix_shape_t Rx_shp = nested_shape_card_t(3, 3);
	card_t size518 = width_matrix_shape_t(Rx_shp);
	array_number_t stgVar426 = storage_alloc(size518);
	array_array_number_t macroDef514;array_array_number_t macroDef502 = (array_array_number_t)stgVar426;
	macroDef502->length=3;
	macroDef502->arr=(array_number_t*)(STG_OFFSET(stgVar426, VECTOR_HEADER_BYTES));
	int stgVar426_offsetVar = 0;storage_t stgVar427 = STG_OFFSET(stgVar426, MATRIX_HEADER_BYTES(3) + stgVar426_offsetVar);array_number_t macroDef499 = (array_number_t)stgVar427;
	macroDef499->length=3;
	macroDef499->arr=(number_t*)(STG_OFFSET(stgVar427, VECTOR_HEADER_BYTES));
	

	macroDef499->arr[0] = 1;;

	macroDef499->arr[1] = 0;;

	macroDef499->arr[2] = 0;;;

	macroDef502->arr[0] = macroDef499;;stgVar426_offsetVar += VECTOR_ALL_BYTES(macroDef502->arr[0]->length);storage_t stgVar431 = STG_OFFSET(stgVar426, MATRIX_HEADER_BYTES(3) + stgVar426_offsetVar);array_number_t macroDef500 = (array_number_t)stgVar431;
	macroDef500->length=3;
	macroDef500->arr=(number_t*)(STG_OFFSET(stgVar431, VECTOR_HEADER_BYTES));
	

	macroDef500->arr[0] = 0;;

	macroDef500->arr[1] = cos(tx_dps);;

	macroDef500->arr[2] = -(sin(tx_dps));;;

	macroDef502->arr[1] = macroDef500;;stgVar426_offsetVar += VECTOR_ALL_BYTES(macroDef502->arr[1]->length);storage_t stgVar435 = STG_OFFSET(stgVar426, MATRIX_HEADER_BYTES(3) + stgVar426_offsetVar);array_number_t macroDef501 = (array_number_t)stgVar435;
	macroDef501->length=3;
	macroDef501->arr=(number_t*)(STG_OFFSET(stgVar435, VECTOR_HEADER_BYTES));
	

	macroDef501->arr[0] = 0;;

	macroDef501->arr[1] = sin(tx_dps);;

	macroDef501->arr[2] = cos(tx_dps);;;

	macroDef502->arr[2] = macroDef501;;stgVar426_offsetVar += VECTOR_ALL_BYTES(macroDef502->arr[2]->length);;
	array_array_number_t Rx_dps = macroDef502;
	matrix_shape_t Ry_shp = nested_shape_card_t(3, 3);
	card_t size517 = width_matrix_shape_t(Ry_shp);
	array_number_t stgVar439 = storage_alloc(size517);
	array_array_number_t macroDef513;array_array_number_t macroDef506 = (array_array_number_t)stgVar439;
	macroDef506->length=3;
	macroDef506->arr=(array_number_t*)(STG_OFFSET(stgVar439, VECTOR_HEADER_BYTES));
	int stgVar439_offsetVar = 0;storage_t stgVar440 = STG_OFFSET(stgVar439, MATRIX_HEADER_BYTES(3) + stgVar439_offsetVar);array_number_t macroDef503 = (array_number_t)stgVar440;
	macroDef503->length=3;
	macroDef503->arr=(number_t*)(STG_OFFSET(stgVar440, VECTOR_HEADER_BYTES));
	

	macroDef503->arr[0] = cos(ty_dps);;

	macroDef503->arr[1] = 0;;

	macroDef503->arr[2] = sin(ty_dps);;;

	macroDef506->arr[0] = macroDef503;;stgVar439_offsetVar += VECTOR_ALL_BYTES(macroDef506->arr[0]->length);storage_t stgVar444 = STG_OFFSET(stgVar439, MATRIX_HEADER_BYTES(3) + stgVar439_offsetVar);array_number_t macroDef504 = (array_number_t)stgVar444;
	macroDef504->length=3;
	macroDef504->arr=(number_t*)(STG_OFFSET(stgVar444, VECTOR_HEADER_BYTES));
	

	macroDef504->arr[0] = 0;;

	macroDef504->arr[1] = 1;;

	macroDef504->arr[2] = 0;;;

	macroDef506->arr[1] = macroDef504;;stgVar439_offsetVar += VECTOR_ALL_BYTES(macroDef506->arr[1]->length);storage_t stgVar448 = STG_OFFSET(stgVar439, MATRIX_HEADER_BYTES(3) + stgVar439_offsetVar);array_number_t macroDef505 = (array_number_t)stgVar448;
	macroDef505->length=3;
	macroDef505->arr=(number_t*)(STG_OFFSET(stgVar448, VECTOR_HEADER_BYTES));
	

	macroDef505->arr[0] = -(sin(ty_dps));;

	macroDef505->arr[1] = 0;;

	macroDef505->arr[2] = cos(ty_dps);;;

	macroDef506->arr[2] = macroDef505;;stgVar439_offsetVar += VECTOR_ALL_BYTES(macroDef506->arr[2]->length);;
	array_array_number_t Ry_dps = macroDef506;
	matrix_shape_t Rz_shp = nested_shape_card_t(3, 3);
	card_t size516 = width_matrix_shape_t(Rz_shp);
	array_number_t stgVar452 = storage_alloc(size516);
	array_array_number_t macroDef512;array_array_number_t macroDef510 = (array_array_number_t)stgVar452;
	macroDef510->length=3;
	macroDef510->arr=(array_number_t*)(STG_OFFSET(stgVar452, VECTOR_HEADER_BYTES));
	int stgVar452_offsetVar = 0;storage_t stgVar453 = STG_OFFSET(stgVar452, MATRIX_HEADER_BYTES(3) + stgVar452_offsetVar);array_number_t macroDef507 = (array_number_t)stgVar453;
	macroDef507->length=3;
	macroDef507->arr=(number_t*)(STG_OFFSET(stgVar453, VECTOR_HEADER_BYTES));
	

	macroDef507->arr[0] = cos(tz_dps);;

	macroDef507->arr[1] = -(sin(tz_dps));;

	macroDef507->arr[2] = 0;;;

	macroDef510->arr[0] = macroDef507;;stgVar452_offsetVar += VECTOR_ALL_BYTES(macroDef510->arr[0]->length);storage_t stgVar457 = STG_OFFSET(stgVar452, MATRIX_HEADER_BYTES(3) + stgVar452_offsetVar);array_number_t macroDef508 = (array_number_t)stgVar457;
	macroDef508->length=3;
	macroDef508->arr=(number_t*)(STG_OFFSET(stgVar457, VECTOR_HEADER_BYTES));
	

	macroDef508->arr[0] = sin(tz_dps);;

	macroDef508->arr[1] = cos(tz_dps);;

	macroDef508->arr[2] = 0;;;

	macroDef510->arr[1] = macroDef508;;stgVar452_offsetVar += VECTOR_ALL_BYTES(macroDef510->arr[1]->length);storage_t stgVar461 = STG_OFFSET(stgVar452, MATRIX_HEADER_BYTES(3) + stgVar452_offsetVar);array_number_t macroDef509 = (array_number_t)stgVar461;
	macroDef509->length=3;
	macroDef509->arr=(number_t*)(STG_OFFSET(stgVar461, VECTOR_HEADER_BYTES));
	

	macroDef509->arr[0] = 0;;

	macroDef509->arr[1] = 0;;

	macroDef509->arr[2] = 1;;;

	macroDef510->arr[2] = macroDef509;;stgVar452_offsetVar += VECTOR_ALL_BYTES(macroDef510->arr[2]->length);;
	array_array_number_t Rz_dps = macroDef510;
	card_t size515 = width_matrix_shape_t(TOP_LEVEL_linalg_matrixMult_shp(Ry_shp, Rx_shp));
	array_number_t stgVar466 = storage_alloc(size515);
	array_array_number_t macroDef511;
	macroDef511 = TOP_LEVEL_linalg_matrixMult_dps(stgVar419, Rz_dps, TOP_LEVEL_linalg_matrixMult_dps(stgVar466, Ry_dps, Rx_dps, Ry_shp, Rx_shp), Rz_shp, TOP_LEVEL_linalg_matrixMult_shp(Ry_shp, Rx_shp));;
	storage_free(stgVar466, size515);
	macroDef512 = macroDef511;;
	storage_free(stgVar452, size516);
	macroDef513 = macroDef512;;
	storage_free(stgVar439, size517);
	macroDef514 = macroDef513;;
	storage_free(stgVar426, size518);
	return macroDef514;
}

matrix_shape_t TOP_LEVEL_usecases_ht_make_relative_shp(card_t pose_params_shp, matrix_shape_t base_relative_shp) {
	
	return TOP_LEVEL_linalg_matrixMult_shp(base_relative_shp, TOP_LEVEL_linalg_matrixConcat_shp(TOP_LEVEL_linalg_matrixConcatCol_shp(TOP_LEVEL_usecases_ht_euler_angles_to_rotation_matrix_shp(pose_params_shp), nested_shape_card_t(1, 3)), nested_shape_card_t(4, 1)));
}


array_array_number_t TOP_LEVEL_usecases_ht_make_relative_dps(storage_t stgVar519, array_number_t pose_params_dps, array_array_number_t base_relative_dps, card_t pose_params_shp, matrix_shape_t base_relative_shp) {
	matrix_shape_t R_shp = TOP_LEVEL_usecases_ht_euler_angles_to_rotation_matrix_shp(pose_params_shp);
	card_t size569 = width_matrix_shape_t(R_shp);
	array_number_t stgVar520 = storage_alloc(size569);
	array_array_number_t macroDef564;array_array_number_t R_dps = TOP_LEVEL_usecases_ht_euler_angles_to_rotation_matrix_dps(stgVar520, pose_params_dps, pose_params_shp);
	matrix_shape_t r1_shp = nested_shape_card_t(1, 3);
	card_t size568 = width_matrix_shape_t(r1_shp);
	array_number_t stgVar522 = storage_alloc(size568);
	array_array_number_t macroDef563;array_array_number_t macroDef557 = (array_array_number_t)stgVar522;
	macroDef557->length=3;
	macroDef557->arr=(array_number_t*)(STG_OFFSET(stgVar522, VECTOR_HEADER_BYTES));
	int stgVar522_offsetVar = 0;storage_t stgVar523 = STG_OFFSET(stgVar522, MATRIX_HEADER_BYTES(3) + stgVar522_offsetVar);array_number_t macroDef554 = (array_number_t)stgVar523;
	macroDef554->length=1;
	macroDef554->arr=(number_t*)(STG_OFFSET(stgVar523, VECTOR_HEADER_BYTES));
	

	macroDef554->arr[0] = 0;;;

	macroDef557->arr[0] = macroDef554;;stgVar522_offsetVar += VECTOR_ALL_BYTES(macroDef557->arr[0]->length);storage_t stgVar525 = STG_OFFSET(stgVar522, MATRIX_HEADER_BYTES(3) + stgVar522_offsetVar);array_number_t macroDef555 = (array_number_t)stgVar525;
	macroDef555->length=1;
	macroDef555->arr=(number_t*)(STG_OFFSET(stgVar525, VECTOR_HEADER_BYTES));
	

	macroDef555->arr[0] = 0;;;

	macroDef557->arr[1] = macroDef555;;stgVar522_offsetVar += VECTOR_ALL_BYTES(macroDef557->arr[1]->length);storage_t stgVar527 = STG_OFFSET(stgVar522, MATRIX_HEADER_BYTES(3) + stgVar522_offsetVar);array_number_t macroDef556 = (array_number_t)stgVar527;
	macroDef556->length=1;
	macroDef556->arr=(number_t*)(STG_OFFSET(stgVar527, VECTOR_HEADER_BYTES));
	

	macroDef556->arr[0] = 0;;;

	macroDef557->arr[2] = macroDef556;;stgVar522_offsetVar += VECTOR_ALL_BYTES(macroDef557->arr[2]->length);;
	array_array_number_t r1_dps = macroDef557;
	matrix_shape_t r2_shp = nested_shape_card_t(4, 1);
	card_t size567 = width_matrix_shape_t(r2_shp);
	array_number_t stgVar529 = storage_alloc(size567);
	array_array_number_t macroDef562;array_array_number_t macroDef559 = (array_array_number_t)stgVar529;
	macroDef559->length=1;
	macroDef559->arr=(array_number_t*)(STG_OFFSET(stgVar529, VECTOR_HEADER_BYTES));
	int stgVar529_offsetVar = 0;storage_t stgVar530 = STG_OFFSET(stgVar529, MATRIX_HEADER_BYTES(1) + stgVar529_offsetVar);array_number_t macroDef558 = (array_number_t)stgVar530;
	macroDef558->length=4;
	macroDef558->arr=(number_t*)(STG_OFFSET(stgVar530, VECTOR_HEADER_BYTES));
	

	macroDef558->arr[0] = 0;;

	macroDef558->arr[1] = 0;;

	macroDef558->arr[2] = 0;;

	macroDef558->arr[3] = 1;;;

	macroDef559->arr[0] = macroDef558;;stgVar529_offsetVar += VECTOR_ALL_BYTES(macroDef559->arr[0]->length);;
	array_array_number_t r2_dps = macroDef559;
	matrix_shape_t T_shp = TOP_LEVEL_linalg_matrixConcat_shp(TOP_LEVEL_linalg_matrixConcatCol_shp(R_shp, r1_shp), r2_shp);
	card_t size566 = width_matrix_shape_t(T_shp);
	array_number_t stgVar535 = storage_alloc(size566);
	array_array_number_t macroDef561;card_t size565 = width_matrix_shape_t(TOP_LEVEL_linalg_matrixConcatCol_shp(R_shp, r1_shp));
	array_number_t stgVar536 = storage_alloc(size565);
	array_array_number_t macroDef560;
	macroDef560 = TOP_LEVEL_linalg_matrixConcat_dps(stgVar535, TOP_LEVEL_linalg_matrixConcatCol_dps(stgVar536, R_dps, r1_dps, R_shp, r1_shp), r2_dps, TOP_LEVEL_linalg_matrixConcatCol_shp(R_shp, r1_shp), r2_shp);;
	storage_free(stgVar536, size565);
	array_array_number_t T_dps = macroDef560;
	macroDef561 = TOP_LEVEL_linalg_matrixMult_dps(stgVar519, base_relative_dps, T_dps, base_relative_shp, T_shp);;
	storage_free(stgVar535, size566);
	macroDef562 = macroDef561;;
	storage_free(stgVar529, size567);
	macroDef563 = macroDef562;;
	storage_free(stgVar522, size568);
	macroDef564 = macroDef563;;
	storage_free(stgVar520, size569);
	return macroDef564;
}
typedef struct env_t_586 {
	matrix_shape_t pose_params_shp;
	matrix3d_shape_t base_relatives_shp;
} env_t_586;
env_t_586 make_env_t_586(matrix_shape_t pose_params_shp,matrix3d_shape_t base_relatives_shp) {
	env_t_586 env;
	env.pose_params_shp = pose_params_shp;
	env.base_relatives_shp = base_relatives_shp;
	return env;
}

value_t lambda586(env_t_586* env583, card_t i_bone_shp) {
	matrix_shape_t pose_params_shp582 = env583->pose_params_shp;
	matrix3d_shape_t base_relatives_shp581 = env583->base_relatives_shp;
	value_t res;
	res.matrix_shape_t_value = TOP_LEVEL_usecases_ht_make_relative_shp(pose_params_shp582.elem, base_relatives_shp581.elem);
	return res;
}
matrix3d_shape_t TOP_LEVEL_usecases_ht_get_posed_relatives_shp(card_t n_bones_shp, matrix_shape_t pose_params_shp, matrix3d_shape_t base_relatives_shp) {
	env_t_586 env_t_586_value = make_env_t_586(pose_params_shp,base_relatives_shp); closure_t closure585 = make_closure(lambda586, &env_t_586_value);
	return TOP_LEVEL_linalg_vectorMapToMatrix3D_shp(closure585, TOP_LEVEL_linalg_vectorRange_shp(0, (n_bones_shp) - (1)));
}

typedef struct env_t_603 {
	matrix_shape_t pose_params_shp;
	array_array_number_t pose_params_dps;
	index_t offset_dps;
	matrix3d_shape_t base_relatives_shp;
	array_array_array_number_t base_relatives_dps;
} env_t_603;
env_t_603 make_env_t_603(matrix_shape_t pose_params_shp,array_array_number_t pose_params_dps,index_t offset_dps,matrix3d_shape_t base_relatives_shp,array_array_array_number_t base_relatives_dps) {
	env_t_603 env;
	env.pose_params_shp = pose_params_shp;
	env.pose_params_dps = pose_params_dps;
	env.offset_dps = offset_dps;
	env.base_relatives_shp = base_relatives_shp;
	env.base_relatives_dps = base_relatives_dps;
	return env;
}

value_t lambda603(env_t_603* env594, storage_t stgVar574, number_t i_bone_dps, card_t i_bone_shp) {
	matrix_shape_t pose_params_shp593 = env594->pose_params_shp;
	array_array_number_t pose_params_dps592 = env594->pose_params_dps;
	index_t offset_dps591 = env594->offset_dps;
	matrix3d_shape_t base_relatives_shp590 = env594->base_relatives_shp;
	array_array_array_number_t base_relatives_dps589 = env594->base_relatives_dps;
	card_t size605 = width_matrix_shape_t(base_relatives_shp590.elem);
	array_number_t stgVar576 = storage_alloc(size605);
	array_array_number_t macroDef588;card_t size604 = width_card_t(pose_params_shp593.elem);
	array_number_t stgVar575 = storage_alloc(size604);
	array_array_number_t macroDef587;
	macroDef587 = TOP_LEVEL_usecases_ht_make_relative_dps(stgVar574, pose_params_dps592->arr[((int)(i_bone_dps)) + (offset_dps591)], base_relatives_dps589->arr[(int)(i_bone_dps)], pose_params_shp593.elem, base_relatives_shp590.elem);;
	storage_free(stgVar575, size604);
	macroDef588 = macroDef587;;
	storage_free(stgVar576, size605);
	value_t res;
	res.array_array_number_t_value = macroDef588;
	return res;
}
typedef struct env_t_606 {
	matrix_shape_t pose_params_shp;
	matrix3d_shape_t base_relatives_shp;
} env_t_606;
env_t_606 make_env_t_606(matrix_shape_t pose_params_shp,matrix3d_shape_t base_relatives_shp) {
	env_t_606 env;
	env.pose_params_shp = pose_params_shp;
	env.base_relatives_shp = base_relatives_shp;
	return env;
}

value_t lambda606(env_t_606* env599, card_t i_bone_shp) {
	matrix_shape_t pose_params_shp598 = env599->pose_params_shp;
	matrix3d_shape_t base_relatives_shp597 = env599->base_relatives_shp;
	value_t res;
	res.matrix_shape_t_value = TOP_LEVEL_usecases_ht_make_relative_shp(pose_params_shp598.elem, base_relatives_shp597.elem);
	return res;
}
array_array_array_number_t TOP_LEVEL_usecases_ht_get_posed_relatives_dps(storage_t stgVar570, card_t n_bones_dps, array_array_number_t pose_params_dps, array_array_array_number_t base_relatives_dps, card_t n_bones_shp, matrix_shape_t pose_params_shp, matrix3d_shape_t base_relatives_shp) {
	card_t offset_shp = 0;
	index_t offset_dps = 3;
	card_t size607 = width_card_t(TOP_LEVEL_linalg_vectorRange_shp(0, (n_bones_shp) - (1)));
	array_number_t stgVar573 = storage_alloc(size607);
	array_array_array_number_t macroDef602;env_t_603 env_t_603_value = make_env_t_603(pose_params_shp,pose_params_dps,offset_dps,base_relatives_shp,base_relatives_dps); closure_t closure596 = make_closure(lambda603, &env_t_603_value);
	env_t_606 env_t_606_value = make_env_t_606(pose_params_shp,base_relatives_shp); closure_t closure601 = make_closure(lambda606, &env_t_606_value);
	macroDef602 = TOP_LEVEL_linalg_vectorMapToMatrix3D_dps(stgVar570, closure596, TOP_LEVEL_linalg_vectorRange_dps(stgVar573, 0, (n_bones_dps) - (1), 0, (n_bones_shp) - (1)), closure601, TOP_LEVEL_linalg_vectorRange_shp(0, (n_bones_shp) - (1)));;
	storage_free(stgVar573, size607);
	return macroDef602;
}

matrix_shape_t TOP_LEVEL_usecases_ht_angle_axis_to_rotation_matrix_shp(card_t angle_axis_shp) {
	
	return nested_shape_card_t(3, 3);
}


array_array_number_t TOP_LEVEL_usecases_ht_angle_axis_to_rotation_matrix_dps(storage_t stgVar608, array_number_t angle_axis_dps, card_t angle_axis_shp) {
	card_t n_shp = 0;
	number_t n_dps = sqrt(TOP_LEVEL_linalg_sqnorm_dps(empty_storage, angle_axis_dps, angle_axis_shp));
	array_array_number_t ite651 ;
	if((n_dps) < (0.0001)) {
		array_array_number_t macroDef646 = (array_array_number_t)stgVar608;
	macroDef646->length=3;
	macroDef646->arr=(array_number_t*)(STG_OFFSET(stgVar608, VECTOR_HEADER_BYTES));
	int stgVar608_offsetVar = 0;storage_t stgVar611 = STG_OFFSET(stgVar608, MATRIX_HEADER_BYTES(3) + stgVar608_offsetVar);array_number_t macroDef643 = (array_number_t)stgVar611;
	macroDef643->length=3;
	macroDef643->arr=(number_t*)(STG_OFFSET(stgVar611, VECTOR_HEADER_BYTES));
	

	macroDef643->arr[0] = 1;;

	macroDef643->arr[1] = 0;;

	macroDef643->arr[2] = 0;;;

	macroDef646->arr[0] = macroDef643;;stgVar608_offsetVar += VECTOR_ALL_BYTES(macroDef646->arr[0]->length);storage_t stgVar615 = STG_OFFSET(stgVar608, MATRIX_HEADER_BYTES(3) + stgVar608_offsetVar);array_number_t macroDef644 = (array_number_t)stgVar615;
	macroDef644->length=3;
	macroDef644->arr=(number_t*)(STG_OFFSET(stgVar615, VECTOR_HEADER_BYTES));
	

	macroDef644->arr[0] = 0;;

	macroDef644->arr[1] = 1;;

	macroDef644->arr[2] = 0;;;

	macroDef646->arr[1] = macroDef644;;stgVar608_offsetVar += VECTOR_ALL_BYTES(macroDef646->arr[1]->length);storage_t stgVar619 = STG_OFFSET(stgVar608, MATRIX_HEADER_BYTES(3) + stgVar608_offsetVar);array_number_t macroDef645 = (array_number_t)stgVar619;
	macroDef645->length=3;
	macroDef645->arr=(number_t*)(STG_OFFSET(stgVar619, VECTOR_HEADER_BYTES));
	

	macroDef645->arr[0] = 0;;

	macroDef645->arr[1] = 0;;

	macroDef645->arr[2] = 1;;;

	macroDef646->arr[2] = macroDef645;;stgVar608_offsetVar += VECTOR_ALL_BYTES(macroDef646->arr[2]->length);;
		ite651 = macroDef646;;
	} else {
		card_t x_shp = 0;
		number_t x_dps = (angle_axis_dps->arr[0]) / (n_dps);
		card_t y_shp = 0;
		number_t y_dps = (angle_axis_dps->arr[1]) / (n_dps);
		card_t z_shp = 0;
		number_t z_dps = (angle_axis_dps->arr[2]) / (n_dps);
		card_t s_shp = 0;
		number_t s_dps = sin(n_dps);
		card_t c_shp = 0;
		number_t c_dps = cos(n_dps);
		array_array_number_t macroDef650 = (array_array_number_t)stgVar608;
	macroDef650->length=3;
	macroDef650->arr=(array_number_t*)(STG_OFFSET(stgVar608, VECTOR_HEADER_BYTES));
	int stgVar608_offsetVar = 0;storage_t stgVar631 = STG_OFFSET(stgVar608, MATRIX_HEADER_BYTES(3) + stgVar608_offsetVar);array_number_t macroDef647 = (array_number_t)stgVar631;
	macroDef647->length=3;
	macroDef647->arr=(number_t*)(STG_OFFSET(stgVar631, VECTOR_HEADER_BYTES));
	

	macroDef647->arr[0] = ((x_dps) * (x_dps)) + (((1) - ((x_dps) * (x_dps))) * (c_dps));;

	macroDef647->arr[1] = (((x_dps) * (y_dps)) * ((1) - (c_dps))) - ((z_dps) * (s_dps));;

	macroDef647->arr[2] = (((x_dps) * (z_dps)) * ((1) - (c_dps))) + ((y_dps) * (s_dps));;;

	macroDef650->arr[0] = macroDef647;;stgVar608_offsetVar += VECTOR_ALL_BYTES(macroDef650->arr[0]->length);storage_t stgVar635 = STG_OFFSET(stgVar608, MATRIX_HEADER_BYTES(3) + stgVar608_offsetVar);array_number_t macroDef648 = (array_number_t)stgVar635;
	macroDef648->length=3;
	macroDef648->arr=(number_t*)(STG_OFFSET(stgVar635, VECTOR_HEADER_BYTES));
	

	macroDef648->arr[0] = (((x_dps) * (y_dps)) * ((1) - (c_dps))) + ((z_dps) * (s_dps));;

	macroDef648->arr[1] = ((y_dps) * (y_dps)) + (((1) - ((y_dps) * (y_dps))) * (c_dps));;

	macroDef648->arr[2] = (((y_dps) * (z_dps)) * ((1) - (c_dps))) - ((x_dps) * (s_dps));;;

	macroDef650->arr[1] = macroDef648;;stgVar608_offsetVar += VECTOR_ALL_BYTES(macroDef650->arr[1]->length);storage_t stgVar639 = STG_OFFSET(stgVar608, MATRIX_HEADER_BYTES(3) + stgVar608_offsetVar);array_number_t macroDef649 = (array_number_t)stgVar639;
	macroDef649->length=3;
	macroDef649->arr=(number_t*)(STG_OFFSET(stgVar639, VECTOR_HEADER_BYTES));
	

	macroDef649->arr[0] = (((x_dps) * (z_dps)) * ((1) - (c_dps))) - ((y_dps) * (s_dps));;

	macroDef649->arr[1] = (((z_dps) * (y_dps)) * ((1) - (c_dps))) + ((x_dps) * (s_dps));;

	macroDef649->arr[2] = ((z_dps) * (z_dps)) + (((1) - ((z_dps) * (z_dps))) * (c_dps));;;

	macroDef650->arr[2] = macroDef649;;stgVar608_offsetVar += VECTOR_ALL_BYTES(macroDef650->arr[2]->length);;
		ite651 = macroDef650;;
	}
	return ite651;
}

matrix3d_shape_t TOP_LEVEL_usecases_ht_relatives_to_absolutes_shp(matrix3d_shape_t relatives_shp, card_t parents_shp) {
	
	return relatives_shp;
}


array_array_array_number_t TOP_LEVEL_usecases_ht_relatives_to_absolutes_dps(storage_t stgVar652, array_array_array_number_t relatives_dps, array_number_t parents_dps, matrix3d_shape_t relatives_shp, card_t parents_shp) {
	matrix3d_shape_t init_shp = relatives_shp;
	array_array_array_number_t init_dps = relatives_dps;
	card_t anfvar654_shp = relatives_shp.card;
	card_t macroDef679 = relatives_dps->length;
	card_t anfvar654_dps = macroDef679;
	card_t anfvar655_shp = 0;
	card_t anfvar655_dps = 0;
	array_array_array_number_t macroDef686 = init_dps;
	storage_t stgVar659 = stgVar652;
	for(int i_dps = anfvar655_dps; i_dps < anfvar654_dps; i_dps++){
		array_array_array_number_t ite687 ;
	if((parents_dps->arr[i_dps]) == (-1)) {
		matrix3d_shape_t newMatrix_shp = nested_shape_matrix_shape_t(relatives_shp.elem, 1);
		card_t size688 = width_matrix3d_shape_t(newMatrix_shp);
	array_number_t stgVar661 = storage_alloc(size688);
	array_array_array_number_t macroDef681;array_array_array_number_t macroDef680 = (array_array_array_number_t)stgVar661;
	macroDef680->length=1;
	macroDef680->arr=(array_array_number_t*)(STG_OFFSET(stgVar661, VECTOR_HEADER_BYTES));
	int stgVar661_offsetVar = 0;storage_t stgVar662 = STG_OFFSET(stgVar661, MATRIX_HEADER_BYTES(1) + stgVar661_offsetVar);

	macroDef680->arr[0] = relatives_dps->arr[i_dps];;stgVar661_offsetVar += VECTOR_ALL_BYTES(macroDef680->arr[0]->length);;
	array_array_array_number_t newMatrix_dps = macroDef680;
	macroDef681 = TOP_LEVEL_usecases_ht_matrix3DUpdate_dps(stgVar659, macroDef686, i_dps, (i_dps) + (1), newMatrix_dps, init_shp, 0, 0, newMatrix_shp);;
	storage_free(stgVar661, size688);
		ite687 = macroDef681;;
	} else {
		matrix3d_shape_t newMatrix_shp = nested_shape_matrix_shape_t(TOP_LEVEL_linalg_matrixMult_shp(init_shp.elem, relatives_shp.elem), 1);
		card_t size691 = width_matrix3d_shape_t(newMatrix_shp);
	array_number_t stgVar668 = storage_alloc(size691);
	array_array_array_number_t macroDef685;array_array_array_number_t macroDef684 = (array_array_array_number_t)stgVar668;
	macroDef684->length=1;
	macroDef684->arr=(array_array_number_t*)(STG_OFFSET(stgVar668, VECTOR_HEADER_BYTES));
	int stgVar668_offsetVar = 0;storage_t stgVar669 = STG_OFFSET(stgVar668, MATRIX_HEADER_BYTES(1) + stgVar668_offsetVar);card_t size690 = width_matrix_shape_t(relatives_shp.elem);
	array_number_t stgVar671 = storage_alloc(size690);
	array_array_number_t macroDef683;card_t size689 = width_matrix_shape_t(init_shp.elem);
	array_number_t stgVar670 = storage_alloc(size689);
	array_array_number_t macroDef682;
	macroDef682 = TOP_LEVEL_linalg_matrixMult_dps(stgVar669, macroDef686->arr[(int)(parents_dps->arr[i_dps])], relatives_dps->arr[i_dps], init_shp.elem, relatives_shp.elem);;
	storage_free(stgVar670, size689);
	macroDef683 = macroDef682;;
	storage_free(stgVar671, size690);

	macroDef684->arr[0] = macroDef683;;stgVar668_offsetVar += VECTOR_ALL_BYTES(macroDef684->arr[0]->length);;
	array_array_array_number_t newMatrix_dps = macroDef684;
	macroDef685 = TOP_LEVEL_usecases_ht_matrix3DUpdate_dps(stgVar659, macroDef686, i_dps, (i_dps) + (1), newMatrix_dps, init_shp, 0, 0, newMatrix_shp);;
	storage_free(stgVar668, size691);
		ite687 = macroDef685;;
	}
		macroDef686 = ite687;;
	}
	return macroDef686;
}
typedef struct env_t_761 {
	matrix_shape_t pose_params_shp;
} env_t_761;
env_t_761 make_env_t_761(matrix_shape_t pose_params_shp) {
	env_t_761 env;
	env.pose_params_shp = pose_params_shp;
	return env;
}

value_t lambda761(env_t_761* env755, card_t row_shp) {
	matrix_shape_t pose_params_shp754 = env755->pose_params_shp;
	value_t res;
	res.card_t_value = TOP_LEVEL_linalg_mult_vec_elementwise_shp(row_shp, pose_params_shp754.elem);
	return res;
}
typedef empty_env_t env_t_762;


value_t lambda762(env_t_762* env758, card_t x_shp) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
matrix_shape_t TOP_LEVEL_usecases_ht_apply_global_transform_shp(matrix_shape_t pose_params_shp, matrix_shape_t positions_shp) {
	env_t_761 env_t_761_value = make_env_t_761(pose_params_shp); closure_t closure757 = make_closure(lambda761, &env_t_761_value);
	env_t_762 env_t_762_value = make_empty_env(); closure_t closure760 = make_closure(lambda762, &env_t_762_value);
	return TOP_LEVEL_linalg_matrixMult_shp(TOP_LEVEL_linalg_matrixConcatCol_shp(TOP_LEVEL_linalg_matrixMap_shp(closure757, TOP_LEVEL_usecases_ht_angle_axis_to_rotation_matrix_shp(pose_params_shp.elem)), TOP_LEVEL_linalg_matrixTranspose_shp(nested_shape_card_t(pose_params_shp.elem, 1))), TOP_LEVEL_linalg_matrixConcat_shp(positions_shp, nested_shape_card_t(TOP_LEVEL_linalg_vectorMap_shp(closure760, TOP_LEVEL_linalg_vectorRange_shp(1, positions_shp.elem)), 1)));
}

typedef struct env_t_801 {
	card_t scale_shp;
} env_t_801;
env_t_801 make_env_t_801(card_t scale_shp) {
	env_t_801 env;
	env.scale_shp = scale_shp;
	return env;
}

value_t lambda801(env_t_801* env765, card_t row_shp) {
	card_t scale_shp764 = env765->scale_shp;
	value_t res;
	res.card_t_value = TOP_LEVEL_linalg_mult_vec_elementwise_shp(row_shp, scale_shp764);
	return res;
}
typedef struct env_t_802 {
	card_t scale_shp;
	array_number_t scale_dps;
} env_t_802;
env_t_802 make_env_t_802(card_t scale_shp,array_number_t scale_dps) {
	env_t_802 env;
	env.scale_shp = scale_shp;
	env.scale_dps = scale_dps;
	return env;
}

value_t lambda802(env_t_802* env770, storage_t stgVar701, array_number_t row_dps, card_t row_shp) {
	card_t scale_shp769 = env770->scale_shp;
	array_number_t scale_dps768 = env770->scale_dps;
	value_t res;
	res.array_number_t_value = TOP_LEVEL_linalg_mult_vec_elementwise_dps(stgVar701, row_dps, scale_dps768, row_shp, scale_shp769);
	return res;
}
typedef struct env_t_803 {
	card_t scale_shp;
} env_t_803;
env_t_803 make_env_t_803(card_t scale_shp) {
	env_t_803 env;
	env.scale_shp = scale_shp;
	return env;
}

value_t lambda803(env_t_803* env774, card_t row_shp) {
	card_t scale_shp773 = env774->scale_shp;
	value_t res;
	res.card_t_value = TOP_LEVEL_linalg_mult_vec_elementwise_shp(row_shp, scale_shp773);
	return res;
}
typedef empty_env_t env_t_806;


value_t lambda806(env_t_806* env780, card_t x_shp) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
typedef empty_env_t env_t_807;


value_t lambda807(env_t_807* env783, storage_t stgVar713, number_t x_dps, card_t x_shp) {
	
	value_t res;
	res.number_t_value = 1;
	return res;
}
typedef empty_env_t env_t_809;


value_t lambda809(env_t_809* env788, card_t x_shp) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
array_array_number_t TOP_LEVEL_usecases_ht_apply_global_transform_dps(storage_t stgVar692, array_array_number_t pose_params_dps, array_array_number_t positions_dps, matrix_shape_t pose_params_shp, matrix_shape_t positions_shp) {
	matrix_shape_t R_shp = TOP_LEVEL_usecases_ht_angle_axis_to_rotation_matrix_shp(pose_params_shp.elem);
	card_t size817 = width_matrix_shape_t(R_shp);
	array_number_t stgVar693 = storage_alloc(size817);
	array_array_number_t macroDef799;card_t size800 = width_card_t(pose_params_shp.elem);
	array_number_t stgVar694 = storage_alloc(size800);
	array_array_number_t macroDef763;
	macroDef763 = TOP_LEVEL_usecases_ht_angle_axis_to_rotation_matrix_dps(stgVar693, pose_params_dps->arr[0], pose_params_shp.elem);;
	storage_free(stgVar694, size800);
	array_array_number_t R_dps = macroDef763;
	card_t scale_shp = pose_params_shp.elem;
	card_t size816 = width_card_t(scale_shp);
	array_number_t stgVar696 = storage_alloc(size816);
	array_array_number_t macroDef798;array_number_t scale_dps = pose_params_dps->arr[1];
	env_t_801 env_t_801_value = make_env_t_801(scale_shp); closure_t closure767 = make_closure(lambda801, &env_t_801_value);
	matrix_shape_t R1_shp = TOP_LEVEL_linalg_matrixMap_shp(closure767, R_shp);
	card_t size815 = width_matrix_shape_t(R1_shp);
	array_number_t stgVar698 = storage_alloc(size815);
	array_array_number_t macroDef797;env_t_802 env_t_802_value = make_env_t_802(scale_shp,scale_dps); closure_t closure772 = make_closure(lambda802, &env_t_802_value);
	env_t_803 env_t_803_value = make_env_t_803(scale_shp); closure_t closure776 = make_closure(lambda803, &env_t_803_value);
	array_array_number_t R1_dps = TOP_LEVEL_linalg_matrixMap_dps(stgVar698, closure772, R_dps, closure776, R_shp);
	matrix_shape_t T_shp = TOP_LEVEL_linalg_matrixConcatCol_shp(R1_shp, TOP_LEVEL_linalg_matrixTranspose_shp(nested_shape_card_t(pose_params_shp.elem, 1)));
	card_t size814 = width_matrix_shape_t(T_shp);
	array_number_t stgVar704 = storage_alloc(size814);
	array_array_number_t macroDef796;card_t size805 = width_matrix_shape_t(TOP_LEVEL_linalg_matrixTranspose_shp(nested_shape_card_t(pose_params_shp.elem, 1)));
	array_number_t stgVar706 = storage_alloc(size805);
	array_array_number_t macroDef779;card_t size804 = width_matrix_shape_t(nested_shape_card_t(pose_params_shp.elem, 1));
	array_number_t stgVar707 = storage_alloc(size804);
	array_array_number_t macroDef778;array_array_number_t macroDef777 = (array_array_number_t)stgVar707;
	macroDef777->length=1;
	macroDef777->arr=(array_number_t*)(STG_OFFSET(stgVar707, VECTOR_HEADER_BYTES));
	int stgVar707_offsetVar = 0;storage_t stgVar708 = STG_OFFSET(stgVar707, MATRIX_HEADER_BYTES(1) + stgVar707_offsetVar);

	macroDef777->arr[0] = pose_params_dps->arr[2];;stgVar707_offsetVar += VECTOR_ALL_BYTES(macroDef777->arr[0]->length);;
	macroDef778 = TOP_LEVEL_linalg_matrixTranspose_dps(stgVar706, macroDef777, nested_shape_card_t(pose_params_shp.elem, 1));;
	storage_free(stgVar707, size804);
	macroDef779 = TOP_LEVEL_linalg_matrixConcatCol_dps(stgVar704, R1_dps, macroDef778, R1_shp, TOP_LEVEL_linalg_matrixTranspose_shp(nested_shape_card_t(pose_params_shp.elem, 1)));;
	storage_free(stgVar706, size805);
	array_array_number_t T_dps = macroDef779;
	env_t_806 env_t_806_value = make_empty_env(); closure_t closure782 = make_closure(lambda806, &env_t_806_value);
	card_t ones_shp = TOP_LEVEL_linalg_vectorMap_shp(closure782, TOP_LEVEL_linalg_vectorRange_shp(1, positions_shp.elem));
	card_t size813 = width_card_t(ones_shp);
	array_number_t stgVar710 = storage_alloc(size813);
	array_array_number_t macroDef795;card_t size810 = width_card_t(TOP_LEVEL_linalg_vectorRange_shp(1, positions_shp.elem));
	array_number_t stgVar712 = storage_alloc(size810);
	array_number_t macroDef791;env_t_807 env_t_807_value = make_empty_env(); closure_t closure785 = make_closure(lambda807, &env_t_807_value);
	card_t size808 = width_card_t(positions_shp.elem);
	array_number_t stgVar716 = storage_alloc(size808);
	card_t macroDef787;card_t macroDef786 = positions_dps->arr[0]->length;
	macroDef787 = macroDef786;;
	storage_free(stgVar716, size808);
	env_t_809 env_t_809_value = make_empty_env(); closure_t closure790 = make_closure(lambda809, &env_t_809_value);
	macroDef791 = TOP_LEVEL_linalg_vectorMap_dps(stgVar710, closure785, TOP_LEVEL_linalg_vectorRange_dps(stgVar712, 1, macroDef787, 1, positions_shp.elem), closure790, TOP_LEVEL_linalg_vectorRange_shp(1, positions_shp.elem));;
	storage_free(stgVar712, size810);
	array_number_t ones_dps = macroDef791;
	matrix_shape_t positions_homog_shp = TOP_LEVEL_linalg_matrixConcat_shp(positions_shp, nested_shape_card_t(ones_shp, 1));
	card_t size812 = width_matrix_shape_t(positions_homog_shp);
	array_number_t stgVar718 = storage_alloc(size812);
	array_array_number_t macroDef794;card_t size811 = width_matrix_shape_t(nested_shape_card_t(ones_shp, 1));
	array_number_t stgVar720 = storage_alloc(size811);
	array_array_number_t macroDef793;array_array_number_t macroDef792 = (array_array_number_t)stgVar720;
	macroDef792->length=1;
	macroDef792->arr=(array_number_t*)(STG_OFFSET(stgVar720, VECTOR_HEADER_BYTES));
	int stgVar720_offsetVar = 0;storage_t stgVar721 = STG_OFFSET(stgVar720, MATRIX_HEADER_BYTES(1) + stgVar720_offsetVar);

	macroDef792->arr[0] = ones_dps;;stgVar720_offsetVar += VECTOR_ALL_BYTES(macroDef792->arr[0]->length);;
	macroDef793 = TOP_LEVEL_linalg_matrixConcat_dps(stgVar718, positions_dps, macroDef792, positions_shp, nested_shape_card_t(ones_shp, 1));;
	storage_free(stgVar720, size811);
	array_array_number_t positions_homog_dps = macroDef793;
	macroDef794 = TOP_LEVEL_linalg_matrixMult_dps(stgVar692, T_dps, positions_homog_dps, T_shp, positions_homog_shp);;
	storage_free(stgVar718, size812);
	macroDef795 = macroDef794;;
	storage_free(stgVar710, size813);
	macroDef796 = macroDef795;;
	storage_free(stgVar704, size814);
	macroDef797 = macroDef796;;
	storage_free(stgVar698, size815);
	macroDef798 = macroDef797;;
	storage_free(stgVar696, size816);
	macroDef799 = macroDef798;;
	storage_free(stgVar693, size817);
	return macroDef799;
}

matrix_shape_t TOP_LEVEL_usecases_ht_get_skinned_vertex_positions_shp(card_t is_mirrored_shp, card_t n_bones_shp, matrix_shape_t pose_params_shp, matrix3d_shape_t base_relatives_shp, card_t parents_shp, matrix3d_shape_t inverse_base_absolutes_shp, matrix_shape_t base_positions_shp, matrix_shape_t weights_shp) {
	
	return TOP_LEVEL_usecases_ht_apply_global_transform_shp(pose_params_shp, TOP_LEVEL_linalg_matrixMult_shp(nested_shape_card_t(3, 3), TOP_LEVEL_linalg_matrixFill_shp(3, base_positions_shp.elem, 0)));
}

typedef empty_env_t env_t_966;


value_t lambda966(env_t_966* env935, matrix_shape_t m1_shp, matrix_shape_t m2_shp) {
	
	value_t res;
	res.matrix_shape_t_value = TOP_LEVEL_linalg_matrixMult_shp(m1_shp, m2_shp);
	return res;
}
typedef empty_env_t env_t_967;


value_t lambda967(env_t_967* env938, storage_t stgVar830, array_array_number_t m1_dps, array_array_number_t m2_dps, matrix_shape_t m1_shp, matrix_shape_t m2_shp) {
	
	value_t res;
	res.array_array_number_t_value = TOP_LEVEL_linalg_matrixMult_dps(stgVar830, m1_dps, m2_dps, m1_shp, m2_shp);
	return res;
}
typedef empty_env_t env_t_968;


value_t lambda968(env_t_968* env941, matrix_shape_t m1_shp, matrix_shape_t m2_shp) {
	
	value_t res;
	res.matrix_shape_t_value = TOP_LEVEL_linalg_matrixMult_shp(m1_shp, m2_shp);
	return res;
}
array_array_number_t TOP_LEVEL_usecases_ht_get_skinned_vertex_positions_dps(storage_t stgVar818, index_t is_mirrored_dps, card_t n_bones_dps, array_array_number_t pose_params_dps, array_array_array_number_t base_relatives_dps, array_number_t parents_dps, array_array_array_number_t inverse_base_absolutes_dps, array_array_number_t base_positions_dps, array_array_number_t weights_dps, card_t is_mirrored_shp, card_t n_bones_shp, matrix_shape_t pose_params_shp, matrix3d_shape_t base_relatives_shp, card_t parents_shp, matrix3d_shape_t inverse_base_absolutes_shp, matrix_shape_t base_positions_shp, matrix_shape_t weights_shp) {
	matrix3d_shape_t relatives_shp = TOP_LEVEL_usecases_ht_get_posed_relatives_shp(n_bones_shp, pose_params_shp, base_relatives_shp);
	card_t size982 = width_matrix3d_shape_t(relatives_shp);
	array_number_t stgVar819 = storage_alloc(size982);
	array_array_number_t macroDef965;array_array_array_number_t relatives_dps = TOP_LEVEL_usecases_ht_get_posed_relatives_dps(stgVar819, n_bones_dps, pose_params_dps, base_relatives_dps, n_bones_shp, pose_params_shp, base_relatives_shp);
	matrix3d_shape_t absolutes_shp = TOP_LEVEL_usecases_ht_relatives_to_absolutes_shp(relatives_shp, parents_shp);
	card_t size981 = width_matrix3d_shape_t(absolutes_shp);
	array_number_t stgVar823 = storage_alloc(size981);
	array_array_number_t macroDef964;array_array_array_number_t absolutes_dps = TOP_LEVEL_usecases_ht_relatives_to_absolutes_dps(stgVar823, relatives_dps, parents_dps, relatives_shp, parents_shp);
	env_t_966 env_t_966_value = make_empty_env(); closure_t closure937 = make_closure(lambda966, &env_t_966_value);
	matrix3d_shape_t transforms_shp = TOP_LEVEL_linalg_matrix3DMap2_shp(closure937, absolutes_shp, inverse_base_absolutes_shp);
	card_t size980 = width_matrix3d_shape_t(transforms_shp);
	array_number_t stgVar826 = storage_alloc(size980);
	array_array_number_t macroDef963;env_t_967 env_t_967_value = make_empty_env(); closure_t closure940 = make_closure(lambda967, &env_t_967_value);
	env_t_968 env_t_968_value = make_empty_env(); closure_t closure943 = make_closure(lambda968, &env_t_968_value);
	array_array_array_number_t transforms_dps = TOP_LEVEL_linalg_matrix3DMap2_dps(stgVar826, closure940, absolutes_dps, inverse_base_absolutes_dps, closure943, absolutes_shp, inverse_base_absolutes_shp);
	card_t n_verts_shp = base_positions_shp.elem;
	card_t size969 = width_card_t(base_positions_shp.elem);
	array_number_t stgVar834 = storage_alloc(size969);
	card_t macroDef945;card_t macroDef944 = base_positions_dps->arr[0]->length;
	macroDef945 = macroDef944;;
	storage_free(stgVar834, size969);
	card_t n_verts_dps = macroDef945;
	matrix_shape_t init_positions_shp = TOP_LEVEL_linalg_matrixFill_shp(3, n_verts_shp, 0);
	card_t size979 = width_matrix_shape_t(init_positions_shp);
	array_number_t stgVar836 = storage_alloc(size979);
	array_array_number_t macroDef962;array_array_number_t init_positions_dps = TOP_LEVEL_linalg_matrixFill_dps(stgVar836, 3, n_verts_dps, 0, 3, n_verts_shp, 0);
	matrix_shape_t positions_shp = init_positions_shp;
	card_t size978 = width_matrix_shape_t(positions_shp);
	array_number_t stgVar840 = storage_alloc(size978);
	array_array_number_t macroDef961;card_t anfvar841_shp = transforms_shp.card;
	card_t macroDef946 = transforms_dps->length;
	card_t anfvar841_dps = macroDef946;
	card_t anfvar842_shp = 0;
	card_t anfvar842_dps = 0;
	array_array_number_t macroDef954 = init_positions_dps;
	storage_t stgVar846 = stgVar840;
	for(int i_transform_dps = anfvar842_dps; i_transform_dps < anfvar841_dps; i_transform_dps++){
		matrix_shape_t curr_positions_shp = TOP_LEVEL_linalg_matrixMult_shp(TOP_LEVEL_linalg_matrixSlice_shp(3, 0, transforms_shp.elem), base_positions_shp);
		card_t size975 = width_matrix_shape_t(curr_positions_shp);
	array_number_t stgVar847 = storage_alloc(size975);
	array_array_number_t macroDef953;card_t size971 = width_matrix_shape_t(TOP_LEVEL_linalg_matrixSlice_shp(3, 0, transforms_shp.elem));
	array_number_t stgVar848 = storage_alloc(size971);
	array_array_number_t macroDef948;card_t size970 = width_matrix_shape_t(transforms_shp.elem);
	array_number_t stgVar852 = storage_alloc(size970);
	array_array_number_t macroDef947;
	macroDef947 = TOP_LEVEL_linalg_matrixSlice_dps(stgVar848, 3, 0, transforms_dps->arr[i_transform_dps], 3, 0, transforms_shp.elem);;
	storage_free(stgVar852, size970);
	macroDef948 = TOP_LEVEL_linalg_matrixMult_dps(stgVar847, macroDef947, base_positions_dps, TOP_LEVEL_linalg_matrixSlice_shp(3, 0, transforms_shp.elem), base_positions_shp);;
	storage_free(stgVar848, size971);
	array_array_number_t curr_positions_dps = macroDef948;
	matrix_shape_t w_shp = TOP_LEVEL_linalg_matrixFillFromVector_shp(base_positions_shp.card, weights_shp.elem);
	card_t size974 = width_matrix_shape_t(w_shp);
	array_number_t stgVar854 = storage_alloc(size974);
	array_array_number_t macroDef952;card_t size972 = width_card_t(weights_shp.elem);
	array_number_t stgVar856 = storage_alloc(size972);
	array_array_number_t macroDef950;card_t macroDef949 = base_positions_dps->length;
	macroDef950 = TOP_LEVEL_linalg_matrixFillFromVector_dps(stgVar854, macroDef949, weights_dps->arr[i_transform_dps], base_positions_shp.card, weights_shp.elem);;
	storage_free(stgVar856, size972);
	array_array_number_t w_dps = macroDef950;
	card_t size973 = width_matrix_shape_t(TOP_LEVEL_linalg_matrixMultElementwise_shp(curr_positions_shp, w_shp));
	array_number_t stgVar860 = storage_alloc(size973);
	array_array_number_t macroDef951;
	macroDef951 = TOP_LEVEL_linalg_matrixAdd_dps(stgVar846, macroDef954, TOP_LEVEL_linalg_matrixMultElementwise_dps(stgVar860, curr_positions_dps, w_dps, curr_positions_shp, w_shp), init_positions_shp, TOP_LEVEL_linalg_matrixMultElementwise_shp(curr_positions_shp, w_shp));;
	storage_free(stgVar860, size973);
	macroDef952 = macroDef951;;
	storage_free(stgVar854, size974);
	macroDef953 = macroDef952;;
	storage_free(stgVar847, size975);
		macroDef954 = macroDef953;;
	}
	array_array_number_t positions_dps = macroDef954;
	matrix_shape_t mirror_matrix_shp = nested_shape_card_t(3, 3);
	matrix_shape_t mirrored_positions_shp = TOP_LEVEL_linalg_matrixMult_shp(mirror_matrix_shp, positions_shp);
	card_t size977 = width_matrix_shape_t(mirrored_positions_shp);
	array_number_t stgVar863 = storage_alloc(size977);
	array_array_number_t macroDef960;array_array_number_t mirrored_positions_dps ;
	if((is_mirrored_dps) == (1)) {
		matrix_shape_t mirror_matrix_shp0 = nested_shape_card_t(3, 3);
		card_t size976 = width_matrix_shape_t(mirror_matrix_shp0);
	array_number_t stgVar864 = storage_alloc(size976);
	array_array_number_t macroDef959;array_array_number_t macroDef958 = (array_array_number_t)stgVar864;
	macroDef958->length=3;
	macroDef958->arr=(array_number_t*)(STG_OFFSET(stgVar864, VECTOR_HEADER_BYTES));
	int stgVar864_offsetVar = 0;storage_t stgVar865 = STG_OFFSET(stgVar864, MATRIX_HEADER_BYTES(3) + stgVar864_offsetVar);array_number_t macroDef955 = (array_number_t)stgVar865;
	macroDef955->length=3;
	macroDef955->arr=(number_t*)(STG_OFFSET(stgVar865, VECTOR_HEADER_BYTES));
	

	macroDef955->arr[0] = -1;;

	macroDef955->arr[1] = 0;;

	macroDef955->arr[2] = 0;;;

	macroDef958->arr[0] = macroDef955;;stgVar864_offsetVar += VECTOR_ALL_BYTES(macroDef958->arr[0]->length);storage_t stgVar869 = STG_OFFSET(stgVar864, MATRIX_HEADER_BYTES(3) + stgVar864_offsetVar);array_number_t macroDef956 = (array_number_t)stgVar869;
	macroDef956->length=3;
	macroDef956->arr=(number_t*)(STG_OFFSET(stgVar869, VECTOR_HEADER_BYTES));
	

	macroDef956->arr[0] = 0;;

	macroDef956->arr[1] = 1;;

	macroDef956->arr[2] = 0;;;

	macroDef958->arr[1] = macroDef956;;stgVar864_offsetVar += VECTOR_ALL_BYTES(macroDef958->arr[1]->length);storage_t stgVar873 = STG_OFFSET(stgVar864, MATRIX_HEADER_BYTES(3) + stgVar864_offsetVar);array_number_t macroDef957 = (array_number_t)stgVar873;
	macroDef957->length=3;
	macroDef957->arr=(number_t*)(STG_OFFSET(stgVar873, VECTOR_HEADER_BYTES));
	

	macroDef957->arr[0] = 0;;

	macroDef957->arr[1] = 0;;

	macroDef957->arr[2] = 1;;;

	macroDef958->arr[2] = macroDef957;;stgVar864_offsetVar += VECTOR_ALL_BYTES(macroDef958->arr[2]->length);;
	array_array_number_t mirror_matrix_dps = macroDef958;
	macroDef959 = TOP_LEVEL_linalg_matrixMult_dps(stgVar863, mirror_matrix_dps, positions_dps, mirror_matrix_shp0, positions_shp);;
	storage_free(stgVar864, size976);
		mirrored_positions_dps = macroDef959;;
	} else {
		
		mirrored_positions_dps = positions_dps;;
	}
	macroDef960 = TOP_LEVEL_usecases_ht_apply_global_transform_dps(stgVar818, pose_params_dps, mirrored_positions_dps, pose_params_shp, mirrored_positions_shp);;
	storage_free(stgVar863, size977);
	macroDef961 = macroDef960;;
	storage_free(stgVar840, size978);
	macroDef962 = macroDef961;;
	storage_free(stgVar836, size979);
	macroDef963 = macroDef962;;
	storage_free(stgVar826, size980);
	macroDef964 = macroDef963;;
	storage_free(stgVar823, size981);
	macroDef965 = macroDef964;;
	storage_free(stgVar819, size982);
	return macroDef965;
}
typedef empty_env_t env_t_1036;


value_t lambda1036(env_t_1036* env1033, card_t i_shp) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
card_t TOP_LEVEL_usecases_ht_hand_objective_shp(card_t is_mirrored_shp, card_t param_shp, card_t correspondences_shp, matrix_shape_t points_shp, card_t n_bones_shp, matrix3d_shape_t base_relatives_shp, card_t parents_shp, matrix3d_shape_t inverse_base_absolutes_shp, matrix_shape_t base_positions_shp, matrix_shape_t weights_shp) {
	env_t_1036 env_t_1036_value = make_empty_env(); closure_t closure1035 = make_closure(lambda1036, &env_t_1036_value);
	return TOP_LEVEL_linalg_vectorMap_shp(closure1035, TOP_LEVEL_linalg_vectorRange_shp(0, (((correspondences_shp) + (correspondences_shp)) + (correspondences_shp)) - (1)));
}

typedef empty_env_t env_t_1059;


value_t lambda1059(env_t_1059* env1038, card_t i_shp) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
typedef struct env_t_1060 {
	matrix_shape_t vertex_positions_shp;
	array_array_number_t vertex_positions_dps;
	matrix_shape_t points_shp;
	array_array_number_t points_dps;
	index_t n_corr_dps;
	array_number_t correspondences_dps;
} env_t_1060;
env_t_1060 make_env_t_1060(matrix_shape_t vertex_positions_shp,array_array_number_t vertex_positions_dps,matrix_shape_t points_shp,array_array_number_t points_dps,index_t n_corr_dps,array_number_t correspondences_dps) {
	env_t_1060 env;
	env.vertex_positions_shp = vertex_positions_shp;
	env.vertex_positions_dps = vertex_positions_dps;
	env.points_shp = points_shp;
	env.points_dps = points_dps;
	env.n_corr_dps = n_corr_dps;
	env.correspondences_dps = correspondences_dps;
	return env;
}

value_t lambda1060(env_t_1060* env1049, storage_t stgVar1002, number_t i_dps, card_t i_shp) {
	matrix_shape_t vertex_positions_shp1048 = env1049->vertex_positions_shp;
	array_array_number_t vertex_positions_dps1047 = env1049->vertex_positions_dps;
	matrix_shape_t points_shp1046 = env1049->points_shp;
	array_array_number_t points_dps1045 = env1049->points_dps;
	index_t n_corr_dps1044 = env1049->n_corr_dps;
	array_number_t correspondences_dps1043 = env1049->correspondences_dps;
	card_t ind_shp = 0;
	index_t ind_dps = (int)(i_dps);
	card_t r_shp = 0;
	index_t r_dps = (ind_dps) / (n_corr_dps1044);
	card_t c_shp = 0;
	index_t c_dps = (ind_dps) % (n_corr_dps1044);
	card_t size1061 = width_card_t(points_shp1046.elem);
	array_number_t stgVar1006 = storage_alloc(size1061);
	number_t macroDef1041;
	macroDef1041 = points_dps1045->arr[r_dps]->arr[c_dps];;
	storage_free(stgVar1006, size1061);
	card_t size1062 = width_card_t(vertex_positions_shp1048.elem);
	array_number_t stgVar1008 = storage_alloc(size1062);
	number_t macroDef1042;
	macroDef1042 = vertex_positions_dps1047->arr[r_dps]->arr[(int)(correspondences_dps1043->arr[c_dps])];;
	storage_free(stgVar1008, size1062);
	value_t res;
	res.number_t_value = (macroDef1041) - (macroDef1042);
	return res;
}
typedef empty_env_t env_t_1063;


value_t lambda1063(env_t_1063* env1052, card_t i_shp) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
array_number_t TOP_LEVEL_usecases_ht_hand_objective_dps(storage_t stgVar983, index_t is_mirrored_dps, array_number_t param_dps, array_number_t correspondences_dps, array_array_number_t points_dps, card_t n_bones_dps, array_array_array_number_t base_relatives_dps, array_number_t parents_dps, array_array_array_number_t inverse_base_absolutes_dps, array_array_number_t base_positions_dps, array_array_number_t weights_dps, card_t is_mirrored_shp, card_t param_shp, card_t correspondences_shp, matrix_shape_t points_shp, card_t n_bones_shp, matrix3d_shape_t base_relatives_shp, card_t parents_shp, matrix3d_shape_t inverse_base_absolutes_shp, matrix_shape_t base_positions_shp, matrix_shape_t weights_shp) {
	matrix_shape_t pose_params_shp = TOP_LEVEL_usecases_ht_to_pose_params_shp(param_shp, n_bones_shp);
	card_t size1067 = width_matrix_shape_t(pose_params_shp);
	array_number_t stgVar984 = storage_alloc(size1067);
	array_number_t macroDef1058;array_array_number_t pose_params_dps = TOP_LEVEL_usecases_ht_to_pose_params_dps(stgVar984, param_dps, n_bones_dps, param_shp, n_bones_shp);
	matrix_shape_t vertex_positions_shp = TOP_LEVEL_usecases_ht_get_skinned_vertex_positions_shp(0, n_bones_shp, pose_params_shp, base_relatives_shp, parents_shp, inverse_base_absolutes_shp, base_positions_shp, weights_shp);
	card_t size1066 = width_matrix_shape_t(vertex_positions_shp);
	array_number_t stgVar987 = storage_alloc(size1066);
	array_number_t macroDef1057;array_array_number_t vertex_positions_dps = TOP_LEVEL_usecases_ht_get_skinned_vertex_positions_dps(stgVar987, is_mirrored_dps, n_bones_dps, pose_params_dps, base_relatives_dps, parents_dps, inverse_base_absolutes_dps, base_positions_dps, weights_dps, 0, n_bones_shp, pose_params_shp, base_relatives_shp, parents_shp, inverse_base_absolutes_shp, base_positions_shp, weights_shp);
	card_t n_corr_card_shp = correspondences_shp;
	card_t macroDef1037 = correspondences_dps->length;
	card_t n_corr_card_dps = macroDef1037;
	card_t n_corr_shp = 0;
	index_t n_corr_dps = (n_corr_card_dps);
	env_t_1059 env_t_1059_value = make_empty_env(); closure_t closure1040 = make_closure(lambda1059, &env_t_1059_value);
	card_t err_shp = TOP_LEVEL_linalg_vectorMap_shp(closure1040, TOP_LEVEL_linalg_vectorRange_shp(0, (((n_corr_card_shp) + (n_corr_card_shp)) + (n_corr_card_shp)) - (1)));
	card_t size1065 = width_card_t(err_shp);
	array_number_t stgVar999 = storage_alloc(size1065);
	array_number_t macroDef1056;card_t size1064 = width_card_t(TOP_LEVEL_linalg_vectorRange_shp(0, (((n_corr_card_shp) + (n_corr_card_shp)) + (n_corr_card_shp)) - (1)));
	array_number_t stgVar1001 = storage_alloc(size1064);
	array_number_t macroDef1055;env_t_1060 env_t_1060_value = make_env_t_1060(vertex_positions_shp,vertex_positions_dps,points_shp,points_dps,n_corr_dps,correspondences_dps); closure_t closure1051 = make_closure(lambda1060, &env_t_1060_value);
	env_t_1063 env_t_1063_value = make_empty_env(); closure_t closure1054 = make_closure(lambda1063, &env_t_1063_value);
	macroDef1055 = TOP_LEVEL_linalg_vectorMap_dps(stgVar999, closure1051, TOP_LEVEL_linalg_vectorRange_dps(stgVar1001, 0, (((n_corr_card_dps) + (n_corr_card_dps)) + (n_corr_card_dps)) - (1), 0, (((n_corr_card_shp) + (n_corr_card_shp)) + (n_corr_card_shp)) - (1)), closure1054, TOP_LEVEL_linalg_vectorRange_shp(0, (((n_corr_card_shp) + (n_corr_card_shp)) + (n_corr_card_shp)) - (1)));;
	storage_free(stgVar1001, size1064);
	array_number_t err_dps = macroDef1055;
	macroDef1056 = err_dps;;
	storage_free(stgVar999, size1065);
	macroDef1057 = macroDef1056;;
	storage_free(stgVar987, size1066);
	macroDef1058 = macroDef1057;;
	storage_free(stgVar984, size1067);
	return macroDef1058;
}

card_t TOP_LEVEL_usecases_ht_test_ht_shp(card_t unitVar0_shp) {
	
	return 0;
}

typedef empty_env_t env_t_1117;


value_t lambda1117(env_t_1117* env1102, card_t i_shp) {
	
	value_t res;
	res.card_t_value = 4;
	return res;
}
void TOP_LEVEL_usecases_ht_test_ht_dps(storage_t stgVar1068, int unitVar0_dps, card_t unitVar0_shp) {
	card_t a_shp = 3;
	card_t size1123 = width_card_t(a_shp);
	array_number_t stgVar1069 = storage_alloc(size1123);
	array_number_t macroDef1097 = (array_number_t)stgVar1069;
	macroDef1097->length=3;
	macroDef1097->arr=(number_t*)(STG_OFFSET(stgVar1069, VECTOR_HEADER_BYTES));
	

	macroDef1097->arr[0] = 1;;

	macroDef1097->arr[1] = 2;;

	macroDef1097->arr[2] = 3;;;
	array_number_t a_dps = macroDef1097;
	array_print(a_dps);
	matrix_shape_t mat1_shp = nested_shape_card_t(3, 3);
	card_t size1122 = width_matrix_shape_t(mat1_shp);
	array_number_t stgVar1073 = storage_alloc(size1122);
	array_array_number_t macroDef1101 = (array_array_number_t)stgVar1073;
	macroDef1101->length=3;
	macroDef1101->arr=(array_number_t*)(STG_OFFSET(stgVar1073, VECTOR_HEADER_BYTES));
	int stgVar1073_offsetVar = 0;storage_t stgVar1074 = STG_OFFSET(stgVar1073, MATRIX_HEADER_BYTES(3) + stgVar1073_offsetVar);array_number_t macroDef1098 = (array_number_t)stgVar1074;
	macroDef1098->length=3;
	macroDef1098->arr=(number_t*)(STG_OFFSET(stgVar1074, VECTOR_HEADER_BYTES));
	

	macroDef1098->arr[0] = 1;;

	macroDef1098->arr[1] = 2;;

	macroDef1098->arr[2] = 3;;;

	macroDef1101->arr[0] = macroDef1098;;stgVar1073_offsetVar += VECTOR_ALL_BYTES(macroDef1101->arr[0]->length);storage_t stgVar1078 = STG_OFFSET(stgVar1073, MATRIX_HEADER_BYTES(3) + stgVar1073_offsetVar);array_number_t macroDef1099 = (array_number_t)stgVar1078;
	macroDef1099->length=3;
	macroDef1099->arr=(number_t*)(STG_OFFSET(stgVar1078, VECTOR_HEADER_BYTES));
	

	macroDef1099->arr[0] = 4;;

	macroDef1099->arr[1] = 5;;

	macroDef1099->arr[2] = 6;;;

	macroDef1101->arr[1] = macroDef1099;;stgVar1073_offsetVar += VECTOR_ALL_BYTES(macroDef1101->arr[1]->length);storage_t stgVar1082 = STG_OFFSET(stgVar1073, MATRIX_HEADER_BYTES(3) + stgVar1073_offsetVar);array_number_t macroDef1100 = (array_number_t)stgVar1082;
	macroDef1100->length=3;
	macroDef1100->arr=(number_t*)(STG_OFFSET(stgVar1082, VECTOR_HEADER_BYTES));
	

	macroDef1100->arr[0] = 7;;

	macroDef1100->arr[1] = 8;;

	macroDef1100->arr[2] = 9;;;

	macroDef1101->arr[2] = macroDef1100;;stgVar1073_offsetVar += VECTOR_ALL_BYTES(macroDef1101->arr[2]->length);;
	array_array_number_t mat1_dps = macroDef1101;
	env_t_1117 env_t_1117_value = make_empty_env(); closure_t closure1104 = make_closure(lambda1117, &env_t_1117_value);
	matrix_shape_t base_rel_shp = nested_shape_card_t(closure1104.lam(closure1104.env, 0).card_t_value, 4);
	card_t size1121 = width_matrix_shape_t(base_rel_shp);
	array_number_t stgVar1086 = storage_alloc(size1121);
	array_array_number_t macroDef1106 = (array_array_number_t)stgVar1086;
		macroDef1106->length=4;
		macroDef1106->arr=(array_number_t*)(STG_OFFSET(macroDef1106, VECTOR_HEADER_BYTES));
		storage_t stgVar1087 = (STG_OFFSET(macroDef1106, MATRIX_HEADER_BYTES(4)));
		for(int i_dps = 0; i_dps < macroDef1106->length; i_dps++){
			array_number_t macroDef1105 = (array_number_t)stgVar1087;
		macroDef1105->length=4;
		macroDef1105->arr=(number_t*)(STG_OFFSET(macroDef1105, VECTOR_HEADER_BYTES));
		storage_t stgVar1088 = macroDef1105;
		for(int j_dps = 0; j_dps < macroDef1105->length; j_dps++){
			
			macroDef1105->arr[j_dps] = (double)((((i_dps) + (1)) * (4)) + (j_dps));;
			stgVar1088 = STG_OFFSET(stgVar1088, sizeof(number_t));
		}
			macroDef1106->arr[i_dps] = macroDef1105;;
			stgVar1087 = STG_OFFSET(stgVar1087, VECTOR_ALL_BYTES(macroDef1106->arr[i_dps]->length));
		}
	array_array_number_t base_rel_dps = macroDef1106;
	matrix_shape_t q_shp = TOP_LEVEL_usecases_ht_make_relative_shp(a_shp, base_rel_shp);
	card_t size1120 = width_matrix_shape_t(q_shp);
	array_number_t stgVar1089 = storage_alloc(size1120);
	array_array_number_t q_dps = TOP_LEVEL_usecases_ht_make_relative_dps(stgVar1089, a_dps, base_rel_dps, a_shp, base_rel_shp);
	matrix_print(q_dps);
	matrix_shape_t r_shp = TOP_LEVEL_usecases_ht_angle_axis_to_rotation_matrix_shp(a_shp);
	card_t size1119 = width_matrix_shape_t(r_shp);
	array_number_t stgVar1092 = storage_alloc(size1119);
	array_array_number_t r_dps = TOP_LEVEL_usecases_ht_angle_axis_to_rotation_matrix_dps(stgVar1092, a_dps, a_shp);
	matrix_print(r_dps);
	matrix_shape_t s_shp = TOP_LEVEL_usecases_ht_apply_global_transform_shp(mat1_shp, mat1_shp);
	card_t size1118 = width_matrix_shape_t(s_shp);
	array_number_t stgVar1094 = storage_alloc(size1118);
	array_array_number_t s_dps = TOP_LEVEL_usecases_ht_apply_global_transform_dps(stgVar1094, mat1_dps, mat1_dps, mat1_shp, mat1_shp);
	matrix_print(s_dps);
	;
	storage_free(stgVar1094, size1118);
	;
	storage_free(stgVar1092, size1119);
	;
	storage_free(stgVar1089, size1120);
	;
	storage_free(stgVar1086, size1121);
	;
	storage_free(stgVar1073, size1122);
	;
	storage_free(stgVar1069, size1123);
	return ;
}
#endif
