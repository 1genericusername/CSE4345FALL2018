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
void AdjMatrix::buildMatrix(std::string filename)
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
}

void AdjMatrix::DFS(int source,int destination)
{
    bool* visited = new bool[numVertices];

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

void AdjMatrix::AStar(int source, int destination)
{

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


