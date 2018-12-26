//
//
// @..*
//
//  Created    on 9/11/18.
//  @..
//

#include "stdc++.h"


using namespace std;


int partition(vector<int>&num,int lo, int hi){

    if(lo>hi)
        return -1;
    
    
    int mid = (lo+hi)/2;

    int t = num[mid];

    int j=lo -1;
    int i = lo;
    int k = hi+1;

   // for(;i<=hi;++i)
    while(i<k)
    {

        if(num[i] < t){
            ++j;
            swap(num[i], num[j]);
            ++i;

        }else if(num[i]== t){
            ++i;

        }else if(num[i] > t){
            --k;
            swap(num[i], num[k]);
        }

    }

    return j+1;

}


int findKth(vector<int>&nums, int lo, int hi, int k)
{

    int m =partition(nums, lo, hi);

    int Lth = hi -m + 1;//hi-lo+1 -m;

    if( Lth == k){
        return nums[m];
    }

    if(Lth > k)
        return findKth(nums, m+1, hi, k );

    else
        return findKth(nums, lo, m-1, k - Lth);


}



int findKthLargest(vector<int>& nums, int k) {

    int ret = findKth(nums,0, nums.size()-1, k);

    return ret;
}


int main(int argc, const char * argv[]) {
    // insert code here...
//   vector<int> nums =  {3,2,1,5,6,4};
//
//   int ret = findKthLargest(nums, 2);
    
    
    vector<int> nums =  {3,2,3,1,2,4,5,5,6};
    
    int ret = findKthLargest(nums, 4);

    
      
    
   
    std::cout << "Hello, World!\n";
    return 0;
}
