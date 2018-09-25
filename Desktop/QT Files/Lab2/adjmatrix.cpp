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

//Add Vertice
void AdjMatrix::addVertice(int i, int j)
{
    adjMatrix[i][j] = 1;
    adjMatrix[j][i] = 1;
}

//Add Vertice with weight
void AdjMatrix::addweightedVertice(int i, int j, int k)
{
    adjMatrix[i][j] = k;
    adjMatrix[j][i] = k;
}

//Remove Vertice
void AdjMatrix::clearVertice(int i, int j)
{
    adjMatrix[i][j] = 0;
    adjMatrix[j][i] = 0;
}

//Check if vertice exists
void AdjMatrix::checkVertice(int i, int j)
{
    if (adjMatrix[i][j] != 0)
    {
        std::cout << "These connected, by a weight of " << adjMatrix[i][j] << std::endl;
    }
    else
        std::cout << "These are not connected" << std::endl;
}

//Print the contents of the matrix
void AdjMatrix::printMatrix()
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
void AdjMatrix::buildMatrix(std::string filename,string filename2)
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
        addweightedVertice(Node1,Node2,weight);
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

            if(queue.front() == dest)
            {
                break;
            }

            queue.pop_front();

            for (int i = 0; i < numVertices; ++i){
                    if(adjMatrix[source][i] != 0 && (! visited[i]) )
                    {
                        queue.push_back(i);
                        visited[i] = true;
                    }
                }

        }

}

void AdjMatrix::BFSREC(int source, int d, bool visited[], list<int> Queue)
{
    source = Queue.front();
    cout << source << " ";

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
    BFSREC(destination,d, visited, Queue);
    }
}

void AdjMatrix::BFSR(int source, int dest)
{
    // Mark all the vertices as not visited
    bool *visited = new bool[numVertices];
    for(int i = 0; i < numVertices; i++)
        visited[i] = false;

    // Create a queue for BFS
    list<int> Queue;

    // Mark the current node as visited and enqueue it
    visited[source] = true;
    Queue.push_back(source);

    BFSREC(source,dest, visited, Queue);
}

void AdjMatrix::DFSREC(int source, int d, bool visited[], list<int> Stack)
{
    source = Stack.front();
    Stack.pop_front();

    if (!visited[source])
    {
        cout << source << endl;
        visited[source] = true;
    }


    if(Stack.front() != d)
    {

    int destination = 0;
    for (int i = 1; i < numVertices; ++i)
    {
            if(adjMatrix[source][i] != 0 && (visited[i] == false))
            {
                destination = i;
                Stack.push_front(i);
         //       visited[i] = true;
            }
    }
    DFSREC(destination,d, visited, Stack);
    }
}

void AdjMatrix::DFSR(int source, int dest)
{
    // Mark all the vertices as not visited
    bool *visited = new bool[numVertices];
    for(int i = 0; i < numVertices; i++)
        visited[i] = false;

    // Create a queue for BFS
    list<int> Stack;

    // Mark the current node as visited and enqueue it
   // visited[source] = true;
    Stack.push_front(source);

    DFSREC(source,dest, visited, Stack);
}

void AdjMatrix::DFS(int source, int dest)
{
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
            Stack.pop_front();

            if(!visited[source])
            {
                cout << source << endl;
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
                            Stack.push_front(i);
                    }

             }

        }
}

double AdjMatrix::heuristic(double x1, double y1, double x2, double y2, int cost)
{
   double dist = pow(pow(x2-x1,2)+pow(y2-y1,2),0.5);
   double heur = dist*(1+cost);
   return heur;
}

void AdjMatrix::AStar(int source, int dest)
{

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

        while(!Stack.empty())
        {
            // Dequeue a vertex from queue and print it
            source = Stack.front();
            Stack.pop_front();

            if(!visited[source])
            {
                cout << source << endl;
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
                        auto one = positions[source].begin();
                        auto two = positions[dest].begin();
                        double temp = heuristic(one->first,one->second,two->first,two->second,adjMatrix[source][i]);
                        tempvector.push_back(temp);
                        nodes.push_back(i);
                        if(i == dest)
                        {
                            nodes.clear();
                            tempvector.clear();
                            tempvector.push_back(temp);
                            nodes.push_back(i);
                        }
                         //   Stack.push_back(i);
                    }
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

           Stack.push_back(smallestL);

           tempvector.clear();
           nodes.clear();

        }


}

void AdjMatrix::dijkstra(int source,int destination)
{
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

    //Loop through every entry of the Adjacency List
    for (int count = 0; count < numVertices; count++)
    {
        //Create temp variables
        int min = INT_MAX;
        int min_index = 0;

        //Loop through visited[] and distance[] assigning values to min and min_index,
        //changing each time is distance[v] is less than the current min
        for (int v = source; v < numVertices; v++)
        {
            if (visited[v] == false && distance[v] <= min)
            {
                min = distance[v];
                min_index = v;
            }
        }
        int u = min_index;
        visited[u] = true;

        //Loop through visited and and distance, comparing if the new distance value is less than the currently saved number
        //If it is, assign the shortest path to distance[v] and move on
        for (int v = source; v < numVertices; v++)
        {
            if (!visited[v] && adjMatrix[u][v] && distance[u] != INT_MAX && distance[u]+adjMatrix[u][v] < distance[v])
            {
                distance[v] = distance[u] + adjMatrix[u][v];
                if(distance[destination] < INT_MAX)
                {
                    count = numVertices+1;
                    v = numVertices+1;
                }
            }


        }


     }


        printf("Vertex   Distance from Source\n");
            for (int i = 1; i < numVertices; i++)
               printf("%d \t\t %d\n", i, distance[i]);

      //   cout << "The shortest path from " << source << " to " << destination << " is " << distance[destination] << endl;

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

