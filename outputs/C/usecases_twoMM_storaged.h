#ifndef __USECASES_TWOMM_STORAGED_H__ 
#define __USECASES_TWOMM_STORAGED_H__ 
#include "../../Runtime/C/fsharp.h"
#include <stdio.h>
#include <math.h>
#include "linalg_storaged.h"
typedef empty_env_t env_t_8;


value_t lambda8(env_t_8* env5, card_t xi_shp) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
card_t TOP_LEVEL_usecases_twoMM__vec_mult_by_scalar_shp(card_t y_shp, card_t x_shp) {
	env_t_8 env_t_8_value = make_empty_env(); closure_t closure7 = make_closure(lambda8, &env_t_8_value);
	return TOP_LEVEL_linalg_vectorMap_shp(closure7, x_shp);
}

typedef struct env_t_16 {
	number_t y_dps;
} env_t_16;
env_t_16 make_env_t_16(number_t y_dps) {
	env_t_16 env;
	env.y_dps = y_dps;
	return env;
}

value_t lambda16(env_t_16* env10, storage_t stgVar4, number_t xi_dps, card_t xi_shp) {
	number_t y_dps9 = env10->y_dps;
	value_t res;
	res.number_t_value = (xi_dps) * (y_dps9);
	return res;
}
typedef empty_env_t env_t_17;


value_t lambda17(env_t_17* env13, card_t xi_shp) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
array_number_t TOP_LEVEL_usecases_twoMM__vec_mult_by_scalar_dps(storage_t stgVar1, number_t y_dps, array_number_t x_dps, card_t y_shp, card_t x_shp) {
	env_t_16 env_t_16_value = make_env_t_16(y_dps); closure_t closure12 = make_closure(lambda16, &env_t_16_value);
	env_t_17 env_t_17_value = make_empty_env(); closure_t closure15 = make_closure(lambda17, &env_t_17_value);
	return TOP_LEVEL_linalg_vectorMap_dps(stgVar1, closure12, x_dps, closure15, x_shp);
}
typedef empty_env_t env_t_27;


value_t lambda27(env_t_27* env24, card_t x_shp0) {
	
	value_t res;
	res.card_t_value = TOP_LEVEL_usecases_twoMM__vec_mult_by_scalar_shp(0, x_shp0);
	return res;
}
matrix_shape_t TOP_LEVEL_usecases_twoMM_matrix_mult_by_scalar_shp(matrix_shape_t x_shp, card_t y_shp) {
	env_t_27 env_t_27_value = make_empty_env(); closure_t closure26 = make_closure(lambda27, &env_t_27_value);
	return TOP_LEVEL_linalg_matrixMap_shp(closure26, x_shp);
}

typedef struct env_t_35 {
	number_t y_dps;
} env_t_35;
env_t_35 make_env_t_35(number_t y_dps) {
	env_t_35 env;
	env.y_dps = y_dps;
	return env;
}

value_t lambda35(env_t_35* env29, storage_t stgVar21, array_number_t x_dps0, card_t x_shp0) {
	number_t y_dps28 = env29->y_dps;
	value_t res;
	res.array_number_t_value = TOP_LEVEL_usecases_twoMM__vec_mult_by_scalar_dps(stgVar21, y_dps28, x_dps0, 0, x_shp0);
	return res;
}
typedef empty_env_t env_t_36;


value_t lambda36(env_t_36* env32, card_t x_shp0) {
	
	value_t res;
	res.card_t_value = TOP_LEVEL_usecases_twoMM__vec_mult_by_scalar_shp(0, x_shp0);
	return res;
}
array_array_number_t TOP_LEVEL_usecases_twoMM_matrix_mult_by_scalar_dps(storage_t stgVar18, array_array_number_t x_dps, number_t y_dps, matrix_shape_t x_shp, card_t y_shp) {
	env_t_35 env_t_35_value = make_env_t_35(y_dps); closure_t closure31 = make_closure(lambda35, &env_t_35_value);
	env_t_36 env_t_36_value = make_empty_env(); closure_t closure34 = make_closure(lambda36, &env_t_36_value);
	return TOP_LEVEL_linalg_matrixMap_dps(stgVar18, closure31, x_dps, closure34, x_shp);
}

matrix_shape_t TOP_LEVEL_usecases_twoMM_twoMM_shp(card_t alpha_shp, card_t beta_shp, matrix_shape_t A_shp, matrix_shape_t B_shp, matrix_shape_t C_shp, matrix_shape_t D_shp) {
	
	return TOP_LEVEL_linalg_matrixAdd_shp(TOP_LEVEL_linalg_matrixMult_shp(TOP_LEVEL_usecases_twoMM_matrix_mult_by_scalar_shp(TOP_LEVEL_linalg_matrixMult_shp(A_shp, B_shp), 0), C_shp), TOP_LEVEL_usecases_twoMM_matrix_mult_by_scalar_shp(D_shp, 0));
}


