//
//
// @..*
//
//   ..
//  @..
//

#include "stdc++.h"


using namespace std;

 // devide two intergers

int divide(int dividend, int divisor){
    if(divisor == 0)
        return INT_MAX;
    
    if(dividend == INT_MIN && divisor == -1)
        return INT_MAX;
    
    if(divisor == 1)
        return dividend;
    
    bool sign = (dividend > 0 && divisor > 0 ) ||
    (dividend < 0 && divisor < 0 );
    
    long long dEnd = abs((long long) dividend);
    long long dSor = (abs(long long) divisor);
    long long res = 0;
    
    while(dEnd >= dSor){
        
        long long tmpDsor = dSor;
        long long cnt = 1;
        
        while(dEnd >= (tmpDsor << 1) ){
            
            tmpDsor = tmpDsor << 1;
            cnt = cnt << 1;
            
        }
        
        res += cnt;
        dEnd -= tmpDsor;
        
    }
    
    return sign ? res : -res;
    
    
    
}



int main(int argc, const char * argv[]) {
    // insert code here...
  
    
    std::cout << "Hello, World!\n";
    return 0;
}
