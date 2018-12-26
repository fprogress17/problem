//
//
// @..*
//
//   ..
//  @..
//

#include "stdc++.h"


using namespace std;

 
ListNode *getIntersectionNode(ListNode *headA, ListNode * headB) {
    
    if (!headA || !headB)
        return NULL;
    
    int lenA = getLength(headA);
    int lenB = getLength(headB);
    
    if (lenA < lenB) {
        for ( int i = 0 ; i < lenB - lenA; ++i)
            headB = headB-> next;
    } else {
        for ( int i = 0 ; i < lenA - lenB; ++i)
            headA = headA-> next;
    }
   
    while (headA && headB && headA != headB) {
        headA = headA-> next;
        headB = headB-> next;
    }
    
    return (headA && headB) ? headA : NULL;
}

int getLength(ListNode* head) {
 
    int cnt = 0 ;
    
    while (head) {
        ++ cnt;
        head = head-> next;
    }
    
    return cnt;
}


int main(int argc, const char * argv[]) {
    // insert code here...
  
    
    std::cout << "Hello, World!\n";
    return 0;
}
