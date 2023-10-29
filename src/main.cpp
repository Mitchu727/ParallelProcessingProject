#include <iostream> 
#include <vector>
#include "firstFunction.h"
#include "secondFunction.h"
#include "vectorUtils.h"
#include "randomSearch.h"
#include "tabuSearch.h"

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

    cout << "Losowe szukanie: ";
    auto res = calculateRandomSearch(calculateFirstFunctionValueForVector, 3);
    res.print();

    cout << "Generowanie sąsiadw dla [2, 3]: ";
    vector<float> p;
    p.push_back(2);
    p.push_back(3);
    generateNeighborhood(point { p });
} 
