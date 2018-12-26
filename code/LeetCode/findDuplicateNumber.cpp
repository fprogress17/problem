//
//
// @..*
//
//  Created by Choonghun Lee on 9/11/18.
//  @..
//

#include "stdc++.h"


using namespace std;

int findDuplicate(vector<int>& nums) {

   int minV = INT_MAX;
   int maxV = INT_MIN;

   for(int i=0;i<nums.size(); ++i){

       int v = nums[i];

       minV = min(minV, v);
       maxV = max(maxV, v);

   }

    int j=minV;
    
   for( int i = minV + 1; i<= maxV; ++i){

       j = j ^ i;

   }

    for(int i=0;i<nums.size(); ++i){

       int v = nums[i];

        j = j ^ v;

   }

   return j;
}


vector<int> nums = {1,3,4,2,2};

int main(int argc, const char * argv[]) {
    // insert code here...
    

   int ret = findDuplicate(nums) ;
   
    std::cout << "Hello, World!\n";
    return 0;
}
