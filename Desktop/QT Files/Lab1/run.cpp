#include "sort.h"
#include "fstream"
#include "iostream"
#include "bubble.h"
#include "insertion.h"
#include "merge.h"


void SortRandom()
{
    Sort random;
    //Sorts 10 set
    random.load("Random(10).txt");
    random.execute();
    random.stats();
    random.save("Random(10)Stats.txt");
    cout << "====================" << endl;
    //Sorts 1000 set
    random.load("Random(1000).txt");
    random.execute();
    random.stats();
    random.save("Random(1000)Stats.txt");
    cout << "====================" << endl;
    //Sorts 10,000 set
    random.load("Random(10000).txt");
    random.execute();
    random.stats();
    random.save("Random(10000)Stats.txt");
    cout << "====================" << endl;
    //Sorts 100,000 set
    random.load("Random(100000).txt");
    random.execute();
    random.stats();
    random.save("Random(100000)Stats.txt");

}

void SortBackwards()
{
    Sort random;
    //Sorts 10 set
    random.load("Backwards(10).txt");
    random.execute();
    random.stats();
    random.save("Backwards(10)Stats.txt");
    cout << "====================" << endl;
    //Sorts 1000 set
    random.load("Backwards(1000).txt");
    random.execute();
    random.stats();
    random.save("Backwards(1000)Stats.txt");
    cout << "====================" << endl;
    //Sorts 10,000 set
    random.load("Backwards(10000).txt");
    random.execute();
    random.stats();
    random.save("Backwards(10000)Stats.txt");
    cout << "====================" << endl;
    //Sorts 100,000 set
    random.load("Backwards(100000).txt");
    random.execute();
    random.stats();
    random.save("Backwards(100000)Stats.txt");
}

void Sort20Percent()
{
    Sort random;
    //Sorts 10 set
    random.load("20%(10).txt");
    random.execute();
    random.stats();
    random.save("20%(10)Stats.txt");
    cout << "====================" << endl;
    //Sorts 1000 set
    random.load("20%(1000).txt");
    random.execute();
    random.stats();
    random.save("20%(1000)Stats.txt");
    cout << "====================" << endl;
    //Sorts 10,000 set
    random.load("20%(10000).txt");
    random.execute();
    random.stats();
    random.save("20%(10000)Stats.txt");
    cout << "====================" << endl;
    //Sorts 100,000 set
    random.load("20%(100000).txt");
    random.execute();
    random.stats();
    random.save("20%(100000)Stats.txt");
}

void Sort30Percent()
{
    Sort random;
    //Sorts 10 set
    random.load("30%(10).txt");
    random.execute();
    random.stats();
    random.save("30%(10)Stats.txt");
    cout << "====================" << endl;
    //Sorts 1000 set
    random.load("30%(1000).txt");
    random.execute();
    random.stats();
    random.save("30%(1000)Stats.txt");
    cout << "====================" << endl;
    //Sorts 10,000 set
    random.load("30%(10000).txt");
    random.execute();
    random.stats();
    random.save("30%(10000)Stats.txt");
    cout << "====================" << endl;
    //Sorts 100,000 set
    random.load("30%(100000).txt");
    random.execute();
    random.stats();
    random.save("30%(100000)Stats.txt");
}
