//
//
// @..*
//
//  Created by Choonghun Lee on 9/11/18.
//  @..
//

#include "stdc++.h"


using namespace std;

int getMoneyAmount(int n) {

    if(n == 0)
        return 0;

    vector<vector<int>> dp(n+1, vector<int>(n+1,0));

    for(int L = 2; L<=n; ++L){

       for(int i = 1; i<= n+1-L; ++i){

           int j = i+L-1;
               dp[i][j] = 0x7FFFFFFF; //INT_MAX
           
           cout<< i << " "<< j << endl;

           for(int k = i;k<=j;++k)

               dp[i][j] = min(dp[i][j], k + max( (k == i ? 0 : dp[i][k-1]),
                                             (k == j ? 0 : dp[k+1][j]) ));


       }

    }

    return dp[1][n];

}

#if 0

#endif

int main(int argc, const char * argv[]) {
    // insert code here...
    int res = getMoneyAmount(4);
    
    std::cout << "Hello, World!\n";
    return 0;
}
