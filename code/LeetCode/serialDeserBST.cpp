//
//
// @..*
//
//  Created by Choonghun Lee on 9/11/18.
//  @..
//

#include "stdc++.h"


using namespace std;

   struct TreeNode{
    int val;
    TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

// use the string to store the more than 2 digit number
// use '.' to separate the number in the string
//
   void serial(TreeNode *root, list<string>& lis){

       if(root == NULL)
       {
           lis.push_back("#");
           return;
       }

       lis.push_back(to_string( root->val) );

       serial(root->left, lis);
       serial(root->right,lis);

   }


   TreeNode* deserial(list<string>& lis){

      string c = lis.front(); lis.pop_front();

      if(c == "#"){
          return NULL;
      }

      TreeNode *n = new TreeNode( stoi(c));

      TreeNode *l = deserial(lis);
      TreeNode *r = deserial(lis);

      n->left = l;
      n->right = r;

      return n;

   }



    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {

       list<string> lis;
        string res;

       serial(root, lis);

       list<string>::iterator it = lis.begin();

       for(; it != lis.end(); ++it){

           res +=   *it + ".";
       }


        return res;

    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {

        list<string> lis;

        int index = 0;
        while (index < data.size()){
        string s;
        for (int i = index; i < data.size(); ++i) {
            char c = data[i];

            if (c != '.') {
                s += c;
            } else {
                lis.push_back(s);
                index = i + 1;
                break;
              
            }
        }
    }


      TreeNode *res = deserial(lis);

      return res;

    }
    


int main(int argc, const char * argv[]) {
    // insert code here...
    
    TreeNode *n1 = new TreeNode(1);
    TreeNode *n2 =  new TreeNode(2);
    TreeNode *n3 =  new TreeNode(3);
    TreeNode *n4 =  new TreeNode(4);
    TreeNode *n5 =  new TreeNode(500);


    n1->left = n2;
    n1->right = n3;
    n3->left = n4;
    n3->right = n5;

    string str = serialize(n1);

    TreeNode *res = deserialize(str);
    
    
    std::cout << "Hello, World!\n";
    return 0;
}
