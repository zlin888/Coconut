#ifndef __USECASES_ONEMM_STORAGED_H__ 
#define __USECASES_ONEMM_STORAGED_H__ 
#include "../../Runtime/C/fsharp.h"
#include <stdio.h>
#include <math.h>
#include "linalg_storaged.h"

card_t TOP_LEVEL_usecases_oneMM__vectorFoldNumber_shp(closure_t f_shp, card_t z_shp, card_t range_shp) {
	
	return 0;
}


number_t TOP_LEVEL_usecases_oneMM__vectorFoldNumber_dps(storage_t stgVar1, closure_t f_dps, number_t z_dps, array_number_t range_dps, closure_t f_shp, card_t z_shp, card_t range_shp) {
	card_t anfvar2_shp = range_shp;
	card_t macroDef11 = range_dps->length;
	card_t anfvar2_dps = macroDef11;
	card_t anfvar3_shp = 0;
	card_t anfvar3_dps = 0;
	number_t macroDef12 = z_dps;
	storage_t stgVar7 = stgVar1;
	for(int idx_dps = anfvar3_dps; idx_dps < anfvar2_dps; idx_dps++){
		
		macroDef12 = f_dps.lam(f_dps.env, stgVar7, macroDef12, range_dps->arr[idx_dps], 0, 0).number_t_value;;
	}
	return macroDef12;
}

card_t TOP_LEVEL_usecases_oneMM__vectorSum_shp(card_t v_shp) {
	
	return 0;
}

typedef empty_env_t env_t_29;


value_t lambda29(env_t_29* env25, storage_t stgVar23, number_t acc0_dps, number_t cur_dps, card_t acc0_shp, card_t cur_shp) {
	
	value_t res;
	res.number_t_value = (acc0_dps) + (cur_dps);
	return res;
}
number_t TOP_LEVEL_usecases_oneMM__vectorSum_dps(storage_t stgVar13, array_number_t v_dps, card_t v_shp) {
	card_t anfvar14_shp = v_shp;
	card_t macroDef24 = v_dps->length;
	card_t anfvar14_dps = macroDef24;
	card_t anfvar15_shp = 0;
	card_t anfvar15_dps = 0;
	number_t macroDef28 = 0;
	storage_t stgVar19 = stgVar13;
	for(int idx_dps = anfvar15_dps; idx_dps < anfvar14_dps; idx_dps++){
		env_t_29 env_t_29_value = make_empty_env(); closure_t closure27 = make_closure(lambda29, &env_t_29_value);
		macroDef28 = closure27.lam(closure27.env, stgVar19, macroDef28, v_dps->arr[idx_dps], 0, 0).number_t_value;;
	}
	return macroDef28;
}

card_t TOP_LEVEL_usecases_oneMM__vectorMap2_shp(closure_t f_shp, card_t v1_shp, card_t v2_shp) {
	
	return v1_shp;
}


array_number_t TOP_LEVEL_usecases_oneMM__vectorMap2_dps(storage_t stgVar30, closure_t f_dps, array_number_t v1_dps, array_number_t v2_dps, closure_t f_shp, card_t v1_shp, card_t v2_shp) {
	card_t macroDef37 = v1_dps->length;
	array_number_t macroDef38 = (array_number_t)stgVar30;
		macroDef38->length=macroDef37;
		macroDef38->arr=(number_t*)(STG_OFFSET(macroDef38, VECTOR_HEADER_BYTES));
		storage_t stgVar32 = macroDef38;
		for(int i_dps = 0; i_dps < macroDef38->length; i_dps++){
			
			macroDef38->arr[i_dps] = f_dps.lam(f_dps.env, stgVar32, v1_dps->arr[i_dps], v2_dps->arr[i_dps], 0, 0).number_t_value;;
			stgVar32 = STG_OFFSET(stgVar32, sizeof(number_t));
		}
	return macroDef38;
}

card_t TOP_LEVEL_usecases_oneMM__dot_prod_shp(card_t x_shp, card_t y_shp) {
	
	return 0;
}

typedef empty_env_t env_t_63;


