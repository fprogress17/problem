//
//
// @..*
//
//  Created    on 9/11/18.
//  @..
//

#include "stdc++.h"

#define MAX_V 10
using namespace std;

int adj[MAX_V][MAX_V];
int via[MAX_V][MAX_V];

int V;

void floyd(){

    memset(via, -1, sizeof(via));

    for(int i = 0; i<V; ++i)
        adj[i][j] = 0;

    for(int k=0; k< V; ++k)
        for(int i=0; i< V; ++i)
            for(int j=0;j<V; ++j){

        if(adj[i][j] > (adj[i][k] + adj[k][j]){

            adj[i][j] = adj[i][k] + adj[k][j];

            via[i][j] = k;

        }

    }
}


void recon(int u, int v, vector<int>&path){

    if( u == v){
        path.push_back(u);
        return;
    }


    int k = via[u][v];

    if(k == -1){ // there is no intermedate k

        path.push_back(u);
        path.push_back(v);
        return ;
    }else{

        recon(u, k, path);
        path.pop_back();
        recon(k, v, path);

    }
}



int main(int argc, const char * argv[]) {
    // insert code here...
    
    
    std::cout << "Hello, World!\n";
    return 0;
}
