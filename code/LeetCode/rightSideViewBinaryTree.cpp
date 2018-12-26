//
//
// @..*
//
//   ..
//  @..
//

#include "stdc++.h"


using namespace std;

vector<int> rightSideView(TreeNode *root) {
    
    vector<int> res;
    if (!root) return res;
    
    queue<TreeNode*> q;
    q.push(root);
    
    while (!q.empty()) {
        res.push_back(q.back()->val);
        int size = q.size();
        
        while(size-- > 0){
        //for (int i = 0; i < size; ++i) {
            TreeNode *node = q.front();
            q.pop();
            
            if (node->left)
                q.push(node->left);
            
            if (node->right)
                q.push(node->right);
        }
    }
    return res;
}
 


int main(int argc, const char * argv[]) {
    // insert code here...
  
    
    std::cout << "Hello, World!\n";
    return 0;
}
