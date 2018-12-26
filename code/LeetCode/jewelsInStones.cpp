//
//
// @..*
//
//   ..
//  @..
//

#include "stdc++.h"


using namespace std;

 
int numJewelsInStones(string J, string S) {
 
    int res = 0;
    
    for (char s : S) {
    
        for (char j : J) {
        
            if (s == j) {
                ++res;
                break;
            }
        }
    }
    return res;
}


int main(int argc, const char * argv[]) {
    // insert code here...
  
    
    std::cout << "Hello, World!\n";
    return 0;
}
