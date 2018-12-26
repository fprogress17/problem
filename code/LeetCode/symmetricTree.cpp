//
//
// @..*
//
//   ..
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


bool isSymmetric ( TreeNode *left,TreeNode  *right) {
   
    if(!left && !right )
        return  true ;
    
    
    if( (!left && right) || (left && !right))
        return false ;
       
    if(left->val != right->val)  
      return false ;
    
    return isSymmetric(left->left, right->right) && isSymmetric(left->right, right-> left);
}


bool isSymmetric(TreeNode * root) {
    if (!root)
        return  true ;
    
    return isSymmetric(root->left, root-> right);
}



int main(int argc, const char * argv[]) {
    // insert code here...
  
    
    std::cout << "Hello, World!\n";
    return 0;
}
