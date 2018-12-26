//
//
// @..*
//
//  Created    on 9/11/18.
//  @..
//

#include "stdc++.h"


using namespace std;


int minSubArrayLen(int s, vector<int>& nums) {


   int n = (int)nums.size();
   int start = 0;
   int end = 0;

   int mValue = INT_MAX;
   int sum = 0;

   for(int i=0;i<n; ++i){

     sum += nums[i]     ;

     if(sum >= s){
        end = i;
        mValue = min(mValue, i-start + 1);

        while(sum >= s){
            sum -= nums[start];
            mValue = min(mValue, i-start + 1);
            ++start;
          
            
        }
     }

    
   }

    if(mValue == INT_MAX)
        mValue = 0;
    
 return mValue;


}

int main(int argc, const char * argv[]) {
    // insert code here...
//    vector<int> nums = {2,3,1,2,4,3};
//    int res = minSubArrayLen(7, nums);

    vector<int> nums = {1,1};
    int res = minSubArrayLen(3, nums);
    
    std::cout << "Hello, World!\n";
    return 0;
}
