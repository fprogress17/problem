//
//
// @..*
//
//   ..
//  @..
//

#include "stdc++.h"


using namespace std;

// Reverse Linked List II

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};



ListNode *reverseListRange(ListNode *head, ListNode *next)


ListNode *reverseBetween(ListNode *head, int m, int n) {
    
    ListNode *curr = head;
    ListNode *beforeStart = NULL;
    
    for ( int i = 0 ; i < m - 1 ; ++i){
        beforeStart = curr;
        curr = curr-> next;
    }
    
    ListNode *start = curr;
    
    curr = head;
    for ( int i = 0 ; i < n  ; ++i)
        curr = curr-> next;
    
    ListNode *before = curr;
    
    ListNode *newHead = reverseListRange(start,before);
    beforeStart->next = newHead;
    start->next = before;
    
    return head;
    
    
}


int main(int argc, const char * argv[]) {
    // insert code here...
  
    
    std::cout << "Hello, World!\n";
    return 0;
}
