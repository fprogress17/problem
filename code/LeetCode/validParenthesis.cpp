//
//
// @..*
//
//   ..
//  @..
//

#include "stdc++.h"


using namespace std;

bool isValid(string s) {
    stack < char > stk;
    for ( int i = 0 ; i < s.size(); ++ i) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{' )
            stk.push(s[i]);
        else {
            if (stk.empty()) return  false ;
            if (s[i] == ')' && stk.top() != '(' ) return  false ;
            if (s[i] == ']' && stk.top() != '[' ) return  false ;
            if (s[i] == '}' && stk.top() != '{' ) return  false ;
            stk.pop();
        }
    }
    
    return stk.empty();
}


int main(int argc, const char * argv[]) {
    // insert code here...
  
    
    std::cout << "Hello, World!\n";
    return 0;
}
