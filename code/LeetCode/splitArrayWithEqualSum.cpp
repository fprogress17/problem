//
//
// @..*
//
//   ..
//  @..
//

#include "stdc++.h"

#if 0

not sure how this results in true in leet

Input
[1,2,1,3,0,0,2,2,1,3,3]
Output
false
Expected
true
#endif


using namespace std;

vector<int> num ;

bool check(int inx, int cnt, int sum){
    
    if(cnt == 0){
        int lsum = accumulate(num.begin() + inx, num.end(),0);
        if(accumulate(num.begin() + inx, num.end(), 0) == sum)
            return true;
        return false;
    }
    
    if(inx == num.size() -1 && cnt != 0){
        return false;
    }
    
    bool ret = false;
    
   // for(int i = inx ; i < num.size()-1; ++i){
        int i = 0;
        int lSum = 0;
        for(int j = 0;i+j < num.size()-1; ++j){
            lSum +=num[i+j];
            if(lSum == sum)
                ret |= check(i+j+2, cnt-1, sum);
        }
   // }
    
    return ret;
    
}



bool splitArray(vector<int>& nums) {
    
    if(nums.size() < 7)
        return false;
    
    num = nums;
    
    int cnt  = 3;
     bool ret = false;
  //  for(int i = 0 ; i < nums.size()-1; ++i){
    int i = 0;
        int lSum = 0;
        for(int j = 0;i+j < nums.size()-1; ++j){
            lSum +=nums[i+j];
            
                ret |= check(i+j+2, cnt-1, lSum);
        }
    //}
    
    return ret;
    
}




int main(int argc, const char * argv[]) {
    // insert code here...
  
   // vector<int> nums = {1,2,1,2,1,2,1};
   // vector<int> nums = {1,2,1,2,1,2,1,2};
    vector<int> nums = { 1,2,1,3,0,0,2,2,1,3,3};
    bool ret = splitArray(nums);
    
    std::cout << "Hello, World!\n";
    return 0;
}
