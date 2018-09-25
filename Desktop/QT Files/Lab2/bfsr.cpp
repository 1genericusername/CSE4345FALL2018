#include "bfsr.h"

void breadthfirstsearchRecursive::BFSREC_L(int source, int destination, bool visited[], std::list<int> Queue, std::list<std::pair<int, int> > *adjlist)
{

    source = Queue.front();
    std::cout << source << " ";

    if(Queue.front() != destination)
    {

        Queue.pop_front();
        // Recur for all the vertices adjacent
        // to this vertex

        int nxtNode = 0;

        for (auto i = adjlist[source].begin(); i != adjlist[source].end(); ++i)
        {
            nxtNode = i->first;
            if (visited[nxtNode] == false)
            {
                visited[nxtNode] = true;
                Queue.push_back(nxtNode);
            }
        }
        BFSREC_L(nxtNode,destination, visited, Queue, adjlist);
     }
}

void breadthfirstsearchRecursive::BFSR_L(int source, int destination, std::list<std::pair<int, int> > *adjlist)
{
    // Mark all the vertices as not visited
    bool *visited = new bool[numVertices];
    for(int i = 0; i < numVertices; i++)
        visited[i] = false;

    // Create a Queue for BFS
    std::list<int> Queue;

    // Mark the current node as visited and enQueue it
    visited[source] = true;
    Queue.push_back(source);

    // Call the recursive function
    BFSREC_L(source,destination, visited, Queue, adjlist);
}


void breadthfirstsearchRecursive::BFSREC_M(int source, int d, bool visited[], std::list<int> Queue, int **adjMatrix)
{
    source = Queue.front();
    std::cout << source << " ";

    if(Queue.front() != d)
    {
    Queue.pop_front();
    int destination = 0;
    for (int i = 1; i < numVertices; ++i)
    {
            if(adjMatrix[source][i] != 0 && (! visited[i]))
            {
                destination = i;
                Queue.push_back(i);
                visited[i] = true;
            }
    }
    BFSREC_M(destination,d, visited, Queue, adjMatrix);
    }
}

void breadthfirstsearchRecursive::BFSR_M(int source, int destination, int **adjMatrix)
{
    // Mark all the vertices as not visited
        bool *visited = new bool[numVertices];
        for (int i = 0; i < numVertices; i++)
            visited[i] = false;

        std::list<int> Stack;

        Stack.push_front(source);

        // Call the recursive helper function
        // to print DFS traversal
        BFSREC_M(source,destination, visited, Stack, adjMatrix);
}
