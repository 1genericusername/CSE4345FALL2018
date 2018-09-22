#ifndef ADJLIST_H
#define ADJLIST_H
#include "iostream"
#include "fstream"
#include <vector>
#include <list>
#include <stack>
#include <ostream>
#include <string>
using namespace std;

class AdjList
{
    private:
        int numVertices;
        list<pair<int,int>>* adjlist;
        bool* visited;

    public:
        AdjList(int size);
        void addVertice(int source, int destination, int weight);
        void printlist();
        void buildList(string filename);
        void BFS(int source, int d);
        void DFS(int source, int d);
        void DFSREC(int s,int d, bool visited[], list<int> stack);
        void DFSR(int source, int d);
};

#endif // ADJLIST_H
