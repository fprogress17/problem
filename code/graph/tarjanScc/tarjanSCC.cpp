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

vector<vector<int>> adj;

vector<int> sccId;
vector<int> discovered;
stack<int> stk;

int sccCnt;
int vertexCnt;

int scc(int here){
    
    int ret = vertexCnt++;
    discovered[here] = vertexCnt;
    
    stk.push(here);
    
    for(int i = 0;i<adj[here].size(); ++i){
        int there = adj[here][i];
        
        if(discovered[there] == -1){
            ret = min(ret, scc(there));
        }else if(sccId[there] == -1){
            ret = min(ret, discovered[there]);
        }
    }
    
    if(ret == discovered[here]){
        
        while(true){
            int t = stk.top();
            stk.pop();
            sccId[t] = sccCnt;
            
            if(t == here)
                break;
        }
        
        ++sccCnt;
    }
    
    return ret;
}


vector<int> tarjanSCC(){
    
    sccId = discovered = vector<int>(adj.size(), -1);
    sccCnt = vertexCnt = 0;
    
    for(int i=0;i< adj.sie();++i){
        if(discovered[i] == -1)
            scc(i);
    }
    
    return sccId;
}


int main(int argc, const char * argv[]) {
    // insert code here...
  
    
    std::cout << "Hello, World!\n";
    return 0;
}
