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
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n,
find the one that is missing from the array.

Example 1:

Input: [3,0,1]
Output: 2
#endif

int missingNumber(vector< int >& nums) {
    
    int sum = 0 , n = nums.size();
    
    for (auto &a : nums) {
        sum += a;
    }
    
    return  n*(n + 1)/2 - sum;
}


int main(int argc, const char * argv[]) {
    // insert code here...
  
    
    std::cout << "Hello, World!\n";
    return 0;
}
