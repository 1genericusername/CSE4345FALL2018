#ifndef ALGORITHM_H
#define ALGORITHM_H
#include "bubble.h"
#include "insertion.h"
#include "merge.h"
#include <vector>
#include <chrono>
#include <iostream>


class Algorithm
{
    //Functions
    public:

    virtual void load(std::string filename) = 0;

    virtual void load(std::string filename, std::string filename2) = 0;

    virtual void Display() = 0;

    virtual void stats() = 0;

    virtual void select(int type) = 0;

    virtual void execute(int type) = 0;

    virtual void GrabUserInput(int one, int two) = 0;

    virtual void execute(int type1, int type2) = 0;

};






#endif // ALGORITHM_H
