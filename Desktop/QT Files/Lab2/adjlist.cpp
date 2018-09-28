#include "adjlist.h"
#include <ctime>

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

void AdjList::Print()
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

void AdjList::Build(string filename, string filename2)
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

void AdjList::BFS(int Source, int Destination)
{
    int sourceV=Destination;
    int destinationV=Source;

    for(int i=0;i<2;i++)
    {
    if(i==1)
    {
       Source=sourceV;
       Destination=destinationV;
    }
    using timer = std::chrono::high_resolution_clock;
    timer::time_point start_time = timer::now();

    // Mark all the vertices as not visited
        bool *visited = new bool[numVertices];
        for(int i = 0; i < numVertices; i++)
            visited[i] = false;

        // Create a Queue for BFS
        list<int> Queue;
        vector<int> nodesVisited;
        int totalDistance = 0;
        list<int> cost;
        vector<int> nodesPath;
        int destination;

        // Mark the current node as visited and enQueue it
        visited[Source] = true;
        Queue.push_back(Source);

        // 'i' will be used to get all adjacent
        // vertices of a vertex

        while(!Queue.empty())
        {
            // DeQueue a vertex from Queue and print it
            Source = Queue.front();
            cout << Source << " ";
            nodesPath.push_back(Source);
            totalDistance += cost.front();
            if(Queue.front() == Destination)
            {
                break;
            }

            Queue.pop_front();
            cost.pop_front();

            // Get all adjacent vertices of the deQueued
            // vertex s. If a adjacent has not been visited,
            // then mark it visited and enQueue it
            for (auto i = adjlist[Source].begin(); i != adjlist[Source].end(); ++i)
            {
                destination = i->first;
                cost.push_back(i->second);
                if (visited[destination] == false)
                {
                    visited[destination] = true;
                    Queue.push_back(destination);
                    nodesVisited.push_back(destination);
                }
            }

        }
        timer::time_point end_time = timer::now();
        ostringstream x;
        x << chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
        string Time = x.str();
        cout << endl;
        cout << "NodesPathSize:" << nodesPath.size() << " NodesVisited:" << nodesVisited.size() << " Time:" << Time << " Distance:" << totalDistance << endl;
        cout << "================================" << endl;
    }



}

void AdjList::BFSREC(int Source,int Destination, bool visited[], list<int> Queue, vector<int>& nodesVisited, int& totalDistance, list<int>& cost,  vector<int>& nodesPath)
{

    // Mark the current node as visited and
    Source = Queue.front();
    cout << Source << " ";
    nodesPath.push_back(Source);
    totalDistance += cost.front();

    if(Queue.front() != Destination)
    {

        Queue.pop_front();
        cost.pop_front();
        // Recur for all the vertices adjacent
        // to this vertex

        int destination = 0;

        for (auto i = adjlist[Source].begin(); i != adjlist[Source].end(); ++i)
        {
            destination = i->first;
            cost.push_back(i->second);
            if (visited[destination] == false)
            {
                visited[destination] = true;
                Queue.push_back(destination);
                nodesVisited.push_back(destination);
            }
        }
        BFSREC(destination,Destination, visited, Queue,nodesVisited,totalDistance,cost,nodesPath);
     }

}

void AdjList::BFSR(int Source, int Destination)
{  
    int sourceV=Destination;
    int destinationV=Source;

    for(int i=0;i<2;i++)
    {
    if(i==1)
    {
       Source=sourceV;
       Destination=destinationV;
    }
    using timer = std::chrono::high_resolution_clock;
    timer::time_point start_time = timer::now();

        vector<int> nodesVisited;
        int totalDistance = 0;
        list<int> cost;
        vector<int> nodesPath;

        // Mark all the vertices as not visited
        bool *visited = new bool[numVertices];
        for(int i = 0; i < numVertices; i++)
            visited[i] = false;

        // Create a Queue for BFS
        list<int> Queue;

        // Mark the current node as visited and enQueue it
        visited[Source] = true;
        Queue.push_back(Source);

        // Call the recursive helper function
        // to print DFS traversal
        BFSREC(Source,Destination, visited, Queue,nodesVisited,totalDistance,cost,nodesPath);

        timer::time_point end_time = timer::now();
        ostringstream x;
        x << chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
        string Time = x.str();

        cout << endl;
        cout << "NodesPathSize:" << nodesPath.size() << " NodesVisited:" << nodesVisited.size() << " Time:" << Time << " Distance:" << totalDistance << endl;
        cout << "================================" << endl;
    }

}

