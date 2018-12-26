//
//
// @..*
//
//  Created by Choonghun Lee on 9/11/18.
//  @..
//

#include "stdc++.h"


using namespace std;


int change(int amount, vector<int>& coins) {
    
    vector<vector<int>> dp(coins.size()+1, vector<int>(amount+1));
    
    for(int i = 0; i <= coins.size() ; ++i)
        dp[i][0] = 1;
    
    for(int i = 1; i<= coins.size(); ++i){     // caution : i = 0 : no coins  , index for dp with no coins
        for(int j = 1; j <= amount; ++j){
            
            dp[i][j] = dp[i-1][j] +
            ( j >= coins[i-1] ? dp[i][j-coins[i-1]] : 0 ); // caution : coins[i-1]  , real coin values starts i-1
            
        }
    }
    
    return dp[coins.size()][amount];
    
}




int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> coins = {1, 2, 5};
    
    int ret = change(5, coins);
    
    std::cout << "Hello, World!\n";
    return 0;
}
