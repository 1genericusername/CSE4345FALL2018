#include "sort.h"
#include <fstream>
#include <iostream>
#include "bubble.h"
#include "insertion.h"
#include "merge.h"


void Sort::load(string filename)
{
    ifstream inFile;
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
        cout << filename << filename2 << endl;
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
    if(type == 0)
    {
        cout << "Breadth First Search" << endl;
        m_path->BFS(userinput1,userinput2);
    }
    else if(type == 1)
    {
        cout << "Recursive Breadth First Search" << endl;
        m_path->BFSR(userinput1,userinput2);
    }
    else if(type == 2)
    {
        cout << "Depth First Search" << endl;
        m_path->DFS(userinput1,userinput2);
    }
    else if(type == 3)
    {
        cout << "Recursive Depth First Search" << endl;
        m_path->DFSR(userinput1,userinput2);
    }
    else if(type == 4)
    {
        cout << "A* Search" << endl;
        m_path->A_star(userinput1,userinput2);
    }
    else if(type == 5)
    {
        cout << "Dijkstra Search" << endl;
        m_path->dijkstra(userinput1,userinput2);
    }
    else if(type == 6)
    {
        m_sort = new Bubble;
        m_sort ->sort(Time,dataset);
    }
    else if(type == 7)
    {
        m_sort = new Merge;
        m_sort ->sort(Time,dataset);
    }
    else if(type == 8)
    {
        m_sort = new Insertion;
        m_sort ->sort(Time,dataset);
    }
}

void::Sort::GrabUserInput(int one, int two)
{
    userinput1 = one;
    userinput2 = two;
}

void Sort::execute(int type)
{
    select(type);
    stats();
    save(type);
    Display();
}

void Sort::execute(int type1, int type2)
{
    if(type1 == 0)
    {
        m_path = new AdjList(17);
        m_path ->Build("weights.txt","positions.txt");
        cout << "(Ajacency List)";
    }
    else if(type1 == 1)
    {
        m_path = new AdjMatrix(17);
        m_path ->Build("weights.txt","positions.txt");
        cout << "(Adjacency Matrix)";
    }
    select(type2);

    cout << endl;
}
