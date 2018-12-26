//
//
// @..*
//
//   ..
//  @..
//

#include "stdc++.h"


using namespace std;

// merge k sorted list

struct ListNode {
         int val;
         ListNode *next;
         ListNode(int x) : val(x), next(NULL) {}
     };


vector<ListNode*> lis;

ListNode *mergeList(ListNode*a,ListNode*b){
    
    ListNode *dummyHead = new ListNode(-1);
    ListNode *retHead = dummyHead;
    
    ListNode *aHead = a;
    ListNode *bHead = b;
    
    
    
    while(aHead && bHead){
        
        if(aHead->val > bHead->val){
            
            dummyHead->next = bHead;
            bHead = bHead->next;
            
        }else{
            dummyHead->next = aHead;
            aHead = aHead->next;
        }
        
        dummyHead = dummyHead->next;
    }
    
    while(aHead){
            dummyHead->next = aHead;
    }
    
    while(bHead){
        dummyHead->next = bHead;
    }
    
    return retHead->next;
    
    
}


ListNode* mergeKListsW(int lo, int hi){
    
    if(hi == lo)
        return lis[lo];
    
    if(lo+1 == hi){
        return mergeList(lis[lo], lis[hi]);
    }
    
    if(lo < hi){
        
        int mid = (lo+hi)/2;
        
        ListNode *l = mergeKListsW(lo,mid);
        ListNode *h = mergeKListsW(mid+1,hi);
        
        return mergeList(l,h);
    }
    
    return NULL;
}

ListNode* mergeKLists(vector<ListNode*>& lists) {
 
    lis = lists;
    
    int n = lists.size();
    
    if(n == 0)
        return NULL;
    
    if(n == 1)
        return lists[0];
    
    if(n == 2)
        return mergeList(lists[0],lists[1]);
    
    
    return mergeKListsW(0, n-1);
    
    
    
}

//    ListNode* mergeKLists(vector<ListNode*>& lists) {
//
//        for(int i =1;i< lists.size();++i){
//
//            lists[0] = mergeList(lists[0],lists[i]);
//        }
//
//
//        return lists[0];
//    }



int main(int argc, const char * argv[]) {
    // insert code here...
  
    
    std::cout << "Hello, World!\n";
    return 0;
}
