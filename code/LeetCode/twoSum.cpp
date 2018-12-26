//
//
// @..*
//
//  Created by Choonghun Lee on 9/11/18.
//  @..
//

#include "stdc++.h"


using namespace std;

bool hasArrayTwoCandidates(int A[], int arr_size, int sum)
{
    int l, r;
    
    /* Sort the elements */
    quickSort(A, 0, arr_size-1);
    
    /* Now look for the two candidates in the sorted
     array*/
    l = 0;
    r = arr_size-1;
    while (l < r)
    {
        if(A[l] + A[r] == sum)
            return 1;
        else if(A[l] + A[r] < sum)
            l++;
        else // A[i] + A[j] > sum
            r--;
    }
    return 0;
}


// this is unsorted array
// so have to sort first to use two pointer like above

vector < int > twoSum(vector< int >& nums, int target) {
    
    unordered_map < int , int > m;
    
    for ( int i = 0 ; i < nums.size(); ++ i) {
    
        if (m.count(target - nums[i]) != 0) {
            return {i, m[target - nums[i]]};
        }
        
        m[nums[i]] = i;
    }
    
    return {};
}



int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cout << "Hello, World!\n";
    return 0;
}
