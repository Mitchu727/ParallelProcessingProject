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

result calculateRandomSearch(function<float(vector<float>)> targetFunction, int dimension, int iterations, float lowerBound, float upperBound)
{
    float y, y_min = numeric_limits<float>::infinity();
    vector<float> x, x_min;

    checkForPositive(dimension, "dimension");
    checkForPositive(iterations, "iterations");

    for (int i = 0; i < iterations; i++) {
        x = generateRandomVectorFromUniformDistribution(dimension, lowerBound, upperBound);
        y = targetFunction(x);
        if (y < y_min) {
            y_min = y;
            x_min = x;
        }
    }

    return result{y_min, x_min};
}
