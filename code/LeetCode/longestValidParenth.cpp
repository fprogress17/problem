//
//
// @..*
//
//  Created    on 9/11/18.
//  @..
//

#include "stdc++.h"


using namespace std;


int longestValidParentheses(string s) {
    int n = s.size();
    int len = 0;
    int tmp = 0;
    
    stack<int> stk;
    
    for (int i = 0; i < n; ++i) {
        if ('(' == s[i])
            stk.push(i);
        else {
                if (!stk.empty() && '(' == s[stk.top()]) {
                    stk.pop();
                    tmp = i - (stk.empty() ? -1 : stk.top());
                    len = max(len, tmp);
                }
                else {
                    stk.push(i);
                }
            }
    }
    return len;
}


int longestValidParenthesis(string s){
    
    int index = 0;
    int len = s.length();
    
    int count = 0;
    
    stack<char> stak;
    
    while(index < len){
        
        if(stak.empty()){
            
            if(s[index] == ')'){
                
            }else if(s[index] == '('){
                stak.push(s[index]);
            }
            
        } else{
            
            
            if(s[index] == ')'){
                stak.pop();
                ++count;
            }else if( s[index] == '('){
                stak.push(s[index]);
            }
            
            
            
        }
        
        ++index;
    }
    
    return count;
    
}

int main(void){
    // Your code here!
    
    cout<< longestValidParenthesis("((()(()())") << endl;
    return 0;
}
