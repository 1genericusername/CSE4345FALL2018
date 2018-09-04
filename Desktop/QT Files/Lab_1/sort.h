#ifndef SORT_H
#define SORT_H
#include "algorithm.h"
#include <fstream>
#include <sstream>
using namespace std;

void runSort();

class sort : public algorithm
{
    private:
        vector<int> dataset;
        string time1;
        string time2;
        string time3;

    public:
        void load(string filename)
        {
            ifstream inFile;
            ofstream writefile;
            inFile.open(filename);
            int entry;
                while(!inFile.eof())
                {
                    inFile >> entry;
                    dataset.push_back(entry);
                }

        }

        void print()
        {
            for(int i=0;i<dataset.size();i++)
            {
                cout << dataset[i] << endl;
            }
        }

        void execute()
        {
            vector<int> temp1 = dataset;
            vector<int> temp2 = dataset;
            vector<int> temp3 = dataset;
            //Time for bubblesort
            using timer = std::chrono::high_resolution_clock;
                    timer::time_point start_time = timer::now();
            bubblesort(temp1);
            timer::time_point end_time = timer::now();
                cout << "Total Time for BubbleSort: " << chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count() << "ms" << endl;

            //Time for MergeSort
            using timer = std::chrono::high_resolution_clock;
                    timer::time_point start_time2 = timer::now();
            MergeSort(temp2,0,temp2.size());
            timer::time_point end_time2 = timer::now();
                cout << "Total Time for MergeSort " << chrono::duration_cast<std::chrono::milliseconds>(end_time2 - start_time2).count() << "ms" << endl;
            //Time for Insertion Sort
            using timer = std::chrono::high_resolution_clock;
                    timer::time_point start_time3 = timer::now();
            insertionsort(temp3,temp3.size());
            timer::time_point end_time3 = timer::now();
                cout << "Total Time for Insertion Sort " << chrono::duration_cast<std::chrono::milliseconds>(end_time3 - start_time3).count() << "ms" << endl;

            //Save time variables
            ostringstream x,y,z;
            x << chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
            time1 = x.str();
            y << chrono::duration_cast<std::chrono::milliseconds>(end_time2 - start_time2).count();
            time2 = y.str();
            z << chrono::duration_cast<std::chrono::milliseconds>(end_time3 - start_time3).count();
            time3 = z.str();
        }

        void display()
        {
            insertionsort(dataset,dataset.size());
            for(int i=0;i<dataset.size();i++)
            {
                cout << dataset[i] << ',';
            }
            cout << endl;
            cout << "===============================================" << endl;
        }

        void stats()
        {
            cout << "To sort this data set of size " << dataset.size() << " using the bubblesort method took " << time1 << " ms." << endl;
            cout << "To sort this data set of size " << dataset.size() << " using the mergesort method took " << time2 << " ms." << endl;
            cout << "To sort this data set of size " << dataset.size() << " using the insert sort method took " << time3 << " ms." << endl;
        }

        void save()
        {
            ofstream writefile;
            writefile.open("Set1-Solution.txt");
            for(int i=0;i<dataset.size();i++)
            {
                writefile << dataset[i];
                writefile << ',';
            }
            writefile << "\n";
            writefile << "===========================================================================" << "\n" << endl;
            writefile << "To sort this data set of size " << dataset.size() << " using the bubblesort method took " << time1 << " ms." << endl;
            writefile << "To sort this data set of size " << dataset.size() << " using the mergesort method took " << time2 << " ms." << endl;
            writefile << "To sort this data set of size " << dataset.size() << " using the insert sort method took " << time3 << " ms." << endl;
        }

};

#endif // SORT_H
