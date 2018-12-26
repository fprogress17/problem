//
//
// @..*
//
//  Created by Choonghun Lee on 9/11/18.
//  @..
//

#include "stdc++.h"


using namespace std;


void nextPermutation(vector< int > & nums) {
    
    int i, j, n = nums.size();
    
    for (i = n - 2 ; i >= 0 ; -- i) {
        if (nums [i + 1 ] > nums[i]) {
            
            for (j = n - 1 ; j > i; -- j) {
                if (nums[j] > nums[i]) break ;
            }
    
            swap(nums[i], nums[j]);
            reverse(nums.begin() + i + 1 , nums.end());
            return ;
        }
    }
    reverse(nums.begin(), nums.end());
}


int main(int argc, const char * argv[]) {
    // insert code here...
  
    
    std::cout << "Hello, World!\n";
    return 0;
}
