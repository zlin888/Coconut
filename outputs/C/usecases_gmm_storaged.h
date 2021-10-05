#ifndef __USECASES_GMM_STORAGED_H__ 
#define __USECASES_GMM_STORAGED_H__ 
#include "../../Runtime/C/fsharp.h"
#include <stdio.h>
#include <math.h>
#include "linalg_storaged.h"

card_t TOP_LEVEL_usecases_gmm_logsumexp_shp(card_t arr_shp) {
	
	return 0;
}

typedef empty_env_t env_t_23;


value_t lambda23(env_t_23* env9, card_t x_shp) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
typedef struct env_t_24 {
	number_t mx_dps;
} env_t_24;
env_t_24 make_env_t_24(number_t mx_dps) {
	env_t_24 env;
	env.mx_dps = mx_dps;
	return env;
}

value_t lambda24(env_t_24* env13, storage_t stgVar8, number_t x_dps, card_t x_shp) {
	number_t mx_dps12 = env13->mx_dps;
	value_t res;
	res.number_t_value = exp((x_dps) - (mx_dps12));
	return res;
}
typedef empty_env_t env_t_25;


value_t lambda25(env_t_25* env16, card_t x_shp) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
typedef empty_env_t env_t_26;


value_t lambda26(env_t_26* env19, card_t x_shp) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
number_t TOP_LEVEL_usecases_gmm_logsumexp_dps(storage_t stgVar1, array_number_t arr_dps, card_t arr_shp) {
	card_t mx_shp = 0;
	number_t mx_dps = TOP_LEVEL_linalg_vectorMax_dps(empty_storage, arr_dps, arr_shp);
	card_t semx_shp = 0;
	env_t_23 env_t_23_value = make_empty_env(); closure_t closure11 = make_closure(lambda23, &env_t_23_value);
	card_t size27 = width_card_t(TOP_LEVEL_linalg_vectorMap_shp(closure11, arr_shp));
	array_number_t stgVar5 = storage_alloc(size27);
	number_t macroDef22;env_t_24 env_t_24_value = make_env_t_24(mx_dps); closure_t closure15 = make_closure(lambda24, &env_t_24_value);
	env_t_25 env_t_25_value = make_empty_env(); closure_t closure18 = make_closure(lambda25, &env_t_25_value);
	env_t_26 env_t_26_value = make_empty_env(); closure_t closure21 = make_closure(lambda26, &env_t_26_value);
	macroDef22 = TOP_LEVEL_linalg_vectorSum_dps(empty_storage, TOP_LEVEL_linalg_vectorMap_dps(stgVar5, closure15, arr_dps, closure18, arr_shp), TOP_LEVEL_linalg_vectorMap_shp(closure21, arr_shp));;
	storage_free(stgVar5, size27);
	number_t semx_dps = macroDef22;
	return (log(semx_dps)) + (mx_dps);
}

card_t TOP_LEVEL_usecases_gmm_tri_shp(card_t n_shp) {
	
	return 0;
}


index_t TOP_LEVEL_usecases_gmm_tri_dps(storage_t stgVar28, index_t n_dps, card_t n_shp) {
	
	return ((n_dps) * ((n_dps) + (1))) / (2);
}

card_t TOP_LEVEL_usecases_gmm_Qtimesv_shp(card_t q_shp, card_t l_shp, card_t v_shp) {
	
	return v_shp;
}


array_number_t TOP_LEVEL_usecases_gmm_Qtimesv_dps(storage_t stgVar29, array_number_t q_dps, array_number_t l_dps, array_number_t v_dps, card_t q_shp, card_t l_shp, card_t v_shp) {
	card_t macroDef47 = v_dps->length;
	array_number_t macroDef50 = (array_number_t)stgVar29;
		macroDef50->length=macroDef47;
		macroDef50->arr=(number_t*)(STG_OFFSET(macroDef50, VECTOR_HEADER_BYTES));
		storage_t stgVar31 = macroDef50;
		for(int i_dps = 0; i_dps < macroDef50->length; i_dps++){
			card_t tis_shp = 0;
			index_t tis_dps = TOP_LEVEL_usecases_gmm_tri_dps(empty_storage, (i_dps) - (1), 0);
			card_t sum_shp = 0;
			card_t anfvar35_shp = l_shp;
			card_t macroDef48 = l_dps->length;
			card_t anfvar35_dps = macroDef48;
			card_t anfvar36_shp = 0;
			card_t anfvar36_dps = 0;
			number_t macroDef49 = 0;
	storage_t stgVar40 = empty_storage;
	for(int idx_dps = anfvar36_dps; idx_dps < anfvar35_dps; idx_dps++){
		card_t j_shp = 0;
		index_t j_dps = (idx_dps) - (tis_dps);
		card_t isInRange_shp = 0;
		bool_t isInRange_dps = 0;
	if((j_dps) >= (0)) {
		
		isInRange_dps = (j_dps) < (i_dps);;
	} else {
		
		isInRange_dps = false;;
	}
		number_t ite51 = 0;
	if(isInRange_dps) {
		
		ite51 = (macroDef49) + ((l_dps->arr[idx_dps]) * (v_dps->arr[j_dps]));;
	} else {
		
		ite51 = macroDef49;;
	}
		macroDef49 = ite51;;
	}
			number_t sum_dps = macroDef49;
			macroDef50->arr[i_dps] = (sum_dps) + ((exp(q_dps->arr[i_dps])) * (v_dps->arr[i_dps]));;
			stgVar31 = STG_OFFSET(stgVar31, sizeof(number_t));
		}
	return macroDef50;
}

