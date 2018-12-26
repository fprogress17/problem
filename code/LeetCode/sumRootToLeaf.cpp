//
//
// @..*
//
//   ..
//  @..
//

#include "stdc++.h"


using namespace std;


int sumNumbers(TreeNode *root) {
    return sumNumbersDFS(root, 0);
}
int sumNumbersDFS(TreeNode *root, int sum) {
    
    if (!root)
        return 0;
    
    sum = sum * 10 + root->val;
    
    if (!root->left && !root->right)
        return sum;
    
    return sumNumbersDFS(root->left, sum) + sumNumbersDFS(root->right, sum);
}

int main(int argc, const char * argv[]) {
    // insert code here...
  
    
    std::cout << "Hello, World!\n";
    return 0;
}
