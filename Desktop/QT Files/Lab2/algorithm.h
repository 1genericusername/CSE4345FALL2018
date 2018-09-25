#ifndef ALGORITHM_H
#define ALGORITHM_H
#include "bubble.h"
#include "insertion.h"
#include "merge.h"
#include "vector"
#include <chrono>
#include "iostream"


class Algorithm
{
    //Functions
    public:

    virtual void load(std::string filename);

    virtual void load(std::string filename, std::string filename2);

    virtual void Display();

    virtual void stats();

    virtual void select(int type) = 0;

    virtual void execute(int type) = 0;

};






#endif // ALGORITHM_H
