//
//
// @..*
//
//  Created    on 9/11/18.
//  @..
//

#include "stdc++.h"


using namespace std;

int min_val = INT_MAX;
stack < int > st;


void push( int x) {
    if (x <= min_val) {
        st.push(min_val);
        min_val = x;
    }
    st.push(x);
}

void pop() {
    int t = st.top(); st.pop();
    if (t == min_val) {
        min_val = st.top (); st.pop ();
    }
}

int top() {
    return st.top();
}

int getMin() {
    return min_val;
}





vector<int> d;
vector<int> m;

void push(int v)
{
    
    int n = d.size();
    
    d.push_back(v);
    
    if(n == 0){
        m.push_back(v);
    }else{
        int minV = min(m[n=1], v);
        m.push_back(minV);
    }
}


int pop()
{
    int ret = d.back();
    d.pop_back();
    m.pop_back();
    return ret;
}

int getMin(){
    
    int ret = m.back();
    return ret;
    
}


int main(int argc, const char * argv[]) {
    // insert code here...
    
    
    std::cout << "Hello, World!\n";
    return 0;
}
