#ifndef PATHBEHAVIOR_H
#define PATHBEHAVIOR_H
#include <list>

class PathBehavior
{
    public:
        int numVertices = 17;

    //Algorithm 1
    virtual void BFS_L(int source, int d, std::list<std::pair<int,int>>* adjlist) = 0;
    virtual void BFS_M(int source, int dest, int** adjMatrix) = 0;

    //Algorithm 2
    virtual void BFSR_L(int source, int d, std::list<std::pair<int,int>>* adjlist) = 0;
    virtual void BFSR_M(int source, int dest, int** adjMatrix) = 0;

    //Algorithm 3
    virtual void DFS_L(int source, int d, std::list<std::pair<int,int>>* adjlist) = 0;
    virtual void DFS_M(int s, int dest, int** adjMatrix) = 0;

    //Algorithm 4
    virtual void DFSR_L(int source, int d, std::list<std::pair<int,int>>* adjlist) = 0;
    virtual void DFSR_M(int source, int dest, int** adjMatrix) = 0;

    //Algorithm 5
    virtual void A_star_L(int source, int destination, std::list<std::pair<int,int>>* adjlist, std::list<std::pair<int,int>>* positions) = 0;
    virtual void A_Star_M(int source, int destination, int** adjmatrix, std::list<std::pair<int,int>>* positions) = 0;

    //Algorithm 6
    virtual void dijkstra_L(int source, int destination, std::list<std::pair<int,int>>* adjlist) = 0;
    virtual void dijkstra_M(int source, int destination, int** adjmatrix) = 0;
};

#endif // PATHBEHAVIOR_H
