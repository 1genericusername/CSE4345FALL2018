#include <adjlist.h>

AdjList::AdjList(int size)
{
    numVertices = size+1;
    adjlist = new list<pair<int,int>>[size+1];

    positions = new list<pair<int,int>>[size+1];
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

    for (int i = 1; i < numVertices; i++)
        {
    for (auto Iterator = positions[i].begin(); Iterator!=positions[i].end(); Iterator++)
    {
        destination = Iterator->first;
        weight = Iterator->second;
        cout << "X:" << destination << "Y:"
             << weight << "\n";
    }
    }
}

void AdjList::buildList(string filename, string filename2)
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
    inFile.close();

    int node,x,y;
    inFile.open(filename2);
    while(inFile >> node)
    {
        getline(inFile,line,',');
        inFile >> x;
        getline(inFile,line,',');
        inFile >> y;
        getline(inFile,line,',');
        positions[node].push_back(make_pair(x,y));
        inFile >> node;
    }

}


void AdjList::BFS(int source, int d)
{
    // Mark all the vertices as not visited
        bool *visited = new bool[numVertices];
        for(int i = 0; i < numVertices; i++)
            visited[i] = false;

        // Create a Queue for BFS
        list<int> Queue;
        int destination;

        // Mark the current node as visited and enQueue it
        visited[source] = true;
        Queue.push_back(source);

        // 'i' will be used to get all adjacent
        // vertices of a vertex

        while(!Queue.empty())
        {
            // DeQueue a vertex from Queue and print it
            source = Queue.front();
            cout << source << " ";

            if(Queue.front() == d)
            {
                break;
            }

            Queue.pop_front();

            // Get all adjacent vertices of the deQueued
            // vertex s. If a adjacent has not been visited,
            // then mark it visited and enQueue it
            for (auto i = adjlist[source].begin(); i != adjlist[source].end(); ++i)
            {
                destination = i->first;
                if (visited[destination] == false)
                {
                    visited[destination] = true;
                    Queue.push_back(destination);
                }
            }

        }
}

void AdjList::BFSREC(int s, int d, bool visited[], list<int> Queue)
{
    // Mark the current node as visited and
        // print it
    s = Queue.front();
    cout << s << " ";

    if(Queue.front() != d)
    {

        Queue.pop_front();
        // Recur for all the vertices adjacent
        // to this vertex

        int destination = 0;

        for (auto i = adjlist[s].begin(); i != adjlist[s].end(); ++i)
        {
            destination = i->first;
            if (visited[destination] == false)
            {
                visited[destination] = true;
                Queue.push_back(destination);
            }
        }
        BFSREC(destination,d, visited, Queue);
     }
}

// DFS traversal of the vertices reachable from v.
// It uses recursive DFSUtil()
void AdjList::BFSR(int s, int d)
{
        // Mark all the vertices as not visited
        bool *visited = new bool[numVertices];
        for(int i = 0; i < numVertices; i++)
            visited[i] = false;

        // Create a Queue for BFS
        list<int> Queue;

        // Mark the current node as visited and enQueue it
        visited[s] = true;
        Queue.push_back(s);

        // Call the recursive helper function
        // to print DFS traversal
        BFSREC(s,d, visited, Queue);
}

void AdjList::DFS(int s, int d)
{
    // Initially mark all verices as not visited
    bool *visited = new bool[numVertices];
    for(int i = 0; i < numVertices; i++)
        visited[i] = false;

        // Create a Stack for DFS
        list<int> Stack;

        // Push the current source node.
        Stack.push_front(s);

        while (!Stack.empty())
        {

            // Pop a vertex from Stack and print it
            s = Stack.front();
            Stack.pop_front();

            if (!visited[s])
            {
                cout << s << endl;
                visited[s] = true;
                if(visited[d] == true)
                {
                    break;
                }
            }

            for (auto i = adjlist[s].begin(); i != adjlist[s].end(); ++i)
            {
                int dest = i->first;
                if (visited[dest] == false)
                    Stack.push_front(dest);
            }
        }

}

void AdjList::DFSREC(int s, int d, bool visited[], list<int> Stack)
{
    // Mark the current node as visited and
        // print it

    s = Stack.front();
    Stack.pop_front();

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

        int dest = 0;

        for (auto i = adjlist[s].begin(); i != adjlist[s].end(); ++i)
        {
            dest = i->first;
            if (visited[dest] == false)
            {
                Stack.push_front(dest);
            }
        }
        DFSREC(dest,d, visited, Stack);
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

        list<int> Stack;

        Stack.push_front(s);

        // Call the recursive helper function
        // to print DFS traversal
        DFSREC(s,d, visited, Stack);
}

double AdjList::heuristic(double x1, double y1, double x2, double y2, int cost)
{
   double dist = pow(pow(x2-x1,2)+pow(y2-y1,2),0.5);
   double heur = dist*(1+cost);
   return heur;
}

void AdjList::A_star(int source, int destination)
{
        list<int> stack;
        vector<double> tempvector;
        vector<int> nodes;

        bool *visited = new bool[numVertices];
        for(int i = 0; i < numVertices; i++)
            visited[i] = false;

        stack.push_back(source);

        while (!stack.empty())
        {
            source = stack.front();
            stack.pop_front();

            if(!visited[source])
            {
                cout << source << endl;
                visited[source] = true;
                if(visited[destination] == true)
                {
                    break;
                }
            }

            for (auto i = adjlist[source].begin(); i != adjlist[source].end(); ++i)
            {
                int v = i->first;
                int weight = i->second;
                auto one = positions[v].begin();
                auto two = positions[destination].begin();
                double temp = heuristic(one->first,one->second,two->first,two->second,weight);
                tempvector.push_back(temp);
                nodes.push_back(v);
            }

            double smallest = tempvector[0];
            int smallestL = nodes[0];
                for(unsigned int i=0;i<tempvector.size();i++)
                {
                    if(tempvector[i]<smallest)
                    {
                        smallest=tempvector[i];
                        smallestL = nodes[i];
                    }
                }

                stack.push_back(smallestL);

                tempvector.clear();
                nodes.clear();
        }

}

void AdjList::dijkstra(int source, int destination)
{
        list<pair<int,int>> pq;

        //vector<int> dist(numVertices, INT_MAX);
        int dist[numVertices];
        for (int i = 0; i < numVertices; i++)
        {
            dist[i] = INT_MAX;
        }

        // Insert source itself in priority Queue and initialize
        // its distance as 0.
        pq.push_back(make_pair(0, source));
        dist[source] = 0;

        /* Looping till priority Queue becomes empty (or all
          distances are not finalized) */
        while (!pq.empty())
        {
            int u = pq.front().second;
            pq.pop_front();

            for (auto i = adjlist[u].begin(); i != adjlist[u].end(); ++i)
            {
                // Get vertex label and weight of current adjacent
                // of u.
                int v = i->first;
                int weight = i->second;

                //  If there is shorted path to v through u.
                if (dist[v] > dist[u] + weight)
                {
                    // Updating distance of v
                    dist[v] = dist[u] + weight;
                    pq.push_back(make_pair(dist[v], v));
                }
            }

            if(dist[destination] != INT_MAX)
            {
                break;
            }
        }

        // Print shortest distances stored in dist[]
  //      printf("Vertex   Distance from Source\n");
   //     for (int i = 1; i < numVertices; ++i)
     //       printf("%d \t\t %d\n", i, dist[i]);
        cout << "The shortest path from " << source << " to " << destination << " is " << dist[destination] << endl;
}


