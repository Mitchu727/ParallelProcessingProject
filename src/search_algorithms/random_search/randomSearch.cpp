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

    // # pragma omp parallel shared(iterations, dimension, lowerBound, upperBound, x_min, y_min, fileLog, saveToLog) private(i, x ,y) //DO ZAPISU DO PLIKU
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
            //DO ZAPISU DO PLIKU
            // if (saveToLog) { 
            // fileLog <<  y_min << "," << y << endl; 
            // }
        }
    }
    

    return result{y_min, x_min};
}

// Otymalizacja - każdy wątek liczy swoje minimum
// result minimizeFunctionUsingRandomSearch(function<float(vector<float>)> targetFunction, int dimension, ofstream& fileLog, bool saveToLog, float lowerBound, float upperBound, int iterations)
// {
//     float y, y_min_in_thread_scope, y_min = numeric_limits<float>::infinity();
//     vector<float> x, x_min, x_min_in_thread_scope;
//     int i;

//     checkForPositive(dimension, "dimension");
//     checkForPositive(iterations, "iterations");

//     // # pragma omp parallel shared(iterations, dimension, lowerBound, upperBound, x_min, y_min, fileLog, saveToLog) private(i, x ,y) //DO ZAPISU DO PLIKU
//     # pragma omp parallel shared(iterations, dimension, lowerBound, upperBound, x_min, y_min) private(i, x ,y, x_min_in_thread_scope, y_min_in_thread_scope) 
//     {
//         y_min_in_thread_scope = numeric_limits<float>::infinity();
//         #pragma omp for
//         for (i = 0; i < iterations; i++) {
//             x = generateRandomVectorFromUniformDistribution(dimension, lowerBound, upperBound);
//             y = targetFunction(x);
//             if (y < y_min_in_thread_scope) {
//                 y_min_in_thread_scope = y;
//                 x_min_in_thread_scope = x;
//             }
//             //DO ZAPISU DO PLIKU - ZAPYTAĆ 
//             // if (saveToLog) { 
//             //    fileLog <<  y_min << "," << y << endl; 
//             // }
//         }
//         #pragma omp critical
//         {
//            if (y_min_in_thread_scope < y_min) {
//                 y_min = y_min_in_thread_scope;
//                 x_min = x_min_in_thread_scope;
//             } 
//         }
//     }
//     return result{y_min, x_min};
// }