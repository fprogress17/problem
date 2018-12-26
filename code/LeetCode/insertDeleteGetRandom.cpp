//
//
// @..*
//
//   ..
//  @..
//

#include "stdc++.h"


using namespace std;


vector<int> nums;
unordered_map<int, int> m;

bool insert(int val) {
    
    if (m.count(val))
        return false;
    
    nums.push_back(val);
    
    m[val] = nums.size() - 1;
    
    return true;
}

bool remove(int val) {

    if (!m.count(val))
        return false;
    
    int last = nums.back();
    m[last] = m[val];
    
    nums[m[val]] = last;
    
    nums.pop_back();
    
    m.erase(val);
    
    return true;
}

int getRandom() {
    return nums[rand() % nums.size()];
}


int main(int argc, const char * argv[]) {
    // insert code here...
  
    
    std::cout << "Hello, World!\n";
    return 0;
}
