//
//
// @..*
//
//  Created by Choonghun Lee on 9/11/18.
//  @..
//

#include "stdc++.h"


using namespace std;

/// with constant space complexity

vector<int> productExceptSelf(vector<int>& nums) {
    
    int n = nums.size();
    vector<int> res(nums.size(), 1);
    int left = 1;
    
    for(int i=n-2; i>=0; --i){
        
        res[i] = nums[i+1] * res[i+1];
        
    }
    
    for(int i=0; i< n; ++i){
        
        res[i] = res[i] * left;
        left = left*nums[i];
        
    }
    
    return res;
    
}



int main(int argc, const char * argv[]) {
    // insert code here...
    
    
    std::cout << "Hello, World!\n";
    return 0;
}
