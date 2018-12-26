//
//
// @..*
//
//   ..
//  @..
//

#include "stdc++.h"


using namespace std;

 
vector<vector<int>> generate(int numRows) {
    
    vector<vector<int>> res(numRows, vector<int>());
    
    for (int i = 0; i < numRows; ++i) {
    
        res[i].resize(i + 1, 1);
        for (int j = 1; j < i; ++j) {
            res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
        }
    }
    return res;

}


int main(int argc, const char * argv[]) {
    // insert code here...
  
    
    std::cout << "Hello, World!\n";
    return 0;
}
