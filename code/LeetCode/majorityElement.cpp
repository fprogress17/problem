//
//
// @..*
//
//   ..
//  @..
//

#include "stdc++.h"


using namespace std;

 
int majorityElement(vector<int>& nums) {
    
    int res = 0 ;
    int cnt = 0 ;
    
    for ( int num : nums) {
    
        if (cnt == 0 )
        {
            res = num;
            ++cnt;
            
        }
        else (num == res) ? ++cnt : -- cnt;
    }
    
    return res;
}


int main(int argc, const char * argv[]) {
    // insert code here...
  
    
    std::cout << "Hello, World!\n";
    return 0;
}
