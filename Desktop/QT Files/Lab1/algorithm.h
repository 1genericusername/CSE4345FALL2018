#ifndef ALGORITHM_H
#define ALGORITHM_H
#include "bubble.h"
#include "insertion.h"
#include "merge.h"
#include "vector"
#include <chrono>
#include "iostream"
using namespace std;

class algorithm
{
    public:
    virtual void load(string filename) = 0;

    virtual void execute() = 0;

    virtual void display() = 0;

    virtual void stats() = 0;

};






#endif // ALGORITHM_H