card_t TOP_LEVEL_usecases_gmm_Qtimesv_test_shp(card_t unitVar0_shp) {
	
	return 0;
}


void TOP_LEVEL_usecases_gmm_Qtimesv_test_dps(storage_t stgVar52, int unitVar0_dps, card_t unitVar0_shp) {
	card_t q_shp = TOP_LEVEL_linalg_vec3_shp(0, 0, 0);
	card_t size103 = width_card_t(q_shp);
	array_number_t stgVar53 = storage_alloc(size103);
	array_number_t q_dps = TOP_LEVEL_linalg_vec3_dps(stgVar53, 0.1, -1, 0.3, 0, 0, 0);
	card_t l_shp = TOP_LEVEL_linalg_vec3_shp(0, 0, 0);
	card_t size102 = width_card_t(l_shp);
	array_number_t stgVar57 = storage_alloc(size102);
	array_number_t l_dps = TOP_LEVEL_linalg_vec3_dps(stgVar57, 5, -2, 7.1, 0, 0, 0);
	card_t v_shp = TOP_LEVEL_linalg_vec3_shp(0, 0, 0);
	card_t size101 = width_card_t(v_shp);
	array_number_t stgVar61 = storage_alloc(size101);
	array_number_t v_dps = TOP_LEVEL_linalg_vec3_dps(stgVar61, 1.4, -7, 3.1, 0, 0, 0);
	card_t ans0_shp = 0;
	number_t ans0_dps = (exp(q_dps->arr[0])) * (v_dps->arr[0]);
	card_t ans1_shp = 0;
	number_t ans1_dps = ((l_dps->arr[0]) * (v_dps->arr[0])) + ((exp(q_dps->arr[1])) * (v_dps->arr[1]));
	card_t ans2_shp = 0;
	number_t ans2_dps = (((l_dps->arr[1]) * (v_dps->arr[0])) + ((l_dps->arr[2]) * (v_dps->arr[1]))) + ((exp(q_dps->arr[2])) * (v_dps->arr[2]));
	card_t ans_shp = TOP_LEVEL_linalg_vec3_shp(0, 0, 0);
	card_t size100 = width_card_t(ans_shp);
	array_number_t stgVar80 = storage_alloc(size100);
	array_number_t ans_dps = TOP_LEVEL_linalg_vec3_dps(stgVar80, ans0_dps, ans1_dps, ans2_dps, 0, 0, 0);
	card_t qv_shp = TOP_LEVEL_usecases_gmm_Qtimesv_shp(q_shp, l_shp, v_shp);
	card_t size99 = width_card_t(qv_shp);
	array_number_t stgVar84 = storage_alloc(size99);
	array_number_t qv_dps = TOP_LEVEL_usecases_gmm_Qtimesv_dps(stgVar84, q_dps, l_dps, v_dps, q_shp, l_shp, v_shp);
	card_t nrm_shp = 0;
	card_t size98 = width_card_t(TOP_LEVEL_linalg_vectorSub_shp(qv_shp, ans_shp));
	array_number_t stgVar89 = storage_alloc(size98);
	number_t macroDef92;
	macroDef92 = TOP_LEVEL_linalg_sqnorm_dps(empty_storage, TOP_LEVEL_linalg_vectorSub_dps(stgVar89, qv_dps, ans_dps, qv_shp, ans_shp), TOP_LEVEL_linalg_vectorSub_shp(qv_shp, ans_shp));;
	storage_free(stgVar89, size98);
	number_t nrm_dps = macroDef92;
	number_print(nrm_dps);
	storage_free(stgVar84, size99);
	;
	storage_free(stgVar80, size100);
	;
	storage_free(stgVar61, size101);
	;
	storage_free(stgVar57, size102);
	;
	storage_free(stgVar53, size103);
	return ;
}

