//
//
// @..*
//
//   ..
//  @..
//

#include "stdc++.h"
// four sum II foursum2

using namespace std;

//  compute how many tuples (i, j, k, l) there are such that A[i] + B[j] + C[k] + D[l] is zero.

int fourSumCount(vector< int >& A, vector< int >& B, vector< int >& C, vector< int >& D) {
    
    int res = 0 ;
    unordered_map < int , int > m;
    
    for ( int i = 0 ; i < A.size(); ++ i) {
        for ( int j = 0 ; j < B.size(); ++ j) {
            ++ m[A[i] + B[j]];
        }
    }
    
    for ( int i = 0 ; i < C.size(); ++ i) {
        for ( int j = 0 ; j < D.size(); ++ j) {
            int target = - 1 * (C[i ] + D[j]);
            res += m[target];
        }
    }
    
    return res;
}



int main(int argc, const char * argv[]) {
    // insert code here...
  
    
    std::cout << "Hello, World!\n";
    return 0;
}
