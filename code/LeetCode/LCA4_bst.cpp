//
//
// @..*
//
//  Created by Choonghun Lee on 9/11/18.
//  @..
//

#include "stdc++.h"


using namespace std;

// C++ Program for Lowest Common Ancestor in a Binary Tree
// A O(n) solution to find LCA of two given values n1 and n2
#include <iostream>
#include <vector>

using namespace std;

struct node
{
    int data;
    struct node* left, *right;
};

TreeNode *lca(TreeNode* root, int n1, int n2){
    
    if (root == NULL) return NULL;
    
    if (root->val > n1 && root->val > n2)
        return lca(root->left, n1, n2);
    
    if (root->val < n1 && root->val < n2)
        return lca(root->right, n1, n2);
    
    return root;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    
    return lca(root, p->val, q->val) ;
}



/* Function to find LCA of n1 and n2. The function assumes that both
 n1 and n2 are present in BST */
struct node *lca_iterative(struct node* root, int n1, int n2)
{
    while (root != NULL)
    {
        // If both n1 and n2 are smaller than root, then LCA lies in left
        if (root->data > n1 && root->data > n2)
            root = root->left;
        
        // If both n1 and n2 are greater than root, then LCA lies in right
        else if (root->data < n1 && root->data < n2)
            root = root->right;
        
        else break;
    }
    return root;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    
    
    std::cout << "Hello, World!\n";
    return 0;
}
