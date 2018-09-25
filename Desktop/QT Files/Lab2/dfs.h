#ifndef DFS_H
#define DFS_H
#include "pathbehavior.h"
#include <iostream>

class depthfirstsearch: public PathBehavior
{
    public:
        void DFS_L(int source, int d, std::list<std::pair<int,int>>* adjlist);
        void DFS_M(int s, int dest, int** adjMatrix);

};

#endif // DFS_H
