//
//
// @..*
//
//  Created    on 9/11/18.
//  @..
//

#include "stdc++.h"


using namespace std;

double myPow(double x, int n) {
    if(n == 0)
        return 1.0;
    
    if(n==1)
        return x;
    
    if(n==-1)
        return 1/x;


    if(n % 2 == 0){
        return myPow(x, n/2) * myPow(x, n/2);
    }
    
    if(n<0)
       return myPow(x, n/2) * myPow(x, n/2) * 1/x;
    
    return myPow(x, n/2) * myPow(x, n/2) * x;
}

//// processing time reduced to half

double myPow2(double x, int n) {
    if(n == 0)
        return 1.0;
    
    if(n==1)
        return x;
    
    if(n==-1)
        return 1/x;
    
    double half =  myPow(x, n/2);
    
    if(n % 2 == 0){
        return half * half;
    }
    
    if(n<0)
        return half * half * 1/x;
    
    return half * half * x;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    
    //double res = myPow(2.0,10);
    
    //double res = myPow(34.00515, -3);
     double res = myPow( 0.00001, 2147483647);
   
    
    cout<< res << endl;
    std::cout << "Hello, World!\n";
    return 0;
}
