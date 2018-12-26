//
//
// @..*
//
//   ..
//  @..
//

#include "stdc++.h"


using namespace std;

// You may complete at most two transactions.

int maxProfit(vector<int> &prices) {
    
    int n = prices.size();
    if (n < 2) return 0;
    
    vector<int> profitUntil(n,0);
    vector<int> profitFrom(n,0);
    
    int ret = 0;
    
    int minPrice = prices[0];
    
    for (int i = 1; i < n; ++i) {
        minPrice = min(minPrice, prices[i]);
        profitUntil[i] = max(profitUntil[i - 1], prices[i] - minPrice);
    }
    
    int maxPrice = prices[n - 1];
    
    for (int i = n - 2; i >= 0; --i) {
        maxPrice = max(maxPrice, prices[i]);
        profitFrom[i] = max(profitFrom[i + 1], maxPrice - prices[i]);
    }
    
 
    for (int i = 0; i < n; ++i)
        ret = max(ret, profitUntil[i] + profitFrom[i]);
    
    
    return ret;
}



int main(int argc, const char * argv[]) {
    // insert code here...
  
    
    std::cout << "Hello, World!\n";
    return 0;
}

