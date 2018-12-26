//
//
// @..*
//
//  Created    on 9/11/18.
//  @..
//

#include "stdc++.h"


using namespace std;


int fence(vector<int> h){

    stack<int> s;
    int ret = 0
    s.push_back(0);

    for(int i=1; i< h.size();++h){

        if(s.empty()){
            s.push_back(i);
            continue;
        }

       if( h[i] > h[s.top()]){

            s.push_back(i);
            
        }else{

            while( h[s.top()] >= h[i]){

                s.pop();
            }

            int width ;
            if(h.empty()){
               width = j+1;
            }else{

                width = i-s.top();
            }
        }

        ret = max(ret, h[j] * width)


    }
}


int main(int argc, const char * argv[]) {
    // insert code here...
    
    
    std::cout << "Hello, World!\n";
    return 0;
}


