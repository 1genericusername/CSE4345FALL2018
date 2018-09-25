#ifndef BFS_H
#define BFS_H
#include "pathbehavior.h"
#include <iostream>

class breadthfirstsearch: public PathBehavior
{
    public:
        void BFS_L(int source, int d, std::list<std::pair<int,int>>* adjlist);
        void BFS_M(int source, int dest, int** adjMatrix);

};

#endif // BFS_H