card_t TOP_LEVEL_usecases_gmm_gmm_objective_shp(matrix_shape_t x_shp, card_t alphas_shp, matrix_shape_t means_shp, matrix_shape_t qs_shp, matrix_shape_t ls_shp, card_t wishart_gamma_shp, card_t wishart_m_shp) {
	
	return 0;
}

typedef empty_env_t env_t_178;


value_t lambda178(env_t_178* env150, card_t value_shp) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
typedef empty_env_t env_t_179;


value_t lambda179(env_t_179* env153, storage_t stgVar134, number_t value_dps, card_t value_shp) {
	
	value_t res;
	res.number_t_value = exp(value_dps);
	return res;
}
typedef empty_env_t env_t_180;


value_t lambda180(env_t_180* env156, card_t value_shp) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
typedef empty_env_t env_t_182;


value_t lambda182(env_t_182* env160, card_t value_shp) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
number_t TOP_LEVEL_usecases_gmm_gmm_objective_dps(storage_t stgVar104, array_array_number_t x_dps, array_number_t alphas_dps, array_array_number_t means_dps, array_array_number_t qs_dps, array_array_number_t ls_dps, number_t wishart_gamma_dps, number_t wishart_m_dps, matrix_shape_t x_shp, card_t alphas_shp, matrix_shape_t means_shp, matrix_shape_t qs_shp, matrix_shape_t ls_shp, card_t wishart_gamma_shp, card_t wishart_m_shp) {
	card_t n_shp = TOP_LEVEL_linalg_rows_shp(x_shp);
	card_t size187 = width_card_t(n_shp);
	array_number_t stgVar105 = storage_alloc(size187);
	number_t macroDef168;card_t n_dps = TOP_LEVEL_linalg_rows_dps(stgVar105, x_dps, x_shp);
	card_t d_shp = TOP_LEVEL_linalg_cols_shp(x_shp);
	card_t size186 = width_card_t(d_shp);
	array_number_t stgVar107 = storage_alloc(size186);
	number_t macroDef167;card_t d_dps = TOP_LEVEL_linalg_cols_dps(stgVar107, x_dps, x_shp);
	card_t K_shp = alphas_shp;
	card_t macroDef138 = alphas_dps->length;
	card_t K_dps = macroDef138;
	card_t size177 = width_card_t(n_shp);
	array_number_t stgVar111 = storage_alloc(size177);
	number_t macroDef149;array_number_t macroDef148 = (array_number_t)stgVar111;
		macroDef148->length=n_dps;
		macroDef148->arr=(number_t*)(STG_OFFSET(macroDef148, VECTOR_HEADER_BYTES));
		storage_t stgVar112 = macroDef148;
		for(int i_dps = 0; i_dps < macroDef148->length; i_dps++){
			card_t size176 = width_card_t(K_shp);
	array_number_t stgVar113 = storage_alloc(size176);
	number_t macroDef147;array_number_t macroDef146 = (array_number_t)stgVar113;
		macroDef146->length=K_dps;
		macroDef146->arr=(number_t*)(STG_OFFSET(macroDef146, VECTOR_HEADER_BYTES));
		storage_t stgVar114 = macroDef146;
		for(int k_dps = 0; k_dps < macroDef146->length; k_dps++){
			card_t size169 = width_card_t(qs_shp.elem);
	array_number_t stgVar116 = storage_alloc(size169);
	number_t macroDef139;
	macroDef139 = TOP_LEVEL_linalg_vectorSum_dps(empty_storage, qs_dps->arr[k_dps], qs_shp.elem);;
	storage_free(stgVar116, size169);
			card_t size175 = width_card_t(TOP_LEVEL_usecases_gmm_Qtimesv_shp(qs_shp.elem, ls_shp.elem, TOP_LEVEL_linalg_vectorSub_shp(x_shp.elem, means_shp.elem)));
	array_number_t stgVar118 = storage_alloc(size175);
	number_t macroDef145;card_t size174 = width_card_t(TOP_LEVEL_linalg_vectorSub_shp(x_shp.elem, means_shp.elem));
	array_number_t stgVar121 = storage_alloc(size174);
	array_number_t macroDef144;card_t size173 = width_card_t(ls_shp.elem);
	array_number_t stgVar120 = storage_alloc(size173);
	array_number_t macroDef143;card_t size172 = width_card_t(qs_shp.elem);
	array_number_t stgVar119 = storage_alloc(size172);
	array_number_t macroDef142;card_t size171 = width_card_t(means_shp.elem);
	array_number_t stgVar125 = storage_alloc(size171);
	array_number_t macroDef141;card_t size170 = width_card_t(x_shp.elem);
	array_number_t stgVar124 = storage_alloc(size170);
	array_number_t macroDef140;
	macroDef140 = TOP_LEVEL_linalg_vectorSub_dps(stgVar121, x_dps->arr[i_dps], means_dps->arr[k_dps], x_shp.elem, means_shp.elem);;
	storage_free(stgVar124, size170);
	macroDef141 = macroDef140;;
	storage_free(stgVar125, size171);
	macroDef142 = TOP_LEVEL_usecases_gmm_Qtimesv_dps(stgVar118, qs_dps->arr[k_dps], ls_dps->arr[k_dps], macroDef141, qs_shp.elem, ls_shp.elem, TOP_LEVEL_linalg_vectorSub_shp(x_shp.elem, means_shp.elem));;
	storage_free(stgVar119, size172);
	macroDef143 = macroDef142;;
	storage_free(stgVar120, size173);
	macroDef144 = macroDef143;;
	storage_free(stgVar121, size174);
	macroDef145 = TOP_LEVEL_linalg_sqnorm_dps(empty_storage, macroDef144, TOP_LEVEL_usecases_gmm_Qtimesv_shp(qs_shp.elem, ls_shp.elem, TOP_LEVEL_linalg_vectorSub_shp(x_shp.elem, means_shp.elem)));;
	storage_free(stgVar118, size175);
			macroDef146->arr[k_dps] = ((alphas_dps->arr[k_dps]) + (macroDef139)) - ((0.5) * (macroDef145));;
			stgVar114 = STG_OFFSET(stgVar114, sizeof(number_t));
		}
	macroDef147 = TOP_LEVEL_usecases_gmm_logsumexp_dps(stgVar112, macroDef146, K_shp);;
	storage_free(stgVar113, size176);
			macroDef148->arr[i_dps] = macroDef147;;
			stgVar112 = STG_OFFSET(stgVar112, sizeof(number_t));
		}
	macroDef149 = TOP_LEVEL_linalg_vectorSum_dps(empty_storage, macroDef148, n_shp);;
	storage_free(stgVar111, size177);
	card_t size185 = width_card_t(K_shp);
	array_number_t stgVar129 = storage_alloc(size185);
	number_t macroDef166;array_number_t macroDef165 = (array_number_t)stgVar129;
		macroDef165->length=K_dps;
		macroDef165->arr=(number_t*)(STG_OFFSET(macroDef165, VECTOR_HEADER_BYTES));
		storage_t stgVar130 = macroDef165;
		for(int k_dps = 0; k_dps < macroDef165->length; k_dps++){
			env_t_178 env_t_178_value = make_empty_env(); closure_t closure152 = make_closure(lambda178, &env_t_178_value);
			card_t size183 = width_card_t(TOP_LEVEL_linalg_vectorMap_shp(closure152, qs_shp.elem));
	array_number_t stgVar131 = storage_alloc(size183);
	number_t macroDef163;card_t size181 = width_card_t(qs_shp.elem);
	array_number_t stgVar133 = storage_alloc(size181);
	array_number_t macroDef159;env_t_179 env_t_179_value = make_empty_env(); closure_t closure155 = make_closure(lambda179, &env_t_179_value);
	env_t_180 env_t_180_value = make_empty_env(); closure_t closure158 = make_closure(lambda180, &env_t_180_value);
	macroDef159 = TOP_LEVEL_linalg_vectorMap_dps(stgVar131, closure155, qs_dps->arr[k_dps], closure158, qs_shp.elem);;
	storage_free(stgVar133, size181);
	env_t_182 env_t_182_value = make_empty_env(); closure_t closure162 = make_closure(lambda182, &env_t_182_value);
	macroDef163 = TOP_LEVEL_linalg_sqnorm_dps(empty_storage, macroDef159, TOP_LEVEL_linalg_vectorMap_shp(closure162, qs_shp.elem));;
	storage_free(stgVar131, size183);
			card_t size184 = width_card_t(ls_shp.elem);
	array_number_t stgVar136 = storage_alloc(size184);
	number_t macroDef164;
	macroDef164 = TOP_LEVEL_linalg_sqnorm_dps(empty_storage, ls_dps->arr[k_dps], ls_shp.elem);;
	storage_free(stgVar136, size184);
			macroDef165->arr[k_dps] = (macroDef163) + (macroDef164);;
			stgVar130 = STG_OFFSET(stgVar130, sizeof(number_t));
		}
	macroDef166 = TOP_LEVEL_linalg_vectorSum_dps(empty_storage, macroDef165, K_shp);;
	storage_free(stgVar129, size185);
	macroDef167 = ((macroDef149) - (((double)((n_dps))) * (TOP_LEVEL_usecases_gmm_logsumexp_dps(empty_storage, alphas_dps, alphas_shp)))) + ((0.5) * (macroDef166));;
	storage_free(stgVar107, size186);
	macroDef168 = macroDef167;;
	storage_free(stgVar105, size187);
	return macroDef168;
}

