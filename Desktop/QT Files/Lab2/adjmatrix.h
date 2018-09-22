#ifndef ADJMATRIX_H
#define ADJMATRIX_H
#include "iostream"
#include "fstream"
#include <vector>
#include <ostream>
#include <list>
#include <string>
#include <queue>
using namespace std;


class AdjMatrix
{
    private:
        int** adjMatrix;
        int numVertices;

    public:
        AdjMatrix(int numVertices);

        void addVertice(int i, int j);

        void addweightedVertice(int i, int j, int k);

        void clearVertice(int i, int j);

        void checkVertice(int i, int j);

        void printMatrix();

        void buildMatrix(string filename);

        void printAllPathsUtil(int source, int distance,bool visited[],int path[],int& path_index);

        void DFS(int source, int destination);

        void dijkstra(int source, int destination);

        void AStar(int source, int destination);

        ~AdjMatrix();


};


#endif // ADJMATRIX_H
