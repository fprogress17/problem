//
//
// @..*
//
//   ..
//  @..
//

#include "stdc++.h"


using namespace std;

#if 0
Given an array nums and a target value k,
find the maximum length of a subarray that sums to k.
If there isn't one, return 0 instead.

Note:
The sum of the entire nums array is guaranteed to fit within the 32-bit signed integer range.

Example 1:

Input: nums = [1, -1, 5, -2, 3], k = 3
Output: 4
Explanation: The subarray [1, -1, 5, -2] sums to 3 and is the longest.

#endif

int maxSubArrayLen(vector< int >& nums, int k) {
    
    int sum = 0 , res = 0 ;
    
    unordered_map < int , int > m;
    
    for ( int i = 0 ; i < nums.size(); ++ i) {
       
        sum += nums[i];
        
        if (sum == k)
            res = i + 1 ;
        else  if (m.count(sum - k))
            res = max(res, i - m[sum - k]);
        
        if (!m.count(sum))
            m[sum] = i;
    }
    
    return res;
}



int main(int argc, const char * argv[]) {
    // insert code here...
  
    
    std::cout << "Hello, World!\n";
    return 0;
}
