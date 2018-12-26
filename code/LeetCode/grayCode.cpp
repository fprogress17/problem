//
//
// @..*
//
//  Created    on 9/11/18.
//  @..
//

#include "stdc++.h"


using namespace std;

#include <string>         // std::string
#include <bitset>


void codeGen(bitset<32>& bits, vector<int>& result, int k){
    if (k==0) {
        
        cout << bits.to_string() << endl;
        
        result.push_back(bits.to_ulong());
       
    }
    else {
        codeGen(bits, result, k-1);
        bits.flip(k-1);
        codeGen(bits, result, k-1);
    }
}



vector<int> grayCode(int n) {
    
    bitset<32> bits;
    vector<int> res;
    
    codeGen( bits, res, n);
    
    return res;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> res = grayCode(3);
    
    std::cout << "Hello, World!\n";
    return 0;
}
