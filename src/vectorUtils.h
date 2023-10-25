#include <vector>

std::vector<float> generateRandomVectorFromUniformDistribution(int size, float minValue, float maxValue);
std::string vectorToString(const std::vector<float>& vec);
std::vector<float> subtractVectors(std::vector<float> x, std::vector<float> y);
void printVector (const std::vector<float>& vec);
float calculateSquareSumOfValuesInVector(std::vector<float> x);
float calculateNeighborhoodBetweenTwoVectors(std::vector<float> x, std::vector<float> y);