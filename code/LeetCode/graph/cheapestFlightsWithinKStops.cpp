//
//
// @..*
//
//  Created by Choonghun Lee on 9/11/18.
//  @..
//

#include "stdc++.h"


using namespace std;
vector<bool>visited;
vector<vector<pair<int,int>>> adj;

void dfs(int src, int dst, int cost, int k, int &res){


    if(src == dst)
    {
        res =  min(res, cost);
        return;
    }

    if(k == 0)
        return;

   for(int i = 0; i < adj[src].size();++i){

       int there = adj[src][i].first;
       int costToThere = adj[src][i].second;

      if(!visited[there]) {

            if(cost+costToThere > res)
                continue;


          visited[there] = true;

          dfs(there, dst, cost +  costToThere, k-1, res);

          visited[there] = false;
      }

   }



}

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K){

    visited = vector<bool>(n, false);

    adj = vector<vector<pair<int,int>>>(n, vector<pair<int,int>>());

    for(vector<int> v  : flights){
        adj[v[0]].push_back(make_pair(v[1],v[2]));
    }
    
    int res = INT_MAX;
    visited[src] = true;
    
    dfs(src, dst,0,K+1, res);

    if(res == INT_MAX)
        return -1;

    return res;



}

#if 0


int dijkstra(int n,vector<vector<int>>& flights, int src, int dst, int K){
    int m = INT_MIN;
    
    for( vector<int> v : flights) {
        
        m = max(m, v[2]);
        
    }
    
    int ma = INT_MAX;
    for(int i = 0; i<4 ; ++i)
        ma /= 10;
    
    vector<vector<pair<int,int>>> adj = vector<vector<pair<int,int>>>(n, vector<pair<int,int>>());

    vector<int> dist= vector<int>(n, ma);

    dist[src] = 0;

    int count = -1;

    priority_queue<pair<int,int>> pq;

    pq.push(make_pair(0,src));

    for(vector<int> v  : flights){
        adj[v[0]].push_back(make_pair(v[1],v[2]));
    }

    while(!pq.empty()){

       count ++;
       pair<int,int> h = pq.top(); pq.pop();

       int here = h.second;
        int cost = -h.first;

       if(count - 1 > K){
           return -1;
       }

      if(here == dst){
        return dist[dst] ;
      }

       if(dist[here] < cost)
           continue;

       for(int i = 0;i < adj[here].size(); ++i) {

           int there = adj[here][i].first;
           int nextCost = cost + adj[here][i].second;

          if( dist[there] > nextCost){

              dist[there] = nextCost;
              //pq.push( make_pair(-there.second, there.first));
              pq.push( make_pair(-nextCost, there));
          }


       }

    }
    
   return -1;
    
    
}





int findCheapestPrice0(int n, vector<vector<int>>& flights, int src, int dst, int K) {

int m = INT_MIN;

    for( vector<int> v : flights) {

        m = max(m, v[2]);

    }

    int ma = INT_MAX;
    for(int i = 0; i<4 ; ++i)
        ma /= 10;

    vector<vector<int>> adj = vector<vector<int>>(n, vector<int>(n, ma));


    for(int i=0;i < n; ++i)
        adj[i][i] = 0;

    
    for( vector<int> v : flights) {
        
        adj[v[0]][v[1]] = v[2];
        
    }

    for(int k=0;k < K; ++k)
        for(int i=0;i < n; ++i)
            for(int j=0;j < n; ++j)
            {
                adj[i][j] = min(adj[i][j], adj[i][k]+adj[k][j]);
            }

            if(adj[src][dst] >= ma)
                return -1;

                return adj[src][dst];

}



int findCheapestPrice1(int n, vector<vector<int>>& flights, int src, int dst, int K) {

    int m = INT_MIN;
    
    for( vector<int> v : flights) {
        
        m = max(m, v[2]);
        
    }

    int ma = INT_MAX;
    for(int i = 0; i<4 ; ++i)
        ma /= 10;

    
   vector<vector<int>> adj = vector<vector<int>>(n, vector<int>(n, ma));
   vector<vector<vector<int>>> dp = vector<vector<vector<int>>>(n, vector<vector<int>>(n,vector<int>(n, ma)));

    for(int i =0; i< n; ++i ) {

        for(int j =0; j< n; ++j ){
           if (i == j)
               adj[i][j] = 0;
       }
   }


  for( vector<int> v : flights) {

      adj[v[0]][v[1]] = v[2];

  }

    for(int i =0; i< n; ++i ) {
        
        for(int j =0; j< n; ++j ){
           if (i == j)
               dp[0][i][j] = 0;
           else{
               dp[0][i][j] = min(adj[i][j], adj[i][0] + adj[0][j]);
           }
       }
   }


  for(int k = 1; k< n; k++)
      for(int i = 0; i< n; i++)
          for(int j = 0; j< n; j++)
          {

              dp[k][i][j] = min(dp[k-1][i][j], dp[k-1][i][k] + dp[k-1][k][j]);
          }

    if( dp[K][src][dst] == 0)
        return -1;
    
      if( dp[K][src][dst] >= ma)
        return -1;
    
    return dp[K][src][dst] ;

}

#endif


int main(int argc, const char * argv[]) {
    // insert code here...
    int n = 3;
    vector<vector<int>> edges = {{0,1,100},{1,2,100},{0,2,500}};
    int ret = findCheapestPrice(3, edges, 0,2, 0);
  //  int ret =dijkstra(3, edges, 0,2, 1);
    



//   vector<vector<int>> edges = {{4,1,1},{1,2,3},{0,3,2},{0,4,10},{3,1,1},{1,4,3}};
//    int ret = findCheapestPrice(5, edges, 2, 1, 1);
//
    std::cout << "Hello, World!\n";
    return 0;
}
