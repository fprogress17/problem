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
vector<int> discovered;
vector<int> parents;
vector<bool> finished;
vector<bool> visited;

vector<vector<int>> rett;

int cnt = 0;
vector<int> ret;

queue<int> q;

void dfs(int s){


    discovered[s] = cnt++;

    for(int i =0;i< adj[s].size(); ++i) {

        int there = adj[s][i];

        if(discovered[there] == -1){
            parents[there] = s ;
            dfs(there);
        }else{

            if(discovered[s] >= discovered[there] && finished[there] == false && parents[s] != there){

                ret.push_back(there);
                ret.push_back(s);

            }
        }
 
    }

    finished[s] = true;
 
}

bool dfsIsCycle(int s){
    
    
    discovered[s] = cnt++;
    bool re = false;
    
    for(int i =0;i< adj[s].size(); ++i) {
        
        int there = adj[s][i];
        
      
        
        if(discovered[there] == -1){
            parents[there] = s ;
           re |= dfsIsCycle(there);
        }else{
            
            if(discovered[s] >= discovered[there] && finished[there] == false && parents[s] != there){
                
                //ret.push_back(there);
                //ret.push_back(s);
                return true;
                
            }
        }
        
    }
    
    finished[s] = true;
    
    return re;
}



void bfs(int h){

   q.push(h);
   visited[h] = true;
   discovered[h] = 1;

   while(!q.empty()){

      int here = q.front(); q.pop();

      for(int i =0; i< adj[here].size(); ++i){

          int there = adj[here][i];

          if(!discovered[there] == -1){

                q.push(there) ;

          } else if( visited[there] != 1){

              vector<int> r;
              r.push_back(min(here, there));
              r.push_back(max(here, there));

              rett.push_back(r);
          }



      }


   }





}

vector<int> findRedundantConnection(vector<vector<int>>& edges) {

    vector<int> v;
    for(int i =0;i <  edges.size(); ++i){
        //for(pair<int, int> p : prerequisites){

        vector<int> p = edges[i];

        for(int j=0;j < p.size(); ++j){
           int k = p[j];

            if( find(v.begin(), v.end(), k) == v.end()){
                v.push_back(k) ;
            }
        }
    }

   int n = v.size();
   sort(v.begin(), v.end()) ;

    adj = vector<vector<int>>(n+1, vector<int>());
    discovered = vector<int>(n+1,-1) ;
    parents = vector<int>(n+1,-1) ;
    finished = vector<bool>(n+1, false);
    visited = vector<bool>(n+1, false);

     for(int i =0;i <  edges.size(); ++i) {

         vector<int> p = edges[i];
         
         adj[p[0]].push_back(p[1]);
         adj[p[1]].push_back(p[0]);
         
         discovered = vector<int>(n+1,-1) ;
         parents = vector<int>(n+1,-1) ;
         finished = vector<bool>(n+1, false);
         visited = vector<bool>(n+1, false);
         
         if( dfsIsCycle(p[0]) == true){
            
             ret.push_back(p[0]);
             ret.push_back(p[1]);
             break;
            }
         
     }


//     dfs( v[0]);

//  bfs(v[0]);

     


    return ret;

}



int main(int argc, const char * argv[]) {
    // insert code here...
    //vector<vector<int>> edges = {{1,2}, {2,3}, {3,4}, {1,4}, {1,5}};
   vector<vector<int>> edges = {{1,2},{1,3},{2,3}};
   
    vector<int> ret = findRedundantConnection(edges);
    std::cout << "Hello, World!\n";
    return 0;
}
