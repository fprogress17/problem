//
//
// @..*
//
//  Created by Choonghun Lee on 9/11/18.
//  @..
//

#include "stdc++.h"


using namespace std;
int m = 0;
int n = 0;
vector<vector<int>> fores;
vector<vector<int>> dist;
vector<vector<bool>> visited;

vector<int> dy = { 1, -1, 0, 0};
vector<int> dx = { 0, 0, 1, -1};

bool inRange(int y, int x){

   if(y >=0 && y<m && x>=0 && x<n)
       return true;

   return false;
}


void dfs(int y, int x ){

   if(!inRange(y, x))
       return;

   int curr =fores[y][x];
  if(fores[y][x] > 1){
      fores[y][x] = 1;
  }


   for(int i =0; i< 4; ++i){
      int ny = y + dy[i];
      int nx = x + dx[i];

      if(!inRange(ny, nx))
          continue;

      if(curr == fores[ny][nx] +1 && visited[ny][nx] == false){

          visited[ny][nx] = true;
          dfs(ny, nx);
          visited[ny][nx] = false;
      }

   }

}
bool isFinished(){

    for(int i =0; i< m; ++i)
        for(int j =0; j< n; ++j)
            if(fores[i][j] != 0 && fores[i][j] != 1 ){
                return false;
            }
            
//            if(fores[i][j] >1 ){
//                return false;
//            }

            return true;
}

int bfs(int y, int x) {


    queue<pair<int, int>> q;

    q.push(make_pair(0, 0));

    dist[0][0] = 0;
    visited[0][0] = true;

    while (!q.empty()) {


        pair<int, int> here = q.front();
        q.pop();

        int cur = fores[here.first][here.second];

        fores[here.first][here.second] = 1;
        y  = here.first;
        x  = here.second;
        
        visited[y][x] = true;
        
        if (isFinished())
            return dist[y][x];


        for (int i = 0; i < 4; ++i) {
            int ny = here.first + dy[i];
            int nx = here.second + dx[i];

            if (inRange(ny, nx) && visited[ny][nx] == false && fores[ny][nx] == cur + 1   ) {

               
                q.push(make_pair(ny, nx));
                dist[ny][nx] = dist[y][x] + 1;
            }

        }

    }

    return -1;
}



int cutOffTree(vector<vector<int>>& forest) {

    fores = forest;
    m = forest.size();
    if(m != 0)
        n = forest[0].size();

    visited = vector<vector<bool>>(m, vector<bool>(n, false)) ;
    dist = vector<vector<int>>(m, vector<int>(n, 0)) ;

    
    int ret = bfs(0,0);

    return ret;


}


int main(int argc, const char * argv[]) {
    // insert code here...

//   vector<vector<int>> golf = {
//   {2,3,4},
//    {0,0,5},
//    {8,7,6}
//    } ;

    vector<vector<int>> golf =
            {
            {4125,0,9785,8392,138,0,0,0},
            {0,0,0,0,6923,6875,8723,0}};

            [[54581641,64080174,24346381,69107959],
            [86374198,61363882,68783324,79706116],
            [668150,92178815,89819108,94701471],
            [83920491,22724204,46281641,47531096],
            [89078499,18904913,25462145,60813308]]

   int ret = cutOffTree(golf);
   

    std::cout << "Hello, World!\n";
    return 0;
}
