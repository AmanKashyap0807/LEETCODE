#include <iostream>
#include <vector>
using namespace std;

void solve(int ind, vector<int> &arr, int sum, vector<int> &ans)
{
    if (ind >= arr.size())
    {
        ans.push_back(sum);
        return;
    }
    solve(ind + 1, arr, sum, ans);
    solve(ind + 1, arr, sum + arr[ind], ans);
}

int main()
{
    vector<int> arr = {2, 3};
    vector<int> ans;
    solve(0, arr, 0, ans);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}