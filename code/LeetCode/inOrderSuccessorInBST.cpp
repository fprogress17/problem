//
//
// @..*
//
//   ..
//  @..
//

#include "stdc++.h"


//In Binary Search Tree, Inorder Successor of an input node can also be defined as
//the node with the smallest key greater than the key of input node.
//So, it is sometimes important to find next node in sorted order.

using namespace std;

// in-order traversal
TreeNode * inorderSuccessor(TreeNode* root, TreeNode* p) {
    
    stack <TreeNode*> s;
    
    bool b = false ;
    TreeNode *t = root;
    
    while (t || ! s.empty()) {
    
        while (t) {
            s.push(t);
            t = t-> left;
        }
        
        t = s.top(); s.pop();
        
        if (b) return t;
        
        if (t == p) b = true ;
        
        t = t-> right;
    }
    
    return NULL;
}


TreeNode *pre = NULL, *suc = NULL;

TreeNode * inorderSuccessor(TreeNode* root, TreeNode* p) {
    if (!p) return NULL;
    inorder(root, p);
    return suc;
}

void inorder(TreeNode *root, TreeNode * p) {
 
    if (!root) return ;
    
    inorder(root -> left, p);
    
    if (pre == p) suc = root;
    pre = root;
    
    inorder(root -> right, p);
}




int main(int argc, const char * argv[]) {
    // insert code here...
  
    
    std::cout << "Hello, World!\n";
    return 0;
}
