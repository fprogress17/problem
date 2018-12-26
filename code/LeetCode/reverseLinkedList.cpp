//
//
// @..*
//
//   ..
//  @..
//

#include "stdc++.h"


using namespace std;

// reverse linked list

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};



ListNode *reverseList(ListNode *head){
    
    if(!head) return head;
    
    ListNode *pre = NULL;
    ListNode *curr = head;
    
    while(current){      // if current is null, exit, so pre is head
        
        ListNode *next = curr->next;
        curr->next = pre;
        pre = curr;
        curr = next;
        
    }
    
    // at this point , curr is NULL
    //head = pre;
    
    
    return pre;
    
}

ListNode *reverseListRec(ListNode *head){
    
    if(head == NULL)
        return NULL ; // this is error checking
       
    if(head->next == NULL)   // this is bottom condition of this recursive
        return head;
    
    ListNode *next = head->next;
    head->next = NULL;
    
    ListNode *rest = reverseListRec(next); // rest is the head of this list, which is retured from bottom condition.
    next->next = head; // current head from call
    
    return rest;
    
    
}


ListNode *reverseListRange(ListNode *head, ListNode *before){
    /// reverse from head before "before"
    
    
    if(!head) return head;
    
    ListNode *pre = NULL;
    ListNode *curr = head;
    
    while(current != before ){
        
        ListNode *next = curr->next;
        curr->next = pre;
        pre = curr;
        curr = next;
        
    }
    
    // at this point , curr is NULL
    //head = pre;
    
    
    return pre;
    
}





//// the following ..hard to understand
ListNode * reverseList(ListNode* head) {

    if (!head) return head;

    ListNode *dummy = new ListNode(- 1 );
    dummy ->next = head;
    ListNode *cur = head;
   
    while (cur-> next) {
        ListNode *tmp = cur-> next;
        cur->next = tmp-> next;
        tmp ->next = dummy->next;
        dummy->next = tmp;
    }
    
    return dummy->next;
}





int main(int argc, const char * argv[]) {
    // insert code here...
  
    
    std::cout << "Hello, World!\n";
    return 0;
}
