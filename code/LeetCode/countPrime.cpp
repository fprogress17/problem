//
//
// @..*
//
//  Created by Choonghun Lee on 9/11/18.
//  @..
//

#include "stdc++.h"


using namespace std;

vector<int> dp;


int countPrimes(int n) {

    dp = vector<int>(n+1, 0);

    for(int i = 2;i<=n; ++i){

        int j = i;

        while(j <= n){
            
            j = j+i;
            
                dp[j] = 1;
            
         

        }
    }


   int count = 2;
    for(int i = 4;i< n ;++i)
        if(dp[i] == 0)
            count++;

        return count;


}

int main(int argc, const char * argv[]) {
    // insert code here...
    int res = countPrimes(100) ;
   
    std::cout << "Hello, World!\n";
    return 0;
}
