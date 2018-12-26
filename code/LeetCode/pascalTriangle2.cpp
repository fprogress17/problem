//
//
// @..*
//
//   ..
//  @..
//

#include "stdc++.h"


using namespace std;

vector < int > getRow( int rowIndex) {
    
    vector < int > res(rowIndex + 1 );
    
    res[ 0 ] = 1 ;
    
    for ( int i = 1 ; i <= rowIndex; ++ i) {
        for ( int j = i; j >= 1 ; -- j) {
            res[j] += res[j - 1 ];
        }
    }
    
    return res;
}



int main(int argc, const char * argv[]) {
    // insert code here...
  
    
    std::cout << "Hello, World!\n";
    return 0;
}
