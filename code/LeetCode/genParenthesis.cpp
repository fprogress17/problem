//
//  main.cpp
// @..*
//
//  Created    on 9/8/18.
//  @..
//

#include <iostream>
using namespace std;


void gen(int open, int close,   string paren){
    
    if(open > close)
        return;
    
    
    if(open == 0 && close == 0)
    {
        for (int i=0; i< paren.size();++i){
            cout << paren[i]  ;
        }
        
        cout << endl;
        
        return;
    }
    
    
    if(open>0){
        gen(open - 1, close+1, paren+"(") ;
    }
    
    if(close>0){
         gen(open , close-1, paren+ ")") ;
    }
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    string s;
    gen(3,0,s );
    std::cout << "Hello, World!\n";
    return 0;
}

