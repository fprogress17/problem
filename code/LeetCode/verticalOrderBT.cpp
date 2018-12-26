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



map<int,vector<int>>m;

void check(TreeNode *root, int cnt){

    if(root == NULL)
        return ;

    if(m.count(cnt) == 0){
        vector<int> v ;
        v.push_back(root->val);
        m[cnt] = v;
    }else{
        m[cnt].push_back(root->val);
    }

   if(root->left){
       check(root->left, cnt -1);
   }

   if(root->right){
       check(root->right, cnt +1);
   }

}



    vector<vector<int>> verticalOrder(TreeNode* root) {

    vector<vector<int>> res ;
     
    check(root, 0) ;


    map<int, vector<int>>::iterator it = m.begin();

    for(; it!= m.end(); ++it){

        vector<int> p = it->second;

        res.push_back(it->second) ;


     } 
        return res;
 
    }




int main(int argc, const char * argv[]) {
    // insert code here...

    TreeNode *n3 = new TreeNode(3);
    TreeNode *n9 = new TreeNode(9);
    TreeNode *n20 = new  TreeNode(20);

   n3->left = n9;
   n3->right = n20;

    TreeNode *n15 = new TreeNode(15);
    TreeNode *n7 = new TreeNode(7);

    n20->left = n15;
    n20->right = n7;

     vector<vector<int>> res = verticalOrder(n3);

    std::cout << "Hello, World!\n";
    return 0;
}
