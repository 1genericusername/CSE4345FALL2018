//#include "dfs.h"

//void depthfirstsearch::DFS_L(int source, int d, std::list<std::pair<int,int>>* adjlist)
//{

//    bool *visited = new bool[numVertices];
//    for(int i = 0; i < numVertices; i++)
//    {
//        visited[i] = false;
//    }

//    std::list<int> Stack;

//    Stack.push_front(source);

//    while (!Stack.empty())
//    {
//        source = Stack.front();
//        Stack.pop_front();

//        if (!visited[source])
//        {
//            std::cout << source << std::endl;
//            visited[source] = true;
//            if(visited[d] == true)
//            {
//                break;
//            }
//        }

//         for (auto i = adjlist[source].begin(); i != adjlist[source].end(); ++i)
//         {
//            int dest = i->first;
//            if (visited[dest] == false)
//            {
//               Stack.push_front(dest);
//            }

//         }
//      }
//}


//void depthfirstsearch::DFS_M(int source, int dest, int **adjMatrix)
//{
//    // Mark all the vertices as not visited
//        bool *visited = new bool[numVertices];
//        for(int i = 0; i < numVertices; i++)
//            visited[i] = false;

//        // Create a queue for BFS
//        std::list<int> Stack;

//        // Mark the current node as visited and enqueue it
//        Stack.push_front(source);

//        while(!Stack.empty())
//        {
//            // Dequeue a vertex from queue and print it
//            source = Stack.front();
//            Stack.pop_front();

//            if(!visited[source])
//            {
//                std::cout << source << std::endl;
//                visited[source] = true;
//                if(visited[dest] == true)
//                {
//                    break;
//                }
//            }


//            for (int i = 0; i < numVertices; ++i)
//            {
//                    if(adjMatrix[source][i] != 0 && visited[i] == false)
//                    {
//                            Stack.push_front(i);
//                    }

//             }

//        }
//}
