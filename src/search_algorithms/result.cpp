#include <iostream>

#include "result.h"
#include "vectorUtils.h"

using namespace std;

void result::print() {
    cout << "result { y = " + to_string(this->y) + ", x = " + vectorToString(this->x) + " }" << endl;
}
