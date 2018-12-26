//
//
// @..*
//
//   ..
//  @..
//

#include "stdc++.h"


using namespace std;

 

bool isSameTree(TreeNode *p, TreeNode * q) {
    if (!p && !q)
        return  true ;
    
    if ((p && !q) || (!p && q) || (p->val != q->val))
        return  false ;
    
    return isSameTree(p->left, q->left) && isSameTree(p->right, q-> right);
}

int main(int argc, const char * argv[]) {
    // insert code here...
  
    
    std::cout << "Hello, World!\n";
    return 0;
}