void AdjList::DFS(int s, int d)
{

    int sourceV=d;
    int destinationV=s;

    for(int i=0;i<2;i++)
    {
    if(i==1)
    {
       s=sourceV;
       d=destinationV;
    }
    using timer = std::chrono::high_resolution_clock;
    timer::time_point start_time = timer::now();

    // Initially mark all verices as not visited
    bool *visited = new bool[numVertices];
    for(int i = 0; i < numVertices; i++)
        visited[i] = false;

        // Create a Stack for DFS
        list<int> Stack;
        vector<int> nodesVisited;
        int totalDistance = 0;
        list<int> cost;
        vector<int> nodesPath;

        // Push the current source node.
        Stack.push_front(s);

        while (!Stack.empty())
        {

            // Pop a vertex from Stack and print it
            s = Stack.front();
            Stack.pop_front();
            nodesPath.push_back(s);
            totalDistance += cost.front();


            if (!visited[s])
            {
                cout << s << " ";
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
                 {

                    cost.push_front(i->second);
                    Stack.push_front(dest);
                     nodesVisited.push_back(s);
                 }
            }
        }

        timer::time_point end_time = timer::now();
        ostringstream x;
        x << chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
        string Time = x.str();

        cout << endl;
        cout << "NodesPathSize:" << nodesPath.size() << " NodesVisited:" << nodesVisited.size() << " Time:" << Time << " TotalDistance:" << totalDistance << endl;
        cout << "================================" << endl;
    }


}

void AdjList::DFSREC(int s, int d, bool visited[], list<int> Stack, vector<int>& nodesVisited, int& totalDistance, list<int>& cost,  vector<int>& nodesPath)
{
    // Mark the current node as visited and
        // print it

    s = Stack.front();
    Stack.pop_front();
    nodesPath.push_back(s);
    totalDistance += cost.front();

    // Stack may contain same vertex twice. So
    // we need to print the popped item only
    // if it is not visited.
    if (!visited[s])
    {
        cout << s << " ";
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
                cost.push_front(i->second);
                nodesVisited.push_back(s);
            }
        }
        DFSREC(dest,d, visited, Stack, nodesVisited, totalDistance, cost, nodesPath);
     }
}

void AdjList::DFSR(int s, int d)
{
    int sourceV=d;
    int destinationV=s;

    for(int i=0;i<2;i++)
    {
    if(i==1)
    {
       s=sourceV;
       d=destinationV;
    }
    using timer = std::chrono::high_resolution_clock;
    timer::time_point start_time = timer::now();

        vector<int> nodesVisited;
        int totalDistance = 0;
        list<int> cost;
        vector<int> nodesPath;

    // Mark all the vertices as not visited
        bool *visited = new bool[numVertices];
        for (int i = 0; i < numVertices; i++)
            visited[i] = false;

        list<int> Stack;

        Stack.push_front(s);

        // Call the recursive helper function
        // to print DFS traversal
        DFSREC(s,d, visited, Stack, nodesVisited, totalDistance, cost, nodesPath);

        timer::time_point end_time = timer::now();
        ostringstream x;
        x << chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
        string Time = x.str();
        cout << endl;
        cout << "NodesPathSize:" << nodesPath.size() << " NodesVisited:" << nodesVisited.size() << " Time:" << Time << " TotalDistance:" << totalDistance << endl;
        cout << "================================" << endl;
    }
}

double AdjList::heuristic(double x1, double y1, double x2, double y2, int cost)
{
   double dist = pow(pow(x2-x1,2)+pow(y2-y1,2),0.5);
   double heur = dist*(1+cost);
   return heur;
}

