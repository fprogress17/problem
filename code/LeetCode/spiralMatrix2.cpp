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
Given a positive integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

Example:

Input: 3
Output:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
 ]

#endif

 
vector <vector< int >> generateMatrix( int n) {
    
    vector <vector< int >> res(n, vector< int >(n, 0 ));
    
    int up = 0 , down = n - 1 , left = 0 , right = n - 1 , val = 1 ;
    
    while ( true ){
        
        for ( int j = left; j <= right; ++j)
            res[up][j] = val++ ;
        if (++up > down) break ;
        
        for ( int i = up; i <= down; ++i)
            res[i][right] = val++ ;
        if(--right < left) break ;
        
        for ( int j = right; j >= left; --j)
            res[down][j] = val++ ;
        if (--down < up) break ;
        
        for ( int i = down; i >= up; --i)
            res[i][left] = val++ ;
        if (++left > right) break ;
    }
           return res;
 }


int main(int argc, const char * argv[]) {
    // insert code here...
  
    
    std::cout << "Hello, World!\n";
    return 0;
}
