//#include "dfsr.h"

//void depthfirstsearchRecursive::DFSREC_L(int source, int destination, bool visited[], std::list<int> Stack, std::list<std::pair<int, int> > *adjlist)
//{
//    source = Stack.front();
//    Stack.pop_front();

//    // Stack may contain same vertex twice. So
//    if (!visited[source])
//    {
//        std::cout << source << std::endl;
//        visited[source] = true;
//    }

//    if(visited[destination] != true)
//    {

//        int nxtNode = 0;

//        for (auto i = adjlist[source].begin(); i != adjlist[source].end(); ++i)
//        {
//            nxtNode = i->first;
//            if (visited[nxtNode] == false)
//            {
//                Stack.push_front(nxtNode);
//            }
//        }
//        DFSREC_L(nxtNode,destination, visited, Stack, adjlist);
//     }
//}

//void depthfirstsearchRecursive::DFSR_L(int source, int destination, std::list<std::pair<int, int> > *adjlist)
//{
//    // Mark all the vertices as not visited
//        bool *visited = new bool[numVertices];
//        for (int i = 0; i < numVertices; i++)
//            visited[i] = false;

//        std::list<int> Stack;

//        Stack.push_front(source);

//        // Call the recursive helper function
//        // to print DFS traversal
//        DFSREC_L(source,destination, visited, Stack, adjlist);
//}


//void depthfirstsearchRecursive::DFSREC_M(int source, int destination, bool visited[], std::list<int> Stack, int **adjMatrix)
//{
//    source = Stack.front();
//    Stack.pop_front();

//    if (!visited[source])
//    {
//        std::cout << source << std::endl;
//        visited[source] = true;
//    }


//    if(Stack.front() != destination)
//    {

//    int nxtNode = 0;
//    for (int i = 1; i < numVertices; ++i)
//    {
//            if(adjMatrix[source][i] != 0 && (visited[i] == false))
//            {
//                nxtNode = i;
//                Stack.push_front(i);
//            }
//    }
//    DFSREC_M(nxtNode,destination, visited, Stack, adjMatrix);
//    }
//}

//void depthfirstsearchRecursive::DFSR_M(int source, int destination, int **adjmatrix)
//{
//    // Mark all the vertices as not visited
//    bool *visited = new bool[numVertices];
//    for(int i = 0; i < numVertices; i++)
//        visited[i] = false;

//    // Create a queue for BFS
//    std::list<int> Stack;

//    // Mark the current node as visited and enqueue it
//   // visited[source] = true;
//    Stack.push_front(source);

//    DFSREC_M(source,destination, visited, Stack, adjmatrix);
//}