value_t lambda63(env_t_63* env51, storage_t stgVar43, number_t acc_dps, number_t cur_dps, card_t acc_shp, card_t cur_shp) {
	
	value_t res;
	res.number_t_value = (acc_dps) + (cur_dps);
	return res;
}
typedef empty_env_t env_t_64;


value_t lambda64(env_t_64* env55, storage_t stgVar50, number_t x_dps0, number_t y_dps0, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.number_t_value = (x_dps0) * (y_dps0);
	return res;
}
typedef empty_env_t env_t_65;


value_t lambda65(env_t_65* env59, card_t acc_shp, card_t cur_shp) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
number_t TOP_LEVEL_usecases_oneMM__dot_prod_dps(storage_t stgVar39, array_number_t x_dps, array_number_t y_dps, card_t x_shp, card_t y_shp) {
	card_t size66 = width_card_t(x_shp);
	array_number_t stgVar42 = storage_alloc(size66);
	number_t macroDef62;env_t_63 env_t_63_value = make_empty_env(); closure_t closure53 = make_closure(lambda63, &env_t_63_value);
	card_t macroDef54 = x_dps->length;
	array_number_t macroDef58 = (array_number_t)stgVar42;
		macroDef58->length=macroDef54;
		macroDef58->arr=(number_t*)(STG_OFFSET(macroDef58, VECTOR_HEADER_BYTES));
		storage_t stgVar45 = macroDef58;
		for(int i_dps = 0; i_dps < macroDef58->length; i_dps++){
			env_t_64 env_t_64_value = make_empty_env(); closure_t closure57 = make_closure(lambda64, &env_t_64_value);
			macroDef58->arr[i_dps] = closure57.lam(closure57.env, stgVar45, x_dps->arr[i_dps], y_dps->arr[i_dps], 0, 0).number_t_value;;
			stgVar45 = STG_OFFSET(stgVar45, sizeof(number_t));
		}
	env_t_65 env_t_65_value = make_empty_env(); closure_t closure61 = make_closure(lambda65, &env_t_65_value);
	macroDef62 = TOP_LEVEL_usecases_oneMM__vectorFoldNumber_dps(stgVar39, closure53, 0, macroDef58, closure61, 0, x_shp);;
	storage_free(stgVar42, size66);
	return macroDef62;
}

matrix_shape_t TOP_LEVEL_usecases_oneMM__matrixTranspose_shp(matrix_shape_t m_shp) {
	
	return nested_shape_card_t(m_shp.card, m_shp.elem);
}


array_array_number_t TOP_LEVEL_usecases_oneMM__matrixTranspose_dps(storage_t stgVar68, array_array_number_t m_dps, matrix_shape_t m_shp) {
	card_t size82 = width_card_t(m_shp.elem);
	array_number_t stgVar69 = storage_alloc(size82);
	card_t macroDef77;card_t macroDef76 = m_dps->arr[0]->length;
	macroDef77 = macroDef76;;
	storage_free(stgVar69, size82);
	array_array_number_t macroDef81 = (array_array_number_t)stgVar68;
		macroDef81->length=macroDef77;
		macroDef81->arr=(array_number_t*)(STG_OFFSET(macroDef81, VECTOR_HEADER_BYTES));
		storage_t stgVar71 = (STG_OFFSET(macroDef81, MATRIX_HEADER_BYTES(macroDef77)));
		for(int i_dps = 0; i_dps < macroDef81->length; i_dps++){
			card_t macroDef78 = m_dps->length;
			array_number_t macroDef80 = (array_number_t)stgVar71;
		macroDef80->length=macroDef78;
		macroDef80->arr=(number_t*)(STG_OFFSET(macroDef80, VECTOR_HEADER_BYTES));
		storage_t stgVar73 = macroDef80;
		for(int j_dps = 0; j_dps < macroDef80->length; j_dps++){
			card_t size83 = width_card_t(m_shp.elem);
	array_number_t stgVar74 = storage_alloc(size83);
	number_t macroDef79;
	macroDef79 = m_dps->arr[j_dps]->arr[i_dps];;
	storage_free(stgVar74, size83);
			macroDef80->arr[j_dps] = macroDef79;;
			stgVar73 = STG_OFFSET(stgVar73, sizeof(number_t));
		}
			macroDef81->arr[i_dps] = macroDef80;;
			stgVar71 = STG_OFFSET(stgVar71, VECTOR_ALL_BYTES(macroDef81->arr[i_dps]->length));
		}
	return macroDef81;
}

