//
//
// @..*
//
//  Created    on 9/11/18.
//  @..
//

#include "stdc++.h"

using namespace std;

#define  MAX_V 100

int V = 100;

vector<pair<int,int>> adj[MAX_V];


vector<int> bellmanFord(int src){

    vector<int> dist(V, INT_MAX);

    dist[src] = 0;

    bool updated = false;

    for(int iter = 0;iter<V; ++iter){


       for(int here = 0; here < V; ++here){

           for(int i=0; i< adj[here].size(); ++ i){

               int there = adj[here][i].first;

               if(dist[there] > dist[here] + adj[here][i].second ){

                   dist[there] = dist[here] + adj[here][i].second; // relaxing
                   updated = true;
               }
           }

           if(!updated) break;
       }
    }

    if(updated)
        return dist.clear();

    return dist;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    
    
    std::cout << "Hello, World!\n";
    return 0;
}
