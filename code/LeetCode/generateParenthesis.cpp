//
//
// @..*
//
//   ..
//  @..
//

#include "stdc++.h"


using namespace std;

vector<string> res;

void generate(int n, int m , string s){
    
    if(n > m)
        return;
    
    if(n==0 && m == 0){
        //cout << s << endl;
        res.push_back(s);
        return;
    }
    
    if(n>0) generate(n-1, m , s+"(");
    if(m>0) generate(n, m-1 , s+")");
}


vector<string> generateParenthesis(int n) {
    string str = "";
    int a = n;
    int b= n;
    generate(a,b, str);
    
    return res;
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
  
    
    std::cout << "Hello, World!\n";
    return 0;
}
