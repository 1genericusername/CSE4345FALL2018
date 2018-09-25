#ifndef SORT_H
#define SORT_H
#include "algorithm.h"
#include "sortbehavior.h"
#include "pathbehavior.h"
#include "bubble.h"
#include <fstream>
#include <sstream>
#include <list>
#include <chrono>

class SortBehavior;
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
    int** adjMatrix;
    list<pair<int,int>>* adjlist;
    list<pair<int,int>>* positions;




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

        //Sort set and time it
        void execute(int type);
};











#endif // SORT_H
