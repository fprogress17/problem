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

vector<vector<int>> pascalTriangle(int rowNum){
    
    vector<vector<int>> res;
    
    if(rowNum <= 0 )
        return res;
    
    vector<int> previous = vector<int>(1,1);
    
    res.push_back(previous);
    
    for(int i = 2; i <= rowNum; ++i){
        
        vector<int>current;
        current.push_back(1);
        
        for(int j=0; j<previous.size()-1; ++j){
            current.push_back( previous[j] + previous[j+1] );
        }
        
        current.push_back(1);
        
        res.push_back(current);
        previous = current;
        
    }
    
    return res;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    
    
    std::cout << "Hello, World!\n";
    return 0;
}


