//
//
// @..*
//
//  Created    on 9/11/18.
//  @..
//

#include "stdc++.h"


using namespace std;


vector<int> dx = { 1, 2, 2, 1,-1,-2,-2,-1 };
vector<int> dy = {-2,-1, 1, 2, 2, 1,-1,-2 };

int n ;

double dp[26][26][101];

vector<vector<bool>> rec(100,vector<bool>(100,false));

bool inRange(int y, int x){

    if(x >= 0 && x < n && y >= 0 && y < n)
        return true;

    return false;
}


double move(int y, int x, int K ){

    if(K==0){
        
        if(inRange(y, x)){
           
            return 1;
        }
       return 0;
    }

     double & ret = dp[y][x][K];
    
    if(ret != -1.0){
        
        return ret;
        
    }
    
    ret = 0.0;

    for(int i =0;i< 8; ++i)
    {
        
        
       if(inRange( y+dy[i], x + dx[i]) /*&& rec[ y+dy[i]][ x + dx[i]] == false*/){
 
          //rec[ y+dy[i]][ x + dx[i]] = true;
          ret += move( y+dy[i],x+dx[i], K-1)/8.0;
         // rec[ y+dy[i]][ x + dx[i]] = false;
       }

    }

    return ret;
   
}


double knightProbability(int N, int K, int r, int c) {

    n = N;
 
 
    
   // rec[ r ][ c ] = true;
  double ret = move(r,c,K);

    return ret;
 
}

int main(int argc, const char * argv[]) {
    // insert code here...
   
    // memset(dp ,-1, sizeof(dp));
    for(int i = 0;i< 26; ++i)
        for(int j = 0;j< 26; ++j)
            for(int k = 0;k< 101; ++k)
                dp[i][j][k] = -1.0;
    
    double ret = knightProbability(3,2,0,0);
    
   
    
    std::cout << "Hello, World!\n";
    return 0;
}
