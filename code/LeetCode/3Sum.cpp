//
//
// @..*
//
//  Created by Choonghun Lee on 9/11/18.
//  @..
//

#include "stdc++.h"


using namespace std;


vector<vector<int>> threeSum(vector<int>& nums) {

   sort(nums.begin(), nums.end()) ;

    int n = (int)nums.size();
     vector<vector<int>> res;

   for(int i =0; i<= n-3; ++i){

       if(i != 0 && nums[i] == nums[i-1])
           continue;
       
       int t = nums[i];

       int j = i+1;
       int k = n-1;

       while(j<k){

          if(nums[i] + nums[j] + nums[k] == 0){

              vector<int> r ;
              r.push_back(nums[i]);
              r.push_back(nums[j]);
              r.push_back(nums[k]);
             res.push_back(r);
          }

          if( nums[j] + nums[k]  < - nums[i]){

              ++j;

              while( nums[j] == nums[j-1])
                  ++j;


          }else{
              --k;
              while( nums[k] == nums[k+1])
                  --k;
          }

       }
   }

   return res;
}


int main(int argc, const char * argv[]) {
    // insert code here...

    vector<int> nums =  {-1, 0, 1, 2, -1, -4};

    vector<vector<int>> res = threeSum(nums);
    

    std::cout << "Hello, World!\n";
    return 0;
}
