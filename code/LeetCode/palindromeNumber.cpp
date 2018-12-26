//
//
// @..*
//
//  Created by Choonghun Lee on 9/11/18.
//  @..
//

#include <iostream>
#include <vector>

using namespace std;


bool isPalindrome0(int x){
    if(x<0) return false;
    
    int p = x;
 
    while( p > 0){
        
        while(p>10){
            p=p/10;
        }
    
    if(p != x%10)
        return false;
    
    p=x/10;
    }
    
    return true;
}


bool isPalindrome(int x){
    
    if(x<0) return false;
    
    int d = 1;
    
    while(x/d >= 10)
    {
        d*=10;
    }

    while(x>0){
        int q = x/d;
        int r = x%10;
        
        if(q!=r) return false;
        
        x = x % (d);
        x= x / 10;
        
        d=d/100; // removed first digit & last digit( two digits were removed)
    }

    return true;
    
}


int main(int argc, const char * argv[]) {
    // insert code here...
    
    isPalindrome(54345);
    std::cout << "Hello, World!\n";
    return 0;
}


