//
//
// @..*
//
//   ..
//  @..
//

#include "stdc++.h"


using namespace std;

 /// find all palindrom

vector <vector< string >> partition( string s) {
    vector <vector< string >> res;
    vector < string > out ;
    
    partitionDFS(s, 0 , out , res);
    
    return res;
}

void partitionDFS( string s, int start, vector< string > & out , vector<vector< string >> & res) {
    
    if (start == s.size()) {
        res.push_back( out );
        return ;
    }
  
    for( int i = start; i < s.size(); ++ i) {
        if (isPalindrome(s, start, i)) {
            
            out.push_back(s.substr(start, i - start + 1 ));
            partitionDFS(s, i + 1 , out , res);
            out.pop_back();
        
        }
    }
}

bool isPalindrome ( string s, int start, int end) {
    
      while (start < end) {
        if ( s[start] != s[end])
            return false ;
        
          ++start;
          --end;
    }
    
    return  true ;
}


int main(int argc, const char * argv[]) {
    // insert code here...
  
    
    std::cout << "Hello, World!\n";
    return 0;
}
