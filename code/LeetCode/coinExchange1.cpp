//
//
// @..*
//
//   ..
//  @..
//

#include "stdc++.h"


using namespace std;

 //. Write a function to compute the fewest number of coins that you need to make up that amount. 

vector<int> dp;
int coinChange(vector<int> coins, int amount)
{
    dp.resize(amount+1, amount+1); //dp.resize(amount+1, INT_MAX);
    
    dp[0] = 0;
    
    for(int i = 1; i<= amount; ++i){
        
        int ret = 0;
        
        for(int j=0;j < coins.size();++j){
            
            if(i >= coins[j]){
                
                //ret = min(ret, dp[i-coins[j]]) + 1;
                dp[i] = min(dp[i], dp[i-coins[j]] + 1);
            }
            
            
        }
        
        //dp[i] = ret;
    }
    
    if( dp[amount] > amount ){
        return -1;
        
    }
    
    return dp[amount];
}



int main(int argc, const char * argv[]) {
    // insert code here...
  
    
    std::cout << "Hello, World!\n";
    return 0;
}
