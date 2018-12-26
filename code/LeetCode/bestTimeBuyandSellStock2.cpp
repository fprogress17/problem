//
//
// @..*
//
//   ..
//  @..
//

#include "stdc++.h"


using namespace std;

//You may complete as many transactions as you like
 
int maxProfit(vector< int >& prices) {
    
    int res = 0 , n = prices.size();
    
    for ( int i = 0 ; i < n - 1 ; ++ i) {
        if (prices [i] < prices[i + 1 ]) {
            res += prices[i + 1 ] - prices[i];
        }
    }
    
    return res;
}


int main(int argc, const char * argv[]) {
    // insert code here...
  
    
    std::cout << "Hello, World!\n";
    return 0;
}
