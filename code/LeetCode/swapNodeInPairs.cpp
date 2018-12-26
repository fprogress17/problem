//
//
// @..*
//
//   ..
//  @..
//

#include "stdc++.h"


using namespace std;

 

ListNode* swapPairs(ListNode* head) {
    
    ListNode *dummy = new ListNode(-1);
    ListNode*pre = dummy;
    dummy->next = head;
    
    while (pre->next && pre->next->next) {
        
        ListNode *t = pre->next->next;
        pre->next->next = t->next;
        t->next = pre->next;
        pre->next = t;
        pre = t->next;
    
    }
    
    return dummy->next;
}

int main(int argc, const char * argv[]) {
    // insert code here...
  
    
    std::cout << "Hello, World!\n";
    return 0;
}
