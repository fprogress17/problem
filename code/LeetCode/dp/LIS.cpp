//
//
// @..*
//
//  Created by Choonghun Lee on 9/11/18.
//  @..
//

#include "stdc++.h"


using namespace std;

int lengthOfLIS(vector<int>& nums) {

    int n = nums.size();
    if(n==0)
        return 0;

    vector<int> dp(n+1);

   dp[0] = 1;

   for(int i = 1; i< n; ++i){
       int ret = INT_MIN;
      for(int j = 0 ; j<i; ++j) {

          if(nums[i] > nums[j]){
              ret = max(ret, dp[j] + 1);
          }
      }

      dp[i] = max(ret, 1);
   }

   return *max_element(dp.begin(),dp.end());
   //return dp[n-1];

}

int main(int argc, const char * argv[]) {
    // insert code here...
   //vector<int> n = {10,9,2,5,3,7,101,18}; //4
   vector<int> n = {1,3,6,7,9,4,10,5,6}; //

   int ret = lengthOfLIS(n);
   
    std::cout << "Hello, World!\n";
    return 0;
}
