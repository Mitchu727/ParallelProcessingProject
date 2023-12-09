# pragma once

#include <vector>
#include <functional>

#include "result.h"
#include "point.h"

using namespace std;

result calculateTabuSearch(const function<float(vector<float>)>& targetFunction, const point& startingPoint, const float gridScale, const int iteration, const float bound);
result minimizeFunctionUsingTabuSearch(const function<float(vector<float>)>& targetFunction, int dimension, ofstream& fileLog, bool saveToLog, float lowerBound, float upperBound, int iterations);
vector<point> generateNeighborhood(const point& pointZero, const vector<result>& tabuList, int maxDistance, float gridScale, float distance);
vector<point> generateNeighborhoodWithConstantDistance(const point& pointZero, float distance, float bound);
vector<result> calculateTargetFunctionForNeighborhood(const function<float(vector<float>)>& targetFunction, const vector<point>& neighborhood);
void removeTabuPoints(vector<point>& neighborhood, const vector<result>& tabuList);
vector<point> withoutDuplicates(const vector<point>& vec);
void updateTabuList(vector<result>& tabuList, const vector<result>& resultsForNeighborhood);
void updateMinimum(result& tmpMinimum, const vector<result>& resultsForNeighborhood);

void insertInTabuList(vector<result>& tabuList, const result& resultToInsert);
bool checkIfTabuListContains(vector<result>& tabuList, point pointToCheck);
bool checkDistanceBetweenPointsIsSmallerThan(point firstPoint, point secondPoint, float distance);

void writeToLog(ofstream& fileLog, float y_min, point x_min, const vector<point>& checkedPoints);
