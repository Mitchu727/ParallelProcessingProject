#include <iostream> 
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include "firstFunction.h"
#include "secondFunction.h"
#include "vectorUtils.h"
#include "randomSearch.h"
#include "tabuSearch.h"
#include "point.h"
#include "result.h"

using namespace std;

int main(int argc, char* argv[]) 
{ 
    // std::vector<int> randomVector = generateRandomVector(10);
    // printVector(randomVector);
    string optimizationType = argv[1];
    if (optimizationType != "random" && optimizationType != "tabu") throw invalid_argument("Uknown optimization type: " + optimizationType);

    function<float(vector<float>)> function;
    float lowerBound;
    float upperBound;
    string functionToOptimize = argv[2];
    if (functionToOptimize == "1") {
        function = calculateFirstFunctionValueForVector;
        lowerBound = -40;
        upperBound = 40;
    } else if (functionToOptimize == "2") {
        function = calculateSecondFunctionValueForVector;
        lowerBound = -30;
        upperBound = 30;
    } else {
        throw invalid_argument("Uknown function to optimize: " + functionToOptimize);
    }

    int dimensions = stoi(argv[3]);
    int iterations = stoi(argv[4]);

    std::ostringstream fileNameStream;
    fileNameStream << "../output/" << argv[1] << "_" << argv[2] << "_" << argv[3] << "_" << argv[4] << ".csv";
    ofstream csvOutputFile;
    csvOutputFile.open(fileNameStream.str());

    // result foundMinimum;

    if (optimizationType == "random") {
        cout << "Performing random search:" << endl;
        result foundMinimum = minimizeFunctionUsingRandomSearch(
            function,
            dimensions,
            lowerBound,
            upperBound,
            iterations
        );
        foundMinimum.print();
    } else if (optimizationType == "tabu")
    {
        // calculateTabuSearch(function, startingPoint, gridScale, maxIterations, bound);
    }

    csvOutputFile.close();
    




    // cout << "Random search: ";
    // result res = minimizeFuntionUsingRandomSearch(calculateFirstFunctionValueForVector, 3);
    // res.print();

    // cout << "Tabu search: " << endl;
    // int dimension = 4;
    // point startingPoint(dimension, 20);
    // printVector(startingPoint);
    // float gridScale = 0.1;
    // int maxIterations = 400;
    // int bound = 40;
    // calculateTabuSearch(calculateFirstFunctionValueForVector, startingPoint, gridScale, maxIterations, bound);
} 
