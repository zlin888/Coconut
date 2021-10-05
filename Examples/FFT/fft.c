#define DPS
#include "../../outputs/C/usecases_fft_storaged.h"
#include "../test.h"
#include "hashmap.h"

#define DEBUG
#define dim 8
#define LEN 12
#define N 1
array_array_number_t matrix_fill(card_t rows, card_t cols, number_t value) {
#ifdef DPS
  return TOP_LEVEL_linalg_matrixFill_dps(malloc(MATRIX_ROWS_OFFSET(rows, cols, rows)), rows, cols, value, rows, cols, 0);
#else
  return TOP_LEVEL_linalg_matrixFill(rows, cols, value);
#endif
}

int vector_shape(array_number_t vec) {
  return vec->length;
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

double dist(int seed) {
  return rand();
}

int main() {
	int rng = 42;

	array_array_number_t primal = matrix_fill(dim, 2, 0);
	array_array_number_t dual = matrix_fill(dim, 2, 0);
	array_number_t p = vector_fill(LEN, 0);
	array_number_t offset0 = vector_fill(LEN, 0);
	array_number_t offset1 = vector_fill(LEN, 0);
	array_number_t k = vector_fill(LEN, 0);
	array_number_t ndiv2 = vector_fill(dim / 2, 0);
	array_number_t logn = vector_fill((int) (log(dim) / log(2)), 0);
	array_array_number_t omegas = matrix_fill(LEN, 2, 0);

    for (int i = 0; i < dim; i++) {
#ifdef DEBUG
        primal->arr[i]->arr[0] = i + 1;
        primal->arr[i]->arr[1] = 0;
#else 
        primal->arr[i]->arr[0] = dist(rng);
        primal->arr[i]->arr[1] = dist(rng);
#endif
    }

	for (int i = 0; i < LEN; i++) {
        omegas->arr[i]->arr[0] = 1;
        omegas->arr[i]->arr[1] = 1;
	}

	for (int i = 0; i < LEN; i++) {
        p->arr[i] = (i / (dim / 2))  + 1;
	}

    for (int i = 0; i < LEN; i++) {
        int j = i / (dim / 2);
        offset0->arr[i] = floor((i % (dim / 2)) / pow(2, j)) * pow(2, j+1);
    }

    for (int i = 0; i < LEN; i++) {
        k->arr[i] = (i % (dim / 2)) % (int) pow(2, (i / (dim / 2)));
    }

    for (int i = 0; i < LEN; i++) {
        offset0->arr[i] += k->arr[i];
    }

    for (int i = 0; i < LEN; i++) {
        int unityStep = 0x1 << (int) p->arr[i];
        offset1->arr[i] = offset0->arr[i] + unityStep / 2;
    }

    // reverse the offset0 and offset1 to offset2 and osffset3
	array_number_t offset2 = vector_fill(LEN, 0);
	array_number_t offset3 = vector_fill(LEN, 0);
    for (int i = 0; i < (int) (log(dim) / log(2)); i++) {
        for (int j = 0; j < dim / 2; j++) {
            int idx = (dim / 2) * i + j;
            int k;
            k = (int) offset0->arr[idx] % dim;
            if (k >= dim / 2) {
                offset3->arr[k % (dim / 2) + (dim / 2) * i] = idx % (dim / 2);
            } else {
                offset2->arr[k % (dim / 2) + (dim / 2) * i] = idx % (dim / 2);
            }
            k = (int) offset1->arr[idx] % dim;
            if (k >= dim / 2) {
                offset3->arr[k % (dim / 2) + (dim / 2) * i] = idx % (dim / 2) + (dim / 2);
            } else {
                offset2->arr[k % (dim / 2) + (dim / 2) * i] = idx % (dim / 2) + (dim / 2);
            }
        }
    }

    array_print(offset0);
    array_print(offset1);
    array_print(offset2);
    array_print(offset3);

	double total = 0;
	TIC();
	for (int i = 0; i < N; i++)
	{
        storage_t s = storage_alloc(1024);
		array_array_number_t r = TOP_LEVEL_usecases_fft_fft_dps(s, 
                primal, ndiv2, logn, p, offset0, offset1, omegas, matrix_shape(primal), 
                vector_shape(ndiv2), vector_shape(logn), vector_shape(p), 
                vector_shape(offset2), vector_shape(offset3),
               matrix_shape(omegas));
	}
	TOC();
	printf("%f", total);

	for (int i = 0; i < dim; i++) {
        dual->arr[i]->arr[0] = 1;
        dual->arr[i]->arr[1] = 1;
	}

}
