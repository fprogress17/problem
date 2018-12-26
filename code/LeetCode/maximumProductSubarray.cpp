//
//
// @..*
//
//  Created by Choonghun Lee on 9/11/18.
//  @..
//

#include "stdc++.h"


using namespace std;

//maximum Product Subarray

#if 0

Given an integer array nums,
find the contiguous subarray within an array
(containing at least one number) which has the largest product.

Example 1:
Input: [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.

Example 2:
Input: [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
#endif


int maxProduct(vector<int>& nums) {
    
    int res = nums[0], n = nums.size();
    
    vector <int> maxA(n, 0 );
    vector<int> minA(n, 0 );
    
    maxA[0] = nums[0];
    minA[0] = nums[0];
    
    for ( int i = 1 ; i < n; ++ i) {
    
        maxA[i] = max( max( maxA[i - 1] * nums[i], minA[i - 1 ] * nums[i] ), nums[i]);
        minA[i] = min( min(maxA[i - 1 ] * nums[i], minA[i - 1 ] * nums[i] ), nums[i]);
        
        res = max(res, maxA[i]);
    }
    
    return res;
}


int main(int argc, const char * argv[]) {
    // insert code here...
  
    
    std::cout << "Hello, World!\n";
    return 0;
}
