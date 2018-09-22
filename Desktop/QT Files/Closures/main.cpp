#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Function to print number if greater than 18 and less than 26
void printnumber(int x)
{
    if(x > 18 && x < 26)
    cout << x << endl;
}

int main()
{
    //vector of numbers
    vector<int> nums {22,16,17,18,20,21,60,23,25,28,30,45,52,15};
    //lambda function to simplify code
    for_each(nums.begin(), nums.end(), printnumber);
}
