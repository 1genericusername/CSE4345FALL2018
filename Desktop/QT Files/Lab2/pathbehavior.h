#ifndef PATHBEHAVIOR_H
#define PATHBEHAVIOR_H
#include <ostream>
#include <vector>
#include <list>

class PathBehavior
{

 //    virtual void addVertice(int source, int destination, int weight) = 0;

 /*   //Algorithm 1
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
    */
        public:

        virtual void addVertice(int source, int destination, int weight) = 0;

        virtual void Print() = 0;

        virtual void Build(std::string filename, std::string filename2) = 0;

        //Algorithm 1
        virtual void BFS(int source, int d) = 0;

        //Algorithm 2
        virtual void BFSREC(int s,int d, bool visited[], std::list<int> stack, std::vector<int>& nodesVisited, int& totalDistance, std::list<int>& cost,  std::vector<int>& nodesPath) = 0;
        virtual void BFSR(int source, int d) = 0;

        //Algorithm 3
        virtual void DFS(int source, int d) = 0;

        //Algorithm 4
        virtual void DFSREC(int s,int d, bool visited[], std::list<int> Stack, std::vector<int>& nodesVisited, int& totalDistance, std::list<int>& cost,  std::vector<int>& nodesPath) = 0;
        virtual void DFSR(int source, int d) = 0;

        //Algorithm 5
        virtual double heuristic(double x1, double y1, double x2, double y2, int cost) = 0;
        virtual void A_star(int source, int destination) = 0;

        //Algorithm 6
        virtual void dijkstra(int source, int destination) = 0;

    int numVertices = 4;
};

#endif // PATHBEHAVIOR_H
