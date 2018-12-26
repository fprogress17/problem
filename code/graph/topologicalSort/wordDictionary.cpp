//
//
// @..*
//
//  Created    on 9/11/18.
//  @..
//

#include "stdc++.h"


using namespace std;


vector<vector<int>> adj;

void makeAdj(vector<string> words){
    
    for(int i=0; i< words.size()-1; ++i) {
        
        for(int j=0 ; j< min(words[i].size(), words[i+1].size()); ++j){
            
            if(words[i][j] != words[i+1][j]){
                
                adj[words[i][j] - 'a'].push_back(words[i+1][j] - 'a');
                break;
            }
            
        }
    }
    
}




int main(int argc, const char * argv[]) {
    // insert code here...
    
    
    std::cout << "Hello, World!\n";
    return 0;
}
