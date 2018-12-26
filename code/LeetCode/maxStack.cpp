//
//
// @..*
//
//   ..
//  @..
//

#include "stdc++.h"


using namespace std;


//// using make_pair(orgvalue, currentMaxValue) to keep record of the maxValue
/// if using 2 stacks, then same usage of memory , but this looks simple



// need to debug the following case from run time error
//["MaxStack","push","push","push","popMax","popMax","top"]
//[[],[5],[1],[-5],[],[],[]]


stack<pair<int,int>> s;

MaxStack() {
    
}

void push(int x) {
    
    
    if(s.empty()){
        
        s.push(make_pair(x,x));
        
    }else{
        
        if(s.top().second > x ) {
            s.push(make_pair(x, s.top().second));
        }else{
            
            s.push(make_pair(x,x));
        }
        
    }
    
    
}

int pop() {
    int ret = s.top().first;
    s.pop();
    return ret;
}

int top() {
    
    return s.top().first;
    
}

int peekMax() {
    
    return s.top().second;
}

int popMax() {
    
    stack<pair<int,int>> tmp;
    
    while(!s.empty() && s.top().first != s.top().second){
        
        tmp.push(s.top());
        s.pop();
    }
    
    if(s.empty()){
        return 1;
    }
    
    int maxValue = s.top().first;
    s.pop();
    
    
    while(!tmp.empty()){
        s.push(tmp.top());
        tmp.pop();
    }
    
    return maxValue;
    
    
}



int main(int argc, const char * argv[]) {
    // insert code here...
  
    
    std::cout << "Hello, World!\n";
    return 0;
}
