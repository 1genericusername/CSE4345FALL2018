#ifndef ADJLIST_H
#define ADJLIST_H
#include "iostream"
#include "fstream"
#include <vector>
#include <list>
#include <math.h>
#include <ostream>
#include <string>
using namespace std;

class AdjList
{
    private:
        int numVertices;
        list<pair<int,int>>* adjlist;
        list<pair<int,int>>* positions;

    public:
        AdjList(int size);
        void addVertice(int source, int destination, int weight);
        void printlist();
        void buildList(string filename, string filename2);
        //Algorithm 1
        void BFS(int source, int d);

        //Algorithm 2
        void BFSREC(int s,int d, bool visited[], list<int> Stack);
        void BFSR(int source, int d);

        //Algorithm 3
        void DFS(int source, int d);

        //Algorithm 4
        void DFSREC(int s,int d, bool visited[], list<int> Stack);
        void DFSR(int source, int d);

        //Algorithm 5
        double heuristic(double x1, double y1, double x2, double y2, int cost);
        void A_star(int source, int destination);

        //Algorithm 6
        void dijkstra(int source, int destination);
};

#endif // ADJLIST_H
