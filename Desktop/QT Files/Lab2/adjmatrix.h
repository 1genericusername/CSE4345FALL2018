#ifndef ADJMATRIX_H
#define ADJMATRIX_H
#include "iostream"
#include "fstream"
#include <vector>
#include <ostream>
#include <math.h>
#include <list>
#include <string>
#include <queue>
using namespace std;


class AdjMatrix
{
    private:
        int** adjMatrix;
        int numVertices;
        list<pair<int,int>>* positions;

    public:
        AdjMatrix(int numVertices);

        void addVertice(int i, int j);

        void addweightedVertice(int i, int j, int k);

        void clearVertice(int i, int j);

        void checkVertice(int i, int j);

        void printMatrix();

        void buildMatrix(string filename, string filename2);

        void printAllPathsUtil(int source, int distance,bool visited[],int path[],int& path_index);

        //Algorithm 1
        void BFS(int source, int dest);

        //Algorithm 2
        void BFSREC(int s,int d, bool visited[], list<int> stack);
        void BFSR(int source, int dest);

        //Algorithm 3
        void DFS(int s, int dest);

        //Algorithm 4
        void DFSREC(int s,int d, bool visited[], list<int> stack);
        void DFSR(int source, int dest);

        //Algorithm 5
        double heuristic(double x1, double y1, double x2, double y2, int cost);
        void AStar(int source, int destination);

        //Algorithm 6
        void dijkstra(int source, int destination);



        ~AdjMatrix();


};


#endif // ADJMATRIX_H
