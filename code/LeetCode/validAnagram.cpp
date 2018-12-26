//
//
// @..*
//
//   ..
//  @..
//

#include "stdc++.h"


using namespace std;

bool isAnagram( string s, string t) {
    
    if (s.size() != t.size())
        return  false ;
    
    int m[ 26 ] = { 0 };
    for ( int i = 0 ; i < s.size(); ++i)
        ++m[s[i] - 'a'];
    
    for ( int i = 0 ; i < t.size(); ++ i) {
        if (-- m[t[i] - 'a' ] <0 )
            return  false ;
    }
    
    return  true ;
}



int main(int argc, const char * argv[]) {
    // insert code here...
  
    
    std::cout << "Hello, World!\n";
    return 0;
}
