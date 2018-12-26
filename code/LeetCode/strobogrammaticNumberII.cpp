//
//
// @..*
//
//   ..
//  @..
//

#include "stdc++.h"


using namespace std;

 //Strobogrammatic Number II

vector<string> fS(int n){
    if(n == 0)
        return "";
    
    if(n == 1){
        return {"1","8"};
    }
    
    if(n == 2){
        return {"11","69","88","96"};
    }
    
    vector<string>r = fS(n-1);
    
    vector<string> ret;
    
    for( string str : r){
        
        string str1 = str.substr(0,1) + "1" + str.substr(1,str.size()-1);
        string str2 = str.substr(0,1) + "8" + str.substr(1,str.size()-1);
        
        ret.push_back(str1);
        ret.push_back(str2);
        
    }
    
    return ret;
    
}

vector<string> findStrobogrammatic(int n) {
    
    vector<string> ret = fS(n);
    return ret;
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
  
    
    std::cout << "Hello, World!\n";
    return 0;
}
