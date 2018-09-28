#ifndef SORTBEHAVIOR_H
#define SORTBEHAVIOR_H
#include <fstream>
#include <vector>

class SortBehavior
{
    public:
        virtual void sort(std::string &Time,std::vector<int> &dataset) = 0;
};


#endif // SORTBEHAVIOR_H
