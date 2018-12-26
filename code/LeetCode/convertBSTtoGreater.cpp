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


void traverse(TreeNode*root,  vector<int>& ele)
{
    if(root== NULL)
        return;
    
    ele.push_back(root->val);
    
    traverse(root->left, ele);
    traverse(root->right, ele);
    
    
}

int getSumGreaterThanMe(const vector<int>& vec, int me){

    int sum = 0;

    for(int i = 0; i<vec.size(); ++i){

        if(vec[i] > me){

            sum += vec[i];
        }

    }

    return sum;

}

void convert(TreeNode *root, const vector<int>& ele){

    if(root == NULL )
        return ;

    int g = getSumGreaterThanMe(ele, root->val);
   if( g > root->val){

       root->val += g;

   }

   convert(root->left, ele);
   convert(root->right, ele);

}

TreeNode* convertBST(TreeNode* root) {
    
   if(root == NULL )
       return NULL;

   vector<int> element;

    traverse(root,element);

    convert(root, element);
    
    return root;
}




int main(int argc, const char * argv[]) {
    // insert code here...
    
    
    std::cout << "Hello, World!\n";
    return 0;
}
