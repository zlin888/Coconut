#define DPS
#define FUSED
#define HOIST
#ifdef DPS
#ifdef FUSED
#include "../test.h"
#include "../../outputs/C/usecases_gmm_opt_storaged.h"
#else
#include "../../outputs/C/usecases_gmm_storaged.h"
#endif
#else
#ifdef FUSED
#include "../../outputs/C/usecases_gmm_opt.h"
#else
#include "../../outputs/C/usecases_gmm.h"
#endif
#endif

#define SIZE 1 << 18
#define N 10

const size_t GMM_K = 5;
const size_t GMM_D = 3;

// double dist(int seed) {
//   return ((double)rand()/(double)RAND_MAX);
// }
// 
// array_array_number_t matrix_fill(card_t rows, card_t cols, number_t value) {
// #ifdef DPS
//   return TOP_LEVEL_linalg_matrixFill_dps(malloc(MATRIX_ROWS_OFFSET(rows, cols, rows)), rows, cols, value, rows, cols, 0);
// #else
//   return TOP_LEVEL_linalg_matrixFill(rows, cols, value);
// #endif
// }
// 
// array_number_t vector_fill(card_t rows, number_t value) {
//   return matrix_fill(1, rows, value)->arr[0];
// }
// 
// matrix_shape_t matrix_shape(array_array_number_t mat) {
//   matrix_shape_t res;
//   res.card = mat->length;
//   res.elem = mat->arr[0]->length;
//   return res;
// }
// 
// int vector_shape(array_number_t vec) {
//   return vec->length;
// }

int main(int argc, char** argv)
{
  int rng = 42;
  srand(rng);
  // std::mt19937 rng(42);
  // std::uniform_real_distribution<Real> dist(0, 1);

  // Problem size
  size_t n = SIZE;
  size_t d = GMM_D;
  size_t K = GMM_K;
#ifdef DPS
  size_t td = TOP_LEVEL_usecases_gmm_tri_dps(empty_storage, d, 0);
#else
  size_t td = TOP_LEVEL_usecases_gmm_tri(d);
#endif
  

  // Declare and fill GMM coeffs
  // Vector alphas{ K };
  // Vec<VectorD> means{ K, VectorD{ d } };
  // Vec<VectorD> qs{ K, VectorD{ d } };
  // Vector l0{ size_t(tri(d)) };
  // Vec<Vector> ls{ K, l0 };
  array_number_t alphas = vector_fill(K, 0);
  array_array_number_t means = matrix_fill(K, d, 0);
  array_array_number_t qs = matrix_fill(K, d, 0);
  array_array_number_t ls = matrix_fill(K, td, 0);
  for (int k = 0; k < K; ++k) {
    alphas->arr[k] = dist();
    for (int j = 0; j < d; ++j) {
      means->arr[k]->arr[j] = dist() - 0.5;
      qs->arr[k]->arr[j] = 10.0*dist() - 5.0;
    }
    for (int j = 0; j < ls->arr[k]->length; ++j) {
      ls->arr[k]->arr[j] = dist() - 0.5;
      if(j >= ls->arr[k]->length - d)
        ls->arr[k]->arr[j] = 0;
    }
  }

  // Declare and fill xs
  // Vec<VectorD> xs{ n, Vector{ d } };
  array_array_number_t xs = matrix_fill(n, d, 0);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < d; ++j)
      xs->arr[i]->arr[j] = dist();

  // TOP_LEVEL_usecases_gmm_Qtimesv_test(0);

  // boost::timer::auto_cpu_timer t;

  // Debug 150s 
    // Release 1s
  double total = 0;
#ifdef _DEBUG
  N = N / 10;  // Debug is roughly this much slower than release -- multiply timings.
#endif
  double wishart_m = 2.0;
  double wishart_gamma = 1.0;
  // printf("x: ");
  // matrix_print(xs);
  printf("alphas: ");
  array_print(alphas);
  printf("means: ");
  matrix_print(means);
  printf("qs: ");
  matrix_print(qs);
  printf("ls: ");
  matrix_print(ls);
  printf("wishart_m, %f\n", wishart_m);
  printf("wishart_gamma, %f\n", wishart_gamma);

	TIC();
  for (int count = 0; count < N; ++count) {
    alphas->arr[0] += 1;
    double wishart_gamma = 1.0 / (1.0 + count);
#ifdef DPS
    double r = TOP_LEVEL_usecases_gmm_gmm_objective_dps(empty_storage, xs, alphas, means, qs, ls, wishart_gamma, wishart_m, 
    	matrix_shape(xs), vector_shape(alphas), matrix_shape(means), matrix_shape(qs), matrix_shape(ls), 0, 0);
    // printf("%f\n", r);
    total += r;
#else
    total += TOP_LEVEL_usecases_gmm_gmm_objective(xs, alphas, means, qs, ls, wishart_gamma, wishart_m);
#endif
  }

  // std::cout << "total =" << total << ", time per call = " << t.elapsed().wall / double(N) / 1000.0 << "us" << std::endl;
  printf("%f\n", total);
  TOC();
  return 0;
}
