//
//
// @..*
//
//  Created by Choonghun Lee on 9/11/18.
//  @..
//

#include "stdc++.h"


using namespace std;


#include <iostream>
#include <vector>
#include <climits>
#include <utility>
#include <algorithm>

using namespace std;
int V ;
vector<int> mst(V, INT_MAX);
vector<vector<pair<int,int>>> adj;
vector<bool> added(V, false);
vector<int> parents(V, -1);

int totalWeight = 0;

// time comp V2

vector<int> mstPrim(int s){
    
    mst[s] = 0;
    added[s] = true;
    parents[s] = 0;
    
    vector<pair<int,int>> ret;
    
  //  while(true){
    for(int iter = 0; iter < V; ++iter ){
        
        int m = INT_MAX;
        int mIndex=-1;
        
        for(int i=0; i<V; ++i){
            
            if( added[false] && mst[i] < m){
                mIndex = i;
                m = mst[i];
            }
        }
        
        if(mIndex == -1){
            
            break;
        }else{
            added[mIndex] = true;
            totalWeight += mst[mIndex];
            ret.push_back(make_pair(parents[mIndex], mIndex));
        }
        
        
        for(int i=0; i< adj[mIndex].size(); ++i){
            
            int there = adj[mIndex][i].first;
            int weight = adj[mIndex][i].second;
            
            //if(mst[there] > mst[mIndex] + weight {
            if(mst[there] >  weight ){
                //mst[there] = mist[mIndex] + weight;
                mst[there] = weight;
                parents[there] = mIndex;
            }
        }
    }
}



int main(int argc, const char * argv[]) {
    // insert code here...
    
    
    std::cout << "Hello, World!\n";
    return 0;
}
