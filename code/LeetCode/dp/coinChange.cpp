//
//
// @..*
//
//  Created    on 9/11/18.
//  @..
//

#include "stdc++.h"


using namespace std;



int cache[100] ;

int minCount = INT_MAX;
vector<int> coinA ;

int coinChangeWithCount(int amount,int cCount);

// coinChange2 has the issues for memoization....

int coinChange2(vector<int>& coins, int amount) {
    
    coinA = coins;
    
    //memset(cache, -1, sizeof(cache));
    memset( &cache[0] , -1, sizeof(cache) );
    //fill( &cache[0][0], &cache[0][0] + sizeof(cache) );
    
    for(int i =0;i <= amount; ++i){

        int ret ;

        
           ret =  coinChangeWithCount( i, 0) ;
            cache[i] = ret;
        



    }

    
    coinChangeWithCount(amount,0);
    
    if(minCount == INT_MAX)
        return -1;
    
    return minCount;
}



int coinChangeWithCount(int amount,int cCount)
{
    cout<< amount << endl;
    
    if(amount == 0){
        minCount = min(minCount, cCount);
        
        
        return  cCount;
    }
    
   //int &ret = cache[amount] ;
    int ret = cache[amount];
    if(ret != -1)
        return ret;
  //  int ret;
    
    int rett = INT_MAX;
    for(int i=0;i<coinA.size(); ++i){
        
        if(amount >= coinA[i]){
            rett = min(rett, coinChangeWithCount( amount - coinA[i], cCount + 1));
        }
    }
    
    ret = rett;
    
    // cache[amount] = ret;
    
    return ret;
}


//// in this case :  coins = [2], amount = 3
///  f[3] = f[3-2] + 1;
///  f[2] = f[2-2] + 1;
///  f[1] = ??? any value greater than amount but pretty less than INT_MAX which can accomdate the gap that can acculate.

vector<int> dp;

int coinChange(vector<int> coins, int amount)
{
    dp.resize(amount+1, amount+1); //dp.resize(amount+1, INT_MAX);

    dp[0] = 0;

    for(int i = 1; i<= amount; ++i){

        int ret = 0;

        for(int j=0;j < coins.size();++j){
            cout<< i << " " << coins[j] << endl;
         if(i >= coins[j]){

            //ret = min(ret, dp[i-coins[j]]) + 1;
          //  dp[i] = min(dp[i], dp[i-coins[j]])+1;
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
    
//    vector<int> coins = {1, 2, 5};
//    int amount = 13;
//
//    vector<int> coins = {  2 };
//    int amount = 3;

    
    
    vector<int> coins = {  2,5,10,1 };
    int amount = 27;
    
    int res = coinChange(coins, amount);
    
    
    std::cout << "Hello, World!\n";
    return 0;
}
