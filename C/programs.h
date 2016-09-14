#ifndef __PROGRAMS_H__ 
#define __PROGRAMS_H__ 
#include "runtime/fsharp.h"
#include <stdio.h>
#include <math.h>
#include "linalg.h"

number_t TOP_LEVEL_programs_test1(number_t x) {
	
	return (1) / ((1) + (x));
}

number_t TOP_LEVEL_programs_test2(number_t x, number_t b) {
	
	return x;
}

array_number_t TOP_LEVEL_programs_vector_add3(array_number_t v1, array_number_t v2, array_number_t v3) {
	
	return TOP_LEVEL_linalg_add_vec(v1, TOP_LEVEL_linalg_add_vec(v2, v3));
}

array_array_number_t TOP_LEVEL_programs_matrix_add3(array_array_number_t m1, array_array_number_t m2, array_array_number_t m3) {
	
	return TOP_LEVEL_linalg_matrixAdd(m1, TOP_LEVEL_linalg_matrixAdd(m2, m3));
}

void TOP_LEVEL_programs_hoistingExample(array_number_t v) {
	number_t macroDef240 = 0;
	for(int idx = 0; idx <= 9; idx++){
		array_number_t tmp = array_slice(v, idx, (idx) + (9));
		macroDef240 = (macroDef240) + (TOP_LEVEL_linalg_sqnorm(TOP_LEVEL_linalg_add_vec(tmp, tmp)));;
	}
	number_t sum = macroDef240;
	number_print(sum);
	return ;
}

void TOP_LEVEL_programs_explicitMallocExample1(array_number_t v) {
	card_t size246 = width_vector_shape_t(nested_shape_card_t(0, 10));
	array_number_t storage1 = storage_alloc(size246);
	number_t macroDef243 = 0;
	for(int idx = 0; idx <= 9; idx++){
		array_number_t macroDef242 = (array_number_t)storage1;
		macroDef242->length=10;
		macroDef242->arr=(number_t*)(STG_OFFSET(macroDef242, VECTOR_HEADER_BYTES));
		storage_t s = macroDef242;
		for(int i = 0; i < macroDef242->length; i++){
			
			macroDef242->arr[i] = v->arr[(i) + (idx)];;
			s = STG_OFFSET(s, sizeof(number_t));
		}
		array_number_t tmp = macroDef242;
		macroDef243 = (macroDef243) + (TOP_LEVEL_linalg_sqnorm(TOP_LEVEL_linalg_add_vec(tmp, tmp)));;
	}
	number_t sum = macroDef243;
	number_print(sum);
	storage_free(storage1, size246);
	;
	return ;
}

array_number_t TOP_LEVEL_programs_vectorMap2GivenStorage(storage_t storage, closure_t f, array_number_t v1, array_number_t v2) {
	card_t macroDef247 = v1->length;
	card_t macroDef248 = v1->length;
	array_number_t macroDef249 = (array_number_t)storage;
		macroDef249->length=macroDef247;
		macroDef249->arr=(number_t*)(STG_OFFSET(macroDef249, VECTOR_HEADER_BYTES));
		storage_t s = macroDef249;
		for(int i = 0; i < macroDef249->length; i++){
			
			macroDef249->arr[i] = f.lam(f.env, v1->arr[i], v2->arr[i]).number_t_value;;
			s = STG_OFFSET(s, sizeof(number_t));
		}
	return macroDef249;
}
typedef empty_env_t env_t_253;


value_t lambda253(env_t_253* env250, number_t x, number_t y) {
	
	value_t res;
	res.number_t_value = (x) + (y);
	return res;
}
array_number_t TOP_LEVEL_programs_add_vecGivenStorage(storage_t s, array_number_t x, array_number_t y) {
	env_t_253 env_t_253_value = make_empty_env(); closure_t closure252 = make_closure(lambda253, &env_t_253_value);
	return TOP_LEVEL_programs_vectorMap2GivenStorage(s, closure252, x, y);
}

