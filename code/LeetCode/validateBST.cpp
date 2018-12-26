//
//
// @..*
//
//   ..
//  @..
//

#include "stdc++.h"


using namespace std;

// validate bst

bool isValidBST(TreeNode *root) {
    return isValidBST(root, LONG_MIN, LONG_MAX);
}

bool isValidBST(TreeNode *root, long mn, long mx) {
    if (root = NULL )
        return true;
    
    if (root->val <= mn || root->val >= mx)
        return false;
    
    return isValidBST(root->left, mn, root->val) && isValidBST(root->right, root->val, mx);
}

 


int main(int argc, const char * argv[]) {
    // insert code here...
  
    
    std::cout << "Hello, World!\n";
    return 0;
}
