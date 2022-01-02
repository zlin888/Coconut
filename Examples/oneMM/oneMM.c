#define DPS
#include "../../outputs/C/usecases_oneMM_storaged.h"
#include "../test.h"

#define P 512
#define Q 512
#define R 512
#define N 1

matrix_shape_t TOP_LEVEL_linalg_oneMM_shp(matrix_shape_t A_shp, matrix_shape_t B_shp) {
	
	return nested_shape_card_t(B_shp.elem, A_shp.card);
}

typedef struct env_t_1876 {
	matrix_shape_t B_shp;
} env_t_1876;
env_t_1876 make_env_t_1876(matrix_shape_t B_shp) {
	env_t_1876 env;
	env.B_shp = B_shp;
	return env;
}

value_t lambda1876(env_t_1876* env1853, card_t i_shp0) {
	matrix_shape_t B_shp1852 = env1853->B_shp;
	value_t res;
	res.card_t_value = B_shp1852.card;
	return res;
}
typedef struct env_t_1877 {
	matrix_shape_t B_shp;
} env_t_1877;
env_t_1877 make_env_t_1877(matrix_shape_t B_shp) {
	env_t_1877 env;
	env.B_shp = B_shp;
	return env;
}

value_t lambda1877(env_t_1877* env1857, card_t i_shp0) {
	matrix_shape_t B_shp1856 = env1857->B_shp;
	value_t res;
	res.card_t_value = B_shp1856.card;
	return res;
}
array_array_number_t TOP_LEVEL_linalg_oneMM_dps(storage_t stgVar1823, array_array_number_t A_dps, array_array_number_t B_dps, matrix_shape_t A_shp, matrix_shape_t B_shp) {
	card_t macroDef1846 = A_dps->length;
	array_array_number_t macroDef1872 = (array_array_number_t)stgVar1823;
		macroDef1872->length=macroDef1846;
		macroDef1872->arr=(array_number_t*)(STG_OFFSET(macroDef1872, VECTOR_HEADER_BYTES));
		storage_t stgVar1825 = (STG_OFFSET(macroDef1872, MATRIX_HEADER_BYTES(macroDef1846)));
		for(int r_dps = 0; r_dps < macroDef1872->length; r_dps++){
			card_t size1873 = width_card_t(B_shp.elem);
	array_number_t stgVar1826 = storage_alloc(size1873);
	card_t macroDef1848;card_t macroDef1847 = B_dps->arr[0]->length;
	macroDef1848 = macroDef1847;;
	storage_free(stgVar1826, size1873);
			array_number_t macroDef1871 = (array_number_t)stgVar1825;
		macroDef1871->length=macroDef1848;
		macroDef1871->arr=(number_t*)(STG_OFFSET(macroDef1871, VECTOR_HEADER_BYTES));
		storage_t stgVar1828 = macroDef1871;
		for(int c_dps = 0; c_dps < macroDef1871->length; c_dps++){
			card_t anfvar1829_shp = A_shp.elem;
			card_t size1882 = width_card_t(anfvar1829_shp);
	array_number_t stgVar1830 = storage_alloc(size1882);
	number_t macroDef1870;card_t size1874 = width_card_t(A_shp.elem);
	array_number_t stgVar1831 = storage_alloc(size1874);
	card_t macroDef1850;card_t macroDef1849 = A_dps->arr[r_dps]->length;
	macroDef1850 = macroDef1849;;
	storage_free(stgVar1831, size1874);
	array_number_t macroDef1868 = (array_number_t)stgVar1830;
		macroDef1868->length=macroDef1850;
		macroDef1868->arr=(number_t*)(STG_OFFSET(macroDef1868, VECTOR_HEADER_BYTES));
		storage_t stgVar1833 = macroDef1868;
		for(int i_dps = 0; i_dps < macroDef1868->length; i_dps++){
			card_t size1875 = width_card_t(A_shp.elem);
	array_number_t stgVar1834 = storage_alloc(size1875);
	number_t macroDef1851;
	macroDef1851 = A_dps->arr[r_dps]->arr[i_dps];;
	storage_free(stgVar1834, size1875);
			env_t_1876 env_t_1876_value = make_env_t_1876(B_shp); closure_t closure1855 = make_closure(lambda1876, &env_t_1876_value);
			card_t size1881 = width_card_t(nested_shape_card_t(closure1855.lam(closure1855.env, 0).card_t_value, B_shp.elem).elem);
	array_number_t stgVar1836 = storage_alloc(size1881);
	number_t macroDef1867;env_t_1877 env_t_1877_value = make_env_t_1877(B_shp); closure_t closure1859 = make_closure(lambda1877, &env_t_1877_value);
	card_t size1880 = width_matrix_shape_t(nested_shape_card_t(closure1859.lam(closure1859.env, 0).card_t_value, B_shp.elem));
	array_number_t stgVar1837 = storage_alloc(size1880);
	array_number_t macroDef1866;card_t size1878 = width_card_t(B_shp.elem);
	array_number_t stgVar1838 = storage_alloc(size1878);
	card_t macroDef1861;card_t macroDef1860 = B_dps->arr[0]->length;
	macroDef1861 = macroDef1860;;
	storage_free(stgVar1838, size1878);
	array_array_number_t macroDef1865 = (array_array_number_t)stgVar1837;
		macroDef1865->length=macroDef1861;
		macroDef1865->arr=(array_number_t*)(STG_OFFSET(macroDef1865, VECTOR_HEADER_BYTES));
		storage_t stgVar1840 = (STG_OFFSET(macroDef1865, MATRIX_HEADER_BYTES(macroDef1861)));
		for(int i_dps0 = 0; i_dps0 < macroDef1865->length; i_dps0++){
			card_t macroDef1862 = B_dps->length;
			array_number_t macroDef1864 = (array_number_t)stgVar1840;
		macroDef1864->length=macroDef1862;
		macroDef1864->arr=(number_t*)(STG_OFFSET(macroDef1864, VECTOR_HEADER_BYTES));
		storage_t stgVar1842 = macroDef1864;
		for(int j_dps = 0; j_dps < macroDef1864->length; j_dps++){
			card_t size1879 = width_card_t(B_shp.elem);
	array_number_t stgVar1843 = storage_alloc(size1879);
	number_t macroDef1863;
	macroDef1863 = B_dps->arr[j_dps]->arr[i_dps0];;
	storage_free(stgVar1843, size1879);
			macroDef1864->arr[j_dps] = macroDef1863;;
			stgVar1842 = STG_OFFSET(stgVar1842, sizeof(number_t));
		}
			macroDef1865->arr[i_dps0] = macroDef1864;;
			stgVar1840 = STG_OFFSET(stgVar1840, VECTOR_ALL_BYTES(macroDef1865->arr[i_dps0]->length));
		}
	macroDef1866 = macroDef1865->arr[c_dps];;
	storage_free(stgVar1837, size1880);
	macroDef1867 = macroDef1866->arr[i_dps];;
	storage_free(stgVar1836, size1881);
			macroDef1868->arr[i_dps] = (macroDef1851) * (macroDef1867);;
			stgVar1833 = STG_OFFSET(stgVar1833, sizeof(number_t));
		}
	array_number_t anfvar1829_dps = macroDef1868;
	number_t macroDef1869 = 0;
	array_number_t cur_dps_range = anfvar1829_dps;
	storage_t stgVar1845 = stgVar1828;
	for(int cur_dps_idx = 0; cur_dps_idx < cur_dps_range->length; cur_dps_idx++){
		number_t cur_dps = cur_dps_range->arr[cur_dps_idx];
		
		macroDef1869 = (macroDef1869) + (cur_dps);;
	}
	macroDef1870 = macroDef1869;;
	storage_free(stgVar1830, size1882);
			macroDef1871->arr[c_dps] = macroDef1870;;
			stgVar1828 = STG_OFFSET(stgVar1828, sizeof(number_t));
		}
			macroDef1872->arr[r_dps] = macroDef1871;;
			stgVar1825 = STG_OFFSET(stgVar1825, VECTOR_ALL_BYTES(macroDef1872->arr[r_dps]->length));
		}
	return macroDef1872;
}
int main() {
    srand(SEED);
	array_array_number_t A = get_mat(P, Q);
	array_array_number_t B = get_mat(Q, R);

	storage_t s = storage_alloc(sizeof(double) * P * Q * 1.1);
	double total = 0;
	TIC();
	for (int i = 0; i < N; i++)
	{
        A->arr[0]->arr[0] = 1 / (i+1);
		array_array_number_t r = TOP_LEVEL_linalg_oneMM_dps(s, A, B, matrix_shape(A), matrix_shape(B));
		//array_array_number_t r = oneMM(A, B);
		total += r->arr[0]->arr[1];
	}
	TOC();
	printf("%f", total);
}
