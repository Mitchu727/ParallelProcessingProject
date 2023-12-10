#include <vector>
#include <bits/stdc++.h>
#include <cmath>
#include "firstFunction.h"
#include "vectorUtils.h"
#include "result.h"
#include "point.h"
#include "tabuSearch.h"
#include "math.h"

using namespace std;

int const TABU_LIST_MAX_SIZE = 100;
int const NEIGHBORS_SIZE = 10000;
int const STUCK_ON_MINIMUM_LIMIT = 20;
float const TABU_LIST_FORBIDDEN_NEIGHBORHOOD_DISTANCE = 0.1;
float EXPLORATION_DISTANCE = 7;

result minimizeFunctionUsingTabuSearch(const function<float(vector<float>)>& targetFunction, int dimension, float lowerBound, float upperBound, int iterations)
{
    point startingPoint = generateRandomVectorFromUniformDistribution(dimension, lowerBound, upperBound);
    result foundMinimum = result(targetFunction(startingPoint), startingPoint);
    vector<result> tabuList;
    int last_updated = 0;

    for (int i = 1; i <= iterations; i++) {
        vector<point> neighborhood;
        cout << "it: " << i << "\t";
        point x, x_min;

        float y, y_min = numeric_limits<float>::infinity();
        #pragma omp parallel for shared(NEIGHBORS_SIZE, dimension, lowerBound, upperBound, x_min, y_min, foundMinimum) private(i, x ,y)
        for (int j=0; j<NEIGHBORS_SIZE; j++) {
            x = generateRandomVectorInNeighborhoodFromUniformDistribution(foundMinimum.x, EXPLORATION_DISTANCE, lowerBound, upperBound);
            y = targetFunction(x);
            if (!checkIfTabuListContains(tabuList, x)) {
                #pragma omp critical
                if (y<y_min) {
                    y_min = y;
                    x_min = x;
                }
            }
        }
        if (y_min < foundMinimum.y) {
            foundMinimum = result(y_min, x_min);
            last_updated = i;
        }
        insertInTabuList(tabuList, foundMinimum);
        foundMinimum.print();
        if (i - last_updated >= STUCK_ON_MINIMUM_LIMIT) {
            cout << "Finished by stuck on minimum point." << endl;
            break;
        }
    }
    return foundMinimum;
}

void insertInTabuList(vector<result>& tabuList, const result& resultToInsert) {
    tabuList.push_back(resultToInsert);
    // float tabuListMaxSize = sqrt(resultToInsert.x.size()); to może dać lepsze efekty
    float tabuListMaxSize = TABU_LIST_MAX_SIZE;
    if (tabuList.size() > tabuListMaxSize) {
        tabuList.erase(tabuList.begin());
    }
}

bool checkIfTabuListContains(vector<result>& tabuList, point pointToCheck) {
    for (int i=0; i<tabuList.size(); i++) {
        if (checkDistanceBetweenPointsIsSmallerThan(tabuList[i].x, pointToCheck, TABU_LIST_FORBIDDEN_NEIGHBORHOOD_DISTANCE)) return true;
    }
    return false;
}

bool checkDistanceBetweenPointsIsSmallerThan(point firstPoint, point secondPoint, float distance) {
    float sum=0;
    for (int i=0; i<firstPoint.size(); i++) {
        sum+= pow(firstPoint[i]-secondPoint[i], 2);
    }
    return sqrt(sum) < distance;
}