#include <vector>
#include <bits/stdc++.h>
#include <cmath>
#include "secondFunction.h"
#include "vectorUtils.h"

using namespace std;

float calculateCosSum(vector<float> x) {
  float value = 0;
  size_t i;
  // #pragma omp parallel for shared(x) private(i) reduction(+:value) spowalnia program nawet z omp nested ustawionym na false
  for (i = 0; i < x.size(); ++i) {
      value += cos(2*M_PI*x[i]);
  };
  return value;
}

float calculateSecondFunctionValueForVector(vector<float> x) {
    return -20*exp(-0.2 * sqrt(calculateSquareSumOfValuesInVector(x)/x.size())) - exp(calculateCosSum(x)/x.size()) + 20 + M_E;
}
