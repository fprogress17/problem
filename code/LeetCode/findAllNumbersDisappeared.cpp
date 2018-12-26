//
//
// @..*
//
//  Created by Choonghun Lee on 9/11/18.
//  @..
//

#include "stdc++.h"


using namespace std;

//Find all the elements of [1, n] inclusive that do not appear in this array.

vector<int> findDisappearedNumbers(vector<int>& nums) {

    vector<int>res ;
    
    if(nums.size() == 0)
        return res;
    

    for(int i=0; i< nums.size(); ++i){

        int index = i;

        while( nums[index] != index+1 ){

            if(nums[index] != nums[nums[index] - 1] ){

                swap(nums[index], nums[nums[index] - 1]);
            }else{
                break;
            }

        }

    }


    for(int i=0; i< nums.size(); ++i){

        if( nums[i] != i+1 ) {

             res.push_back(i+1);

        }
    }
    
       return res;
}





int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> nums = {4,3,2,7,8,2,3,1};
    
    vector<int> res = findDisappearedNumbers(nums);
    
    std::cout << "Hello, World!\n";
    return 0;
}