card_t TOP_LEVEL_usecases_gmm_test_gmm_shp(card_t dum_shp) {
	
	return 0;
}


void TOP_LEVEL_usecases_gmm_test_gmm_dps(storage_t stgVar188, array_number_t dum_dps, card_t dum_shp) {
	card_t a_shp = 3;
	card_t size216 = width_card_t(a_shp);
	array_number_t stgVar189 = storage_alloc(size216);
	array_number_t macroDef206 = (array_number_t)stgVar189;
	macroDef206->length=3;
	macroDef206->arr=(number_t*)(STG_OFFSET(stgVar189, VECTOR_HEADER_BYTES));
	

	macroDef206->arr[0] = 1;;

	macroDef206->arr[1] = 2;;

	macroDef206->arr[2] = 3;;;
	array_number_t a_dps = macroDef206;
	array_print(a_dps);
	matrix_shape_t mat1_shp = nested_shape_card_t(3, 3);
	card_t size215 = width_matrix_shape_t(mat1_shp);
	array_number_t stgVar193 = storage_alloc(size215);
	array_array_number_t macroDef210 = (array_array_number_t)stgVar193;
	macroDef210->length=3;
	macroDef210->arr=(array_number_t*)(STG_OFFSET(stgVar193, VECTOR_HEADER_BYTES));
	int stgVar193_offsetVar = 0;storage_t stgVar194 = STG_OFFSET(stgVar193, MATRIX_HEADER_BYTES(3) + stgVar193_offsetVar);array_number_t macroDef207 = (array_number_t)stgVar194;
	macroDef207->length=3;
	macroDef207->arr=(number_t*)(STG_OFFSET(stgVar194, VECTOR_HEADER_BYTES));
	

	macroDef207->arr[0] = 1;;

	macroDef207->arr[1] = 2;;

	macroDef207->arr[2] = 3;;;

	macroDef210->arr[0] = macroDef207;;stgVar193_offsetVar += VECTOR_ALL_BYTES(macroDef210->arr[0]->length);storage_t stgVar198 = STG_OFFSET(stgVar193, MATRIX_HEADER_BYTES(3) + stgVar193_offsetVar);array_number_t macroDef208 = (array_number_t)stgVar198;
	macroDef208->length=3;
	macroDef208->arr=(number_t*)(STG_OFFSET(stgVar198, VECTOR_HEADER_BYTES));
	

	macroDef208->arr[0] = 4;;

	macroDef208->arr[1] = 5;;

	macroDef208->arr[2] = 6;;;

	macroDef210->arr[1] = macroDef208;;stgVar193_offsetVar += VECTOR_ALL_BYTES(macroDef210->arr[1]->length);storage_t stgVar202 = STG_OFFSET(stgVar193, MATRIX_HEADER_BYTES(3) + stgVar193_offsetVar);array_number_t macroDef209 = (array_number_t)stgVar202;
	macroDef209->length=3;
	macroDef209->arr=(number_t*)(STG_OFFSET(stgVar202, VECTOR_HEADER_BYTES));
	

	macroDef209->arr[0] = 7;;

	macroDef209->arr[1] = 8;;

	macroDef209->arr[2] = 9;;;

	macroDef210->arr[2] = macroDef209;;stgVar193_offsetVar += VECTOR_ALL_BYTES(macroDef210->arr[2]->length);;
	array_array_number_t mat1_dps = macroDef210;
	matrix_print(mat1_dps);
	;
	storage_free(stgVar193, size215);
	;
	storage_free(stgVar189, size216);
	return ;
}
#endif
