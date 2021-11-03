#ifndef TEST_H
#define TEST_H
#define SEED 42

#include <stdio.h>
#include <stdlib.h>
#include "../outputs/C/linalg_storaged.h"
#include "mytime.h"

array_array_number_t matrix_fill(card_t rows, card_t cols, number_t value) {
#ifdef DPS
  return TOP_LEVEL_linalg_matrixFill_dps(malloc(MATRIX_ROWS_OFFSET(rows, cols, rows)), rows, cols, value, rows, cols, 0);
#else
  return TOP_LEVEL_linalg_matrixFill(rows, cols, value);
#endif
}

array_number_t vector_fill(card_t rows, number_t value) {
  return matrix_fill(1, rows, value)->arr[0];
}

matrix_shape_t matrix_shape(array_array_number_t mat) {
  matrix_shape_t res;
  res.card = mat->length;
  res.elem = mat->arr[0]->length;
  return res;
}

#define SEED 42

array_array_number_t get_mat(int rows, int cols) {
	return matrix_fill(rows, cols, 0);
}

array_number_t get_vec(int rows) {
	return vector_fill(rows, 0);
}



double dist() {
  return ((double)rand()/(double)RAND_MAX);
}

void populate_mat_rand(array_array_number_t mat) {
	for (int i = 0; i < mat->length; i++) {
		for (int j = 0; j < mat->arr[0]->length; j++) {
			mat->arr[i]->arr[j] = dist();
		}
	}
}

void populate_vec_rand(array_number_t vec) {
	for (int i = 0; i < vec->length; i++) {
        vec->arr[i] = dist();
	}
}

int vector_shape(array_number_t vec) {
  return vec->length;
}




#endif