matrix_shape_t TOP_LEVEL_usecases_oneMM__matrixMult_shp(matrix_shape_t m1_shp, matrix_shape_t m2_shp) {
	
	return nested_shape_card_t(m2_shp.elem, m1_shp.card);
}

typedef struct env_t_4051 {
	matrix_shape_t m2_shp;
} env_t_4051;
env_t_4051 make_env_t_4051(matrix_shape_t m2_shp) {
	env_t_4051 env;
	env.m2_shp = m2_shp;
	return env;
}

value_t lambda4051(env_t_4051* env4021, card_t i_shp) {
	matrix_shape_t m2_shp4020 = env4021->m2_shp;
	value_t res;
	res.card_t_value = m2_shp4020.card;
	return res;
}
typedef empty_env_t env_t_4055;


value_t lambda4055(env_t_4055* env4033, card_t x_shp, card_t y_shp) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
typedef empty_env_t env_t_4056;


value_t lambda4056(env_t_4056* env4036, storage_t stgVar4017, number_t x_dps, number_t y_dps, card_t x_shp, card_t y_shp) {
	
	value_t res;
	res.number_t_value = (x_dps) * (y_dps);
	return res;
}
typedef empty_env_t env_t_4057;


value_t lambda4057(env_t_4057* env4039, card_t x_shp, card_t y_shp) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
typedef empty_env_t env_t_4060;


