#ifndef SORT_H
#define SORT_H
#include "algorithm.h"
#include "adjlist.h"
#include "adjmatrix.h"
#include "sortbehavior.h"
#include "pathbehavior.h"
#include "bubble.h"
#include <fstream>
#include <sstream>
#include <list>
#include <chrono>

class SortBehavior;
//class AdjMatrix;
//class AdjList;
class PathBehavior;

class Sort : public Algorithm
{
    private:
    SortBehavior* m_sort;
    vector<int> dataset;
    string file;
    string Time;
    int SortType;
    PathBehavior* m_path;
    int userinput1;
    int userinput2;
  //  AdjMatrix AdjM;
   // AdjList* AdjL;
    //int** adjMatrix;
    //list<pair<int,int>>* adjlist;
    //list<pair<int,int>>* positions;




    public:


        //loads file into program
        void load(std::string filename);

        //Load two files
        void load(std::string filename, std::string filename2);

        //Print the vector
        void Display();

        //Print the size of the dataset,method and time it took
        void stats();

        //Save stats to a file
        void save(int type);


        void select(int type);

        void GrabUserInput(int one, int two);

        //Sort set and time it
        void execute(int type);

        void execute(int type1, int type2);
};











#endif // SORT_H