void TOP_LEVEL_programs_explicitMallocExample2(array_number_t v) {
	card_t size260 = width_vector_shape_t(nested_shape_card_t(0, 10));
	array_number_t storage1 = storage_alloc(size260);
	card_t size259 = width_vector_shape_t(nested_shape_card_t(0, 10));
	array_number_t storage2 = storage_alloc(size259);
	number_t macroDef255 = 0;
	for(int idx = 0; idx <= 9; idx++){
		array_number_t macroDef254 = (array_number_t)storage1;
		macroDef254->length=10;
		macroDef254->arr=(number_t*)(STG_OFFSET(macroDef254, VECTOR_HEADER_BYTES));
		storage_t s = macroDef254;
		for(int i = 0; i < macroDef254->length; i++){
			
			macroDef254->arr[i] = v->arr[(i) + (idx)];;
			s = STG_OFFSET(s, sizeof(number_t));
		}
		array_number_t tmp = macroDef254;
		array_number_t tmp2 = TOP_LEVEL_programs_add_vecGivenStorage(storage2, tmp, tmp);
		macroDef255 = (macroDef255) + (TOP_LEVEL_linalg_sqnorm(tmp2));;
	}
	number_t sum = macroDef255;
	number_print(sum);
	storage_free(storage2, size259);
	;
	storage_free(storage1, size260);
	;
	return ;
}

void TOP_LEVEL_programs_stackAllocExample(number_t x, number_t y, number_t z) {
	array_number_t v = (array_number_t)storage_alloc(sizeof(int) * 2);
	v->length=3;
	v->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	v->arr[0] = x;
	v->arr[1] = y;
	v->arr[2] = z;;
	array_number_t v2 = TOP_LEVEL_linalg_add_vec(v, v);
	array_print(v2);
	return ;
}

void TOP_LEVEL_programs_storageConvertorExample(card_t s, card_t e) {
	array_number_t v2 = TOP_LEVEL_linalg_vectorRange(s, e);
	array_print(v2);
	return ;
}
typedef empty_env_t env_t_268;


value_t lambda268(env_t_268* env265, array_number_t a, array_number_t b) {
	card_t macroDef263 = a->length;
	array_number_t macroDef264 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef264->length=macroDef263;
	macroDef264->arr = (number_t*)storage_alloc(sizeof(number_t) * macroDef263);
		for(int i = 0; i < macroDef264->length; i++){
			
			macroDef264->arr[i] = (a->arr[i]) + (b->arr[i]);;
		}
	value_t res;
	res.array_number_t_value = macroDef264;
	return res;
}
array_number_t TOP_LEVEL_programs_vectorAddExample(number_t dum) {
	env_t_268 env_t_268_value = make_empty_env(); closure_t closure267 = make_closure(lambda268, &env_t_268_value);
	closure_t add = closure267;
	array_number_t vec1 = (array_number_t)storage_alloc(sizeof(int) * 2);
	vec1->length=3;
	vec1->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	vec1->arr[0] = 1;
	vec1->arr[1] = 2;
	vec1->arr[2] = 3;;
	array_number_t vec2 = (array_number_t)storage_alloc(sizeof(int) * 2);
	vec2->length=3;
	vec2->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	vec2->arr[0] = 4;
	vec2->arr[1] = 5;
	vec2->arr[2] = 6;;
	return add.lam(add.env, vec1, vec2).array_number_t_value;
}

void TOP_LEVEL_programs_small_tests(number_t dum) {
	number_t a269 = TOP_LEVEL_programs_test1(2);
	number_print(a269);
	number_print(TOP_LEVEL_programs_test2(2, a269));
	array_number_t v2270 = TOP_LEVEL_linalg_vectorRange(0, 99);
	TOP_LEVEL_programs_hoistingExample(v2270);
	TOP_LEVEL_programs_explicitMallocExample1(v2270);
	TOP_LEVEL_programs_explicitMallocExample2(v2270);
	TOP_LEVEL_programs_stackAllocExample(2, 3, 5);
	return ;
}
#endif