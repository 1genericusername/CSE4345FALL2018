#include "sort.h"
#include "fstream"
#include "iostream"
#include "bubble.h"
#include "insertion.h"
#include "merge.h"


void Sort::load(string filename)
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

void Sort::load(string filename, string filename2)
{
    cout << filename << " " << filename2 << endl;
}

void Sort::Display()
{
    for(unsigned int i=0;i<dataset.size();i++)
    {
        cout << dataset[i] << ',';
    }
    cout << endl;
    cout << "===============================================" << endl;
}

void Sort::stats()
{
    if(SortType == 1)
    {
        cout << "To sort this data set of size " << dataset.size() << " using the BubbleSort method took " << Time << " ms." << endl;
    }
    else if(SortType == 2)
    {
        cout << "To sort this data set of size " << dataset.size() << " using the MergeSort method took " << Time << " ms." << endl;
    }
    else if(SortType == 3)
    {
        cout << "To sort this data set of size " << dataset.size() << " using the InsertionSort method took " << Time << " ms." << endl;
    }

}

void Sort::save(int type)
{
    ofstream writefile;
    string filename = "SORTED" + file;
    writefile.open(filename);
    writefile << "\n";
    if (type == 1)
    {
        writefile << "===========================================================================" << "\n" << endl;
        writefile << "To sort this data set of size " << dataset.size() << " using the bubblesort method took " << Time << " ms." << endl;
        writefile << "===========================================================================" << "\n" << endl;
    }
    else if (type == 2)
    {
        writefile << "===========================================================================" << "\n" << endl;
        writefile << "To sort this data set of size " << dataset.size() << " using the mergesort method took " << Time << " ms." << endl;
        writefile << "===========================================================================" << "\n" << endl;
    }
    else if (type == 3)
    {
        writefile << "===========================================================================" << "\n" << endl;
        writefile << "To sort this data set of size " << dataset.size() << " using the Insertion method took " << Time << " ms." << endl;
        writefile << "===========================================================================" << "\n" << endl;
    }
    for(unsigned int i=0;i<dataset.size();i++)
    {
        writefile << dataset[i];
        writefile << ',';
    }

}

void Sort::select(int type)
{
    SortType = type;
    if(type == 1)
    {
        m_sort = new Bubble;
        m_sort ->sort(Time,dataset);
    }
    else if(type == 2)
    {
        m_sort = new Merge;
        m_sort ->sort(Time,dataset);
    }
    else if(type == 3)
    {
        m_sort = new Insertion;
        m_sort ->sort(Time,dataset);
    }
}

void Sort::execute(int type)
{
    select(type);
    stats();
    save(type);
    Display();
}
