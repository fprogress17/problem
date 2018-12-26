//
//
// @..*
//
//   ..
//  @..
//

#include "stdc++.h"


using namespace std;

int numDecodings(string s) {
    if (s.empty() || (s.size() > 1 && s[0] == '0' )) return  0 ;
    
    vector <int> dp(s.size() + 1 , 0 );
    
    dp[0] = 1 ;
    
    for ( int i = 1 ; i < dp.size(); ++ i) {
        
        dp[i] = (s[i-1] == '0' ) ? 0 : dp[i-1];
        
        if (i > 1 && (s[i-2] == '1' || (s[i-2] == '2' && s[ -1] <= '6' ))) {
            dp[i] += dp[i-2];
        }
    }
    
    return dp.back();
}

//int f(string digits){
//
//    
//    if(digits.length() == 0)
//        return 1;
//
//    string s1 = digits.substr(0,1);
//    if(s1[0] > '0' && s1[0] < '7'){
//        count += f(digits.substr(1));
//    }
//
//    string s2 = digits.substr(0,2);
//    if( s2[0] == '1' || (s2[0] == '2' && s2[1] < '7' )){
//        count += f(digits.substr(2));
//    }
//
//    return count;
//}

int main(int argc, const char * argv[]) {
    // insert code here...
  
    
    std::cout << "Hello, World!\n";
    return 0;
}
