#include <iostream>

#include "result.h"
#include "vectorUtils.h"

using namespace std;

result::result(float y, point x) {
    this->y = y;
    this->x = x;
}

result::result(float y) {
    this->y = y;
}

bool result::operator==(const result& other) const {
    return this->y == other.y && this->x == other.x;
}

bool result::operator<(const result& other) const { 
    return this->y < other.y; 
}

void result::print() {
    cout << "result { y = " + to_string(this->y) + ", x = " + vectorToString(this->x) + " }" << endl;
}
