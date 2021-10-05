#define DPS
#include "../../outputs/C/usecases_blur_storaged.h"
#include "../test.h"

#define SIZE 1000
#define N 100

array_array_number_t matrix_fill(card_t rows, card_t cols, number_t value) {
#ifdef DPS
  return TOP_LEVEL_linalg_matrixFill_dps(malloc(MATRIX_ROWS_OFFSET(rows, cols, rows)), rows, cols, value, rows, cols, 0);
#else
  return TOP_LEVEL_linalg_matrixFill(rows, cols, value);
#endif
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
	size_t n = SIZE;
	size_t m = SIZE;
	int rng = 42;

	array_array_number_t image = matrix_fill(n, m, 0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			image->arr[i]->arr[j] = dist(rng);
		}
	}
	storage_t s = storage_alloc(sizeof(float) * n * m * 5);
	double total = 0;
	TIC();
	for (int i = 0; i < N; i++)
	{
                image->arr[0]->arr[0] = image->arr[0]->arr[0] + 1;
                image->arr[1]->arr[1] = image->arr[1]->arr[1] + 1;
                image->arr[2]->arr[2] = image->arr[2]->arr[2] + 1;
		array_array_number_t r = TOP_LEVEL_usecases_blur_blur_forward_dps(s, image, matrix_shape(image));
		total += r->arr[3]->arr[3];
	}
	TOC();
	printf("%f", total);
}
