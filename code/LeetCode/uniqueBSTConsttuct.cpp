//
//
// @..*
//
//  Created    on 9/11/18.
//  @..
//

#include "stdc++.h"


using namespace std;

vector<int> a;

struct node
{
    int key;
    struct node *left, *right;
};

vector<struct node *> constructTrees(int start, int end)
{
    vector<struct node *> list;
    
    /*  if start > end   then subtree will be empty so returning NULL
     in the list */
    if (start > end)
    {
        list.push_back(NULL);
        return list;
    }
    
    /*  iterating through all values from start to end  for constructing\
     left and right subtree recursively  */
    for (int i = start; i <= end; i++)
    {
        /*  constructing left subtree   */
        vector<struct node *> leftSubtree  = constructTrees(start, i - 1);
        
        /*  constructing right subtree  */
        vector<struct node *> rightSubtree = constructTrees(i + 1, end);
        
        /*  now looping through all left and right subtrees and connecting
         them to ith root  below  */
        for (int j = 0; j < leftSubtree.size(); j++)
        {
            struct node* left = leftSubtree[j];
            
            for (int k = 0; k < rightSubtree.size(); k++)
            {
                struct node * right = rightSubtree[k];
                struct node * node = newNode(i);// making value i as root
                node->left = left;              // connect left subtree
                node->right = right;            // connect right subtree
                list.push_back(node);           // add this tree to list
            }
        }
    }
    return list;
}


///// assume that we make the mid as root
///// and call the recursive call for left & right
//// this can be one of the all.

node* opt(int i, int j){
    
    if(i> j)
        return NULL;
    
    if(i==j){
        node *n = new node(a[i]);
        return n;
    }
    
    int mid = (i+j)/2;
    
    node *root = new node(a[mod]);
    
    node *left = opt(i, mid -1);
    node *right = opt(mid+1, j);
    
    root->left = left;
    root->right = right;
    
    return root;
    
}


int main(int argc, const char * argv[]) {
    // insert code here...
    
    
    std::cout << "Hello, World!\n";
    return 0;
}
