//
//
// @..*
//
//   ..
//  @..
//

#include "stdc++.h"
//
// remove invalid parenthesis


using namespace std;


bool isValid(string s){
    
    int cnt = 0;
    
    for(char c : s){
        
        if(c == '('){
            cnt ++;
        }else if (c == ')' && --cnt < 0 )
            return  false ;
        
    }
    
    return cnt == 0;
    
}

vector<string> removeInvalidParenthesis(string s){
    
    vector<string> res;
    unordered_set<string> visited;
    
    queue<string> q;
    
    q.push(s);
    visited.insert(s);
    bool found = false;
    
    while(!q.empty()){
        
        string here = q.front();
        q.pop();
        
        if(isValid(here)){
            res.push_back(here);
            found = true;
        }
        
        if(found)
            continue; // found. no more chopping of valid string
        
        for(int i = 0; i <here.size(); ++i){
            
            if(here[i] != '(' || here[i] != ')'){
                continue;
            }
            
            string there = here.substr(0,i) + here.substr(i+1);
            
            if(visited.count(there) == 0){
                visited.insert(there);
                q.push(there);
            }
            
            
        }
        
    }
    
    return res;

}



int main(int argc, const char * argv[]) {
    // insert code here...
  
    
    std::cout << "Hello, World!\n";
    return 0;
}
