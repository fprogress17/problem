//
//
// @..*
//
//  Created    on 9/11/18.
//  @..
//

#include "stdc++.h"


using namespace std;

struct node{
    int val;
    node* next;
    node(int v):val(val), next(nullptr){};
};

node* removeDuplicatedfromSorteListII(node* head)
        {
            node* prev = new node(0);
            node *curr = head;
            prev->next = head;

            while(curr && curr->next){

                bool dup = false;

                if(curr->val == curr->next->val){

                    while(curr->val == curr->next->val){
                        node *tmp = curr;
                        curr->next = curr->next->next;
                        delete(tmp) ;
                        dup = true;
                    }
                }

                if(dup){
                    prev->next = curr->next;
                    delete(curr);
                }

                prev= curr;
                curr = curr->next;

            }

            return prev;

        };


int main(int argc, const char * argv[]) {
    // insert code here...
    
    
    std::cout << "Hello, World!\n";
    return 0;
}

