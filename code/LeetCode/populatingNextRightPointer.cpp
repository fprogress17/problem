//
//
// @..*
//
//   ..
//  @..
//

#include "stdc++.h"


using namespace std;


// Populating Next Right Pointers in Each Node

void connect(TreeLinkNode *root) {
    
    if (!root) return;
    
    if (root->left)
        root->left->next = root->right;
    
    if (root->right)
        root->right->next = root->next? root->next->left : NULL;
    
    connect(root->left);
    connect(root->right);
}


int main(int argc, const char * argv[]) {
    // insert code here...
  
    
    std::cout << "Hello, World!\n";
    return 0;
}
