//
//
// @..*
//
//   ..
//  @..
//

#include "stdc++.h"


using namespace std;

int longestConsective(vector<int>& nums){
    
    unordered_set<int> s(nums.begin(), nums.end());
    
    int res = 0;
    
    for(int val : nums){
        
        int count = 1;
        int pre = val -1;
        int next = val + 1;
        
        while(s.count(pre)){
            s.erase(pre);
            pre--;
            count++;
        }
        
        while(s.count(next)){
            s.erase(next);
            next++;
            count++;
        }
        
        res = max(res, count);
    }
    
    return res;
    
    
}



int main(int argc, const char * argv[]) {
    // insert code here...
  
    
    std::cout << "Hello, World!\n";
    return 0;
}
