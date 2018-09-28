#include "createfile.h"
#include <iostream>
#include <fstream>
using namespace std;

void createRandomSet()
{
    ofstream writefile;
    string name;
    int size;
    int entry;
    cout << "Enter number of entries in set" << endl;
    cin >> size;
    cout << "Enter name of file" << endl;
    cin >> name;
    writefile.open(name);
    for(int i=0;i<size;i++)
    {
        entry = rand()%(size);
        writefile << entry;
        writefile << "\n";
    }
    writefile.close();
}

void createBackwardSet()
{
    ofstream writefile;
    string name;
    int size;
    int entry;
    cout << "Enter number of entries in set" << endl;
    cin >> size;
    cout << "Enter name of file" << endl;
    cin >> name;
    writefile.open(name);
    for(int i=size;i>0;i--)
    {
        entry = i;
        writefile << entry;
        writefile << "\n";
    }
    writefile.close();
}

void createFiveSet()
{
    ofstream writefile;
    string name;
    int size;
    int entry;
    cout << "Enter number of entries in set" << endl;
    cin >> size;
    cout << "Enter name of file" << endl;
    cin >> name;
    writefile.open(name);
    for(int i=0;i<size;i++)
    {
        entry = rand()% 5 + 1;
        writefile << entry;
        writefile << "\n";
    }
    writefile.close();
}

void createThirtySet()
{
    ofstream writefile;
    string name;
    int size;
    int counter = 0;
    int percentage;
    int random;
    int entry;
    cout << "Enter number of entries in set" << endl;
    cin >> size;
    cout << "Enter name of file" << endl;
    cin >> name;
    percentage = (size/3);
    writefile.open(name);
    for(int i=0;i<size;i++)
    {

        random = rand() % 3 + 1;
        if((random == 1 || random == 2) && counter != percentage)
        {
            entry = rand()%(size);
            counter++;
        }
        else
        {
        entry = i;
        }
        writefile << entry;
        writefile << "\n";
    }
    writefile.close();
}
