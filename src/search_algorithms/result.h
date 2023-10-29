#pragma once

#include <vector>
#include "point.h"

struct result
{
    float y;
    point x;

    result(float y, point x);
    result(float y);

    bool operator==(const result& other) const;
    bool operator<(const result& other) const;

    void print();
};
