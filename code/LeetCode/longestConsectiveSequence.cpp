//
//
// @..*
//
//  Created by Choonghun Lee on 9/11/18.
//  @..
//

#include "stdc++.h"

using namespace std;

int longestConsectiveSequence(vector<int> &a){
    
    unordered_set<int> s;
    
    for(int i=0;i<a.size();++i){
        s.insert(a[i]);
    }
    
    
    int res = 0;
    for(int i=0;i<a.size();++i){
        
        int num = a[i];
        int count = 0;
        
        while( s.find(num) != s.end()){
            
            count++;
            num++;
        }
        
        res = max(res, count);
    }
    
    return res;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    
    
    std::cout << "Hello, World!\n";
    return 0;
}


