#include "bubble.h"
#include "iostream"

//template <typename T>
void bubblesort(vector<int> &init)
{
    vector<int> original = init;
    bool sorted = false;
    int swaps;
    while(sorted != true)
    {
        swaps = 0;
        for(int i=0;i<original.size();i++)
        {
            if(i != original.size()-1 && original[i] > original[i+1])
            {
                swap(original[i],original[i+1]);
                swaps++;
            }
        }
        if(swaps == 0)
        {
            sorted = true;
        }
    }
    init = original;
}