value_t lambda4060(env_t_4060* env4044, card_t x_shp, card_t y_shp) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
array_array_number_t TOP_LEVEL_usecases_oneMM__matrixMult_dps(storage_t stgVar3998, array_array_number_t m1_dps, array_array_number_t m2_dps, matrix_shape_t m1_shp, matrix_shape_t m2_shp) {
	card_t cols881062005791718_shp = m2_shp.elem;
	env_t_4051 env_t_4051_value = make_env_t_4051(m2_shp); closure_t closure4023 = make_closure(lambda4051, &env_t_4051_value);
	matrix_shape_t m2T89107201580_shp = nested_shape_card_t(closure4023.lam(closure4023.env, 0).card_t_value, cols881062005791718_shp);
	card_t size4062 = width_matrix_shape_t(m2T89107201580_shp);
	array_number_t stgVar3999 = storage_alloc(size4062);
	array_array_number_t macroDef4050;card_t cols881062005791718_shp0 = m2_shp.elem;
	card_t size4052 = width_card_t(m2_shp.elem);
	array_number_t stgVar4001 = storage_alloc(size4052);
	card_t macroDef4025;card_t macroDef4024 = m2_dps->arr[0]->length;
	macroDef4025 = macroDef4024;;
	storage_free(stgVar4001, size4052);
	card_t cols881062005791718_dps = macroDef4025;
	array_array_number_t macroDef4029 = (array_array_number_t)stgVar3999;
		macroDef4029->length=cols881062005791718_dps;
		macroDef4029->arr=(array_number_t*)(STG_OFFSET(macroDef4029, VECTOR_HEADER_BYTES));
		storage_t stgVar4003 = (STG_OFFSET(macroDef4029, MATRIX_HEADER_BYTES(cols881062005791718_dps)));
		for(int i_dps = 0; i_dps < macroDef4029->length; i_dps++){
			card_t macroDef4026 = m2_dps->length;
			array_number_t macroDef4028 = (array_number_t)stgVar4003;
		macroDef4028->length=macroDef4026;
		macroDef4028->arr=(number_t*)(STG_OFFSET(macroDef4028, VECTOR_HEADER_BYTES));
		storage_t stgVar4005 = macroDef4028;
		for(int j_dps = 0; j_dps < macroDef4028->length; j_dps++){
			card_t size4053 = width_card_t(m2_shp.elem);
	array_number_t stgVar4006 = storage_alloc(size4053);
	number_t macroDef4027;
	macroDef4027 = m2_dps->arr[j_dps]->arr[i_dps];;
	storage_free(stgVar4006, size4053);
			macroDef4028->arr[j_dps] = macroDef4027;;
			stgVar4005 = STG_OFFSET(stgVar4005, sizeof(number_t));
		}
			macroDef4029->arr[i_dps] = macroDef4028;;
			stgVar4003 = STG_OFFSET(stgVar4003, VECTOR_ALL_BYTES(macroDef4029->arr[i_dps]->length));
		}
	array_array_number_t m2T89107201580_dps = macroDef4029;
	card_t macroDef4030 = m1_dps->length;
	array_array_number_t macroDef4049 = (array_array_number_t)stgVar3998;
		macroDef4049->length=macroDef4030;
		macroDef4049->arr=(array_number_t*)(STG_OFFSET(macroDef4049, VECTOR_HEADER_BYTES));
		storage_t stgVar4009 = (STG_OFFSET(macroDef4049, MATRIX_HEADER_BYTES(macroDef4030)));
		for(int r_dps = 0; r_dps < macroDef4049->length; r_dps++){
			card_t size4054 = width_card_t(m2_shp.elem);
	array_number_t stgVar4010 = storage_alloc(size4054);
	card_t macroDef4032;card_t macroDef4031 = m2_dps->arr[0]->length;
	macroDef4032 = macroDef4031;;
	storage_free(stgVar4010, size4054);
			array_number_t macroDef4048 = (array_number_t)stgVar4009;
		macroDef4048->length=macroDef4032;
		macroDef4048->arr=(number_t*)(STG_OFFSET(macroDef4048, VECTOR_HEADER_BYTES));
		storage_t stgVar4012 = macroDef4048;
		for(int c_dps = 0; c_dps < macroDef4048->length; c_dps++){
			env_t_4055 env_t_4055_value = make_empty_env(); closure_t closure4035 = make_closure(lambda4055, &env_t_4055_value);
			card_t size4061 = width_card_t(TOP_LEVEL_usecases_oneMM__vectorMap2_shp(closure4035, m1_shp.elem, m2T89107201580_shp.elem));
	array_number_t stgVar4013 = storage_alloc(size4061);
	number_t macroDef4047;card_t size4059 = width_card_t(m2T89107201580_shp.elem);
	array_number_t stgVar4016 = storage_alloc(size4059);
	array_number_t macroDef4043;card_t size4058 = width_card_t(m1_shp.elem);
	array_number_t stgVar4015 = storage_alloc(size4058);
	array_number_t macroDef4042;env_t_4056 env_t_4056_value = make_empty_env(); closure_t closure4038 = make_closure(lambda4056, &env_t_4056_value);
	env_t_4057 env_t_4057_value = make_empty_env(); closure_t closure4041 = make_closure(lambda4057, &env_t_4057_value);
	macroDef4042 = TOP_LEVEL_usecases_oneMM__vectorMap2_dps(stgVar4013, closure4038, m1_dps->arr[r_dps], m2T89107201580_dps->arr[c_dps], closure4041, m1_shp.elem, m2T89107201580_shp.elem);;
	storage_free(stgVar4015, size4058);
	macroDef4043 = macroDef4042;;
	storage_free(stgVar4016, size4059);
	env_t_4060 env_t_4060_value = make_empty_env(); closure_t closure4046 = make_closure(lambda4060, &env_t_4060_value);
	macroDef4047 = TOP_LEVEL_usecases_oneMM__vectorSum_dps(stgVar4012, macroDef4043, TOP_LEVEL_usecases_oneMM__vectorMap2_shp(closure4046, m1_shp.elem, m2T89107201580_shp.elem));;
	storage_free(stgVar4013, size4061);
			macroDef4048->arr[c_dps] = macroDef4047;;
			stgVar4012 = STG_OFFSET(stgVar4012, sizeof(number_t));
		}
			macroDef4049->arr[r_dps] = macroDef4048;;
			stgVar4009 = STG_OFFSET(stgVar4009, VECTOR_ALL_BYTES(macroDef4049->arr[r_dps]->length));
		}
	macroDef4050 = macroDef4049;;
	storage_free(stgVar3999, size4062);
	return macroDef4050;
}

