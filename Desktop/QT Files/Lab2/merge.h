#ifndef MERGE_H
#define MERGE_H
#include "sortbehavior.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <chrono>
using namespace std;


//void merge(std::vector<int> &arr, int left, int m, int right);
//void MergeSort(std::vector<int> &arr, int left, int right);
class SortBehavior;

class Merge: public SortBehavior {
    public:
        void merge(std::vector<int> &arr, int left, int m, int right);
        void MergeSort(std::vector<int> &arr, int left, int right);
        void sort(string &Time,vector<int> &dataset) ;
};

#endif // MERGE_H
