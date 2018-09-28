#ifndef ADJMATRIX_H
#define ADJMATRIX_H
#include <iostream>
#include <fstream>
#include <vector>
#include "pathbehavior.h"
#include <ostream>
#include <cmath>
#include <chrono>
#include <sstream>
#include <list>
#include <string>
#include <queue>
using namespace std;


class AdjMatrix : public PathBehavior
{
    private:
        int** adjMatrix;
        double** largem;
        int numVertices;
        list<pair<int,int>>* positions;

    public:
        AdjMatrix(int numVertices);

        void addVertice(int i, int j, int k);

        void Print();

        void Build(string filename, string filename2);

        //Algorithm 1
        void BFS(int source, int dest);

        //Algorithm 2
        void BFSREC(int s,int d, bool visited[], list<int> stack, vector<int>& nodesVisited, int& totalDistance, list<int>& cost,  vector<int>& nodesPath);
        void BFSR(int source, int dest);

        //Algorithm 3
        void DFS(int s, int dest);

        //Algorithm 4
        void DFSREC(int s,int d, bool visited[], list<int> stack, vector<int>& nodesVisited, int& totalDistance, list<int>& cost,  vector<int>& nodesPath);
        void DFSR(int source, int dest);

        //Algorithm 5
        double heuristic(double x1, double y1, double x2, double y2, int cost);
        void A_star(int source, int destination);

        //Algorithm 6
        void dijkstra(int source, int destination);


        ~AdjMatrix();


};





#endif // ADJMATRIX_H
