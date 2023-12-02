#include <vector>
#include <bits/stdc++.h> 
#include <cmath>
#include "firstFunction.h"
#include "vectorUtils.h"

using namespace std;

float calculateCosProduct(vector<float> x) {
  float value = 1;
  size_t i;
  #pragma omp parallel for shared(x) private(i) reduction(*:value)
  for (i = 0; i < x.size(); ++i) {
      value *= cos(x[i]/(i+1));
  };
  return value;
}

float calculateFirstFunctionValueForVector(vector<float> x) {
  return calculateSquareSumOfValuesInVector(x)/40 + 1 - calculateCosProduct(x);
}