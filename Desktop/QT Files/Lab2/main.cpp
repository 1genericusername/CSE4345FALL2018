#include <iostream>
#include "merge.h"
#include "bubble.h"
#include "insertion.h"
#include "sort.h"
#include "adjmatrix.h"
#include "adjlist.h"
using namespace std;

int main()
{

    AdjMatrix g(17);
    g.buildMatrix("weights.txt","positions.txt");
//    g.DFS(1,16);
//    g.printMatrix();
  //  g.dijkstra(1,4);

//    g.dijkstra(13,2);


    AdjList test(16);
    test.buildList("weights.txt","positions.txt");
 //   test.printlist();
 //   test.BFS(1,16);
 //   cout << endl;
 //   test.BFSR(1,6);
//    test.DFS(1,16);
 //   test.DFSR(1,6);
 //   test.BFS(1,8);
    test.A_star(1,11);



}
