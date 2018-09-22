#ifndef SORT_H
#define SORT_H
#include "algorithm.h"
#include "sortbehavior.h"
#include "bubble.h"
#include <fstream>
#include <sstream>
#include <chrono>

class SortBehavior;

class Sort : public Algorithm
{
    private:
    vector<int> dataset;
    string file;
    string Time;
    SortBehavior* m_sort;
    int SortType;


    public:


        //loads file into program
        void load(std::string filename);

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
