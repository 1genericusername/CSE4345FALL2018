#include "adjmatrix.h"
#include "iostream"
#include "fstream"

//Constructor
AdjMatrix::AdjMatrix(int numVertices)
{
    this->numVertices = numVertices;
    adjMatrix = new int*[numVertices];
    for (int i = 0; i < numVertices; i++)
    {
        adjMatrix[i] = new int[numVertices];
        for (int j = 0; j < numVertices; j++)
        {
            adjMatrix[i][j] = 0;
        }
  }


    positions = new list<pair<int,int>>[numVertices+1];
}

//Add Vertice with weight
void AdjMatrix::addVertice(int i, int j, int k)
{
    adjMatrix[i][j] = k;
    adjMatrix[j][i] = k;
}


//Print the contents of the matrix
void AdjMatrix::Print()
{

    for (int i = 1; i < numVertices; i++)
    {
        cout << i << "   ";
        for (int j = 1; j < numVertices; j++)
        {
            cout << adjMatrix[i][j] << " ";
        }
        cout << "\n";
    }


}

//Load file into matrix
void AdjMatrix::Build(std::string filename,string filename2)
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

void AdjMatrix::BFS(int source,int dest)
{
        int sourceV=dest;
        int destV=source;

        for(int i=0;i<2;i++)
        {
        if(i==1)
        {
           source=sourceV;
           dest=destV;
        }
        using timer = std::chrono::high_resolution_clock;
        timer::time_point start_time = timer::now();

        cout << "Path:";

        vector<int> nodesVisited;
        int totalDistance = 0;
        list<int> cost;
        vector<int> nodesPath;

    // Mark all the vertices as not visited
        bool *visited = new bool[numVertices];
        for(int i = 0; i < numVertices; i++)
            visited[i] = false;

        // Create a queue for BFS
        list<int> queue;

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
            nodesPath.push_back(source);
            totalDistance += cost.front();

            if(queue.front() == dest)
            {
                break;
            }
            cost.pop_front();
            queue.pop_front();

            for (int i = 0; i < numVertices; ++i){
                    if(adjMatrix[source][i] != 0 && (! visited[i]) )
                    {
                        nodesVisited.push_back(i);
                        cost.push_back(adjMatrix[source][i]);
                        queue.push_back(i);
                        visited[i] = true;
                    }
                }

        }

        timer::time_point end_time = timer::now();
        ostringstream x;
        x << chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
        string Time = x.str();
        cout << endl;
        cout << "NodesPathSize:" << nodesPath.size() << " NodesVisitedSize:" << nodesVisited.size() << " TimeTaken(ms):" << Time << " Distance:" << totalDistance << endl;
        cout << "================================================" << endl;
        }
}

void AdjMatrix::BFSREC(int s,int d, bool visited[], std::list<int> Stack, std::vector<int>& nodesVisited, int& totalDistance, std::list<int>& cost,  std::vector<int>& nodesPath)
{
    s = Stack.front();
    cout << s << " ";
    nodesPath.push_back(s);
    totalDistance += cost.front();

    if(Stack.front() != d)
    {
    cost.pop_front();
    Stack.pop_front();
    int destination = 0;
    for (int i = 1; i < numVertices; ++i)
    {
            if(adjMatrix[s][i] != 0 && (! visited[i]))
            {
                nodesVisited.push_back(i);
                cost.push_back(adjMatrix[s][i]);
                destination = i;
                Stack.push_back(i);
                visited[i] = true;
            }
    }
    BFSREC(destination,d, visited, Stack, nodesVisited, totalDistance, cost, nodesPath);
    }
}

