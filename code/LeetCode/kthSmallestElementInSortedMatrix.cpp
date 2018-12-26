//
//
// @..*
//
//   ..
//  @..
//

#include "stdc++.h"

//Kth Smallest Element in a Sorted Matrix
using namespace std;

int search_less_equal(vector<vector< int >>& matrix, int target) {
 
    int n = matrix.size(), i = n - 1 , j = 0 , res = 0 ;
    
    while (i >= 0 && j < n ) {
        
        if (matrix[i][j] <= target) {
            
            res += i + 1 ;     // if it is smaller than the target value,
                               // we move one bit to the right,
                                // and we know that all the above numbers of the current position of the current column are smaller than the target value, then cnt += i+1
            
            ++ j;
        } else {
            
            -- i;
        }
    }
    
    return res;
}


int kthSmallest(vector<vector< int >>& matrix, int k) {
    
    int left = matrix[ 0 ][ 0 ], right = matrix.back().back();
    
    while (left < right ) {
        
        int mid = left + (right - left) / 2 ;
        
        int cnt = search_less_equal(matrix, mid);
        
        if (cnt < k)
            left = mid + 1 ;
        else
            right = mid;
    }
           return left;
}
           




int main(int argc, const char * argv[]) {
    // insert code here...
  
    vector<vector<int>> matrix = {
                  { 1,  5,  9},
                  {10, 11, 13},
                  {12, 13, 15}
              };
    int k = 8;
    
    int res = search_less_equal(matrix, 12);
    
    int ret = kthSmallest(matrix, k);
    
    std::cout << "Hello, World!\n";
    return 0;
}
