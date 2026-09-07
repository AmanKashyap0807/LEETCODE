#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<vector<string>> groupByKey(const vector<string> &items,
                                  function<string(string)> normalize)
{
    unordered_map<string, vector<string>> groups;
    // For loop for traversing each element
    for (const string &item : items)
    {
        // get the key from the item
        string key = normalize(item);
        // push the item on the hashmap with that key
        groups[key].push_back(item);
    }
    // create bucket as per return required
    vector<vector<string>> ans;
    for (auto &p : groups)
    {
        ans.push_back(p.second);
    }

    return ans;
}

int main()
{
    return 0;
}