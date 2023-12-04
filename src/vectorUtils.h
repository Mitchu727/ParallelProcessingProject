#include <vector>
#include <point.h>

std::vector<float> generateRandomVectorFromUniformDistribution(int size, float minValue, float maxValue);
std::vector<float> generateRandomVectorInNieghborhoodFromUniformDistribution(point basePoint, float distance,float minValue, float maxValue);
std::string vectorToString(const std::vector<float>& vec);
void printVector (const std::vector<float>& vec);
float calculateSquareSumOfValuesInVector(std::vector<float> x);