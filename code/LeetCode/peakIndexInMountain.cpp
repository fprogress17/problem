//
//
// @..*
//
//   ..
//  @..
//

#include "stdc++.h"


using namespace std;

#if 0
Given an array that is definitely a mountain,
return any i such that A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... > A[A.length - 1].

#endif
 
int peakIndexInMountainArray(vector<int>& A) {
    
    int l = 0;
    int r = A.size() -1;
    
    while (l < r) {    /// not l <= r
    
        int m = l + (r - l) / 2;
        
        if (A[m] > A[m + 1])
            r = m;
        else
            l = m + 1;
    }
    return l;
}


int peakIndexInMountainArray(vector<int>& A) {
    for (int i = 1; i < A.size(); ++i)
        if (A[i] < A[i - 1])
            return i - 1;
}


int main(int argc, const char * argv[]) {
    // insert code here...
  
    
    std::cout << "Hello, World!\n";
    return 0;
}
