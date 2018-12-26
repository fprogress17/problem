//
//
// @..*
//
//   ..
//  @..
//

#include "stdc++.h"


using namespace std;

void flatten(TreeNode * root) {
    
    if (!root)
        return ;
    
    if (root->left)
        flatten(root->left);
    
    if (root->right)
        flatten(root->right);
    
    TreeNode *tmp = root-> right;
    root ->right = root-> left;
    root ->left = NULL;
    
    while (root->right)
        root = root-> right;
    
    root ->right = tmp;
}



int main(int argc, const char * argv[]) {
    // insert code here...
  
    
    std::cout << "Hello, World!\n";
    return 0;
}
