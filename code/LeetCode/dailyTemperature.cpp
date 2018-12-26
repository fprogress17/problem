//
//
// @..*
//
//  Created    on 9/11/18.
//  @..
//

#include "stdc++.h"


using namespace std;
vector<int> dailyTemperatures(vector<int>& T) {
    
    int n = T.size();
    
    vector < int > res(n, 0 );
    
    stack < int > st;
    
    for ( int i = 0 ; i <T.size (); ++i) {
        
        while (! st.empty () &&
               T[i] > T [st.top ()]) {
            auto t = st.top(); st.pop();
            res[t] = i - t;
        }
        
        st.push(i);
    }
    
    return res;
}




int main(int argc, const char * argv[]) {
    // insert code here...
  
    
    std::cout << "Hello, World!\n";
    return 0;
}
