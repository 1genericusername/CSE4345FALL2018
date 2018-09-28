#ifndef ASTAR_H
#define ASTAR_H
#include "pathbehavior.h"
#include <iostream>
#include <cmath>
#include <vector>

class AStarSearch: public PathBehavior
{
    public:
    double heuristic(double x1, double y1, double x2, double y2, int cost);
    void A_star_L(int source, int destination, std::list<std::pair<int,int>>* adjlist, std::list<std::pair<int,int>>* positions);
    void A_Star_M(int source, int destination, int** adjmatrix, std::list<std::pair<int,int>>* positions);

};

#endif // ASTAR_H
