//
//
// @..*
//
//  Created by Choonghun Lee on 9/11/18.
//  @..
//

#include "stdc++.h"


using namespace std;

void printTarget(string target);

string countAndsay(int n){
    
    string target = "1";
    
    string ret;
    
    --n;
    
    while(  n > 0){
        
        int len = target.length();
        int index = 0;
        
        while( index  < len){
            
            int tIndex = index;
            int count = 1;
            
            
            // count the same char
            while(tIndex + 1 < len ) {
                
                if (target[tIndex] == target[tIndex + 1]){
                    ++count;
                    ++tIndex;
                }else{
                    break;
                }
            }
            
            string c = string (1, count + '0');
            
            ret += c ;
            ret += target[index] ;
            
            
            if(tIndex > index){
                index = tIndex;
            }
                
                ++index;
            
        }
        
        target = ret;
        //cout<< target << endl;
        printTarget(target);
        
        index = 0;
        ret = "";
        --n;
    }
    
     return target;
}

void printTarget(string target){
    
    int i=0;
    
    while( i < target.length()){
        
     string sub = target.substr(i, 2);
        i += 2;
    
        cout << sub << " " ;
    }
    
    cout << endl;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    cout<< countAndsay(20) << endl;
    
    std::cout << "Hello, World!\n";
    return 0;
}
