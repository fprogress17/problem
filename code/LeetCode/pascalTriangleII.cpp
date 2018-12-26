//
//
// @..*
//
//  Created    on 9/11/18.
//  @..
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> pascalTriangleII(int numRow){
    
    vector<int> res;
    
    if(numRow <= 0 )
        return res;
    
    res.push_back(0);
    
    for(int i = 1;i <= numRow; ++i){
        
        for(int j=1;j<res.size();j++){
            res[j] =  res[j] + res[j-1];
        }
        
        res.push_back(1);
    }
    
    return res;
    
}


int main(int argc, const char * argv[]) {
    // insert code here...
    
    
    std::cout << "Hello, World!\n";
    return 0;
}


