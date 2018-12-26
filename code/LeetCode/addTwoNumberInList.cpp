//
//
// @..*
//
//   ..
//  @..
//

#include "stdc++.h"


using namespace std;

#if 0

    Input:     (2 -> 4 -> 3)
             + (5 -> 6 -> 4)
    Output:     7 -> 0 -> 8
    Explanation: 342 + 465 = 807.

#endif

ListNode *addTwoNumbers(ListNode *l1, ListNode * l2) {
    
    ListNode *res = new ListNode(- 1 );
    ListNode *curr = res;
    
    int carry = 0 ;
    
    while (l1 || l2) {
        
        int n1 = l1 ? l1->val : 0 ;
        int n2 = l2 ? l2->val : 0 ;
        
        int sum = n1 + n2 + carry;
        
        carry = sum / 10 ;
        curr -> next = new ListNode (sum % 10 );
        curr = curr-> next;
        
        if (l1) l1 = l1-> next;
        if (l2) l2 = l2-> next;
    }
    
    if (carry)
        cur->next = new ListNode( 1 );
    
    return res-> next;
    


int main(int argc, const char * argv[]) {
    // insert code here...
  
    
    std::cout << "Hello, World!\n";
    return 0;
}
