#include <iostream> 
#include <vector>
#include "firstFunction.h"
#include "secondFunction.h"
#include "vectorUtils.h"

using namespace std;

int main(int argc, char* argv[]) 
{ 
    cout << "Hello world" <<endl;
    vector<float> vect = generateRandomVectorFromUniformDistribution(2, 0.,0.);
    cout << "Wielkość wektora: " << vect.size() <<endl; 
    cout << "Wektor:" << endl;
    printVector(vect);
    cout << endl << "Wartość funkcji 1:" << calculateFirstFunctionValueForVector(vect);
    cout << endl << "Wartość funkcji 2:" << calculateSecondFunctionValueForVector(vect);
    cout << endl;
    // std::vector<int> randomVector = generateRandomVector(10);
    // printVector(randomVector);
} 
