#include <vector>
#include "result.h"

using namespace std;

// const float X_LOWER_BOUND = -40.;
// const float X_UPPER_BOUND = 40.;
// const int NUM_ITERS = 10000;

// result calculateTabuSearch(
//     function<float(vector<float>)> targetFunction, 
//     int dimension,
//     int iterations = NUM_ITERS,
//     float lowerBound = X_LOWER_BOUND,
//     float upperBound = X_UPPER_BOUND
// );

struct point {
    vector<float> coordinates;
};

vector<vector<float>> generateNeighborhood(point pointZero);
