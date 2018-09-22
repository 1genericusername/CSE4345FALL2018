#ifndef BUBBLE_H
#define BUBBLE_H
#include "sortbehavior.h"
#include <iostream>
#include "vector"
#include <fstream>
#include <sstream>
#include <chrono>
using namespace std;

//template <typename T>
//void bubblesort(std::vector<int> &init);


class Bubble: public SortBehavior
{
    public:
        void sort(string &Time,vector<int> &dataset) ;
};


#endif // BUBBLE_H
