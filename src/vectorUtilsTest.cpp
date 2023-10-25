#include <vector>
#include <iostream> 
#include "vectorUtils.h"

using namespace std;

int main(int argc, char* argv[]) {
    vector<float> vect1{ 4, 5};
    vector<float> vect2{ 1, 1};
    cout << "================TEST================"<< endl;
    cout << "Pierwszy wektor: " << vectorToString(vect1) << endl;
    cout << "Drugi wektor: " << vectorToString(vect2) << endl;
    vector<float> diff = subtractVectors(vect1, vect2);
    cout << "Różnica między wektorami" << vectorToString(diff) <<endl;
    float squareSum = calculateSquareSumOfValuesInVector(vect1);
    cout << "Suma kwadratów w wektorze 1 (powinno wyjść 49):" << squareSum << endl;
    float neighborhood = calculateDistanceBetweenVectors(vect1, vect2);
    cout << "Odległość między wektorami (powinno wyjść 5):" << neighborhood << endl;
    return 0;
}