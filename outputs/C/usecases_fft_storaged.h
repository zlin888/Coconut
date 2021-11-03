#ifndef __USECASES_FFT_STORAGED_H__ 
#define __USECASES_FFT_STORAGED_H__ 
#include "../../Runtime/C/fsharp.h"
#include <stdio.h>
#include <math.h>
#include "linalg_storaged.h"
#include "reverse_bits.h"

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


index_t TOP_LEVEL_usecases_fft_reverse_bits_dps(storage_t stgVar532, index_t i_dps, card_t i_shp) {
	
	return 1;
}

card_t TOP_LEVEL_usecases_fft_complex_mul_shp(card_t c0_shp, card_t c1_shp) {
	
	return 2;
}


array_number_t TOP_LEVEL_usecases_fft_complex_mul_dps(storage_t stgVar533, array_number_t c0_dps, array_number_t c1_dps, card_t c0_shp, card_t c1_shp) {
	array_number_t macroDef544 = (array_number_t)stgVar533;
	macroDef544->length=2;
	macroDef544->arr=(number_t*)(STG_OFFSET(stgVar533, VECTOR_HEADER_BYTES));
	

	macroDef544->arr[0] = ((c0_dps->arr[0]) * (c1_dps->arr[0])) - ((c0_dps->arr[1]) * (c1_dps->arr[1]));;

	macroDef544->arr[1] = ((c0_dps->arr[0]) * (c1_dps->arr[1])) + ((c0_dps->arr[1]) * (c1_dps->arr[0]));;;
	return macroDef544;
}

card_t TOP_LEVEL_usecases_fft_complex_sub_shp(card_t c0_shp, card_t c1_shp) {
	
	return 2;
}


array_number_t TOP_LEVEL_usecases_fft_complex_sub_dps(storage_t stgVar545, array_number_t c0_dps, array_number_t c1_dps, card_t c0_shp, card_t c1_shp) {
	array_number_t macroDef552 = (array_number_t)stgVar545;
	macroDef552->length=2;
	macroDef552->arr=(number_t*)(STG_OFFSET(stgVar545, VECTOR_HEADER_BYTES));
	

	macroDef552->arr[0] = (c0_dps->arr[0]) + (c1_dps->arr[0]);;

	macroDef552->arr[1] = (c1_dps->arr[1]) + (c1_dps->arr[1]);;;
	return macroDef552;
}

card_t TOP_LEVEL_usecases_fft_complex_add_shp(card_t c0_shp, card_t c1_shp) {
	
	return 2;
}


array_number_t TOP_LEVEL_usecases_fft_complex_add_dps(storage_t stgVar553, array_number_t c0_dps, array_number_t c1_dps, card_t c0_shp, card_t c1_shp) {
	array_number_t macroDef560 = (array_number_t)stgVar553;
	macroDef560->length=2;
	macroDef560->arr=(number_t*)(STG_OFFSET(stgVar553, VECTOR_HEADER_BYTES));
	

	macroDef560->arr[0] = (c0_dps->arr[0]) - (c1_dps->arr[0]);;

	macroDef560->arr[1] = (c1_dps->arr[1]) - (c1_dps->arr[1]);;;
	return macroDef560;
}

matrix_shape_t TOP_LEVEL_usecases_fft_fft_shp(matrix_shape_t primal_shp, card_t ndiv2_shp, card_t logn_shp, card_t p_shp, card_t offset0_shp, card_t offset1_shp, matrix_shape_t omegas_shp) {
	
	return nested_shape_card_t(primal_shp.elem, primal_shp.card);
}

typedef struct env_t_678 {
	matrix_shape_t primal_shp;
} env_t_678;
env_t_678 make_env_t_678(matrix_shape_t primal_shp) {
	env_t_678 env;
	env.primal_shp = primal_shp;
	return env;
}

value_t lambda678(env_t_678* env614, card_t i_shp) {
	matrix_shape_t primal_shp613 = env614->primal_shp;
	card_t j_shp = 0;
	card_t jj_shp = 0;
	value_t res;
	res.card_t_value = primal_shp613.elem;
	return res;
}
typedef struct env_t_679 {
	matrix_shape_t dual_shp;
} env_t_679;
env_t_679 make_env_t_679(matrix_shape_t dual_shp) {
	env_t_679 env;
	env.dual_shp = dual_shp;
	return env;
}

