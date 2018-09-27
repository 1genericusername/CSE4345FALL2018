#include "astar.h"
/*
double AStarSearch::heuristic(double x1, double y1, double x2, double y2, int cost)
{
    double dist = pow(pow(x2-x1,2)+pow(y2-y1,2),0.5);
    double heur = dist*(1+cost);
    return heur;
}

void AStarSearch::A_star_L(int source, int destination, std::list<std::pair<int, int>>* adjlist, std::list<std::pair<int,int>>* positions)
{

    std::list<int> Stack;
    std::vector<double> tempvector;
    std::vector<int> nodes;

    bool *visited = new bool[numVertices];
    for(int i = 0; i < numVertices; i++)
        visited[i] = false;

    Stack.push_back(source);

    while (!Stack.empty())
    {
        source = Stack.front();
        Stack.pop_front();

        if(!visited[source])
        {
            std::cout << source << std::endl;
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

            Stack.push_back(smallestL);

            tempvector.clear();
            nodes.clear();
    }

}


void AStarSearch::A_Star_M(int source, int destination, int** adjmatrix, std::list<std::pair<int,int>>* positions)
{
    // Mark all the vertices as not visited
        bool *visited = new bool[numVertices];
        for(int i = 0; i < numVertices; i++)
            visited[i] = false;

        // Create a queue for BFS
        std::list<int> Stack;
        std::vector<double> tempvector;
        std::vector<int> nodes;

        // Mark the current node as visited and enqueue it
        Stack.push_back(source);

        while(!Stack.empty())
        {
            // Dequeue a vertex from queue and print it
            source = Stack.front();
            Stack.pop_front();

            if(!visited[source])
            {
                std::cout << source << std::endl;
                visited[source] = true;
                if(visited[destination] == true)
                {
                    break;
                }
            }


            for (int i = 0; i < numVertices; ++i)
            {
                    if(adjmatrix[source][i] != 0 && visited[i] == false )
                    {
                        auto one = positions[source].begin();
                        auto two = positions[destination].begin();
                        double temp = heuristic(one->first,one->second,two->first,two->second,adjmatrix[source][i]);
                        tempvector.push_back(temp);
                        nodes.push_back(i);
                        if(i == destination)
                        {
                            nodes.clear();
                            tempvector.clear();
                            tempvector.push_back(temp);
                            nodes.push_back(i);
                        }
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
*/
