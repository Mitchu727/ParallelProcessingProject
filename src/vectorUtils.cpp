#include <vector>
#include <bits/stdc++.h> 
#include "vectorUtils.h"

using namespace std;

std::default_random_engine generator;

float generateRandomNumberFromUniformDistribution(float minValue, float maxValue) {
  std::uniform_real_distribution<double> distribution(minValue,maxValue);
  return distribution(generator);
}

vector<float> generateRandomVectorFromUniformDistribution(int size, float minValue, float maxValue) {
    vector<float> generatedVector(size);
    for (size_t i = 0; i < generatedVector.size(); i++) {
        generatedVector[i] = generateRandomNumberFromUniformDistribution(minValue, maxValue);
    }
    return generatedVector;
}

float calculateSquareSumOfValuesInVector(vector<float> x) {
  int i;
  float sum = 0;
  // #pragma omp parallel for shared(x) private(i) reduction(+:sum) spowalnia program nawet z omp nested ustawionym na false
  for(i=0; i<x.size(); i++) {
    sum += x[i]*x[i];
  }
  return sum;
}

void printVector (const vector<float>& vec) {
  cout << vectorToString(vec) << endl;
}

string vectorToString(const vector<float>& vec) {
  string begin("[");
  string end("]");
  std::string body = accumulate(++vec.begin(), vec.end(), std::string(to_string(vec[0])), 
    [](const string &a, float b) -> string {
      return a + ", " + to_string(b);
    }
  );

  return begin + body + end;
}
