#include <vector>
#include <bits/stdc++.h>
#include <cmath>
#include "firstFunction.h"
#include "vectorUtils.h"
#include "result.h"

using namespace std;

void checkForPositive(int param, string name) { 
    if (param <= 0) 
        throw invalid_argument("Nonpositive argument " + name + " in calculateRandomSearch: " + to_string(param));
}

result minimizeFunctionUsingRandomSearch(function<float(vector<float>)> targetFunction, int dimension, ofstream& fileLog, bool saveToLog, float lowerBound, float upperBound, int iterations)
{
    float y, y_min = numeric_limits<float>::infinity();
    vector<float> x, x_min;
    
    int i;
    checkForPositive(dimension, "dimension");
    checkForPositive(iterations, "iterations");

    /*
        In each iteration:
            1. Generate random point (vector)
            2. Calculate target function.
            3. In a critical section - check if it is a new maximum. If so, save it.
    */
    #pragma omp parallel for shared(iterations, dimension, lowerBound, upperBound, x_min, y_min) private(i, x ,y)
    for (i = 0; i < iterations; i++) {
        x = generateRandomVectorFromUniformDistribution(dimension, lowerBound, upperBound);
        y = targetFunction(x);
        #pragma omp critical 
        {
            if (y < y_min) {
                y_min = y;
                x_min = x;
            }
            /*
                Save to file if desired. Works only for dimension == 2, because such plots weren only needed
            */
            if (saveToLog && dimension == 2) { 
                fileLog <<  y_min << "," << x_min[0] << "," << x_min[1] << "," << x[0] << "," << x[1] << endl; 
            }
        }
    }

    return result{y_min, x_min};
}