//
//
// @..*
//
//   ..
//  @..
//

#include "stdc++.h"

// Kth Smallest Element in a BST
using namespace std;

int count(TreeNode* node) {
    
    if (!node)
        return  0 ;
    
    return  1 + count(node->left) + count(node-> right);
}

int kthSmallest(TreeNode* root, int k) {
    
    int cnt = count(root-> left);
    
    if (k <= cnt) {
        return kthSmallest(root-> left, k);
    } else  if (k > cnt + 1 ) {
        return kthSmallest(root->right, k - cnt - 1 );
    }
    
    return root-> val;
}




int main(int argc, const char * argv[]) {
    // insert code here...
  
    
    std::cout << "Hello, World!\n";
    return 0;
}
