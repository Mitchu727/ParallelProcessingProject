#include <vector>
#include <bits/stdc++.h>
#include <cmath>
#include "secondFunction.h"
#include "vectorUtils.h"

using namespace std;

float calculateCosSum(vector<float> x) {
  float value = 0;
  //TODO spróbować ładniej
  for (size_t i = 0; i < x.size(); ++i) {
      value += cos(2*M_PI*x[i]);
  };
  return value;
}

float calculateSecondFunctionValueForVector(vector<float> x) {
    return 20*exp(-0.2 * sqrt(calculateSquareSumOfValuesInVector(x)/x.size())) - exp(calculateCosSum(x)/x.size()) + 20 + M_E;
}