//
//
// @..*
//
//  Created    on 9/11/18.
//  @..
//

#include "stdc++.h"


using namespace std;


// A recursive binary search function. It returns
// location of x in given array arr[l..r] is present,
// otherwise -1
int binarySearch(int arr[], int lo, int hi, int target)
{
    if (lo <= hi )
    {
        int mid = lo + (hi - lo)/2;
        
        // If the element is present at the middle
        // itself
        if (arr[mid] == target)
            return mid;
        
        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (arr[mid] > target)
            return binarySearch(arr, lo, mid-1, target);
        
        // Else the element can only be present
        // in right subarray
        return binarySearch(arr, mid+1, hi, target);
    }
    
    // We reach here when element is not
    // present in array
    return -1;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    
    
    std::cout << "Hello, World!\n";
    return 0;
}


