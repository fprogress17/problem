//
//
// @..*
//
//  Created by Choonghun Lee on 9/11/18.
//  @..
//

#include "stdc++.h"


using namespace std;

bool compare(pair<int, int> i, pair<int,int> j);


vector<int> topKFrequent1(vector<int>& nums, int k) {

    vector<int> count(nums.size(),0);
    vector<int> res;

    for(int i=0;i < nums.size(); ++i){

        int v= nums[i];
        count[v]++;
    }

   for(int i=0;i < count.size(); ++i){

        if(count[i] >= k){
            res.push_back(i);
        }

    }

    return res;
}


vector<int> topKFrequent2(vector<int>& nums, int k) {
    
    vector<int> count(nums.size(),0);
    vector<int> res;
    
    for(int i=0;i < nums.size(); ++i){
        
        int v= nums[i];
        count[v]++;
    }
    
    for(int i=0;i < count.size(); ++i){
        
        if(count[i] >= k){
            res.push_back(i);
        }
        
    }
    
    return res;
}

//// all less than kth element  --> so, priority queue or put it into array and sort
///  not the frequency is less than k
/// problem description is
/// Given a non-empty array of integers, return the k most frequent elements.
///
vector<int> topKFrequent(vector<int>& nums, int k) {

    unordered_map<int,int> m;
    vector<int> res;


    for(int i=0;i < nums.size(); ++i){

        m[ nums[i] ]++;   /// initialization ?
    }

    vector<pair<int,int>> arr(m.begin(), m.end());

    sort(arr.begin(), arr.end(), compare);

    for(int i=0;i < arr.size(); ++i){

        if(i < k){

            pair<int, int> p = arr[i];

            res.push_back(p.first);
        }

    }

    return res;
}

bool compare(pair<int, int> i, pair<int,int> j){

    if(i.second == j.second){
        return i.first > i.second;
    }

    return i.second > j.second;

}


int main(int argc, const char * argv[]) {
    // insert code here...
    
    
    std::cout << "Hello, World!\n";
    return 0;
}
