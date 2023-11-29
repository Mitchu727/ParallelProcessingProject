#include <vector>
#include <bits/stdc++.h>
#include <cmath>
#include "firstFunction.h"
#include "vectorUtils.h"
#include "result.h"
#include "point.h"
#include "tabuSearch.h"

using namespace std;


result calculateTabuSearch(const function<float(vector<float>)>& targetFunction, const point& startingPoint, const float gridScale, const int maxIterations, const float bound)
{
    result tmpMinimum(targetFunction(startingPoint), startingPoint);
    vector<result> tabuList;

    for (int i = 1; i <= maxIterations; i++) {
        cout << "it: " << i << "\t";
        int requiredNeighbors = 20;
        vector<point> neighborhood = generateNeighborhood(tmpMinimum.x, tabuList, requiredNeighbors, gridScale, bound);
        if (neighborhood.empty()) break;
        
        vector<result> resultsForCurrentNeighborhood = calculateTargetFunctionForNeighborhood(targetFunction, neighborhood);
        updateTabuList(tabuList, resultsForCurrentNeighborhood);
        updateMinimum(tmpMinimum, resultsForCurrentNeighborhood);
        tmpMinimum.print();
    }

    result result(tmpMinimum.y, tmpMinimum.x);
    result.print();
    return result;
}

/*
    Generate numNeighbors nearest neighbors with condition that 0 < distance < maxDistance.
    Exclude tabu points.
    Distance is maximal coordinate difference, not hypotenuse.

    The algorithm:
        1. Start with distance of 1 from starting point
        2. Generate neighborhood
        3. Remove tabu points from neighborhood
        4. If neighborhood size is less than numNeighbors, increace the distance by 1 and go back to 2.
        5. Continue until at least numNeighbors neighbors are gathered
        6. Trim the neighborhood to numNeighbors neighbors
*/
vector<point> generateNeighborhood(const point& startingPoint, const vector<result>& tabuList, int numNeighbors, float gridScale, float bound) {
    vector<point> neighborhood;
    for (float distance = gridScale; distance < bound; distance += gridScale) {
        vector<point> newDistanceNeighborhood = generateNeighborhoodWithConstantDistance(startingPoint, distance, bound);
        neighborhood.insert(neighborhood.end(), newDistanceNeighborhood.begin(), newDistanceNeighborhood.end()); 
        removeTabuPoints(neighborhood, tabuList);
        if (neighborhood.size() < numNeighbors) 
            continue;
        else
            break;
    }

    if (neighborhood.size() > numNeighbors)
        neighborhood.resize(numNeighbors);

    return neighborhood;
}


/*
    This function generates neighborhood only in given distance from starting point. Distance is maximal coordinate difference, not hypotenuse. 
    Example of neighborhood generated for distance = 2 and gridScale = 1:

    x   x   x   x   x
    x   .   .   .   x
    x   .   O   .   x
    x   .   .   .   x
    x   x   x   x   x

    Algorithm:
    1. Add the starting point to an empty neighbors list
    2. For each of leighbors list elements add to the neighbor list this point, moved in the first dimension by -distance, 0 and distance
        (3 new points for each element in the neighbor list)
    3. 3. Repeat ad. 2 for another dimensions
    4. Delete repetitions and starting point from neighobrs list

    Example
    Let's start with point (0, 0)
    1. neighbors_list = [(0, 0)]
    2. iterations:
        1. Frst dimension: neighbors_list = [(0, 0), (-1, 0), (0, 0), (1, 0)]
        2. Second dimension: neighbors_list = [(0, 0), 
                                               (0, -1), (0, 0), (0, 1), 
                                               (-1, 0),
                                               (-1, -1), (-1, 0), (-1, 1), 
                                               (0, 0),
                                               (0, -1), (0, 0), (0, 1), 
                                               (1, 0),
                                               (1, -1), (1, 0), (1, 1)]
    3. Delete repetitions. neighbors_list = [(-1, 1),  (0, 1),   (1, 1),
                                             (-1, 0),            (1, 0),
                                             (-1, -1), (-1, 0), (-1, -1)]

*/
vector<point> generateNeighborhoodWithConstantDistance(const point& pointZero, float distance, float bound) {
    int pointsDimensions = pointZero.size();

    vector<point> neighbors;
    neighbors.push_back(pointZero);
    
    for (int dimension = 0; dimension < pointsDimensions; dimension++) {
        vector<point> temporaryNeighbors(neighbors);
        for (point neighbor : temporaryNeighbors) {
            float modifiers[3] = {-distance, 0, distance};
            vector<point> points(3, neighbor);
            for (int i = 0; i < 3; i++) {
                points[i][dimension] = points[i][dimension] + modifiers[i];
                if (points[i][dimension] <= bound && points[i][dimension] >= -bound)
                    neighbors.push_back(points[i]);
            }
        }
    }

    erase(neighbors, pointZero);
    return withoutDuplicates(neighbors);
}

void removeTabuPoints(vector<point>& neighborhood, const vector<result>& tabuList) {
    for (result tabuPoint : tabuList) {
        auto it = remove(neighborhood.begin(), neighborhood.end(), tabuPoint.x);
        neighborhood.erase(it, neighborhood.end());
    }
}

vector<point> withoutDuplicates(const vector<point>& vec) {
    vector<point> copy(vec);
    sort(copy.begin(), copy.end());
    auto it = unique(copy.begin(), copy.end());
    copy.erase(it, copy.end());
    return copy;
}

vector<result> calculateTargetFunctionForNeighborhood(const function<float(vector<float>)>& targetFunction, const vector<point>& neighborhood) {
    vector<result> resultsForNeighborhood;
    for (point neighbor : neighborhood) {
        float y = targetFunction(neighbor);
        result resultForNeighbor(y, neighbor); 
        resultsForNeighborhood.push_back(resultForNeighbor);
    }
    return resultsForNeighborhood;
}

void updateTabuList(vector<result>& tabuList, const vector<result>& resultsForNeighborhood) {
    tabuList.insert(tabuList.end(), resultsForNeighborhood.begin(), resultsForNeighborhood.end());
}

void updateMinimum(result& tmpMinimum, const vector<result>& resultsForNeighborhood) {
    auto it = min_element(resultsForNeighborhood.begin(), resultsForNeighborhood.end());
    if (*it < tmpMinimum) {
        tmpMinimum = *it;
    }
}
