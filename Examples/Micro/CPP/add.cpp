#include <random>
#define ADD3

#include "stdafx.h"
#include "../../mytime.h"

typedef Vec<Real> Vector;


Real dist(int seed) {
  return ((double)rand()/(double)RAND_MAX);
}


int main(int argc, char** argv)
{
  int rng = 42;
  srand(rng);

int N = 1;
cardinality_t DIM = (1 << 24);
Vector vec1{ DIM };
Vector vec2{ DIM };
Vector vec3{ DIM };

  for (cardinality_t k = 0; k < DIM; ++k) {
    vec1[k] = dist(rng);
    vec2[k] = dist(rng);
#ifdef ADD3
    vec3[k] = dist(rng);
#endif
  }


  TIC();
  double total = 0;

  for (cardinality_t count = 0; count < N; ++count) {
    vec1[0] += 1.0 / (2.0 + vec1[0]);
    vec2[1] += 1.0 / (2.0 + vec2[1]);
#ifdef ADD3
  #ifdef EIGEN
    total += sum((vec1 + vec2 + vec3).eval());
  #else
    total += sum((vec1 + vec2 + vec3));
  #endif
#elif DOT
    total += dot(vec1, vec2);
#elif CROSS
    total += sum(cross(vec1, vec2));
#endif
  }

  TOC();
  std::cout << total << std::endl;

  return 0;
}
