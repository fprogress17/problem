//
//
// @..*
//
//   ..
//  @..
//

#include "stdc++.h"

// maximum subarray
// Largest Sum Contiguous Subarray

#if 0
find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:
Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
#endif

using namespace std;


int maxSubArray(vector<int> nums) {
    
    int res = INT_MIN;
    int currSum = 0;
    
    for (int num : nums) {
        
        currSum += num;
        currSum = max(currSum, num);
        
        res = max(res, currSum);
    }
    
    return res;
}

////////////////////////////////
////////////////////////////////

int opt(int m, vector<int>&nums, vector<int>&res){
    
    if(m==0)
        return nums[0];
    
    if(res [m] != -1)
        return res[m];
    
    int mV = INT_MIN;
    
    
    mV =    opt(m-1, nums, res) + nums[m] ;
    
    
    // mV = max(mV, 0);
    mV = max(mV, nums[m]);
    
    
    res[m]=mV;
    
    return mV;
}

int maxSubArray(vector<int>& nums) {
    
    
    vector<int> res(nums.size()+1, -1);
    
    int ret = INT_MIN;
    
    for(int i=0;i<nums.size();++i){
        
        ret = max(ret, opt(i, nums, res));
    }
    
    return ret;
}




int main(int argc, const char * argv[]) {
    // insert code here...
  
    
    std::cout << "Hello, World!\n";
    return 0;
}
