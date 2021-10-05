#ifndef __USECASES_FFT_STORAGED_H__ 
#define __USECASES_FFT_STORAGED_H__ 
#include "../../Runtime/C/fsharp.h"
#include <stdio.h>
#include <math.h>
#include "linalg_storaged.h"

card_t TOP_LEVEL_usecases_fft_get_N_shp() {
	
	return 0;
}


index_t TOP_LEVEL_usecases_fft_get_N_dps() {
	
	return 8;
}

card_t TOP_LEVEL_usecases_fft_get_LEN_shp() {
	
	return 0;
}


index_t TOP_LEVEL_usecases_fft_get_LEN_dps() {
	
	return 12;
}

card_t TOP_LEVEL_usecases_fft_get_P_shp() {
	
	return 0;
}


index_t TOP_LEVEL_usecases_fft_get_P_dps() {
	
	return 3;
}

card_t TOP_LEVEL_usecases_fft_reverse_bits_shp(card_t i_shp) {
	
	return 0;
}


index_t TOP_LEVEL_usecases_fft_reverse_bits_dps(storage_t stgVar1, index_t i_dps, card_t i_shp) {
	
	return 1;
}

card_t TOP_LEVEL_usecases_fft_complex_mul_shp(card_t c0_shp, card_t c1_shp) {
	
	return 2;
}


array_number_t TOP_LEVEL_usecases_fft_complex_mul_dps(storage_t stgVar2, array_number_t c0_dps, array_number_t c1_dps, card_t c0_shp, card_t c1_shp) {
	array_number_t macroDef13 = (array_number_t)stgVar2;
	macroDef13->length=2;
	macroDef13->arr=(number_t*)(STG_OFFSET(stgVar2, VECTOR_HEADER_BYTES));
	

	macroDef13->arr[0] = ((c0_dps->arr[0]) * (c1_dps->arr[0])) - ((c0_dps->arr[1]) * (c1_dps->arr[1]));;

	macroDef13->arr[1] = ((c0_dps->arr[0]) * (c1_dps->arr[1])) + ((c0_dps->arr[1]) * (c1_dps->arr[0]));;;
	return macroDef13;
}

card_t TOP_LEVEL_usecases_fft_complex_sub_shp(card_t c0_shp, card_t c1_shp) {
	
	return 2;
}


array_number_t TOP_LEVEL_usecases_fft_complex_sub_dps(storage_t stgVar14, array_number_t c0_dps, array_number_t c1_dps, card_t c0_shp, card_t c1_shp) {
	array_number_t macroDef21 = (array_number_t)stgVar14;
	macroDef21->length=2;
	macroDef21->arr=(number_t*)(STG_OFFSET(stgVar14, VECTOR_HEADER_BYTES));
	

	macroDef21->arr[0] = (c0_dps->arr[0]) + (c1_dps->arr[0]);;

	macroDef21->arr[1] = (c1_dps->arr[1]) + (c1_dps->arr[1]);;;
	return macroDef21;
}

card_t TOP_LEVEL_usecases_fft_complex_add_shp(card_t c0_shp, card_t c1_shp) {
	
	return 2;
}


array_number_t TOP_LEVEL_usecases_fft_complex_add_dps(storage_t stgVar22, array_number_t c0_dps, array_number_t c1_dps, card_t c0_shp, card_t c1_shp) {
	array_number_t macroDef29 = (array_number_t)stgVar22;
	macroDef29->length=2;
	macroDef29->arr=(number_t*)(STG_OFFSET(stgVar22, VECTOR_HEADER_BYTES));
	

	macroDef29->arr[0] = (c0_dps->arr[0]) - (c1_dps->arr[0]);;

	macroDef29->arr[1] = (c1_dps->arr[1]) - (c1_dps->arr[1]);;;
	return macroDef29;
}

matrix_shape_t TOP_LEVEL_usecases_fft_fft_shp(matrix_shape_t primal_shp, card_t ndiv2_shp, card_t logn_shp, card_t p_shp, card_t offset0_shp, card_t offset1_shp, matrix_shape_t omegas_shp) {
	
	return nested_shape_card_t(primal_shp.elem, primal_shp.card);
}

typedef struct env_t_120 {
	matrix_shape_t primal_shp;
} env_t_120;
env_t_120 make_env_t_120(matrix_shape_t primal_shp) {
	env_t_120 env;
	env.primal_shp = primal_shp;
	return env;
}

value_t lambda120(env_t_120* env74, card_t i_shp) {
	matrix_shape_t primal_shp73 = env74->primal_shp;
	card_t j_shp = 0;
	card_t jj_shp = 0;
	value_t res;
	res.card_t_value = primal_shp73.elem;
	return res;
}
typedef struct env_t_121 {
	matrix_shape_t dual_shp;
} env_t_121;
env_t_121 make_env_t_121(matrix_shape_t dual_shp) {
	env_t_121 env;
	env.dual_shp = dual_shp;
	return env;
}

