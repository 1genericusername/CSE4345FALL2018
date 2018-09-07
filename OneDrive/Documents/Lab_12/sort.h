#ifndef SORT_H
#define SORT_H
#include "algorithm.h"
#include <fstream>
#include <sstream>
#include <chrono>
using namespace std;


class sort : public algorithm
{
    private:
        vector<int> dataset;
        string file;
        string time1;
        string time2;
        string time3;

    public:
        //loads file into program
        void load(string filename)
        {
            ifstream inFile;
            ofstream writefile;
            inFile.open(filename);
            file = filename;
            int entry;
            string str;
                while(std::getline(inFile, str))
                {
                    inFile >> entry;
                    dataset.push_back(entry);
                }

        }

        //Print the unsorted vector
        void print()
        {
            for(int i=0;i<dataset.size();i++)
            {
                cout << dataset[i] << endl;
            }
        }

        //Sort set and time it
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

            //Time for MergeSort
            using timer = std::chrono::high_resolution_clock;
                    timer::time_point start_time2 = timer::now();
            MergeSort(temp2,0,temp2.size()-1);
                    timer::time_point end_time2 = timer::now();

            //Time for Insertion Sort
            using timer = std::chrono::high_resolution_clock;
                    timer::time_point start_time3 = timer::now();
            insertionsort(temp3,temp3.size());
            timer::time_point end_time3 = timer::now();

            //Save time variables
            ostringstream x,y,z;
            x << chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
            time1 = x.str();
            y << chrono::duration_cast<std::chrono::milliseconds>(end_time2 - start_time2).count();
            time2 = y.str();
            z << chrono::duration_cast<std::chrono::milliseconds>(end_time3 - start_time3).count();
            time3 = z.str();

            dataset = temp1;

        }

        //print sorted vector to screen
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

        //Print the size of the dataset,method and time it took
        void stats()
        {
            cout << "To sort this data set of size " << dataset.size() << " using the bubblesort method took " << time1 << " ms." << endl;
            cout << "To sort this data set of size " << dataset.size() << " using the mergesort method took " << time2 << " ms." << endl;
            cout << "To sort this data set of size " << dataset.size() << " using the insert sort method took " << time3 << " ms." << endl;
        }

        //Save stats to a file
        void save(string filename)
        {
            ofstream writefile;
            writefile.open(filename);
            writefile << "\n";
            writefile << "===========================================================================" << "\n" << endl;
            writefile << "To sort this data set of size " << dataset.size() << " using the bubblesort method took " << time1 << " ms." << endl;
            writefile << "To sort this data set of size " << dataset.size() << " using the mergesort method took " << time2 << " ms." << endl;
            writefile << "To sort this data set of size " << dataset.size() << " using the insert sort method took " << time3 << " ms." << endl;
            writefile << "===========================================================================" << "\n" << endl;
            for(int i=0;i<dataset.size();i++)
            {
                writefile << dataset[i];
                writefile << ',';
            }

            dataset.clear();
        }


};

void SortRandom();
void SortBackwards();
void Sort20Percent();
void Sort30Percent();

#endif // SORT_H
