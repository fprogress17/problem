//
//
// @..*
//
//   ..
//  @..
//

#include "stdc++.h"

// from algo spot

using namespace std;

const INT = INT_MAX;
int V;

int capacity[MAX_V][MAX_V];
int flow[MAX_V][MAX_V];

int networkFlow(int source, int sink){
    
    memset(flow,0,sizeof(flow));
    int totalFlow = 0;
    
    while(true){
        vector<int> parent(MAX_V,-1);
        queue<int> q;
        parent[source] = source;
        
        q.push(source);
        
        while(!q.empty()){
            
            int here = q.front(); q.pop();
            
            for(int there = 0; there < V; ++there){
                
                if(capacity[here][there] - flow[here][there] > 0 &&
                   parent[there] == -1){
                    q.push(there);
                    parent[there] = here;
                }
            }
            
        }
        
        if(parent[sink] == -1)
            break;
        
        int amount = INF;
        
        for(int p = sink;p!= source; p = parent[p]){
            amount = min(capacity[parent[p]][p] - flow[parent[p]][p], amount);
          }
        
        for(int p = sink; p!=source; p= parent[p]){
                flow[parent[p]][p] += amount;
                flow[parent[p]][p] -= amount;
        }
        
        totalFlow += amount
    }
    
    return totalFlow;
}



int main(int argc, const char * argv[]) {
    // insert code here...
  
    
    std::cout << "Hello, World!\n";
    return 0;
}
