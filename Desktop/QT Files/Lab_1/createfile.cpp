#include "createfile.h"
#include "iostream"
#include "fstream"
using namespace std;

void createSet()
{
    ofstream writefile;
    string name;
    int size;
    int entry;
    cout << "Enter number of entries in set" << endl;
    cin >> size;
    cout << "Enter name of csv file" << endl;
    cin >> name;
    writefile.open(name);
    for(int i=0;i<size;i++)
    {
        entry = rand()%(size+1);
        writefile << entry;
        writefile << "\n";
    }
    writefile.close();
}
