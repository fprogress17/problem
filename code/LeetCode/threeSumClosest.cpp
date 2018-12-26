//
//
// @..*
//
//  Created by Choonghun Lee on 9/11/18.
//  @..
//

#include <iostream>
#include <vector>

using namespace std;

int threeSumClosest(vector<int>& nums, int target) {
    
    int closest = nums[ 0 ] + nums[ 1 ] + nums[ 2 ];
    int diff = abs(closest - target);
    
    sort(nums.begin(), nums.end()); // this sort is necessary
    
    
    for ( int i = 0 ; i < nums.size() - 2 ; ++ i) {
    
        int left = i + 1 , right = nums.size() - 1 ;
        
        while (left < right) {
            int sum = nums [i] + nums[left] + nums[right];
            int newDiff = abs(sum - target);
            if (diff > newDiff) {
                diff = newDiff;
                closest = sum;
            }
            if (sum < target) ++ left;
            else -- right;
        }
    }
    
    return closest;
}



// the below is not correct

int threeSumClosest(vector<int> a, int target){

    if(a.size()<3) return INT_MAX;
    
    int res = INT_MAX;
    int mDiff = INT_MIN;
    int left = 0;
    int right = a.size()-1;

    for(int i=0;i<a.size()-2;++i){
            left = i+1;

            while(left<right){

                if(a[i] + a[left] + a[right] <= target ){
                    int diff = abs(target - (a[i] + a[left] + a[right]));
                    ++left;
                    
                    if(mDiff > diff){
                    
                        mDiff = diff;
                        res = a[i] + a[left] + a[right] ;
                    }
                    
                    
                }else{
                    int diff = abs(target - (a[i] + a[left] + a[right]));
                    if(mDiff > diff){
                        
                        mDiff = diff;
                        res = a[i] + a[left] + a[right] ;
                    }
                    
                    
                    
                    --right;
                }

            }
    }

    return res;

}


int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> a = {0,0,0};
    int r = threeSumClosest(a,0);
    std::cout << "Hello, World!\n";
    return 0;
}