matrix_shape_t TOP_LEVEL_usecases_oneMM_oneMM_shp(matrix_shape_t A_shp, matrix_shape_t B_shp) {
	
	return nested_shape_card_t(B_shp.elem, A_shp.card);
}


array_array_number_t TOP_LEVEL_usecases_oneMM_oneMM_dps(storage_t stgVar8389, array_array_number_t A_dps, array_array_number_t B_dps, matrix_shape_t A_shp, matrix_shape_t B_shp) {
	card_t c2406540854189_shp = B_shp.elem;
	card_t size8412 = width_card_t(B_shp.elem);
	array_number_t stgVar8391 = storage_alloc(size8412);
	card_t macroDef8405;card_t macroDef8404 = B_dps->arr[0]->length;
	macroDef8405 = macroDef8404;;
	storage_free(stgVar8391, size8412);
	card_t c2406540854189_dps = macroDef8405;
	matrix_shape_t m2T40684088419246135874_shp = TOP_LEVEL_usecases_oneMM__matrixTranspose_shp(B_shp);
	card_t size8415 = width_matrix_shape_t(m2T40684088419246135874_shp);
	array_number_t stgVar8393 = storage_alloc(size8415);
	array_array_number_t macroDef8411;array_array_number_t m2T40684088419246135874_dps = TOP_LEVEL_usecases_oneMM__matrixTranspose_dps(stgVar8393, B_dps, B_shp);
	card_t macroDef8406 = A_dps->length;
	array_array_number_t macroDef8410 = (array_array_number_t)stgVar8389;
		macroDef8410->length=macroDef8406;
		macroDef8410->arr=(array_number_t*)(STG_OFFSET(macroDef8410, VECTOR_HEADER_BYTES));
		storage_t stgVar8396 = (STG_OFFSET(macroDef8410, MATRIX_HEADER_BYTES(macroDef8406)));
		for(int r_dps = 0; r_dps < macroDef8410->length; r_dps++){
			array_number_t macroDef8409 = (array_number_t)stgVar8396;
		macroDef8409->length=c2406540854189_dps;
		macroDef8409->arr=(number_t*)(STG_OFFSET(macroDef8409, VECTOR_HEADER_BYTES));
		storage_t stgVar8397 = macroDef8409;
		for(int c_dps = 0; c_dps < macroDef8409->length; c_dps++){
			card_t size8414 = width_card_t(m2T40684088419246135874_shp.elem);
	array_number_t stgVar8399 = storage_alloc(size8414);
	number_t macroDef8408;card_t size8413 = width_card_t(A_shp.elem);
	array_number_t stgVar8398 = storage_alloc(size8413);
	number_t macroDef8407;
	macroDef8407 = TOP_LEVEL_usecases_oneMM__dot_prod_dps(stgVar8397, A_dps->arr[r_dps], m2T40684088419246135874_dps->arr[c_dps], A_shp.elem, m2T40684088419246135874_shp.elem);;
	storage_free(stgVar8398, size8413);
	macroDef8408 = macroDef8407;;
	storage_free(stgVar8399, size8414);
			macroDef8409->arr[c_dps] = macroDef8408;;
			stgVar8397 = STG_OFFSET(stgVar8397, sizeof(number_t));
		}
			macroDef8410->arr[r_dps] = macroDef8409;;
			stgVar8396 = STG_OFFSET(stgVar8396, VECTOR_ALL_BYTES(macroDef8410->arr[r_dps]->length));
		}
	macroDef8411 = macroDef8410;;
	storage_free(stgVar8393, size8415);
	return macroDef8411;
}
#endif
