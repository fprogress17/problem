//
//
// @..*
//
//  Created    on 9/11/18.
//  @..
//

#include "stdc++.h"


using namespace std;


int state;

queue<int> q;

map<int, int> dist;
map<int, map<int, bool>> visited;

vector<vector<int>> adj;
int n;

bool isFinished(int tstate){

   int t = tstate& 0xffff;

   return t == (1 << n) -1;

}


int shortestPathLength(vector<vector<int>>& graph) {

 int n = graph.size();

 adj= vector<vector<int>>(n, vector<int>());



 for( int i =0;i<n;++i){

     int tstate = 0;

     tstate = ( i << 24) | (i << 16) | (1 << i);
                //org   //here    // state
     q.push(tstate);
     dist[tstate] = 0;
     visited[0][0]  = true;;

     adj[i] = graph[i];

 }

 while(!q.empty()){
     
     int s = q.size();
         while(s--){

         int h = q.front(); q.pop();

         int  here = (h &0x00ff0000) >> 16;
         int hstate = h & 0x0000ffff;

         int org = (h & 0xff000000) >> 24;
        if(isFinished(h)){
            return dist[h];
        }


       for(int i = 0;i< adj[here].size(); ++i){

           int there = adj[here][i];
           int tstate = (h & 0x00ffffff ) | ((1 << there) << 16) | (hstate | (1<<there));

          if(visited[org][there] == false)
           // if(dist.count(tstate) == 0)
           {
                    dist[tstate] = dist[hstate] + 1;
               visited[org][there] = true;
                    q.push(tstate);
           }
       }

     }
 }
    return -1;



}


int main(int argc, const char * argv[]) {
    // insert code here...

    vector<vector<int>> g = {{1},{0,2,4},{1,3,4},{2},{1,2}};
    
    int ret = shortestPathLength(g);

    std::cout << "Hello, World!\n";
    return 0;
}