void AdjList::A_star(int Source, int destination)
{

    int sourceV=destination;
    int destinationV=Source;

    for(int i=0;i<2;i++)
    {
    if(i==1)
    {
       Source=sourceV;
       destination=destinationV;
    }
    using timer = std::chrono::high_resolution_clock;
    timer::time_point start_time = timer::now();


        list<int> stack;
        vector<double> tempvector;
        vector<int> nodes;

        vector<int> nodesVisited;
        int totalDistance = 0;
        vector<int> cost;
        int costTemp = 0;
        vector<int> nodesPath;

        bool *visited = new bool[numVertices];
        for(int i = 0; i < numVertices; i++)
            visited[i] = false;

        stack.push_back(Source);
        nodesPath.push_back(Source);

        auto one = positions[Source].begin();
        auto two = positions[destination].begin();
        double temp = heuristic(one->first,one->second,two->first,two->second,totalDistance);

        while (!stack.empty())
        {
            Source = stack.front();
            stack.pop_front();

            if(!visited[Source])
            {
                cout << Source << " ";
                visited[Source] = true;
                if(visited[destination] == true)
                {
                    break;
                }
            }

            for (auto i = adjlist[Source].begin(); i != adjlist[Source].end(); ++i)
            {
                int v = i->first;
                int weight = i->second;
                auto one = positions[v].begin();
                auto two = positions[destination].begin();
                double temp = heuristic(one->first,one->second,two->first,two->second,weight);
                tempvector.push_back(temp);
                nodes.push_back(v);
                cost.push_back(weight);
            }

            double smallest = tempvector[0];
            int smallestL = nodes[0];
                for(unsigned int i=0;i<tempvector.size();i++)
                {
                    if(tempvector[i]<smallest)
                    {
                        smallest=tempvector[i];
                        smallestL = nodes[i];
                        costTemp = cost[i];
                    }
                }

                nodesVisited.push_back(smallestL);
                nodesPath.push_back(smallestL);
                totalDistance += costTemp;
                stack.push_back(smallestL);

                tempvector.clear();
                nodes.clear();
                cost.clear();
        }

        timer::time_point end_time = timer::now();
        ostringstream x;
        x << chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
        string Time = x.str();


        cout << endl;

        cout << "NodesPathSize:" << nodesPath.size() << " NodesVisited:" << nodesVisited.size() << " Time:" << Time << " Distance:" << totalDistance << " Heuristic:"  << temp << "\n";
        cout << "===================================" << endl;
    }

}

void AdjList::dijkstra(int source, int destination)
{

    int sourceV=destination;
    int destinationV=source;

    for(int i=0;i<2;i++)
    {
    if(i==1)
    {
       source=sourceV;
       destination=destinationV;
    }
        using timer = std::chrono::high_resolution_clock;
        timer::time_point start_time = timer::now();


        vector<int> nodesVisited;
        vector<int> cost;
        vector<int> nodesPath;


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
        nodesPath.push_back(source);
        dist[source] = 0;

        // Loop until empty
        while (!pq.empty())
        {
            int u = pq.front().second;
            pq.pop_front();
            nodesVisited.push_back(u);
            cout << u << " ";

            for (auto i = adjlist[u].begin(); i != adjlist[u].end(); ++i)
            {
                // Get vertex label and weight of current adjacent
                // of u.
                int v = i->first;
                int weight = i->second;

                //  If there is shorted path to v through u.
                if (dist[v] > dist[u] + weight)
                {
                    // Update v
                    dist[v] = dist[u] + weight;
                    pq.push_back(make_pair(dist[v], v));
                    nodesPath.push_back(v);

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
   //     cout << "The shortest path from " << source << " to " << destination << " is " << dist[destination] << endl;


        timer::time_point end_time = timer::now();
        ostringstream x;
        x << chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
        string Time = x.str();
        cout << destination << " ";
        cout << endl;
        cout  << "NodesInPath:" << nodesVisited.size()+1 << " NodesVisited:" << nodesVisited.size() << " Time:" << Time << " Distance:" << dist[destination] << "\n";
        cout << "=============================================" << endl;
}


}