value_t lambda121(env_t_121* env81, card_t k_shp) {
	matrix_shape_t dual_shp80 = env81->dual_shp;
	card_t i_shp = 0;
	value_t res;
	res.card_t_value = dual_shp80.elem;
	return res;
}
typedef struct env_t_122 {
	matrix_shape_t omegas_shp;
	matrix_shape_t dual_shp;
} env_t_122;
env_t_122 make_env_t_122(matrix_shape_t omegas_shp,matrix_shape_t dual_shp) {
	env_t_122 env;
	env.omegas_shp = omegas_shp;
	env.dual_shp = dual_shp;
	return env;
}

value_t lambda122(env_t_122* env88, card_t k_shp) {
	matrix_shape_t omegas_shp87 = env88->omegas_shp;
	matrix_shape_t dual_shp86 = env88->dual_shp;
	card_t i_shp = 0;
	value_t res;
	res.card_t_value = TOP_LEVEL_usecases_fft_complex_mul_shp(omegas_shp87.elem, dual_shp86.elem);
	return res;
}
array_array_number_t TOP_LEVEL_usecases_fft_fft_dps(storage_t stgVar30, array_array_number_t primal_dps, array_number_t ndiv2_dps, array_number_t logn_dps, array_number_t p_dps, array_number_t offset0_dps, array_number_t offset1_dps, array_array_number_t omegas_dps, matrix_shape_t primal_shp, card_t ndiv2_shp, card_t logn_shp, card_t p_shp, card_t offset0_shp, card_t offset1_shp, matrix_shape_t omegas_shp) {
	env_t_120 env_t_120_value = make_env_t_120(primal_shp); closure_t closure76 = make_closure(lambda120, &env_t_120_value);
	matrix_shape_t init_dual_shp = nested_shape_card_t(closure76.lam(closure76.env, 0).card_t_value, primal_shp.card);
	card_t size131 = width_matrix_shape_t(init_dual_shp);
	array_number_t stgVar31 = storage_alloc(size131);
	array_array_number_t macroDef118;card_t macroDef77 = primal_dps->length;
	array_array_number_t macroDef78 = (array_array_number_t)stgVar31;
		macroDef78->length=macroDef77;
		macroDef78->arr=(array_number_t*)(STG_OFFSET(macroDef78, VECTOR_HEADER_BYTES));
		storage_t stgVar33 = (STG_OFFSET(macroDef78, MATRIX_HEADER_BYTES(macroDef77)));
		for(int i_dps = 0; i_dps < macroDef78->length; i_dps++){
			card_t j_shp = 0;
			index_t j_dps = TOP_LEVEL_usecases_fft_reverse_bits_dps(empty_storage, i_dps, 0);
			card_t jj_shp = 0;
			index_t jj_dps = (j_dps) >> ((32) - (3));
			macroDef78->arr[i_dps] = primal_dps->arr[jj_dps];;
			stgVar33 = STG_OFFSET(stgVar33, VECTOR_ALL_BYTES(macroDef78->arr[i_dps]->length));
		}
	array_array_number_t init_dual_dps = macroDef78;
	card_t anfvar38_shp = logn_shp;
	card_t macroDef79 = logn_dps->length;
	card_t anfvar38_dps = macroDef79;
	card_t anfvar39_shp = 0;
	card_t anfvar39_dps = 0;
	array_array_number_t macroDef117 = init_dual_dps;
	storage_t stgVar43 = stgVar30;
	for(int j_dps = anfvar39_dps; j_dps < anfvar38_dps; j_dps++){
		env_t_121 env_t_121_value = make_env_t_121(init_dual_shp); closure_t closure83 = make_closure(lambda121, &env_t_121_value);
		matrix_shape_t us_shp = nested_shape_card_t(closure83.lam(closure83.env, 0).card_t_value, ndiv2_shp);
		card_t size130 = width_matrix_shape_t(us_shp);
	array_number_t stgVar44 = storage_alloc(size130);
	array_array_number_t macroDef102;card_t macroDef84 = ndiv2_dps->length;
	array_array_number_t macroDef85 = (array_array_number_t)stgVar44;
		macroDef85->length=macroDef84;
		macroDef85->arr=(array_number_t*)(STG_OFFSET(macroDef85, VECTOR_HEADER_BYTES));
		storage_t stgVar46 = (STG_OFFSET(macroDef85, MATRIX_HEADER_BYTES(macroDef84)));
		for(int k_dps = 0; k_dps < macroDef85->length; k_dps++){
			card_t i_shp = 0;
			index_t i_dps = ((j_dps) * (4)) + (k_dps);
			macroDef85->arr[k_dps] = macroDef117->arr[(int)(offset0_dps->arr[i_dps])];;
			stgVar46 = STG_OFFSET(stgVar46, VECTOR_ALL_BYTES(macroDef85->arr[k_dps]->length));
		}
	array_array_number_t us_dps = macroDef85;
	env_t_122 env_t_122_value = make_env_t_122(omegas_shp,init_dual_shp); closure_t closure90 = make_closure(lambda122, &env_t_122_value);
	matrix_shape_t ms_shp = nested_shape_card_t(closure90.lam(closure90.env, 0).card_t_value, ndiv2_shp);
	card_t size129 = width_matrix_shape_t(ms_shp);
	array_number_t stgVar50 = storage_alloc(size129);
	array_array_number_t macroDef101;card_t macroDef91 = ndiv2_dps->length;
	array_array_number_t macroDef94 = (array_array_number_t)stgVar50;
		macroDef94->length=macroDef91;
		macroDef94->arr=(array_number_t*)(STG_OFFSET(macroDef94, VECTOR_HEADER_BYTES));
		storage_t stgVar52 = (STG_OFFSET(macroDef94, MATRIX_HEADER_BYTES(macroDef91)));
		for(int k_dps = 0; k_dps < macroDef94->length; k_dps++){
			card_t i_shp = 0;
			index_t i_dps = ((j_dps) * (4)) + (k_dps);
			card_t size124 = width_card_t(init_dual_shp.elem);
	array_number_t stgVar55 = storage_alloc(size124);
	array_number_t macroDef93;card_t size123 = width_card_t(omegas_shp.elem);
	array_number_t stgVar54 = storage_alloc(size123);
	array_number_t macroDef92;
	macroDef92 = TOP_LEVEL_usecases_fft_complex_mul_dps(stgVar52, omegas_dps->arr[i_dps], macroDef117->arr[(int)(offset1_dps->arr[i_dps])], omegas_shp.elem, init_dual_shp.elem);;
	storage_free(stgVar54, size123);
	macroDef93 = macroDef92;;
	storage_free(stgVar55, size124);
			macroDef94->arr[k_dps] = macroDef93;;
			stgVar52 = STG_OFFSET(stgVar52, VECTOR_ALL_BYTES(macroDef94->arr[k_dps]->length));
		}
	array_array_number_t ms_dps = macroDef94;
	card_t macroDef95 = primal_dps->length;
	array_array_number_t macroDef100 = (array_array_number_t)stgVar43;
		macroDef100->length=macroDef95;
		macroDef100->arr=(array_number_t*)(STG_OFFSET(macroDef100, VECTOR_HEADER_BYTES));
		storage_t stgVar60 = (STG_OFFSET(macroDef100, MATRIX_HEADER_BYTES(macroDef95)));
		for(int k_dps = 0; k_dps < macroDef100->length; k_dps++){
			card_t i_shp = 0;
			index_t i_dps = (k_dps) % (4);
			card_t c_shp = 0;
			bool_t c_dps = (k_dps) < (4);
			array_number_t ite119 ;
	if((k_dps) < (4)) {
		card_t size126 = width_card_t(ms_shp.elem);
	array_number_t stgVar64 = storage_alloc(size126);
	array_number_t macroDef97;card_t size125 = width_card_t(us_shp.elem);
	array_number_t stgVar63 = storage_alloc(size125);
	array_number_t macroDef96;
	macroDef96 = TOP_LEVEL_usecases_fft_complex_add_dps(stgVar60, us_dps->arr[i_dps], ms_dps->arr[i_dps], us_shp.elem, ms_shp.elem);;
	storage_free(stgVar63, size125);
	macroDef97 = macroDef96;;
	storage_free(stgVar64, size126);
		ite119 = macroDef97;;
	} else {
		card_t size128 = width_card_t(ms_shp.elem);
	array_number_t stgVar68 = storage_alloc(size128);
	array_number_t macroDef99;card_t size127 = width_card_t(us_shp.elem);
	array_number_t stgVar67 = storage_alloc(size127);
	array_number_t macroDef98;
	macroDef98 = TOP_LEVEL_usecases_fft_complex_sub_dps(stgVar60, us_dps->arr[i_dps], ms_dps->arr[i_dps], us_shp.elem, ms_shp.elem);;
	storage_free(stgVar67, size127);
	macroDef99 = macroDef98;;
	storage_free(stgVar68, size128);
		ite119 = macroDef99;;
	}
			macroDef100->arr[k_dps] = ite119;;
			stgVar60 = STG_OFFSET(stgVar60, VECTOR_ALL_BYTES(macroDef100->arr[k_dps]->length));
		}
	macroDef101 = macroDef100;;
	storage_free(stgVar50, size129);
	macroDef102 = macroDef101;;
	storage_free(stgVar44, size130);
		macroDef117 = macroDef102;;
	}
	macroDef118 = macroDef117;;
	storage_free(stgVar31, size131);
	return macroDef118;
}
#endif
