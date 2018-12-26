//
//
// @..*
//
//  Created by Choonghun Lee on 9/11/18.
//  @..
//

#include "stdc++.h"


using namespace std;


struct Node
{
    int data;
    struct Node *left, *right;
};

/* Helper function that allocates a new node with the
 given data and NULL left and right pointers. */
Node *newNode(int data)
{
    Node *new_node = new Node;
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return new_node;
}

/* Given a binary tree, print its nodes in inorder*/
void inorder(Node * node)
{
    if (!node)
        return;
    
    /* first recur on left child */
    inorder(node->left);
    
    /* then print the data of node */
    printf("%d ", node->data);
    
    /* now recur on right child */
    inorder(node->right);
}

/* Function to merge given two binary trees*/
Node *MergeTrees(Node * t1, Node * t2)
{
    if (!t1)
        return t2;

    if (!t2)
        return t1;

    t1->data += t2->data;

    t1->left = MergeTrees(t1->left, t2->left);
    t1->right = MergeTrees(t1->right, t2->right);

    return t1;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    
    std::cout << "Hello, World!\n";
    return 0;
}