value_t lambda679(env_t_679* env621, card_t k_shp) {
	matrix_shape_t dual_shp620 = env621->dual_shp;
	card_t i_shp = 0;
	value_t res;
	res.card_t_value = dual_shp620.elem;
	return res;
}
typedef struct env_t_680 {
	matrix_shape_t omegas_shp;
	matrix_shape_t dual_shp;
} env_t_680;
env_t_680 make_env_t_680(matrix_shape_t omegas_shp,matrix_shape_t dual_shp) {
	env_t_680 env;
	env.omegas_shp = omegas_shp;
	env.dual_shp = dual_shp;
	return env;
}

value_t lambda680(env_t_680* env628, card_t k_shp) {
	matrix_shape_t omegas_shp627 = env628->omegas_shp;
	matrix_shape_t dual_shp626 = env628->dual_shp;
	card_t i_shp = 0;
	value_t res;
	res.card_t_value = TOP_LEVEL_usecases_fft_complex_mul_shp(omegas_shp627.elem, dual_shp626.elem);
	return res;
}
typedef struct env_t_683 {
	matrix_shape_t us_shp;
	matrix_shape_t ms_shp;
} env_t_683;
env_t_683 make_env_t_683(matrix_shape_t us_shp,matrix_shape_t ms_shp) {
	env_t_683 env;
	env.us_shp = us_shp;
	env.ms_shp = ms_shp;
	return env;
}

value_t lambda683(env_t_683* env637, card_t k_shp) {
	matrix_shape_t us_shp636 = env637->us_shp;
	matrix_shape_t ms_shp635 = env637->ms_shp;
	card_t i_shp = 0;
	card_t c_shp = 0;
	value_t res;
	res.card_t_value = TOP_LEVEL_usecases_fft_complex_add_shp(us_shp636.elem, ms_shp635.elem);
	return res;
}
typedef struct env_t_688 {
	matrix_shape_t dual_concat_shp;
} env_t_688;
env_t_688 make_env_t_688(matrix_shape_t dual_concat_shp) {
	env_t_688 env;
	env.dual_concat_shp = dual_concat_shp;
	return env;
}

