//
//
// @..*
//
//   ..
//  @..
//

#include "stdc++.h"


using namespace std;

void rotate(vector< int >& nums, int k) {

    if (nums.empty() || (k %= nums.size()) == 0 )
        return ;
    
    int n = nums.size (), start = 0;
    int i = 0 , cur = nums[i], cnt = 0 ;
    
    while (cnt++ < n) {
        
        i = (i + k) % n;
        int t = nums[i];
        
        nums[i] = cur;
        
        if (i == start) {
            ++start;
            ++ i;
            cur = nums[i];
        } else {
            cur = t;
        }
    }
}



int main(int argc, const char * argv[]) {
    // insert code here...
  
    
    std::cout << "Hello, World!\n";
    return 0;
}
