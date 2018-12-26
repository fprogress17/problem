//
//
// @..*
//
//  Created by Choonghun Lee on 9/11/18.
//  @..
//

#include "stdc++.h"


using namespace std;

int n;
int m;
string digits;
string price;

static int num = 0;

void generate(string price, vector<bool> taken){

    if(price.size() == n)
    {
        cout << price << " " << num++ <<  endl;
        return;
    }

    for(int i=0;i <n ;++i){
        if(taken[i] == false){
            
          //  if( i>0  && digits[i-1] == digits[i])
          //      continue;
            
          //  if(i == 0 || digits[i-1] != digits[i] || taken[i-1] == true ){
            
           // if(i > 0 && (digits[i-1] == digits[i]) && (taken[i-1] == false )){

            if( i > 0 && digits[i-1] == digits[i] && taken[i-1] == false)
                continue;

            
                taken[i] = true;
                generate(price + digits[i], taken);
                taken[i] = false;
            //}
        }
    }
}



int main(int argc, const char * argv[]) {
    // insert code here...

    vector<bool> taken(15,false);
    
    digits = "1234";
    digits = "1224";
    
    n= digits.size();
    
   generate(price, taken);
   
    std::cout << "Hello, World!\n";
    return 0;
}
