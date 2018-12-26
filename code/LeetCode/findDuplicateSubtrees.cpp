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

vector<TreeNode*> v;
vector<TreeNode*> res;

 void toVector(TreeNode *root){


     if(root == NULL)
         return ;

     v.push_back(root);

     if(root->left)
         toVector(root->left);

     if(root->right)
         toVector(root->right);

 }

bool isSame(TreeNode *a, TreeNode *b)
{

    if(a == NULL & b == NULL)
        return true;

    if((a != NULL && b== NULL) || (a == NULL && b!= NULL))
        return false;

     if(a->val != b->val)
         return false;

     bool l = isSame(a->left, b->left);
     bool r = isSame(a->right, b->right);


     if(l && r){
        res.push_back(a) ;
         return true;
     }

     return false;
}

vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {

   toVector(root) ;

   for(int i = 0;i< v.size(); ++i)
       for(int j = i+1;j< v.size(); ++j)
       {
         TreeNode *a = v[i]   ;
         TreeNode *b = v[j]   ;

         isSame(a, b) ;
       }

}

    
int main(int argc, const char * argv[]) {
    // insert code here...




    std::cout << "Hello, World!\n";
    return 0;
}
