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

bool isSame(TreeNode *a, TreeNode *b){

   if(a== NULL && b == NULL)
       return true;

   if(!( a!= NULL &&  b!= NULL)){

      return false;
   }

  bool l = isSame(a->left, b->left) ;
  bool r = isSame(a->right, b->right) ;

  return (l && r);

}

bool isSubtree(TreeNode* s, TreeNode* t) {

    if(s == NULL && t == NLLL)
        return true;

    if(s == NULL && t != NULL )
        return false;


    if(s != NULL && t == NULL )
        return true;


    if(s->val == t->val){
        bool res = isSame(s, t);
        return res;
    }


    bool l = isSubtree(s->left , t);
    bool r = isSubtree(s->right, t);

    return (l||r);

}


int main(int argc, const char * argv[]) {
    // insert code here...
    
    
    std::cout << "Hello, World!\n";
    return 0;
}
