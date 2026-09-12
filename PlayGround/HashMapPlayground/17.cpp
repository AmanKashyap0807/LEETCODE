#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> arr = {2, 4, 1, 3, 5};
    vector<int> ps;
    ps.push_back(arr[0]);
    for (int i = 1; i < arr.size(); i++)
    {
        ps.push_back(arr[i] + ps[i - 1]);
    }
    for (int i = 0; i < arr.size(); i++)
    {
        cout << ps[i]<<" ";
    }
    cout<<endl;

    // this above has an edge case proble like for sum from 1st to 3rd element with formula ps[j]-ps[i-1] will give error
    // so for this case we intentionally increse prefix sum array length by 1 and add 0 at the start of prefix sum array
    vector<int> ps1;
    ps1.push_back(0);
    for (int i = 0; i < arr.size(); i++)
    {
        ps1.push_back(arr[i] + ps1[i]);
    }
    for (int i = 0; i < ps1.size(); i++)
    {
        cout << ps1[i]<<" ";
    }
    return 0;
}