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

stack<TreeNode*> stk;

void BSTIterator(TreeNode *root) {

  while(root != NULL ){

      stk.push(root);
      root = root->left;
  }
}

/** @return whether we have a next smallest number */
bool hasNext() {

        return !stk.empty();
}

/** @return the next smallest number */
int next() {

  TreeNode *n = stk.top();
    stk.pop();

  int res = n->val;

  if(n->right){
      n = n->right;

      while(n != NULL){

          stk.push(n);
          n = n->left;

      }

  }

  return res;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    
    
    std::cout << "Hello, World!\n";
    return 0;
}
