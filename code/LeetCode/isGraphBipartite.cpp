//
//
// @..*
//
//   ..
//  @..
//

#include "stdc++.h"


using namespace std;

 // Is Graph Bipartite

int n ;
vector<int> color;
vector<vector<int>> adj;



bool dfs(int s, int col){
    
    
    color[s] = col;
    
    for(int i =0;i < adj[s].size(); ++i){
        
        int there = adj[s][i];
        
        if(color[there] != 0 && color[there] == color[s])
            return false;
        
        if(color[there] != 0 && color[there] != color[s])
            continue;
        
        int nextColor  =  ( col == 1 ? 2 : 1 );
        
            bool re = dfs(there, nextColor);
            if(!re)
                return false;
            
        }
        
    
    return true;
}

bool check(vector<vector<int>> &graph){
    
    adj = graph;
    
    for(int i =0;i<n; ++i){
        
        if(color[i] == 0){
            bool r = dfs(i, 1);
            if(!r)
                return false;
        }
        
        
    }
    
    return true;;
    
    
    
}

bool isBipartite(vector<vector<int>>& graph) {
    
    n = graph.size();
    color.resize(n, 0);
    
    return check(graph);
    
}



#if 0

bool dfs(int s){
    
 
        bool ret = true;
    
        for(int i =0;i < adj[s].size(); ++i){
            
            int there = adj[s][i];
            
            if(color[there] != 0 && color[there] == color[s])
                return false;
            
            if(color[there] != 0 && color[there] != color[s])
                continue;
            
            
            if(color[there] == 0){
                if(color[s] == 1){
                    color[there] = 2;
                }else{
                    color[there] = 1;
                }
                
               ret  &= dfs(there);
                
            }
            
            
        }
    
    return ret;
}


bool check(vector<vector<int>> &graph){
    
    adj = graph;
    
    int start = -1;
    
    for(int i = 0;i < n; ++i){
        int k = graph[i].size();
        if(k >0){
            int t = graph[i].size();
            if(t> 0){
                start = graph[i][0];
                break;
            }
            
        }
        
    }

    if(start == -1)
        return true; //// this is true to pass the leet : case :  vector<vector<int>> a =  {{}};
    
    color[start] = 1;
  bool ret =  dfs(start);
  return ret;
    
    
    
}

bool isBipartite(vector<vector<int>>& graph) {
    
    n = graph.size();
    color.resize(n, 0);
    
    return check(graph);
    
}

#endif

int main(int argc, const char * argv[]) {
    // insert code here...
  
    // [[],[2,4,6],[1,4,8,9],[7,8],[1,2,8,9],[6,9],[1,5,7,8,9],[3,6,9],[2,3,4,6,9],[2,4,5,6,7,8]]
  //  vector<vector<int>> a = {{1,3},{0,2},{1,3},{0,2}};
    vector<vector<int>> a =  {{}};
    bool ret = isBipartite(a);
    
    std::cout << "Hello, World!\n";
    return 0;
}
