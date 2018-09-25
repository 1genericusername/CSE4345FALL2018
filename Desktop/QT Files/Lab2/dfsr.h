#ifndef DFSR_H
#define DFSR_H
#include "pathbehavior.h"
#include <iostream>

class depthfirstsearchRecursive: public PathBehavior
{
    public:
        void DFSREC_L(int s, int d, bool visited[], std::list<int> Queue,std::list<std::pair<int,int>>* adjlist);
        void DFSR_L(int source, int d, std::list<std::pair<int,int>>* adjlist);
        void DFSREC_M(int source, int d, bool visited[], std::list<int> Queue, int** adjMatrix);
        void DFSR_M(int source, int dest, int** adjmatrix);

};

#endif // DFSR_H