value_t lambda688(env_t_688* env647, card_t k_shp) {
	matrix_shape_t dual_concat_shp646 = env647->dual_concat_shp;
	card_t i_shp = 0;
	value_t res;
	res.card_t_value = dual_concat_shp646.elem;
	return res;
}
array_array_number_t TOP_LEVEL_usecases_fft_fft_dps(storage_t stgVar561, array_array_number_t primal_dps, array_number_t ndiv2_dps, array_number_t logn_dps, array_number_t p_dps, array_number_t offset0_dps, array_number_t offset1_dps, array_array_number_t omegas_dps, matrix_shape_t primal_shp, card_t ndiv2_shp, card_t logn_shp, card_t p_shp, card_t offset0_shp, card_t offset1_shp, matrix_shape_t omegas_shp) {
	env_t_678 env_t_678_value = make_env_t_678(primal_shp); closure_t closure616 = make_closure(lambda678, &env_t_678_value);
	matrix_shape_t init_dual_shp = nested_shape_card_t(closure616.lam(closure616.env, 0).card_t_value, primal_shp.card);
	card_t size693 = width_matrix_shape_t(init_dual_shp);
	array_number_t stgVar562 = storage_alloc(size693);
	array_array_number_t macroDef675;card_t macroDef617 = primal_dps->length;
	array_array_number_t macroDef618 = (array_array_number_t)stgVar562;
		macroDef618->length=macroDef617;
		macroDef618->arr=(array_number_t*)(STG_OFFSET(macroDef618, VECTOR_HEADER_BYTES));
		storage_t stgVar564 = (STG_OFFSET(macroDef618, MATRIX_HEADER_BYTES(macroDef617)));
		for(int i_dps = 0; i_dps < macroDef618->length; i_dps++){
			card_t jj_shp = 0;
			index_t jj_dps = 0;
            reverse_bits(i_dps, log(dim) / log(2), &jj_dps);
			macroDef618->arr[i_dps] = primal_dps->arr[jj_dps];;
			stgVar564 = STG_OFFSET(stgVar564, VECTOR_ALL_BYTES(macroDef618->arr[i_dps]->length));
		}
	array_array_number_t init_dual_dps = macroDef618;

#ifdef DEBUG
    printf("INITDUAL\n");
    matrix_print(init_dual_dps);
#endif

	card_t anfvar569_shp = logn_shp;
	card_t macroDef619 = logn_dps->length;
	card_t anfvar569_dps = macroDef619;
	card_t anfvar570_shp = 0;
	card_t anfvar570_dps = 0;
	array_array_number_t macroDef674 = init_dual_dps;
	storage_t stgVar574 = stgVar561;
	for(int j_dps = anfvar570_dps; j_dps < anfvar569_dps; j_dps++){
		env_t_679 env_t_679_value = make_env_t_679(init_dual_shp); closure_t closure623 = make_closure(lambda679, &env_t_679_value);
		matrix_shape_t us_shp = nested_shape_card_t(closure623.lam(closure623.env, 0).card_t_value, ndiv2_shp);
		card_t size692 = width_matrix_shape_t(us_shp);
	array_number_t stgVar575 = storage_alloc(size692);
	array_array_number_t macroDef655;card_t macroDef624 = ndiv2_dps->length;
	array_array_number_t macroDef625 = (array_array_number_t)stgVar575;
		macroDef625->length=macroDef624;
		macroDef625->arr=(array_number_t*)(STG_OFFSET(macroDef625, VECTOR_HEADER_BYTES));
		storage_t stgVar577 = (STG_OFFSET(macroDef625, MATRIX_HEADER_BYTES(macroDef624)));
		for(int k_dps = 0; k_dps < macroDef625->length; k_dps++){
			card_t i_shp = 0;
			index_t i_dps = ((j_dps) * (dim / 2)) + (k_dps);
			macroDef625->arr[k_dps] = macroDef674->arr[(int)(offset0_dps->arr[i_dps])];;
			stgVar577 = STG_OFFSET(stgVar577, VECTOR_ALL_BYTES(macroDef625->arr[k_dps]->length));
		}
	array_array_number_t us_dps = macroDef625;
	env_t_680 env_t_680_value = make_env_t_680(omegas_shp,init_dual_shp); closure_t closure630 = make_closure(lambda680, &env_t_680_value);
	matrix_shape_t ms_shp = nested_shape_card_t(closure630.lam(closure630.env, 0).card_t_value, ndiv2_shp);
	card_t size691 = width_matrix_shape_t(ms_shp);
	array_number_t stgVar581 = storage_alloc(size691);
	array_array_number_t macroDef654;card_t macroDef631 = ndiv2_dps->length;
	array_array_number_t macroDef634 = (array_array_number_t)stgVar581;
		macroDef634->length=macroDef631;
		macroDef634->arr=(array_number_t*)(STG_OFFSET(macroDef634, VECTOR_HEADER_BYTES));
		storage_t stgVar583 = (STG_OFFSET(macroDef634, MATRIX_HEADER_BYTES(macroDef631)));
		for(int k_dps = 0; k_dps < macroDef634->length; k_dps++){
			card_t i_shp = 0;
			index_t i_dps = ((j_dps) * (dim / 2)) + (k_dps);
			card_t size682 = width_card_t(init_dual_shp.elem);
	array_number_t stgVar586 = storage_alloc(size682);
	array_number_t macroDef633;card_t size681 = width_card_t(omegas_shp.elem);
	array_number_t stgVar585 = storage_alloc(size681);
	array_number_t macroDef632;
	macroDef632 = TOP_LEVEL_usecases_fft_complex_mul_dps(stgVar583, omegas_dps->arr[i_dps], macroDef674->arr[(int)(offset1_dps->arr[i_dps])], omegas_shp.elem, init_dual_shp.elem);;
	storage_free(stgVar585, size681);
	macroDef633 = macroDef632;;
	storage_free(stgVar586, size682);
			macroDef634->arr[k_dps] = macroDef633;;
			stgVar583 = STG_OFFSET(stgVar583, VECTOR_ALL_BYTES(macroDef634->arr[k_dps]->length));
		}
	array_array_number_t ms_dps = macroDef634;
	env_t_683 env_t_683_value = make_env_t_683(us_shp,ms_shp); closure_t closure639 = make_closure(lambda683, &env_t_683_value);
	matrix_shape_t dual_concat_shp = nested_shape_card_t(closure639.lam(closure639.env, 0).card_t_value, primal_shp.card);
	card_t size690 = width_matrix_shape_t(dual_concat_shp);
	array_number_t stgVar590 = storage_alloc(size690);
	array_array_number_t macroDef653;card_t macroDef640 = primal_dps->length;
	array_array_number_t macroDef645 = (array_array_number_t)stgVar590;
		macroDef645->length=macroDef640;
		macroDef645->arr=(array_number_t*)(STG_OFFSET(macroDef645, VECTOR_HEADER_BYTES));
		storage_t stgVar592 = (STG_OFFSET(macroDef645, MATRIX_HEADER_BYTES(macroDef640)));
		for(int k_dps = 0; k_dps < macroDef645->length; k_dps++){
			card_t i_shp = 0;
			index_t i_dps = (k_dps) % (dim / 2);
			card_t c_shp = 0;
			bool_t c_dps = (k_dps) < (dim / 2);
			array_number_t ite676 ;
	if((k_dps) < (dim / 2)) {
		card_t size685 = width_card_t(ms_shp.elem);
	array_number_t stgVar596 = storage_alloc(size685);
	array_number_t macroDef642;card_t size684 = width_card_t(us_shp.elem);
	array_number_t stgVar595 = storage_alloc(size684);
	array_number_t macroDef641;
	macroDef641 = TOP_LEVEL_usecases_fft_complex_add_dps(stgVar592, us_dps->arr[i_dps], ms_dps->arr[i_dps], us_shp.elem, ms_shp.elem);;
	storage_free(stgVar595, size684);
	macroDef642 = macroDef641;;
	storage_free(stgVar596, size685);
		ite676 = macroDef642;;
	} else {
		card_t size687 = width_card_t(ms_shp.elem);
	array_number_t stgVar600 = storage_alloc(size687);
	array_number_t macroDef644;card_t size686 = width_card_t(us_shp.elem);
	array_number_t stgVar599 = storage_alloc(size686);
	array_number_t macroDef643;
	macroDef643 = TOP_LEVEL_usecases_fft_complex_sub_dps(stgVar592, us_dps->arr[i_dps], ms_dps->arr[i_dps], us_shp.elem, ms_shp.elem);;
	storage_free(stgVar599, size686);
	macroDef644 = macroDef643;;
	storage_free(stgVar600, size687);
		ite676 = macroDef644;;
	}
			macroDef645->arr[k_dps] = ite676;;
			stgVar592 = STG_OFFSET(stgVar592, VECTOR_ALL_BYTES(macroDef645->arr[k_dps]->length));
		}
	array_array_number_t dual_concat_dps = macroDef645;
	env_t_688 env_t_688_value = make_env_t_688(dual_concat_shp); closure_t closure649 = make_closure(lambda688, &env_t_688_value);
	matrix_shape_t dual_permute_shp = nested_shape_card_t(closure649.lam(closure649.env, 0).card_t_value, primal_shp.card);
	card_t size689 = width_matrix_shape_t(dual_permute_shp);
	array_number_t stgVar603 = storage_alloc(size689);
	array_array_number_t macroDef652;card_t macroDef650 = primal_dps->length;
	array_array_number_t macroDef651 = (array_array_number_t)stgVar603;
		macroDef651->length=macroDef650;
		macroDef651->arr=(array_number_t*)(STG_OFFSET(macroDef651, VECTOR_HEADER_BYTES));
		storage_t stgVar605 = (STG_OFFSET(macroDef651, MATRIX_HEADER_BYTES(macroDef650)));

		for(int k_dps = 0; k_dps < macroDef651->length; k_dps++){
			card_t i_shp = 0;
			index_t i_dps = ((j_dps) * (dim / 2)) + ((k_dps) % (dim / 2));
			array_number_t ite677 ;
            //printf("%d, %d, %d\n", j_dps, i_dps, k_dps);
	if((k_dps) < (dim / 2)) {
		
		ite677 = dual_concat_dps->arr[(int)(offset0_dps->arr[i_dps])];;
	} else {
		
		ite677 = dual_concat_dps->arr[(int)(offset1_dps->arr[i_dps])];;
	}
			macroDef651->arr[k_dps] = ite677;;
			stgVar605 = STG_OFFSET(stgVar605, VECTOR_ALL_BYTES(macroDef651->arr[k_dps]->length));
		}

	array_array_number_t dual_permute_dps = macroDef651;
	macroDef652 = dual_permute_dps;;
	macroDef653 = macroDef652;;
	storage_free(stgVar590, size690);
	macroDef654 = macroDef653;;
	storage_free(stgVar581, size691);
	macroDef655 = macroDef654;;
	storage_free(stgVar575, size692);
		macroDef674 = macroDef655;;
#ifdef DEBUG
        printf("DUAL(%d)\n", j_dps);
        matrix_print(macroDef674);
#endif
	storage_free(stgVar603, size689);
	}
	macroDef675 = macroDef674;;
	storage_free(stgVar562, size693);
	return macroDef675;
}
#endif
