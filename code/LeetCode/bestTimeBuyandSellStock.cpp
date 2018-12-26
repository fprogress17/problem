//
//
// @..*
//
//   ..
//  @..
//

#include "stdc++.h"


using namespace std;

// best time buy and sell stock
//

int maxProfit(vector<int> &prices) {
    
    int minPrices = INT_MAX;
    int ret = 0;
    
    int n = prices.size();
    
    for (int i = 0; i < n; ++i) {
        minPrices = min(minPrices, prices[i]);
        ret = max(ret, prices[i] - minPrices);
    }
    
    return ret;
}


int maxProfit(vector< int >& prices) {
    
    int res = 0 , buy = INT_MAX;
    
    for ( int price : prices) {
    
        buy = min(buy, price);
        res = max(res, price - buy);
    
    }
    
    return res;
}
 



int main(int argc, const char * argv[]) {
    // insert code here...
  
    
    std::cout << "Hello, World!\n";
    return 0;
}
