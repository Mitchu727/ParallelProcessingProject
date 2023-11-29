#include <iostream> 
#include <vector>
#include "firstFunction.h"
#include "secondFunction.h"
#include "vectorUtils.h"
#include "randomSearch.h"
#include "tabuSearch.h"
#include "point.h"

using namespace std;

int main(int argc, char* argv[]) 
{ 
    cout << "Hello world" <<endl;
    vector<float> vect = generateRandomVectorFromUniformDistribution(2, -10., 10.);
    cout << "Wielkość wektora: " << vect.size() <<endl; 
    cout << "Wektor:" << endl;
    printVector(vect);
    cout << endl << "Wartość funkcji 1:" << calculateFirstFunctionValueForVector(vect);
    cout << endl << "Wartość funkcji 2:" << calculateSecondFunctionValueForVector(vect);
    cout << endl;
    // std::vector<int> randomVector = generateRandomVector(10);
    // printVector(randomVector);

    cout << "Random search: ";
    auto res = calculateRandomSearch(calculateFirstFunctionValueForVector, 3);
    res.print();

    cout << "Tabu search: ";
    int dimension = 4;
    point startingPoint(dimension, 20);
    float gridScale = 0.1;
    int maxIterations = 400;
    int bound = 40;
    calculateTabuSearch(calculateFirstFunctionValueForVector, startingPoint, gridScale, maxIterations, bound);
} 
