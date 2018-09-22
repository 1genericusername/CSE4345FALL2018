#include "insertion.h"
#include "iostream"

/*
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
*/

void Insertion::sort(string &Time,vector<int> &dataset)
{
    //Time for Insertion Sort
    int num = dataset.size();
    using timer = std::chrono::high_resolution_clock;
    timer::time_point start_time = timer::now();
            int x,y,z;
            for(x=1;x<num;x++)
            {
                y = dataset[x];
                z = x-1;

                while (z >= 0 && dataset[z] > y)
                {
                    dataset[z+1] = dataset[z];
                    z = z-1;
                }
                    dataset[z+1] = y;
            }
    timer::time_point end_time = timer::now();
    ostringstream tempstring;
    tempstring << chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
    Time = tempstring.str();
}
