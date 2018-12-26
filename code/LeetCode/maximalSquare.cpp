//
//
// @..*
//
//  Created by Choonghun Lee on 9/11/18.
//  @..
//

#include "stdc++.h"


using namespace std;


int maximalSquare(vector<vector<char>> &matrix){
    
    if(matrix.empty() || matrix[0].empty())
        return 0;
    
    int m  = matrix.size(); int n = matrix[0].size();
    int mVal= 0;
    
    vector<vector<int>> dp(matrix.size(), vector<int>(n,0));
    
    for(int i=0;i< m; ++i)
        for(int j=0; j<n; ++j){
            
            //cout<< "mat" << i << " " << j << " " << matrix[i][j] << endl;
            
            if(i==0 || j == 0){
                
                dp[i][j] = matrix[i][j] - '0';
                
            }else if(matrix[i][j] == '1'){ // matrix[i][j] == 1
                    
                
                dp[i][j] = min( min( dp[i-1][j], dp[i][j-1] ), dp[i-1][j-1] ) + 1; //min(matrix[i-1][j],
            }
            
            if(mVal <= dp[i][j]){
                
                cout<< mVal << " " << i << " " << j <<" " << dp[i][j] << endl;
                mVal = max(mVal, dp[i][j]);
            }
        }
    
    return mVal * mVal;
}


vector<vector<char>> m = {{'1','0','1','0','0'},
                          {'1','0','1','1','1'},
                          {'1','1','1','1','1'},
                          {'1','0','0','1','0'}};

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int ret = maximalSquare(m);
    
    
    
    
    
    std::cout << 'Hello, World!\n';
    return 0;
}
