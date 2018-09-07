#include "insertion.h"
#include "iostream"

void insertionsort(vector<int> &vec, int num)
{
    int x,y,z;
    for(x=1;x<num;x++)
    {
        y = vec[x];
        z = x-1;

        while (z >= 0 && vec[z] > y)
        {
            vec[z+1] = vec[z];
            z = z-1;
        }
            vec[z+1] = y;
    }
}
