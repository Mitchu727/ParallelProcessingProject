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
  return inner_product( x.begin(), x.end(), x.begin(), 0 );
}

float calculateNeighborhoodBetweenTwoVectors(vector<float> x, vector<float> y) { 
  return sqrt(calculateSquareSumOfValuesInVector(subtractVectors(x, y)));
}

vector<float> subtractVectors(vector<float> x, vector<float> y) {
    vector<float> result;
    transform(x.begin(),x.end(),y.begin(), std::back_inserter(result), std::minus<float>());
    return result;
}

void printVector (const vector<float>& vec) {
  cout << vectorToString(vec);
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


