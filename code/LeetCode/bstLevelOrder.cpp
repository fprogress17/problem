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

    vector<vector<int>> levelOrder(TreeNode* root) {

        queue<TreeNode*> q;
        queue<TreeNode*> q2;

        vector<vector<int>> res;

        if(root == NULL)
            return res;

        q.push(root);

        while(!q.empty()) {

            vector<int> v;

            while (!q.empty()) {


                TreeNode *h = q.front();
                q.pop();

                v.push_back(h->val);

                if (h->left)
                    q2.push(h->left);

                if (h->right)
                    q2.push(h->right);


            }

            res.push_back(v);
            q = q2;
            
            while(!q2.empty()){
                q2.pop();
            }
           
        }

       return res;

    }

int main(int argc, const char * argv[]) {
    // insert code here...
    
    TreeNode *n3 = new TreeNode(3);
    TreeNode *n9 =  new TreeNode(9);
    TreeNode *n7 =  new TreeNode(7);
    TreeNode *n15 =  new TreeNode(15);
    TreeNode *n20 =  new TreeNode(20);
    
    
    n3->left = n9;
    n3->right = n20;
    n20->left = n15;
    n20->right = n7;

    vector<vector<int>> res = levelOrder(n3);
    
    std::cout << "Hello, World!\n";
    return 0;
}
