// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#include "../../polybench.h"
#define N 100000
int SIZE = 10;
cardinality_t P = SIZE;
cardinality_t Q = SIZE;
cardinality_t R = SIZE;
cardinality_t S = SIZE;

void twoMM(Real alpha, Real beta, std::vector<Vec<Real>> &A, std::vector<Vec<Real>> &B,std::vector<Vec<Real>> &C,std::vector<Vec<Real>> &D, std::vector<Vec<Real>> &E) {
  std::vector<Vec<Real>> tmp{P, Vec<Real>{R}};
  /* D := alpha*A*B*C + beta*D */
  for (int i = 0; i < P; i++)
    for (int j = 0; j < R; j++)
      {
	tmp[i][j] = 0.0;
	for (int k = 0; k < Q; ++k)
	  tmp[i][j] += alpha * A[i][k] * B[k][j];
      }

  for (int i = 0; i < P; i++)
    for (int j = 0; j < S; j++)
      {
	E[i][j] = D[i][j] * beta;
	for (int k = 0; k < R; ++k)
	  E[i][j] += tmp[i][k] * C[k][j];
      }
}


int main() {
  srand(SEED);
  Real alpha = 10;
  Real beta = 10;

  std::vector<Vec<Real>> A{P, Vec<Real>{Q}};
  std::vector<Vec<Real>> B{Q, Vec<Real>{R}};
  std::vector<Vec<Real>> C{R, Vec<Real>{S}};
  std::vector<Vec<Real>> D{P, Vec<Real>{S}};
  std::vector<Vec<Real>> E{P, Vec<Real>{S}};

  populate_mat_rand(A);
  populate_mat_rand(B);
  populate_mat_rand(C);
  populate_mat_rand(D);

  Real total = 0;
  TIC();
  for(int g = 0; g < N; g++) {
      A[0][0] += 1 / g;
      twoMM(alpha, beta, A, B, C, D, E);
      total += E[0][1];
  }
  TOC();
  
    print_mat(E);
    printf("%f", total);
}
