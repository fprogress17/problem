//
//
// @..*
//
//  Created by Choonghun Lee on 9/11/18.
//  @..
//

#include "stdc++.h"


using namespace std;


vector<int> largestDivisibleSubset(vector<int>& nums) {

      vector<int> res;

    int n = nums.size();
    if(n==0)
        return res;

    vector<int> dp(n+1,1);
    vector<int> par(n+1);
    

    int currMax = INT_MIN;
    int maxIndex = 0;

    for(int i =0; i<par.size();++i)
        par[i] = i;
  
    sort(nums.begin(), nums.end());

   for(int i = 1; i< n; ++i) {
      for(int j = i-1; j>=0; --j) {

         if(nums[i] % nums[j] == 0 ){

             if( dp[i] < dp[j] + 1){

                 dp[i] = dp[j] + 1;

                 par[i] = j;

             }

             if(dp[i] > currMax){

                 currMax = dp[i];
                 maxIndex = i;
             }

         }

      }
   }


   while(par[maxIndex]!=maxIndex){

      res.push_back(nums[maxIndex]) ;
      maxIndex = par[maxIndex];
   }

    res.push_back(nums[maxIndex]) ;
    
   return res;


}


int main(int argc, const char * argv[]) {
    // insert code here...
    int n = 10;
    
    vector<int> dp[n+1];
    vector<int> par[n+1];
    
    vector<int> t(10);
    

    
    std::cout << "Hello, World!\n";
    return 0;
}
