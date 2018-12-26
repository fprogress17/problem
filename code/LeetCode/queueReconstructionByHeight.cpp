//
//
// @..*
//
//   ..
//  @..
//

#include "stdc++.h"


using namespace std;

// queueReconstructionByHeight

vector <pair< int , int >> reconstructQueue(vector<pair< int , int >>& people) {
    
    sort(people.begin(), people.end(), []( const pair< int , int >& a, const pair< int , int >& b) {
        return a.first > b.first || (a .first == b.first && a.second < b.second);
    });
    
    vector <pair< int , int >> res;
    
    for (auto a : people) {
        res.insert(res.begin() + a.second, a);
    }
    
    return res;
}

 


int main(int argc, const char * argv[]) {
    // insert code here...
  
    vector<pair<int,int>> peo = {{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}};
    
    vector<pair<int,int>> res = reconstructQueue(peo);
    
    std::cout << "Hello, World!\n";
    return 0;
}
