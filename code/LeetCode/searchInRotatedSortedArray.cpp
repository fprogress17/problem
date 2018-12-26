//
//
// @..*
//
//  Created    on 9/11/18.
//  @..
//

#include "stdc++.h"


using namespace std;



int search(vector<int>& nums, int target) {

    int lo = 0; int hi = (int)nums.size()-1;

    if(lo > hi)
        return -1;

   while(lo<=hi){

    int mid = (lo+hi)/2;

    if(nums[mid] == target){
        return mid;
    }

    if(nums[lo] <= nums[mid]){

        if(nums[lo] <= target && target <nums[mid]) {
            hi = mid - 1;
        }
        else{
            lo = mid + 1;
        }

    }else{
        if(nums[mid] < target && target <= nums[hi])
            lo = mid + 1;
        else
            hi = mid -1;

    }

   }

   return -1;
}

    
    
int search2(vector<int>& nums, int target) {
    if(nums.size() ==0)
        return -1;

    int lo = 0; int hi = (int)nums.size()-1;

    if(lo == hi){
        
        if(nums[lo] == target)
            return lo;
        return -1;
        
    }
    
    if(nums[lo] <= nums[hi]){
        
        while(lo <= hi){
            
            int mid = (lo+hi)/2;
            
            if(nums[mid] == target)
                return mid;
            
            if(  nums[mid] < target ){
                
                lo = mid + 1  ;
                
            }else{
                hi = mid - 1 ;
            }
            
        }
        
        return -1;

        
        
    }
    
    
    while(lo < hi){

       int mid = (lo+hi)/2;

       if(nums[mid] == target)
           return mid;

       if(nums[lo] < nums[mid]){

           lo = mid  ;

       }else{
           hi = mid ;
       }

    }

    return -1;

}


//int binarySearchInRotatedArray(int arr[], int lo, int hi, int target)
int binarySearchInRotatedArray(vector<int> arr, int lo, int hi, int target)
{
    
    while (lo <= hi )
    {
        int mid = lo + (hi - lo)/2;
        
        // If the element is present at the middle itself
        if (arr[mid] == target)
            return mid;
        
        if (arr[mid] > target){
            if(arr[lo] <= arr[mid] && arr[lo] <= target) {
                hi = mid - 1;
            }else {
                lo = mid + 1;
            }
        }else {
            if(arr[mid] <= arr[hi] && target <= arr[hi] ) {
                lo = mid + 1;
            }else {
                hi = mid - 1;
            }
        }
        
    }
    
    
    return -1;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    //vector<int> nums = {4,5,6,7,0,1,2};
   //vector<int> nums = {1};
   //  vector<int> nums = {1,3};
    // vector<int> nums = {3,1}; //1
    vector<int> nums = {4,5,6,7,8,1,2,3};//    8
 
    
    int r = binarySearchInRotatedArray(nums, 0,7,8);
    
    
   // int ret = search(nums, 0);
    int ret = search(nums, 1);


    std::cout << "Hello, World!\n";
    return 0;
}
