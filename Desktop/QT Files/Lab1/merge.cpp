#include "merge.h"
#include "iostream"

void merge(vector<int> &vec, int left, int middle, int right)
{
    int x,y,z;
    int Lsize = middle - left + 1;
    int Rsize =  right - middle;

    //Temp Arrays
    int LeftArray[Lsize], RightArray[Rsize];

    //Copy into Temp arrays
    for (x = 0; x < Lsize; x++)
        LeftArray[x] = vec[left + x];
    for (y = 0; y < Rsize; y++)
        RightArray[y] = vec[middle + 1+ y];

    //Reset Values
    x = 0, y = 0, z = left;

    //Merge arrays into vector
    while (x < Lsize && y < Rsize)
        {
            if (LeftArray[x] <= RightArray[y])
            {
                vec[z] = LeftArray[x];
                x++;
            }
            else
            {
                vec[z] = RightArray[y];
                y++;
            }
            z++;
        }

        // Merge any leftover elements of left temp array
        while (x < Lsize)
        {
            vec[z] = LeftArray[x];
            x++;
            z++;
        }

        // Merge any leftover elements of right temp array
        while (y < Rsize)
        {
            vec[z] = RightArray[y];
            y++;
            z++;
        }
    }


void MergeSort(vector<int> &vec, int left, int right)
{
    if (left < right)
    {
        // Get middle of vector
        int middle = left+(right-left)/2;

        // Sort first half
        MergeSort(vec, left, middle);
        //Sort second half
        MergeSort(vec, middle+1, right);
        //Merge sorted vectors
        merge(vec, left, middle, right);
    }
}
