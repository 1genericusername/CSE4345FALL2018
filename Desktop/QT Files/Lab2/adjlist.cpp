#include <adjlist.h>

AdjList::AdjList(int size)
{
    numVertices = size+1;
    adjlist = new list<pair<int,int>>[size+1];
    visited = new bool[size+1];
    for(int i=0;i<size+1;i++)
    {
        visited[i] = false;
    }
}

void AdjList::addVertice(int source, int destination, int weight)
{
    adjlist[source].push_back(make_pair(destination,weight));
}

void AdjList::printlist()
{
    int destination;
    int weight;
    for (int i = 1; i < numVertices; i++)
        {
            cout << "Node " << i << " makes an edge with \n";
            for (auto Iterator = adjlist[i].begin(); Iterator!=adjlist[i].end(); Iterator++)
            {
                destination = Iterator->first;
                weight = Iterator->second;
                cout << "\tNode " << destination << " with edge weight = "
                     << weight << "\n";
            }
            cout << "\n";
        }
}

void AdjList::buildList(string filename)
{
    int Node1,Node2,weight;
    string line;
    ifstream inFile;
    inFile.open(filename);
    while(inFile >> Node1)
    {
        getline(inFile,line,',');
        inFile >> Node2;
        getline(inFile,line,',');
        inFile >> weight;
        addVertice(Node1,Node2,weight);
    }
}


void AdjList::BFS(int source, int d)
{
    // Mark all the vertices as not visited
        bool *visited = new bool[numVertices];
        for(int i = 0; i < numVertices; i++)
            visited[i] = false;

        // Create a queue for BFS
        list<int> queue;
        int destination;

        // Mark the current node as visited and enqueue it
        visited[source] = true;
        queue.push_back(source);

        // 'i' will be used to get all adjacent
        // vertices of a vertex

        while(!queue.empty())
        {
            // Dequeue a vertex from queue and print it
            source = queue.front();
            cout << source << " ";

            if(queue.front() == d)
            {
                break;
            }

            queue.pop_front();

            // Get all adjacent vertices of the dequeued
            // vertex s. If a adjacent has not been visited,
            // then mark it visited and enqueue it
            for (auto i = adjlist[source].begin(); i != adjlist[source].end(); ++i)
            {
                destination = i->first;
                if (visited[destination] == false)
                {
                    visited[destination] = true;
                    queue.push_back(destination);
                }
            }

        }
}

void AdjList::DFS(int s, int d)
{
    // Initially mark all verices as not visited
    bool *visited = new bool[numVertices];
    for(int i = 0; i < numVertices; i++)
        visited[i] = false;

        // Create a stack for DFS
        list<int> stack;

        // Push the current source node.
        stack.push_front(s);

        while (!stack.empty())
        {

            // Pop a vertex from stack and print it
            s = stack.front();
            stack.pop_front();

            // Stack may contain same vertex twice. So
            // we need to print the popped item only
            // if it is not visited.
            if (!visited[s])
            {
                cout << s << endl;
                visited[s] = true;
                if(visited[d] == true)
                {
                    break;
                }
            }



            // Get all adjacent vertices of the popped vertex s
            // If a adjacent has not been visited, then puah it
            // to the stack.
            for (auto i = adjlist[s].begin(); i != adjlist[s].end(); ++i)
            {
                int dest = i->first;
                if (visited[dest] == false)
                    stack.push_front(dest);
            }

        }

}

void AdjList::DFSREC(int s, int d, bool visited[], list<int> stack)
{
    // Mark the current node as visited and
        // print it

    s = stack.front();
    stack.pop_front();

    // Stack may contain same vertex twice. So
    // we need to print the popped item only
    // if it is not visited.
    if (!visited[s])
    {
        cout << s << endl;
        visited[s] = true;
    }


    if(visited[d] != true)
    {
        // Recur for all the vertices adjacent
        // to this vertex

        int dest;

        for (auto i = adjlist[s].begin(); i != adjlist[s].end(); ++i)
        {
            dest = i->first;
            if (visited[dest] == false)
            {
                stack.push_front(dest);
              //  DFSUtil(dest, visited, stack);
            }
        }
        DFSREC(dest,d, visited, stack);
     }
}

// DFS traversal of the vertices reachable from v.
// It uses recursive DFSUtil()
void AdjList::DFSR(int s, int d)
{
    // Mark all the vertices as not visited
        bool *visited = new bool[numVertices];
        for (int i = 0; i < numVertices; i++)
            visited[i] = false;

        list<int> stack;

        stack.push_front(s);

        // Call the recursive helper function
        // to print DFS traversal
        DFSREC(s,d, visited, stack);
}

