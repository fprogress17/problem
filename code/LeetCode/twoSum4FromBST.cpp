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


bool helper(TreeNode* node, int k, unordered_set< int >& s) {
    
    if (!node)
        return  false ;
    
    if (s.count(k - node->val))
        return  true ;
    
    s.insert(node -> val);
    
    return helper(node->left, k, s) || helper(node-> right, k, s);
}

bool findTarget(TreeNode* root, int k) {
    if (!root)
        return  false ;
    
    unordered_set <int> s;
    
    return helper(root, k, s);
}




int main(int argc, const char * argv[]) {
    // insert code here...
  
    
    std::cout << "Hello, World!\n";
    return 0;
}
