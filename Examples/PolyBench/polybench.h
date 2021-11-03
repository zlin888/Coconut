// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include <stdio.h>
// #include <tchar.h>

// #include <boost/timer/timer.hpp>

#include "../../Runtime/CPP/Vec.h"

#include <stdlib.h>
#include <time.h>

#include "../test.h"
#include <random>

using namespace std;

Real dist() {
  return ((double)rand()/(double)RAND_MAX);
}

void populate_mat_rand(std::vector<Vec<Real>> &m) {
  for (cardinality_t i = 0; i < m.size(); ++i) {
      for (cardinality_t j = 0; j < m[0].size(); ++j) {
          m[i][j] = dist();
      }
  }
}

void populate_mat_zero(std::vector<Vec<Real>> &m) {
  for (cardinality_t i = 0; i < m.size(); ++i) {
      for (cardinality_t j = 0; j < m[0].size(); ++j) {
          m[i][j] = 0;
      }
  }
}

void print_mat(std::vector<Vec<Real>> &m) {
  for (cardinality_t i = 0; i < m.size(); ++i) {
      for (cardinality_t j = 0; j < m[0].size(); ++j) {
          cout << m[i][j] << ", ";
      }
      cout << endl;
  }
}

