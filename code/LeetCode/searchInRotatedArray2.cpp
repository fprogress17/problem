//
//
// @..*
//
//   ..
//  @..
//

#include "stdc++.h"


using namespace std;
// search rotated with repeated values
// Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

//(i.e., [0,0,1,2,2,5,6] might become [2,5,6,0,0,1,2]).


#if 0

if the middle number is smaller than the rightmost number, the right half is ordered,
and if the middle number is greater than the rightmost number, the left half It is orderly .
And if there are duplicate values, there will be two cases, [3 1 1] and [1 1 3 1].
For the two cases, the intermediate value is equal to the rightmost value,
and the target value 3 can be on the left side. Can be on the right, what should I do?
For this case, the processing is very simple.
Just left the rightmost value to the left to continue the loop.

#endif

bool search(vector<int>& nums, int target) {
    
    int n = nums.size();
    
    if (n == 0 )
        return  false ;
    
    int left = 0 , right = n - 1 ;
    
    while (left <= right) {
        
        int mid = (left + right) / 2 ;
        
        if (nums[mid] == target)
            return  true ;
        else  if (nums[mid] < nums[right]) {
            if(nums[mid] < target &&nums[right] >= target)
                left = mid + 1 ;
            else
                right = mid - 1 ;
        } else  if (nums[mid] > nums[right]){
            if (nums[left] <= target && nums[mid] > target)
                right = mid - 1 ;
            else
                left = mid + 1 ;
        } else
            -- right;
    }
    
    return  false ;
}


int main(int argc, const char * argv[]) {
    // insert code here...
  
    
    std::cout << "Hello, World!\n";
    return 0;
}
