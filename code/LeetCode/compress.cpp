//
//
// @..*
//
//  Created by Choonghun Lee on 9/11/18.
//  @..
//

#include "stdc++.h"


using namespace std;


int compress(vector<char>& chars) {
    
    vector<char> c = chars;
    
    int count = 1;
    int diffIndex = 0;
    
    for(int i = 1; i< c.size();++i)
        
        if(c[i] == c[i-1]){
            
            ++count;
            
        }else{
            
            ++diffIndex;
            if(count == 1){
                
            }
            else if(count < 10 ){
                
                c[diffIndex] = '0' + count;
                
            }else if(count<100 && count > 1){
                c[diffIndex] = '0' + count/10;
                ++diffIndex;
                c[diffIndex] = '0' + count%10;
            }else if(count < 1000){
                c[diffIndex] = '0' + count/100;
                ++diffIndex;
                c[diffIndex] = '0' + (count%100)/10;
                ++diffIndex;
                c[diffIndex] = '0' + (count%100)%10;
            }else if ( count == 1000){
                c[diffIndex] = '1';
                ++diffIndex;
                c[diffIndex] = '0' ;
                ++diffIndex;
                c[diffIndex] = '0' ;
                ++diffIndex;
                c[diffIndex] = '0' ;
            }
            
            count = 1;
        }
    
    
    if(count > 1){
        if(count < 10){
            
            c[diffIndex] = '0' + count;
            
        }else if(count<100){
            c[diffIndex] = '0' + count/10;
            ++diffIndex;
            c[diffIndex] = '0' + count%10;
        }else if(count < 1000){
            c[diffIndex] = '0' + count/100;
            ++diffIndex;
            c[diffIndex] = '0' + (count%100)/10;
            ++diffIndex;
            c[diffIndex] = '0' + (count%100)%10;
        }else if ( count == 1000){
            c[diffIndex] = '1';
            ++diffIndex;
            c[diffIndex] = '0' ;
            ++diffIndex;
            c[diffIndex] = '0' ;
            ++diffIndex;
            c[diffIndex] = '0' ;
        }
    }
    
    vector<char> ret(c.begin(), c.begin() + diffIndex);
    int len = diffIndex + 1;
    
    return len;
    
}



int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<char> c = {'a','b','b','b','b','b','b','b','b','b','b','b','b'};
    
    compress(c);
    std::cout << "Hello, World!\n";
    return 0;
}
