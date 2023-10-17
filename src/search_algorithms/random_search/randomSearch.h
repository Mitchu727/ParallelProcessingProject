#include <vector>
#include "result.h"

using namespace std;

float X_LOWER_BOUND = -40.;
float X_UPPER_BOUND = 40.;
int NUM_ITERS = 10000;

result calculateRandomSearch(
    function<float(vector<float>)> targetFunction, 
    int dimension, 
    int iterations = NUM_ITERS, 
    float lowerBound = X_LOWER_BOUND, 
    float upperBound = X_UPPER_BOUND
);
