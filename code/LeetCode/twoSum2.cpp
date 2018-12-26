//
//
// @..*
//
//   ..
//  @..
//

#include "stdc++.h"


using namespace std;

// sorted input array : so two pointer is possible,

vector<int> twoSum(vector<int>& numbers, int target) {
   
    int l = 0, r = numbers.size() - 1;
    
    while (l < r) {
        int sum = numbers[l] + numbers[r];
    
        if (sum == target)
            return {l + 1, r + 1};
        else if (sum < target)
            ++l;
        else --r;
    }
    
    return {};
}



int main(int argc, const char * argv[]) {
    // insert code here...
  
    
    std::cout << "Hello, World!\n";
    return 0;
}
