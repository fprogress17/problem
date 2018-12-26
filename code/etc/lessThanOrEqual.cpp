//
//
// @..*
//
//  Created by Choonghun Lee on 9/11/18.
//  @..
//
// https://www.geeksforgeeks.org/element-1st-array-count-elements-less-equal-2nd-array/
#include "stdc++.h"

#if 0

    Given two unsorted arrays arr1[] and arr2[].
    They may contain duplicates.
    For each element in arr1[],
    count elements less than or equal to it in array arr2[].

#edif

using namespace std;

// function returns the index of largest element
// smaller than equal to 'x' in 'arr'. For duplicates
// it returns the last index of occurrence of required
// element. If no such element exits then it returns -1.
int binary_search(int arr[], int l, int h, int x)
{
    while (l <= h)
    {
        int mid = (l+h) / 2;
        
        // if 'x' is greater than or equal to arr[mid],
        // then search in arr[mid+1...h]
        if (arr[mid] <= x)
            l = mid + 1;
        
        // else search in arr[l...mid-1]
        else
            h = mid - 1;
    }
    
    // required index
    return h;
}

// function to count for each element in 1st array,
// elements less than or equal to it in 2nd array
void countEleLessThanOrEqual(int arr1[], int arr2[],
                             int m, int n)
{
    // sort the 2nd array
    sort(arr2, arr2+n);
    
    // for each element of 1st array
    for (int i=0; i<m; i++)
    {
        // last index of largest element
        // smaller than or equal to x
        int index = binary_search(arr2, 0, n-1, arr1[i]);
        
        // required count for the element arr1[i]
        cout << (index+1) << " ";
    }
} 


int main(int argc, const char * argv[]) {
    // insert code here...
    
    
    std::cout << "Hello, World!\n";
    return 0;
}
