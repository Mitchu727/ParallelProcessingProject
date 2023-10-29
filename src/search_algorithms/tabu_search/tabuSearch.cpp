#include <vector>
#include <bits/stdc++.h>
#include <cmath>
#include "firstFunction.h"
#include "vectorUtils.h"
#include "result.h"

using namespace std;

// void checkForPositive(int param, string name) { 
//     if (param <= 0) 
//         throw invalid_argument("Nonpositive argument " + name + " in calculateRandomSearch: " + to_string(param));
// }

struct point {
    vector<float> coordinates;
};

bool pred(vector<float> first, vector<float> second) {
    bool result = true;
    for (int i = 0; i < first.size(); i++) {
        if (first[i] != second[i]) {
            result = false;
        }
    }
    return result;
}


vector<vector<float>> generateNeighborhood(point pointZero) {

    size_t dimension = pointZero.coordinates.size();
    // vector<int> ones(dimension, 1);
    vector<vector<float>> neighbors;
    neighbors.push_back(pointZero.coordinates);
    
    for (int i = 0; i < dimension; i++) {
        int howManyNeighbors = neighbors.size();
        for (int j = 0; j < howManyNeighbors; j++) {
            printVector(neighbors[i]);
            vector<float> seq1 = vector(neighbors[j]);
            vector<float> seq2 = vector(neighbors[j]);
            vector<float> seq3 = vector(neighbors[j]);
            seq1[i] = seq1[i] - 1;
            seq2[i] = seq2[i] + 0;
            seq3[i] = seq3[i] + 1;
            neighbors.push_back(seq1);
            neighbors.push_back(seq2);
            neighbors.push_back(seq3);
        }
    }

    auto it = unique(neighbors.begin(), neighbors.end(), pred);
    neighbors.erase(it, neighbors.end());
    for (int i = 0; i < neighbors.size(); i++) {
        printVector(neighbors[i]);
    }

    return neighbors;
}








// vector<point> generateNeighborhood(point pointZero) {

//     size_t dimension = pointZero.coordinates.size();
//     // vector<int> ones(dimension, 1);
//     vector<vector<int>> onesAndMinusOnes;
//     for (int i = 0; i < dimension + 1; i++) { // ile minus jedynek
//         vector<int> nextOnes(dimension, 1);
//         for (int j = 0; j < i; j++) {
//             nextOnes.push_back(1);
//         }
//         for (int j = i; j < dimension; j++) {
//             nextOnes.push_back(-1);
//         }
//         onesAndMinusOnes.push_back(nextOnes);
//     }

//     vector<vector<int>> allPermutations;
//     for (int i = 0; i < dimension + 1; i++) {
//         do {
//             allPermutations.push_back(onesAndMinusOnes[i]);
//         } while (next_permutation(onesAndMinusOnes[i].begin(), onesAndMinusOnes[i].end()));
//     }

//     for (int i = 0; i < allPermutations.size(); i++) {
//         printVector(allPermutations[i]);
//     }


//     vector<point> neighbors;
//     for (int i = 0; i < allPermutations.size(); i++) {
//         vector<float> generatedNeighbor;
//         for (int j = 0; j < allPermutations[i].size(); j++) {
//             generatedNeighbor.push_back(pointZero.coordinates[j] + allPermutations[i][j]);
//         }
//         neighbors.push_back(point { generatedNeighbor });
//     }

//     // for (int i = 0; i < dimension; i++) {
//     //     printVector(allPermutations[i]);
//     // }


//     return neighbors;
// }

// result calculateTabuSearch(function<float(vector<float>)> targetFunction, int dimension, int iterations, float lowerBound, float upperBound)
// {
//     float y, y_min = numeric_limits<float>::infinity();
//     vector<float> x, x_min;



//     checkForPositive(dimension, "dimension");
//     checkForPositive(iterations, "iterations");

//     for (int i = 0; i < iterations; i++) {
//         x = generateRandomVectorFromUniformDistribution(dimension, lowerBound, upperBound);
//         y = targetFunction(x);
//         if (y < y_min) {
//             y_min = y;
//             x_min = x;
//         }
//     }

//     return result{y_min, x_min};
// }
