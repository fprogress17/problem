//
//
// @..*
//
//   ..
//  @..
//

#include "stdc++.h"


using namespace std;

//////////////
//// remove the duplication block & add the path duplication avoiding with set
/////////////


#if 1

vector<int> num;
set<vector<int>> res;
vector<int> path;

void check(int inx,vector<int>&path, set<vector<int>>&res){
    
    if(path.size() > 1){
        res.insert(path);
    }
        
        for(int i = inx; i< num.size(); ++i){
            
            // if( i == 0 || num[i] != num[i-1]){
             
                if(path.size() == 0 || (path.size() > 0 && path.back() <= num[i] )){
                    
                    path.push_back(num[i]);
                    check(i+1, path, res);
                    path.pop_back();
               // }
            }
        }
    
}

vector<vector<int>> findSubsequences(vector<int>& nums) {
    
    num = nums;
    
    check(0, path, res ) ;
    
    vector<vector<int>> ret(res.begin(), res.end());
    
    return ret;
    
    
}

#endif

int main(int argc, const char * argv[]) {
    // insert code here...
  
    vector<int> n = {4,6,7,7};
    
    vector<vector<int>> ret = findSubsequences(n);
    
    std::cout << "Hello, World!\n";
    return 0;
}
