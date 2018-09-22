#include "bubble.h"
#include "iostream"


void Bubble::sort(string &Time,vector<int> &dataset)
{
    //Time for bubblesort
    using timer = std::chrono::high_resolution_clock;
    timer::time_point start_time = timer::now();
           // vector<int> original = dataset;
            bool sorted = false;
            int swaps;
            while(sorted != true)
            {
                swaps = 0;
                for(unsigned int i=0;i<dataset.size();i++)
                {
                    if(i != dataset.size()-1 && dataset[i] > dataset[i+1])
                    {
                        swap(dataset[i],dataset[i+1]);
                        swaps++;
                    }
                }
                if(swaps == 0)
                {
                    sorted = true;
                }
            }
    timer::time_point end_time = timer::now();
    ostringstream x;
    x << chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
    Time = x.str();


}
