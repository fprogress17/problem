//
//
// @..*
//
//  Created    on 9/11/18.
//  @..
//

#include <iostream>
#include <vector>

using namespace std;

 int divide(int dividend, int divisor) {
    
    if (-1 == divisor && INT_MIN == dividend)
        return INT_MAX;
    
    if (0 == divisor)
        return INT_MAX;
    
    bool sign = (dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0);
    
    if (dividend == divisor)
        return 1;
    
    if (abs(divisor) == 1)
        return divisor == 1 ? dividend : -dividend;
    
    if (abs(divisor) == 2)
        return divisor == 2 ? dividend >> 1 : -(dividend >> 1);
    
    if (0 == dividend)
        return 0;
    
    if (INT_MIN == divisor)
        return 0;
    
    
    dividend = abs(dividend);
    divisor  = abs(divisor);
    
    int q = 0;
    int substract = 0;
    int bitToSet = 0;
    int endValue = 0;
    
    while (dividend >= divisor) {
        
        substract = divisor;
        bitToSet = 1;
        endValue = (dividend >> 1);
        
        while (endValue >= substract) {
            substract <<= 1;
            bitToSet  <<= 1;
        }
        
        q |= bitToSet;
        dividend -= substract;
    }
    return sign ? q : -q;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    
    
    std::cout << "Hello, World!\n";
    return 0;
}


