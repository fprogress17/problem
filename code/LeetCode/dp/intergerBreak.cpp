//
//
// @..*
//
//  Created    on 9/11/18.
//  @..
//

#include "stdc++.h"


using namespace std;

int breakInt(int n);

int integerBreak(int n) {


   return breakInt(n) ;


}


int breakInt(int n){

    if(n == 2){
        return 2;
    }

    if(n == 1){
        return 0;
    }
    

    

    int res = 1;

    for(int i =2; i<= n/2;++i){


       if(n - i >= 0){


            res = max(res, breakInt( n - i));
       }

       res = res *i;

    }


    return res;

}


int main(int argc, const char * argv[]) {
    // insert code here...

   int ret =  integerBreak(10);

    std::cout << "Hello, World!\n";
    return 0;
}
