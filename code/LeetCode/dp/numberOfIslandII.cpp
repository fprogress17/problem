//
//
// @..*
//
//  Created by Choonghun Lee on 9/11/18.
//  @..
//

#include "stdc++.h"


using namespace std;


vector<int> dx = {0,0,1,-1};
vector<int> dy = {1,-1,0,0};


vector<vector<int>> adj;
vector<int> res;


struct Uf{

    vector<int> parent;
    vector<int> rank;

   Uf(int n): parent(n), rank(n) {

       for(int i =0;i<n;++i){
        //  parent[i]= i;
          parent[i]= -1;
          rank[i] = 1;
       }
   }


   int find(int t){

       int p = parent[t];

       if(p == t)
           return t;

       if(p == -1){

           parent[t] = t;
           return t;
       }

       int p1 = find(p);
       parent[t] = p1;
       return p1;
   }

   void merge(int a, int b){

       int pa = find(a);
       int pb = find(b);


       if(pa != pb){

           parent[pb] = pa;

       }
   }

   int count(){

      set<int> s;

      for( int i =0;i<parent.size();++i)
      {
          int p = parent[i];
          if(p != -1){
              s.insert(find(p));
          }
      }

     return s.size();

   }

};

int M;
int N;

int getIntFrom(int y, int x){

    return y*M +x ;

}

vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {


    M = m;
    N= n;

    adj = vector<vector<int>>(m, vector<int>(n,0));
    int cnt = 0;

    Uf uf(m*n) ;

    for(int i =0;i< positions.size() ; ++i ){

         pair<int,int> p = positions[i];

        if(  i == 0 && p.first>=0 && p.first < m && p.second >=0 && p.second < n)
        {
            adj[p.first][p.second] = 1;

            cnt++;
            res.push_back(cnt);
        }



        if(  i != 0 && p.first>=0 && p.first < m && p.second >=0 && p.second < n)
        {

            adj[p.first][p.second] = 1;

            bool there = false;

            for(int k = 0; k< 4; ++k){

                int y = p.first + dy[k];
                int x = p.second + dx[k];

                if( y>=0 && y < m && x >=0 && x < n)
                {

                    if(adj[y][x] == 1){

                       int p1 = uf.find(getIntFrom(p.first,p.second) );
                       int p2 = uf.find(getIntFrom(y,x) );

                       uf.merge(p1,p2);
                    }
                }

            }



            res.push_back(cnt);
        }

    }

    return res;
}



int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cout << "Hello, World!\n";
    return 0;
}
