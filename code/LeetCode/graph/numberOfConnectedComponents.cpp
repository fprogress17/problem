//
//
// @..*
//
//  Created    on 9/11/18.
//  @..
//

#include "stdc++.h"


using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

void dfs(int s){


    visited[s] = true;

   for(int i =0;i< adj[s].size(); ++i) {

      int there = adj[s][i];

      if(!visited[there]){
          dfs(there);
      }


   }



}

int countComponents(int n, vector<pair<int, int>>& edges) {

    adj= vector<vector<int>>(n, vector<int>());
    visited = vector<bool>(n, false);

    for( pair<int,int>p : edges){

        adj[p.first].push_back(p.second);
        adj[p.second].push_back(p.first);

    }

    int cnt = 0;
    for(int i =0;i < n; ++i){

        if(!visited[i]){
           cnt ++;
           dfs(i);

        }
    }

    return cnt;
}

int main(int argc, const char * argv[]) {
    // insert code here...


    vector<pair<int,int>> edges ={{0,1},{1,2},{3,4}};

    int n = 5;

    int ret = countComponents(n, edges);
    
    std::cout << "Hello, World!\n";
    return 0;
}
