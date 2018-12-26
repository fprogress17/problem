//
//
// @..*
//
//  Created by Choonghun Lee on 9/11/18.
//  @..
//

#include "stdc++.h"


using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *partition(ListNode *head, int x) {
    ListNode dummy1(0), dummy2(0);
    ListNode* p1 = &dummy1;
    ListNode* p2 = &dummy2;
    
    ListNode* p = head;
    while(p) {
        if(p->val < x) {
            p1->next = p;
            p1 = p1->next;
        } else {
            p2->next = p;
            p2 = p2->next;
        }
        p = p->next;
    }
    
    p2->next = NULL;
    p1->next = dummy2.next;
    return dummy1.next;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    
    std::cout << "Hello, World!\n";
    return 0;
}


ListNode *reverseBetween(ListNode *head, int m, int n) {
    if(m<1 || m>=n || !head) return head;
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    head = dummy;
    
    // move head to (m-1)th node
    for(int i=0; i<m-1; i++)
        head = head->next;
    
    // reverse list from pre with length n-m+1
    ListNode *pre = head->next, *cur = pre->next;
    for(int i=0; i<n-m; i++) {
        ListNode *temp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = temp;
    }
    
    head->next->next = cur;
    head->next = pre;
    head = dummy->next;
    delete dummy;
    return head;
    }
