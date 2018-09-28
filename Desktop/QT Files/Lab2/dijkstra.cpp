//#include "dijkstra.h"

//void DijkstraSearch::dijkstra_L(int source, int destination, std::list<std::pair<int,int>>* adjlist)
//{
//    std::list<std::pair<int,int>> pq;

//    //vector<int> dist(numVertices, INT_MAX);
//    int dist[numVertices];
//    for (int i = 0; i < numVertices; i++)
//    {
//        dist[i] = INT_MAX;
//    }

//    // Insert source itself in priority Queue and initialize
//    // its distance as 0.
//    pq.push_back(std::make_pair(0, source));
//    dist[source] = 0;

//    /* Looping till priority Queue becomes empty (or all
//      distances are not finalized) */
//    while (!pq.empty())
//    {
//        int u = pq.front().second;
//        pq.pop_front();

//        for (auto i = adjlist[u].begin(); i != adjlist[u].end(); ++i)
//        {
//            // Get vertex label and weight of current adjacent
//            // of u.
//            int v = i->first;
//            int weight = i->second;

//            //  If there is shorted path to v through u.
//            if (dist[v] > dist[u] + weight)
//            {
//                // Updating distance of v
//                dist[v] = dist[u] + weight;
//                pq.push_back(std::make_pair(dist[v], v));
//            }
//        }

//        if(dist[destination] != INT_MAX)
//        {
//            break;
//        }
//    }

//    // Print shortest distances stored in dist[]
////      printf("Vertex   Distance from Source\n");
////     for (int i = 1; i < numVertices; ++i)
// //       printf("%d \t\t %d\n", i, dist[i]);
//    std::cout << "The shortest path from " << source << " to " << destination << " is " << dist[destination] << std::endl;
//}



//void DijkstraSearch::dijkstra_M(int source, int destination, int **adjmatrix)
//{
//    //Initialize distance and visited Stacks
//    int distance[numVertices];
//    bool visited[numVertices];

//    //Fill distance[] with max int value, fill visited[] with false
//    for (int i = 0; i < numVertices; i++)
//    {
//        distance[i] = INT_MAX, visited[i] = false;
//    }
//    //Distance from source to itself is 0
//    distance[source] = 0;

//    //Loop through every entry of the Adjacency List
//    for (int count = 0; count < numVertices; count++)
//    {
//        //Create temp variables
//        int min = INT_MAX;
//        int min_index = 0;

//        //Loop through visited[] and distance[] assigning values to min and min_index,
//        //changing each time is distance[v] is less than the current min
//        for (int v = source; v < numVertices; v++)
//        {
//            if (visited[v] == false && distance[v] <= min)
//            {
//                min = distance[v];
//                min_index = v;
//            }
//        }
//        int u = min_index;
//        visited[u] = true;

//        //Loop through visited and and distance, comparing if the new distance value is less than the currently saved number
//        //If it is, assign the shortest path to distance[v] and move on
//        for (int v = source; v < numVertices; v++)
//        {
//            if (!visited[v] && adjmatrix[u][v] && distance[u] != INT_MAX && distance[u]+adjmatrix[u][v] < distance[v])
//            {
//                distance[v] = distance[u] + adjmatrix[u][v];
//                if(distance[destination] < INT_MAX)
//                {
//                    count = numVertices+1;
//                    v = numVertices+1;
//                }
//            }


//        }


//     }


//        printf("Vertex   Distance from Source\n");
//            for (int i = 1; i < numVertices; i++)
//               printf("%d \t\t %d\n", i, distance[i]);

//      //   cout << "The shortest path from " << source << " to " << destination << " is " << distance[destination] << endl;
//}