array_array_number_t TOP_LEVEL_usecases_twoMM_twoMM_dps(storage_t stgVar37, number_t alpha_dps, number_t beta_dps, array_array_number_t A_dps, array_array_number_t B_dps, array_array_number_t C_dps, array_array_number_t D_dps, card_t alpha_shp, card_t beta_shp, matrix_shape_t A_shp, matrix_shape_t B_shp, matrix_shape_t C_shp, matrix_shape_t D_shp) {
	matrix_shape_t A_shp0 = A_shp;
	array_array_number_t A_dps0 = A_dps;
	matrix_shape_t B_shp0 = B_shp;
	array_array_number_t B_dps0 = B_dps;
	matrix_shape_t C_shp0 = C_shp;
	array_array_number_t C_dps0 = C_dps;
	matrix_shape_t D_shp0 = D_shp;
	array_array_number_t D_dps0 = D_dps;
	matrix_shape_t tmp_shp = TOP_LEVEL_usecases_twoMM_matrix_mult_by_scalar_shp(TOP_LEVEL_linalg_matrixMult_shp(A_shp0, B_shp0), 0);
	card_t size80 = width_matrix_shape_t(tmp_shp);
	array_number_t stgVar42 = storage_alloc(size80);
	array_array_number_t macroDef76;card_t size77 = width_matrix_shape_t(TOP_LEVEL_linalg_matrixMult_shp(A_shp0, B_shp0));
	array_number_t stgVar43 = storage_alloc(size77);
	array_array_number_t macroDef73;
	macroDef73 = TOP_LEVEL_usecases_twoMM_matrix_mult_by_scalar_dps(stgVar42, TOP_LEVEL_linalg_matrixMult_dps(stgVar43, A_dps0, B_dps0, A_shp0, B_shp0), alpha_dps, TOP_LEVEL_linalg_matrixMult_shp(A_shp0, B_shp0), 0);;
	storage_free(stgVar43, size77);
	array_array_number_t tmp_dps = macroDef73;
	card_t size79 = width_matrix_shape_t(TOP_LEVEL_usecases_twoMM_matrix_mult_by_scalar_shp(D_shp0, 0));
	array_number_t stgVar48 = storage_alloc(size79);
	array_array_number_t macroDef75;card_t size78 = width_matrix_shape_t(TOP_LEVEL_linalg_matrixMult_shp(tmp_shp, C_shp0));
	array_number_t stgVar47 = storage_alloc(size78);
	array_array_number_t macroDef74;
	macroDef74 = TOP_LEVEL_linalg_matrixAdd_dps(stgVar37, TOP_LEVEL_linalg_matrixMult_dps(stgVar47, tmp_dps, C_dps0, tmp_shp, C_shp0), TOP_LEVEL_usecases_twoMM_matrix_mult_by_scalar_dps(stgVar48, D_dps0, beta_dps, D_shp0, 0), TOP_LEVEL_linalg_matrixMult_shp(tmp_shp, C_shp0), TOP_LEVEL_usecases_twoMM_matrix_mult_by_scalar_shp(D_shp0, 0));;
	storage_free(stgVar47, size78);
	macroDef75 = macroDef74;;
	storage_free(stgVar48, size79);
	macroDef76 = macroDef75;;
	storage_free(stgVar42, size80);
	return macroDef76;
}

matrix_shape_t TOP_LEVEL_usecases_twoMM_threeMM_shp(matrix_shape_t A_shp, matrix_shape_t B_shp, matrix_shape_t C_shp, matrix_shape_t D_shp) {
	
	return TOP_LEVEL_linalg_matrixMult_shp(TOP_LEVEL_linalg_matrixMult_shp(A_shp, B_shp), TOP_LEVEL_linalg_matrixMult_shp(C_shp, D_shp));
}


array_array_number_t TOP_LEVEL_usecases_twoMM_threeMM_dps(storage_t stgVar81, array_array_number_t A_dps, array_array_number_t B_dps, array_array_number_t C_dps, array_array_number_t D_dps, matrix_shape_t A_shp, matrix_shape_t B_shp, matrix_shape_t C_shp, matrix_shape_t D_shp) {
	matrix_shape_t A_shp0 = A_shp;
	array_array_number_t A_dps0 = A_dps;
	matrix_shape_t B_shp0 = B_shp;
	array_array_number_t B_dps0 = B_dps;
	matrix_shape_t C_shp0 = C_shp;
	array_array_number_t C_dps0 = C_dps;
	matrix_shape_t D_shp0 = D_shp;
	array_array_number_t D_dps0 = D_dps;
	card_t size107 = width_matrix_shape_t(TOP_LEVEL_linalg_matrixMult_shp(C_shp0, D_shp0));
	array_number_t stgVar87 = storage_alloc(size107);
	array_array_number_t macroDef105;card_t size106 = width_matrix_shape_t(TOP_LEVEL_linalg_matrixMult_shp(A_shp0, B_shp0));
	array_number_t stgVar86 = storage_alloc(size106);
	array_array_number_t macroDef104;
	macroDef104 = TOP_LEVEL_linalg_matrixMult_dps(stgVar81, TOP_LEVEL_linalg_matrixMult_dps(stgVar86, A_dps0, B_dps0, A_shp0, B_shp0), TOP_LEVEL_linalg_matrixMult_dps(stgVar87, C_dps0, D_dps0, C_shp0, D_shp0), TOP_LEVEL_linalg_matrixMult_shp(A_shp0, B_shp0), TOP_LEVEL_linalg_matrixMult_shp(C_shp0, D_shp0));;
	storage_free(stgVar86, size106);
	macroDef105 = macroDef104;;
	storage_free(stgVar87, size107);
	return macroDef105;
}
#endif
