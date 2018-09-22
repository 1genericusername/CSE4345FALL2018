#ifndef INSERTION_H
#define INSERTION_H
#include "sortbehavior.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <chrono>
using namespace std;

//void insertionsort(std::vector<int> &vec, int num);
class Insertion: public SortBehavior
{
    public:
        void sort(string &Time,vector<int> &dataset);
};



#endif // INSERTION_H
