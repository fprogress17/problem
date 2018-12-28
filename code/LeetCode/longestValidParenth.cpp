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
    
    int longestValidParentheses(string s) {
        
        stack<pair<int,int>> stk;   // first: index, second: 0:'(', 1:')'
        int maxLen = 0, curLen = 0;
        
        for(int i=0; i<s.size(); i++) {
        
            if(s[i]=='(')   // left parenthesis
                stk.push(make_pair(i,0));
            else {          // right parenthesis
                if(stk.empty() || stk.top().second == 1 )
                    stk.push(make_pair(i,1));
                else {
                    stk.pop ();
                    if(stk.empty())
                        curLen = i + 1 ;
                    else
                        curLen = i - stk.top().first;
                    maxLen = max(maxLen, curLen);
                }
            }
        }
        return maxLen;
    }
    
}

int main(void){
    // Your code here!
    
    cout<< longestValidParenthesis("((()(()())") << endl;
    return 0;
}
