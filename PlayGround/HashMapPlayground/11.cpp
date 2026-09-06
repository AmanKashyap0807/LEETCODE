#include<stdio.h>
#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int main(){
    unordered_map<int, int> mp;
    vector<int> arr = {1,2,3,3,2,2,4,4,4,4};

    // Building the frequency map
    for(int num:arr){
        mp[num]++;
    }
    
    // Look up a count, let suppose we have to find count of k
    int k =10;
    auto it=mp.find(k);
    // in map if a key exist then the iterator will point to that key
    // otherwise it will point to the end of the map
    if(it!=mp.end()){
        cout<<"Count of "<<k<<" is "<<it->second<<endl;
    }else{
        cout<<k<<" is not present in the map"<<endl;
    }

    // for iterating whole map with their count
    for(const auto& [val,cnt]:mp){
        cout<<val<<" "<<cnt<<endl;
    }

    // find max/min freq element
    int maxval=0;
    int maxcnt =0;
    for(const auto& [val,cnt]:mp){
        if(cnt>maxcnt){
            maxcnt=cnt;
            maxval=val;
        }
    }
    cout<<"Element with maximum frequency: "<<maxval<<" (Frequency: "<<maxcnt<<")"<<endl;

    // ---- 5. Compare two frequency maps for equality ----
    bool sameMultiset(unordered_map<int,int>& a, unordered_map<int,int>& b) {
        return a == b;   // unordered_map has operator== (order-independent)
    }   

    return 0;
}