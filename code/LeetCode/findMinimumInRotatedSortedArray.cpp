//
//
// @..*
//
//  Created by Choonghun Lee on 9/11/18.
//  @..
//

#include "stdc++.h"


using namespace std;

int findMin(vector<int>& nums) {

  int lo = 0; int hi = (int)nums.size()-1;

  while(lo < hi - 1){

      int mid = (lo+hi)/2;

      if(nums[lo] < nums[mid] && nums[mid] < nums[hi])
          return nums[lo];
      
      if(nums[lo] < nums[mid]){

          lo = mid;

      }else{
          hi = mid;
      }

  }

  return min(nums[lo], nums[hi]);

    
    
}



int main(int argc, const char * argv[]) {
    // insert code here...

    //vector<int> nums =  { 4,5,6,7,0,1,2};
   // vector<int> nums =  {3,4,5,1,2};
    //vector<int> nums =  {1,2};
    vector<int> nums =  {1,2,3};
    
    int ret = findMin(nums);
    
    
    std::cout << "Hello, World!\n";
    return 0;
}
