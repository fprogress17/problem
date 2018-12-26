//
//
// @..*
//
//  Created    on 9/11/18.
//  @..
//

#include "stdc++.h"


using namespace std;


int n;
int m;

vector<int> dy = { 1, -1, 0, 0 };
vector<int> dx = { 0, 0,  1, -1};

vector<vector<bool>> check;

bool inRange(int y, int x){

   if(y>=0 && y<n && x >= 0 && x < m)
       return true;

   return false;

}

void move( int y, int x, vector<vector<char>>& grid ){


   if(grid[y][x] == '1' && !check[y][x]){

      check[y][x] = true;

      for(int i = 0; i< 4; ++i){

          if(inRange(y + dy[i], x + dx[i])){

              move(y+dy[i], x+ dx[i], grid);

          }

      }
   }
}



int numIslands(vector<vector<char>>& grid) {

   n = grid.size();
    
   if(n != 0)
        m = grid[0].size();
    
    if(n == 0 )
        return 0;

  check = vector<vector<bool>>(n, vector<bool>(m, false)) ;
   int count = 0;

  for(int i = 0; i < n ; ++i){
      for(int j = 0; j < m ; ++j){

          if(grid[i][j] == '1' && check[i][j] == false ){

                count ++;

                move(i, j,grid);

          }


      }
  }


  return count;
    
}


int main(int argc, const char * argv[]) {
    // insert code here...
//
//    vector<vector<char>> grid =  {{'1','1','0','0','0'},
//                                  {'1','1','0','0','0'},
//                                  {'0','0','1','0','0'},
//                                  {'0','0','0','1','1'}};
//
    vector<vector<char>> grid =  { };

        int res = numIslands(grid);
        
    std::cout << "Hello, World!\n";
    return 0;
}
