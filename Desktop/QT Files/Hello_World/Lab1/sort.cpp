#include "sort.h"
#include "fstream"
#include "iostream"
#include "bubble.h"
#include "insertion.h"
#include "merge.h"
using namespace std;

void runSort()
{
    sort one;
    one.load("set1.csv");
    one.execute();
    one.display();
    one.stats();
    one.save("Set1_Stats.txt");

    sort two;
    two.load("set2.csv");
    two.execute();
    two.display();
    two.stats();
    two.save("Set2_Stats.txt");

    sort three;
    three.load("set3.csv");
    three.execute();
    three.display();
    three.stats();
    three.save("Set3_Stats.txt");

    sort four;
    four.load("set4.csv");
    four.execute();
    four.display();
    four.stats();
    four.save("Set4_Stats.txt");

}
