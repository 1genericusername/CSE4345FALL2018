#include <iostream>


#include "merge.h"
#include "bubble.h"
#include "insertion.h"
#include "createfile.h"
#include "sort.h"
using namespace std;

int main()
{
    cout << "You can do it Xavier, I believe in you" << endl;
    //========================================
    //Sort Random Sets
    //========================================
    cout << "\t\t Random Set" << endl;
    cout << "========================================" << endl;
    SortRandom();
    cout << endl;
    cout << endl;
    cout << "\t Backward Set" << endl;
    cout << "========================================" << endl;
    //========================================
    //Sort Backward Sets
    //========================================
    SortBackwards();
    cout << endl;
    cout << endl;
    //========================================
    //Sort sets with 20% Unique
    //========================================
    cout << "\t 20% Unique Set" << endl;
    cout << "========================================" << endl;
    Sort20Percent();
    cout << endl;
    cout << endl;
    //========================================
    //Sort sets with 30% randomized
    //========================================
    cout << "\t 30% Randomized Set" << endl;
    cout << "========================================" << endl;
    Sort30Percent();

}
