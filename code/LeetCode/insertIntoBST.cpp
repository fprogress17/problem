//
//
// @..*
//
//   ..
//  @..
//

#include "stdc++.h"


using namespace std;


TreeNode * insertIntoBST(TreeNode* root, int val) {
    
    if (root == NULL)
        return new TreeNode(val);
    
    if (root->val > val)
        root->left = insertIntoBST(root-> left, val);
    
    else root ->right = insertIntoBST(root-> right, val);
    
    return root;
}

int main(int argc, const char * argv[]) {
    // insert code here...
  
    
    std::cout << "Hello, World!\n";
    return 0;
}
