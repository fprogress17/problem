//
//
// @..*
//
//  Created by Choonghun Lee on 9/11/18.
//  @..
//

#include "stdc++.h"


using namespace std;

bool isUnique(int n){

    vector<bool> uni(10, false);

    while(n >0){


        if( uni[n%10] == false){

            uni[n%10] = true;
            n = n/10;
        }else{
            return false;
        }


    }

    return true;

}

vector<int> dp(12,0);
vector<int> s(12,0);
void f(){

    dp[1] = 10;
    dp[2] = 9*9;

    for(int i = 3; i< 11;++i){

        dp[i] = dp[i-1]* (8-i+3);

    }


    for(int i =0;i < 11;++i){

        s[i] += s[i-1] + dp[i];
    }

}


int countNumbersWithUniqueDigits(int n) {

  f();

  return s[n];

}


int countNumbersWithUniqueDigits2(int n) {


    int count = 0;

    for(int i= 0;i< pow(10,n);++i){

        if(isUnique(i)){
           ++count;
        }
    }

   return count;
}



int main(int argc, const char * argv[]) {
    // insert code here...
   //int ret = countNumbersWithUniqueDigits(2);
    
    int ret = countNumbersWithUniqueDigits(1);
    std::cout << "Hello, World!\n";
    return 0;
}
