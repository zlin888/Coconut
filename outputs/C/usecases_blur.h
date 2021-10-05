#ifndef __USECASES_BLUR_H__ 
#define __USECASES_BLUR_H__ 
#include "../../Runtime/C/fsharp.h"
#include <stdio.h>
#include <math.h>
#include "linalg.h"

number_t TOP_LEVEL_usecases_blur_new_value(array_array_number_t image, index_t row, index_t col) {
	number_t sum = ((((((((image->arr[(row) - (1)]->arr[(col) - (1)]) + (image->arr[(row) - (1)]->arr[col])) + (image->arr[(row) - (1)]->arr[(col) + (1)])) + (image->arr[row]->arr[(col) - (1)])) + (image->arr[row]->arr[col])) + (image->arr[row]->arr[(col) + (1)])) + (image->arr[(row) + (1)]->arr[(col) - (1)])) + (image->arr[(row) + (1)]->arr[col])) + (image->arr[(row) + (1)]->arr[(col) + (1)]);
	return (sum) / ((double)(9));
}
#endif
