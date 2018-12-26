//
//
// @..*
//
//  Created by Choonghun Lee on 9/11/18.
//  @..
//

#include "stdc++.h"


using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


int mValue = 0;

int height(TreeNode* root){

    if(root == NULL )
    {
        return 0;
    }

    int left = height(root->left);
    int right = height(root->right);

    mValue = max( mValue, left+right);

    return max(left, right ) + 1;


}

int diameterOfBinaryTree(TreeNode* root) {

    if(root == NULL )
        return 0;

    height(root);

    return mValue;

}


int main(int argc, const char * argv[]) {
    // insert code here...
    
    
    std::cout << "Hello, World!\n";
    return 0;
}
