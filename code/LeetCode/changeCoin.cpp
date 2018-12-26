//
//
// @..*
//
//  Created by Choonghun Lee on 9/11/18.
//  @..
//

#include "stdc++.h"


using namespace std;

int coinChangeWithCount( int amount,int cCount) ;

int minCount = INT_MAX;

int cache[100000][1000];

vector<int> coinA ;
int coinChange(vector<int>& coins, int amount) {

    coinA = coins;

    //memset(cache, -1, sizeof(cache));
    memset( &cache[0][0], -1, sizeof(cache) );
    //fill( &cache[0][0], &cache[0][0] + sizeof(cache) );
    coinChangeWithCount( amount, 0) ;

    if(minCount == INT_MAX)
        return -1;

    return minCount;
}



int coinChangeWithCount(int amount,int cCount)
{
    if(amount == 0){
        minCount = min(minCount, cCount);
        return  cCount;
  }

  int &ret = cache[amount][cCount];
    if(ret != -1)
        return ret;

    int rett = INT_MAX;
  for(int i=0;i<coinA.size(); ++i){

        if(amount >= coinA[i]){
          rett = min(ret, coinChangeWithCount( amount - coinA[i], cCount + 1));
        }
    }
    
    ret = rett;

    return ret;
}
 

vector<int> coinsVector = {1,2,5};

int main(int argc, const char * argv[]) {
    // insert code here...
    int ret = coinChange(coinsVector, 11);
    
    std::cout << "Hello, World!\n";
    return 0;
}
