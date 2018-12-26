//
//
// @..*
//
//  Created    on 9/11/18.
//  @..
//

#include "stdc++.h"


using namespace std;



#include <iostream>
#include <vector>
using namespace std;

///////sol 1

bool isPalindrome(ListNode* head) {
    
    if (!head || !head->next)
        return  true ;
    
    ListNode *slow = head, *fast = head;
    stack < int > s;
    
    s.push(head -> val);
    
    while (fast->next && fast->next-> next) {
        slow = slow-> next;
        fast = fast->next-> next;
        s.push(slow -> val);
    }
    
    if (fast->next == NULL) s.pop();
    
    while (slow-> next) {
        slow = slow-> next;
        
        int tmp = s.top(); s.pop();
        
        if (tmp != slow->val)
            return  false ;
    }
    
    return  true ;
}










/////////////////sol 2
// Data Structure to store a linked list node
struct Node {
    int data;
    Node* next;
};

// Helper function to print given linked list
void printList(Node* head)
{
    Node* ptr = head;
    while (ptr)
    {
        cout << ptr->data << " -> ";
        ptr = ptr->next;
    }
    
    cout << "null\n";
}

// Helper function to insert a new node in the beginning of the linked list
void push(Node* &head, int data)
{
    Node* node = new Node();
    node->data = data;
    node->next = head;
    
    head = node;
}

// Iterative function to reverse nodes of linked list
void reverse(Node* &head)
{
    Node* result = nullptr;
    Node* current = head;
    
    // Iterate through the list and move/insert each node to the
    // front of the result list (like a push of the node)
    while (current != nullptr)
    {
        // tricky: note the next node
        Node* next = current->next;
        
        // move the current node onto the result
        current->next = result;
        result = current;
        
        // process next node
        current = next;
    }
    
    // fix head pointer
    head = result;
}

// Recursive function to check if two linked lists are equal or not
bool compare(Node* a, Node* b)
{
    // see if both list is empty
    if (a == nullptr && b == nullptr)
        return true;
    
    return a && b && (a->data == b->data) && compare(a->next, b->next);
}

// Function to split the linked list into two equal parts and return
// pointer to the second half
Node* findMiddle(Node* head, bool &odd)
{
    Node* prev = nullptr;
    Node *slow = head, *fast = head;
    
    // find middle pointer
    while (fast && fast->next)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    
    // for odd nodes, fast still points to last node
    if (fast)
        odd = true;
    
    // make next of prev node null
    prev->next = nullptr;
    
    // return mid node
    return slow;
}

// Function to check if linked list is palindrome or not
bool checkPalindrome(Node* head)
{
    // base case
    if (head == nullptr)
        return true;
    
    // flag to indicate if number of nodes in the linked list is
    // odd or not. It will be passed by reference to findMiddle()
    bool odd = false;
    
    // find second half of linked list
    Node* mid = findMiddle(head, odd);
    
    // if number of nodes is odd, advance mid
    if (odd)
        mid = mid->next;
    
    // reverse the second half
    reverse(mid);
    
    // compare first and second half
    return compare(head, mid);
}

int main(int argc, const char * argv[]) {
   
    // input keys
    vector<int> keys = { 1, 2, 3, 2, 1};
    
    Node* head = nullptr;
    for (int i = keys.size() - 1; i >= 0; i--)
        push(head, keys[i]);
    
    if (checkPalindrome(head))
        cout << "Linked list is Palindrome";
    else
        cout << "Linked list is not Palindrome";
    
    std::cout << "Hello, World!\n";
    return 0;
}
