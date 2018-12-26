//
//
// @..*
//
//  Created    on 9/11/18.
//  @..
//

#include "stdc++.h"


using namespace std;

int n = 0;
int m = 0;

vector<int> dy = { 1 ,-1 ,0 ,0};
vector<int> dx = { 0 ,0 ,1 ,-1};


bool inRange(int y, int x){

   if(y >=0 && y<n && x >= 0 && x < m)
       return true;
   return false;
}


void dfs(int i, int j, int val, vector<vector<int>> &rooms){

    if(!inRange(i,j))
        return ;

    if(rooms[i][j] == -1)
        return;

    if( rooms[i][j] < val)
        return;
 
    rooms[i][j] = val;
    
   for(int k =0;k<4; ++k){

       cout<< i+ dy[k] << " " << j+dx[k] << endl;
      dfs(i+dy[k], j+dx[k], val + 1, rooms) ;
       cout<< endl;

   }



}

void wallsAndGates(vector<vector<int>>& rooms) {

    n = rooms.size();
    if(n!=0)
        m = rooms[0].size();
    
   for(int i =0; i< rooms.size(); ++i)
       for(int j =0; j< rooms[0].size(); ++j)
       {

           if(rooms[i][j] == 0){
               for(int k =0;k<4; ++k){
                   
                   cout<< i+ dy[k] << " " << j+dx[k] << endl;
                   dfs(i+dy[k], j+dx[k],   1, rooms) ;
                   cout<< endl;
                   
               }
           }

       }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<vector<int>> rooms = {{2147483647,         -1,       0,       2147483647},
                                 {2147483647,  2147483647, 2147483647          ,-1},
                                 {2147483647,        -1,    2147483647,        -1},
                                 {0,              -1,     2147483647,   2147483647}};
    wallsAndGates(rooms);

    std::cout << "Hello, World!\n";
    return 0;
}
