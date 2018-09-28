#include <iostream>
#include "merge.h"
#include "bubble.h"
#include <cstdio>
#include "insertion.h"
#include "sort.h"
#include "adjmatrix.h"
#include "adjlist.h"
using namespace std;

int main(int argc, char* argv[])
{
    Sort Graphs;

    Graphs.GrabUserInput(atoi(argv[1]),atoi(argv[2]));

    for(int algorithms=0;algorithms<6;algorithms++)
    {
        for(int graphs=0;graphs<2;graphs++)
        {
            Graphs.execute(graphs,algorithms);
        }
    }




}
