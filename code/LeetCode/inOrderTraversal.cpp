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

vector<int> inOrderTraversal(TreeNode *root){
    
    vector<int> result;
    stack<TreeNode*> s;
    TreeNode *p = root;
    
    while(!s.empty() || p != NULL ){
        
        if(p != NULL){
            s.push(p);
            p=p->left;
        }else{
            p = s.top();
            s.pop();
            result.push_back(p->val);
            p= p->right;
        }
    }
    
    return result;
    
}
 


int main(int argc, const char * argv[]) {
    // insert code here...
  
    
    std::cout << "Hello, World!\n";
    return 0;
}
