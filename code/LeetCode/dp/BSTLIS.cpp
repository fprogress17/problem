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




int ret = INT_MIN;

void check(TreeNode *root, int pValue, int cnt, bool isRoot){

    if(root == NULL){

        return;
    }

    if(isRoot){

        ret = max(ret, 1);
        check(root->left, root->val, 1, false);
        check(root->right, root->val, 1, false);
        return;
    }


    if( root-> val == pValue + 1){
        ret = max(ret, cnt+1);

        check(root->left, root->val, cnt+1, false);
        check(root->right, root->val, cnt+1, false);

    }else{

        check(root->left, root->val, 1, false);
        check(root->right, root->val, 1, false);

    }

}




int longestConsecutive(TreeNode* root) {
    check(root,INT_MIN, 0, true);

    if(ret == INT_MIN)
        return 0;

    return ret;
}
    
int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cout << "Hello, World!\n";
    return 0;
}
