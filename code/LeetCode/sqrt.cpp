//
//
// @..*
//
//  Created    on 9/11/18.
//  @..
//

#include "stdc++.h"


using namespace std;

int mySqrt(int x) {

   double lo = 0; double hi = (double)x;

   while(lo<hi){

      double mid = (lo+hi)/2;

       if( fabs(mid*mid - double(x)) < 10e-7){

           return (int)mid;

       }

       if(mid*mid  < (double)x){

          lo = mid;
       }else{
           hi = mid;
       }


   }

   return -1;
}

int main(int argc, const char * argv[]) {
    // insert code here...

    int ret = mySqrt(8);
     
    
    std::cout << "Hello, World!\n";
    return 0;
}
