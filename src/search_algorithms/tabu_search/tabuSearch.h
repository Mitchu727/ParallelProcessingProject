# pragma once

#include <vector>
#include <functional>

#include "result.h"
#include "point.h"

using namespace std;

result minimizeFunctionUsingTabuSearch(const function<float(vector<float>)>& targetFunction, int dimension, ofstream& fileLog, bool saveToLog, float lowerBound, float upperBound, int iterations);

void insertInTabuList(vector<result>& tabuList, const result& resultToInsert);
bool checkIfTabuListContains(vector<result>& tabuList, point pointToCheck);
bool checkDistanceBetweenPointsIsSmallerThan(point firstPoint, point secondPoint, float distance);
void writeToLog(ofstream& fileLog, float y_min, point x_min, const vector<point>& checkedPoints);
