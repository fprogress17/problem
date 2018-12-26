//
//
// @..*
//
//   ..
//  @..
//

#include "stdc++.h"


using namespace std;

bool hasCycle(ListNode *head) {
    
    ListNode *slow = head, *fast = head;
    
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        
        if (slow == fast)
            return true;
    }
    
    return false;
}



int main(int argc, const char * argv[]) {
    // insert code here...
  
    
    std::cout << "Hello, World!\n";
    return 0;
}
