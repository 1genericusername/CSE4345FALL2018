#include "bfs.h"


void breadthfirstsearch::BFS_L(int source, int destination, std::list<std::pair<int,int>>* adjlist)
{

        int numVertices = 17;
    //Mark all the vertices as not visited
        bool *visited = new bool[numVertices];
        for(int i = 0; i < numVertices; i++)
        {
            visited[i] = false;
        }

    //Make a Queue for BFS
        std::list<int> Queue;
        int nxtNode;

    // Mark the current node as visited and enQueue it
        visited[source] = true;
        Queue.push_back(source);

        while(!Queue.empty())
        {
            //DeQueue vertex and print it
            source = Queue.front();
            std::cout << source << " ";

            if(Queue.front() == destination)
            {
                break;
            }
            Queue.pop_front();

            for (auto i = adjlist[source].begin(); i != adjlist[source].end(); ++i)
            {
                nxtNode = i->first;
                if (visited[nxtNode] == false)
                {
                    visited[nxtNode] = true;
                    Queue.push_back(nxtNode);
                }
            }

        }

}

void breadthfirstsearch::BFS_M(int source, int destination, int** adjMatrix)
{
        int numVertices = 17;
    // Mark all the vertices as not visited
        bool *visited = new bool[numVertices];
        for(int i = 0; i < numVertices; i++)
        {
            visited[i] = false;
        }

        std::list<int> Queue;

        // Mark the current node as visited
        visited[source] = true;
        Queue.push_back(source);

        // 'i' will be used to get all adjacent
        // vertices of a vertex

        while(!Queue.empty())
        {
            // Dequeue a vertex from queue and print it
            source = Queue.front();
            std::cout << source << " ";

            if(Queue.front() == destination)
            {
                break;
            }

            Queue.pop_front();

            for (int i = 0; i < numVertices; ++i){
                    if(adjMatrix[source][i] != 0 && (! visited[i]) )
                    {
                        Queue.push_back(i);
                        visited[i] = true;
                    }
                }

        }
}

