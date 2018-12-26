//
//
// @..*
//
//   ..
//  @..
//

#include "stdc++.h"

//evaluateReversePolishNotation

using namespace std;

int evalRPN(vector<string>& tokens) {
    
    stack<int> s;
    
    for (auto a : tokens) {
        
        if (a == "+" || a == "-" || a == "*" || a == "/") {
        
            if (s.size() < 2)
                break;
            
            int t = s.top(); s.pop();
            int k = s.top(); s.pop();
            
            if (a == "+")
                k += t;
            else if (a == "-")
                k -= t;
            else if (a == "*")
                k *= t;
            else if (a == "/")
                k /= t;
            
            s.push(k);
            
        } else {
            
            s.push(stoi(a));
        
        }
    }
    
    return s.top();
}



int main(int argc, const char * argv[]) {
    // insert code here...
  
    
    std::cout << "Hello, World!\n";
    return 0;
}
