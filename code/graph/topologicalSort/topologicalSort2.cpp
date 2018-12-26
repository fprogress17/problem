//
//
// @..*
//
//  Created by Choonghun Lee on 9/11/18.
//  @..
//

#include "stdc++.h"


using namespace std;

int V = 10;
vector<int> indegree(V,0);
vector<bool> visited(V, false);
vector<int> res;


vector<vector<int>> adj = { {},
    {},
    {3},
    {1},
    {0,1},
    {0,2}
};


void makeIndegree(){
    
 //   V = adj.size();
    
    for(int i=0; i<adj.size();++i) {
        for(int j=0;j< adj[i].size(); ++j){
            ++indegree[adj[i][j]];
        }
    }
}


void topologicalSortAllPrint( vector<bool> visited, vector<int>res){
    
    bool allVisited = true;
 //   for(int i =0; i< visited.size(); ++i){
       for(int i =0; i< adj.size(); ++i){
        
           if(visited[i] != true){
               allVisited = false;
               break;
           }
        
    }
    
    if(allVisited == true)
    {
        for(int i=0; i<adj.size();++i)
            printf("%d",res[i]);
        
        printf("\n");
        return;
    }
    
    //for(int i=0;i < V; ++i){
    for(int i=0;i < adj.size(); ++i){
        
        if(indegree[i] == 0 && !visited[i]){
            
            visited[i] = true;
            res.push_back(i);
            
            for(int j=0;j < adj[i].size(); ++j){
                
                int there = adj[i][j];
                if(indegree[there] >0)
                    --indegree[there];
            }
            
            topologicalSortAllPrint(visited, res);
            
            visited[i] = false;
            res.pop_back();
            
           
            for(int j=0;j < adj[i].size(); ++j){
            
             //   printf("%d, %d", i, j);
                int there = adj[i][j];
                ++indegree[there];
            }
            
            
            
        }
        
    }
    
    
}

void test(){
    makeIndegree();
    topologicalSortAllPrint(visited, res);
}

int main(void){
    // Your code here!
    test();
    
    return 0;
    
}
