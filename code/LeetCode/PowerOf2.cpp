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
 
1 2 4 8 16 ....

1 10 100 1000 10000 ....

Then we can easily see that the number of powers of 2 is only one,
and the rest are all 0, so our problem-solving ideas will be there.
We only need to judge whether the lowest bit is 1 and then shift to the right.
Finally, the number of statistics 1 can be judged whether it is the power of 2, the code is as follows:

#endif

bool isPowerOfTwo( int n) {
    
    int cnt = 0 ;
    
    while (n > 0 ) {
        cnt += (n & 1 );
        n >>= 1 ;
    }
    
    return cnt == 1 ;
}


int main(int argc, const char * argv[]) {
    // insert code here...
  
    
    std::cout << "Hello, World!\n";
    return 0;
}
