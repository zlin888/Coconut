#define DPS
#include "../../outputs/C/usecases_oneMM_storaged.h"
#include "../test.h"

//#define P 512
//#define Q 512
//#define R 512
//#define N 1

#define P 2 
#define Q 2 
#define R 2 
#define N 1

matrix_shape_t comp_c(matrix_shape_t A_c, matrix_shape_t B_c) {
	
	return nested_shape_card_t(B_c.elem, A_c.card);
}


array_array_number_t comp_s(storage_t stgVar586, array_array_number_t A_s, array_array_number_t B_s, matrix_shape_t A_c, matrix_shape_t B_c) {
	card_t macroDef603 = A_s->length;
	array_array_number_t macroDef616 = (array_array_number_t)stgVar586;
		macroDef616->length=macroDef603;
		macroDef616->arr=(array_number_t*)(STG_OFFSET(macroDef616, VECTOR_HEADER_BYTES));
		storage_t stgVar588 = (STG_OFFSET(macroDef616, MATRIX_HEADER_BYTES(macroDef603)));
		for(int r_s = 0; r_s < macroDef616->length; r_s++){
			card_t size617 = width_card_t(B_c.elem);
	array_number_t stgVar589 = storage_alloc(size617);
	card_t macroDef605;card_t macroDef604 = B_s->arr[0]->length;
	macroDef605 = macroDef604;;
	storage_free(stgVar589, size617);
			array_number_t macroDef615 = (array_number_t)stgVar588;
		macroDef615->length=macroDef605;
		macroDef615->arr=(number_t*)(STG_OFFSET(macroDef615, VECTOR_HEADER_BYTES));
		storage_t stgVar591 = macroDef615;
		for(int c_s = 0; c_s < macroDef615->length; c_s++){
			card_t size618 = width_card_t(A_c.elem);
	array_number_t stgVar600 = storage_alloc(size618);
	card_t macroDef612;card_t macroDef611 = A_s->arr[r_s]->length;
	macroDef612 = macroDef611;;
	storage_free(stgVar600, size618);
			array_number_t macroDef613 = (array_number_t)empty_storage;
		macroDef613->length=(((macroDef612) - (1)) - (0)) + (1);
		macroDef613->arr=(number_t*)(STG_OFFSET(macroDef613, VECTOR_HEADER_BYTES));
		storage_t stgVar602 = macroDef613;
		for(int i_s = 0; i_s < macroDef613->length; i_s++){
			
			macroDef613->arr[i_s] = (double)(((0)) + (i_s));;
			stgVar602 = STG_OFFSET(stgVar602, sizeof(number_t));
		}
			number_t macroDef614 = 0;
	array_number_t cur_s_range = macroDef613;
	storage_t stgVar592 = stgVar591;
	for(int cur_s_idx = 0; cur_s_idx < cur_s_range->length; cur_s_idx++){
		number_t cur_s = cur_s_range->arr[cur_s_idx];
		card_t size619 = width_card_t(A_c.elem);
	array_number_t stgVar593 = storage_alloc(size619);
	number_t macroDef606;
	macroDef606 = A_s->arr[r_s]->arr[(int)(cur_s)];;
	storage_free(stgVar593, size619);
		card_t size621 = width_card_t(B_c.card);
	array_number_t stgVar595 = storage_alloc(size621);
	number_t macroDef610;card_t macroDef607 = B_s->length;
	array_number_t macroDef609 = (array_number_t)stgVar595;
		macroDef609->length=macroDef607;
		macroDef609->arr=(number_t*)(STG_OFFSET(macroDef609, VECTOR_HEADER_BYTES));
		storage_t stgVar597 = macroDef609;
		for(int j_s = 0; j_s < macroDef609->length; j_s++){
			card_t size620 = width_card_t(B_c.elem);
	array_number_t stgVar598 = storage_alloc(size620);
	number_t macroDef608;
	macroDef608 = B_s->arr[j_s]->arr[c_s];;
	storage_free(stgVar598, size620);
			macroDef609->arr[j_s] = macroDef608;;
			stgVar597 = STG_OFFSET(stgVar597, sizeof(number_t));
		}
	macroDef610 = macroDef609->arr[(int)(cur_s)];;
	storage_free(stgVar595, size621);
		macroDef614 = (macroDef614) + ((macroDef606) * (macroDef610));;
	}
			macroDef615->arr[c_s] = macroDef614;;
			stgVar591 = STG_OFFSET(stgVar591, sizeof(number_t));
		}
			macroDef616->arr[r_s] = macroDef615;;
			stgVar588 = STG_OFFSET(stgVar588, VECTOR_ALL_BYTES(macroDef616->arr[r_s]->length));
		}
	return macroDef616;
}


int main() {
    srand(SEED);
	array_array_number_t A = get_mat(P, Q);
	array_array_number_t B = get_mat(Q, R);

	storage_t s = storage_alloc(sizeof(double) * P * Q * 1.1 * 100);
	double total = 0;
	TIC();
	for (int i = 0; i < N; i++)
	{
        A->arr[0]->arr[0] = 1 / (i+1);
		array_array_number_t r = comp_s(s, A, B, matrix_shape(A), matrix_shape(B));
		//array_array_number_t r = oneMM(A, B);
		total += r->arr[0]->arr[1];
	}
	TOC();
	printf("%f", total);
}
