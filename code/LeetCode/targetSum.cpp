//
//
// @..*
//
//  Created    on 9/11/18.
//  @..
//

#include "stdc++.h"


using namespace std;

int findTargetSum(vector<int>& nums, int count,  int S);



int findTargetSumWays(vector<int>& nums, int S) {

    if(nums.size() == 0)
        return 0;

    
    int tCount  =  findTargetSum(nums, 0, S);

    return tCount;

}




int findTargetSum(vector<int>& nums, int count,  int S) {

    if(count == nums.size()-1){

        if(S == 0){
            return 1;
        }

        return 0;
    }

   int a = findTargetSum( nums, count + 1, S + nums[count]);
    int b = findTargetSum( nums, count + 1, S - nums[count]);

    return (a+b);

}

    int main(int argc, const char * argv[]) {
    // insert code here...
    
        vector<int> nums = {1, 1, 1, 1, 1};
        int S = 3;
        
       int ret = findTargetSumWays(nums, 3);
        
    std::cout << "Hello, World!\n";
    return 0;
}
