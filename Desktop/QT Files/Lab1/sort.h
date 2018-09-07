#ifndef SORT_H
#define SORT_H
#include "algorithm.h"
#include <fstream>
#include <sstream>
#include <chrono>



class Sort : public algorithm
{
    private:
    vector<int> dataset;
    string file;
    string time1;
    string time2;
    string time3;

    public:

        //loads file into program
        void load(string filename);

        //Print the unsorted vector
        void print();

        //Sort set and time it
        void execute();


        //print sorted vector to screen
        void display();

        //Print the size of the dataset,method and time it took
        void stats();

        //Save stats to a file
        void save(string filename);

};



#endif // SORT_H
