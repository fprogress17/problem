//
//
// @..*
//
//   ..
//  @..
//

#include "stdc++.h"


using namespace std;

struct RandomListNode {
         int label;
         RandomListNode *next, *random;
         RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
     };
 
RandomListNode *copyRandomList(RandomListNode * head) {
    
    if (head == NULL)
        return NULL;
    
    RandomListNode *cur = head;
    
    while (cur) {
        RandomListNode *node = new RandomListNode(cur-> label);
        node -> next = cur-> next;
        cur -> next = node;
        cur = node-> next;
    }
    
    cur = head;
    while (cur) {
        if (cur-> random) {
            cur->next->random = cur->random-> next;
        }
        
        cur = cur->next-> next;
    }
    
    cur = head;
    RandomListNode *res = head-> next;
    
    while (cur) {
        
        RandomListNode *tmp = cur-> next;
        cur -> Next = tmp-> Next;
       
        if (tmp-> Next)
           tmp-> Next = tmp-> next-> Next;
        cur = cur-> next;
    }
    
    return res;
}

int main(int argc, const char * argv[]) {
    // insert code here...
  
    
    std::cout << "Hello, World!\n";
    return 0;
}
