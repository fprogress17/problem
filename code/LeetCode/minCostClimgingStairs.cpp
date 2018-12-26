//
//
// @..*
//
//   ..
//  @..
//

#include "stdc++.h"


using namespace std;

 
int minCostClimbingStairs(vector<int>& cost) {
    
    int n = cost.size();
    vector<int> dp(n + 1, 0);
    
    for (int i = 2; i < n + 1; ++i) {
    
        dp[i] = min( dp[i- 2] + cost[i - 2], dp[i - 1] + cost[i - 1]);
    }
    
    return dp.back();
}


int main(int argc, const char * argv[]) {
    // insert code here...
  
    
    std::cout << "Hello, World!\n";
    return 0;
}
