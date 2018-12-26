//
//
// @..*
//
//   ..
//  @..
//

#include "stdc++.h"


using namespace std;
// findFirstLastElementSortedArray
//Find First and Last Position of Element in Sorted Array
//Input: nums = [5,7,7,8,8,10], target = 8
//Output: [3,4]


int findFirstOccurrence(vector<int> arr, int x)
{
    // search space is arr[low..high]
    int low = 0, high = arr.size() - 1;
    
    // initialize the result by -1
    int result = -1;
    
    // iterate till search space contains at-least one element
    while (low <= high)
    {
        int mid = (low + high)/2;
        
        
        if (x == arr[mid])
        {
            result = mid;
            high = mid - 1;
        }
        
        else if (x < arr[mid])
            high = mid - 1;
        
        
        else
            low = mid + 1;
    }
    
    
    return result;
}



int findLastOccurrence(vector<int> arr, int x)
{
    
    int low = 0, high = arr.size() - 1;
    
    
    int result = -1;
    
   
    while (low <= high)
    {
     
        int mid = (low + high)/2;
        
       
        if (x == arr[mid])
        {
            result = mid;
            low = mid + 1;
        }
        
        
        else if (x < arr[mid])
            high = mid - 1;
        
       
        else
            low = mid + 1;
    }
    
   
    return result;
}

// main function
int main(void)
{
    int A[] = {2, 5, 5, 5, 6, 6, 8, 9, 9, 9};
    int n = sizeof(A)/sizeof(A[0]);
    
    int target = 5;
    
    int index = findLastOccurrence(A, n, target);
    
    if (index != -1)
        printf("First occurrence of element %d is found at index %d",
               target, index);
    else
        printf("Element not found in the array");
    
    return 0;
}


// main function
int main(void)
{
    int arr[] = {2, 5, 5, 5, 6, 6, 8, 9, 9, 9};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    int target = 5;
    
    int index = findFirstOccurrence(arr, n, target);
    
    if (index != -1)
        printf("First occurrence of element %d is found at index %d",
               target, index);
    else
        printf("Element not found in the array");
    
    return 0;
}



int main(int argc, const char * argv[]) {
    // insert code here...
  
    
    std::cout << "Hello, World!\n";
    return 0;
}
