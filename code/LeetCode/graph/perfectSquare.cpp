//
//
// @..*
//
//  Created by Choonghun Lee on 9/11/18.
//  @..
//

#include "stdc++.h"


using namespace std;


int numSquares( int n) {
    
    vector < int > dp(n + 1 , INT_MAX);
    
    dp[ 0 ] = 0 ;
    
    for ( int i = 0 ; i <= n; ++ i) {
        for ( int j = 1 ; i + j * j <= n; ++ j) {
            
            dp[i + j * j] = min(  dp[i + j * j],  dp[i] + 1 );
        
        }
    }
    
    return dp.back();
}







bool isPerfect(int n){

   int s = (int)sqrt(n);

   return n == s*s;


}


bool perfect(int n, int &depth){

   int s = (int)sqrt(n);

    for(int i = s; i>0; --i){
        
        
       int r = n - i*i;

        if (r == 0)
        {

            return true;
        }

       if(isPerfect(r)){
           
           depth++;
           return true;
       }else{
           depth++;
           return perfect(r ,depth );
       }

    }
        return false;
}


int numSquares(int n) {

    int depth = 0;

    if(perfect(n,depth)){
        return depth;
    }

    return -1;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    
    int ret =  numSquares(12);
    
    std::cout << "Hello, World!\n";
    return 0;
}
