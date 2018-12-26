//
//
// @..*
//
//  Created by Choonghun Lee on 9/11/18.
//  @..
//

#include "stdc++.h"


using namespace std;

vector<vector<int>> adj;
vector<int> discovered;
vector<bool> visited;
int cnt = 0;

vector<int> res;

void dfs(int s ){


    visited[s] = true;

    for(int i = 0;i < adj[s].size(); ++i){

      int there = adj[s][i] ;

      if(!visited[there]){

          discovered[there] = ++cnt;
          dfs(there);

       }else{

         if(discovered[s] >= discovered[there]) {

         }

      }

    }

   res.push_back(s) ;

}

bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {

    vector<int> v;
   for(int i =0;i <  prerequisites.size(); ++i){
       //for(pair<int, int> p : prerequisites){

       pair<int,int> p = prerequisites[i];

     if( find(v.begin(), v.end(), p.first) == v.end()){
         v.push_back(p.first) ;
      }


      if( find(v.begin(), v.end(), p.second) == v.end()){
         v.push_back(p.second) ;
      }
   }


   
   adj =  vector<vector<int>>(numCourses, vector<int>());
   discovered = vector<int>(numCourses, 0);
   visited = vector<bool>(numCourses, false);

    for(int i =0;i <  prerequisites.size(); ++i) {

        pair<int, int> p = prerequisites[i];

        adj[p.second].push_back(p.first);
        //adj[p.first].push_back(p.second);
    }

    for(int i =0;i < numCourses; ++i){
        if(!visited[i])
            dfs(i);


    }


    reverse(res.begin(), res.end());



    for(int i =0;i < numCourses; ++i){
        for(int j= i+1;j< numCourses; ++j){

            if(find(adj[res[j]].begin(),
                    adj[res[j]].end(), res[i]) != adj[res[j]].end())
                return false;
        }
    }

    return true;


}



int main(int argc, const char * argv[]) {
    // insert code here...

    //vector<pair<int, int>>pre = {{1,0},{0,1}};
  //  vector<pair<int, int>>pre = {{1,0}};
      vector<pair<int, int>>pre = {{0,1}};

    bool ret = canFinish(2, pre);
    std::cout << "Hello, World!\n";
    return 0;
}