void AdjMatrix::BFSR(int source, int dest)
{

    int sourceV=dest;
    int destV=source;

    for(int i=0;i<2;i++)
    {
    if(i==1)
    {
       source=sourceV;
       dest=destV;
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

    // Create a queue for BFS
    list<int> Queue;

    // Mark the current node as visited and enqueue it
    visited[source] = true;
    Queue.push_back(source);

    BFSREC(source,dest, visited, Queue, nodesVisited, totalDistance, cost, nodesPath);
    cout << endl;

    timer::time_point end_time = timer::now();
    ostringstream x;
    x << chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
    string Time = x.str();

    cout << "NodesPathSize:" << nodesPath.size() << " NodesVisitedSize:" << nodesVisited.size() << " TimeTaken(ms):" << Time << " Distance:" << totalDistance << endl;
    cout << "======================" << endl;
    }
}

void AdjMatrix::DFSREC(int source, int d, bool visited[], list<int> Stack, vector<int>& nodesVisited, int& totalDistance, list<int>& cost,  vector<int>& nodesPath)
{
    source = Stack.front();
    nodesPath.push_back(source);
    Stack.pop_front();
    totalDistance += cost.front();
    cost.pop_front();

    if (!visited[source])
    {
        cout << source << " ";
        visited[source] = true;
    }


    if(visited[d] == false)
    {

    int destination = 0;
    for (int i = 1; i < numVertices; ++i)
    {
            if(adjMatrix[source][i] != 0 && (visited[i] == false))
            {
                destination = i;
                Stack.push_front(i);
                nodesVisited.push_back(i);
                cost.push_back(adjMatrix[source][i]);
         //       visited[i] = true;
            }
    }
    DFSREC(destination,d, visited, Stack,nodesVisited,totalDistance,cost,nodesPath);

    }
}

void AdjMatrix::DFSR(int source, int dest)
{
    int sourceV=dest;
    int destinationV=source;

    for(int i=0;i<2;i++)
    {
    if(i==1)
    {
       source=sourceV;
       dest=destinationV;
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

    // Create a queue for BFS
    list<int> Stack;

    // Mark the current node as visited and enqueue it
   // visited[source] = true;
    Stack.push_front(source);

    DFSREC(source,dest, visited, Stack, nodesVisited, totalDistance, cost, nodesPath);

    timer::time_point end_time = timer::now();
    ostringstream x;
    x << chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
    string Time = x.str();
    cout << endl;
    cout << "NodesPathSize:" << nodesPath.size() << " NodesVisited:" << nodesVisited.size() << " Time(ms):" << Time << " Distance:" << totalDistance << endl;
    cout << "=======================" << endl;
    }
}

void AdjMatrix::DFS(int source, int dest)
{

    int sourceV=dest;
    int destinationV=source;

    for(int i=0;i<2;i++)
    {
    if(i==1)
    {
       source=sourceV;
       dest=destinationV;
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

        // Create a queue for BFS
        list<int> Stack;

        // Mark the current node as visited and enqueue it
        Stack.push_front(source);

        while(!Stack.empty())
        {
            // Dequeue a vertex from queue and print it
            source = Stack.front();
            nodesPath.push_back(source);
            Stack.pop_front();
            totalDistance += cost.front();
            cost.pop_front();

            if(!visited[source])
            {
                cout << source << " ";
                visited[source] = true;
                if(visited[dest] == true)
                {
                    break;
                }
            }


            for (int i = 0; i < numVertices; ++i)
            {
                    if(adjMatrix[source][i] != 0 && visited[i] == false)
                    {
                            nodesVisited.push_back(i);
                            cost.push_back(adjMatrix[source][i]);
                            Stack.push_front(i);
                    }

             }

        }

        timer::time_point end_time = timer::now();
        ostringstream x;
        x << chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
        string Time = x.str();
        cout << endl;

        cout << "NodesPathSize:" << nodesPath.size() << " NodesVisited:" << nodesVisited.size() << " Time(ms):" << Time << " Distance:" << totalDistance << endl;
        cout << "==========================================" << endl;
    }


}

double AdjMatrix::heuristic(double x1, double y1, double x2, double y2, int cost)
{
   double dist = pow(pow(x2-x1,2)+pow(y2-y1,2),0.5);
   double heur = dist*(1+cost);
   return heur;
}

void AdjMatrix::A_star(int source, int dest)
{
    int sourceV=dest;
    int destinationV=source;

    for(int i=0;i<2;i++)
    {
    if(i==1)
    {
       source=sourceV;
       dest=destinationV;
    }

        using timer = std::chrono::high_resolution_clock;
        timer::time_point start_time = timer::now();

        vector<int> nodesVisited;
        int totalDistance = 0;
        vector<int> cost;
        vector<int> nodesPath;

    // Mark all the vertices as not visited
        bool *visited = new bool[numVertices];
        for(int i = 0; i < numVertices; i++)
            visited[i] = false;

        // Create a queue for BFS
        list<int> Stack;
        vector<double> tempvector;
        vector<int> nodes;

        // Mark the current node as visited and enqueue it
        Stack.push_back(source);

        auto one = positions[source].begin();
        auto two = positions[dest].begin();
        double temp = heuristic(one->first,one->second,two->first,two->second,totalDistance);

        while(!Stack.empty())
        {
            // Dequeue a vertex from queue and print it
            source = Stack.front();
            Stack.pop_front();
            nodesPath.push_back(source);
            nodesVisited.push_back(source);

            if(!visited[source])
            {
                cout << source << " ";
                visited[source] = true;
                if(visited[dest] == true)
                {
                    break;
                }
            }


            for (int i = 0; i < numVertices; ++i)
            {
                    if(adjMatrix[source][i] != 0 && visited[i] == false )
                    {
                        auto one = positions[i].begin();
                        auto two = positions[dest].begin();
                        double temp = heuristic(one->first,one->second,two->first,two->second,adjMatrix[source][i]);
                        tempvector.push_back(temp);
                        nodes.push_back(i);
                        cost.push_back(adjMatrix[source][i]);
                        if(i == dest)
                        {
                            nodes.clear();
                            tempvector.clear();
                            cost.clear();
                            tempvector.push_back(temp);
                            nodes.push_back(i);
                            cost.push_back(adjMatrix[source][i]);
                        }
                         //   Stack.push_back(i);
                    }
             }

            double smallest = tempvector[0];
            int smallestL = nodes[0];
            int tmpNum = cost[0];
                for(unsigned int i=0;i<tempvector.size();i++)
                {
                    if(tempvector[i]<smallest)
                    {
                        smallest=tempvector[i];
                        smallestL = nodes[i];
                        tmpNum = cost[i];
                    }
                }

           totalDistance += tmpNum;
           Stack.push_back(smallestL);

           tempvector.clear();
           nodes.clear();
           cost.clear();

        }

        timer::time_point end_time = timer::now();
        ostringstream x;
        x << chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
        string Time = x.str();
        cout << endl;

        cout << "NodesPathSize:" << nodesPath.size() << " NodesVisited:" << nodesVisited.size() << " Time(ms)" << Time << " Distance:" << totalDistance << " Heuristic Cost:" << temp <<"\n";
        cout << "====================================" << endl;
    }

}

void AdjMatrix::dijkstra(int source,int destination)
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

    //Initialize distance and visited Stacks
    int distance[numVertices];
    bool visited[numVertices];

    //Fill distance[] with max int value, fill visited[] with false
    for (int i = 0; i < numVertices; i++)
    {
        distance[i] = INT_MAX, visited[i] = false;
    }
    //Distance from source to itself is 0
    distance[source] = 0;

   // Loop through every entry of the Adjacency List
    for (int count = 0; count < numVertices; count++)
    {
        //Create temp variables
        int min = INT_MAX;
        int min_index = 0;

        //Loop through visited[] and distance[] assigning values to min and min_index,
        //changing each time is distance[v] is less than the current min
        for (int v = 0; v < numVertices; v++)
        {
            if (visited[v] == false && distance[v] <= min)
            {
                min = distance[v];
                min_index = v;
            }
        }
        int u = min_index;
        visited[u] = true;
        nodesPath.push_back(u);
         cout << u << " ";


        //Loop through visited and and distance, comparing if the new distance value is less than the currently saved number
        for (int v = 0; v < numVertices; v++)
        {
            if (!visited[v] && adjMatrix[u][v] && distance[u] != INT_MAX && distance[u]+adjMatrix[u][v] < distance[v])
            {
                nodesVisited.push_back(u);
                distance[v] = distance[u] + adjMatrix[u][v];
           //     cout << v << " ";
                if(distance[destination] < INT_MAX)
                {

                    count = numVertices;
                    v = numVertices;
                }
            }


        }

     //   cout << u << " ";
     }
    cout << destination << " ";


  //      printf("Vertex   Distance from Source\n");
 //           for (int i = 1; i < numVertices; i++)
          //     printf("%d \t\t %d\n", i, distance[i]);



    timer::time_point end_time = timer::now();
    ostringstream x;
    x << chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
    string Time = x.str();

 //   cout << "The shortest path from " << source << " to " << destination << " is " << distance[destination] << endl;
    cout << endl;
    cout << "NodesPathSize:" << nodesPath.size() << " NodesVisited:" << nodesVisited.size() << " Time(ms):" << Time << " Distance:" << distance[destination] << "\n";
    cout << "==================================" << endl;

    }
}


//Matrix deconstructor
AdjMatrix::~AdjMatrix()
{
    for (int i = 0; i < numVertices; i++)
    {
          delete[] adjMatrix[i];
    }
    delete[] adjMatrix;
}

