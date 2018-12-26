//
//
// @..*
//
//   ..
//  @..
//

#include "stdc++.h"


using namespace std;

// if there are n points and a distance equal,
// Then the arrangement is n(n-1),
// which is the simplest arrangement and combination problem.


int numberOfBoomerangs(vector<pair<int, int>>& points) {
    
    int res = 0;
    
    for (int i = 0; i < points.size(); ++i) {
    
        unordered_map<int, int> m;
        
        for (int j = 0; j < points.size(); ++j) {
        
            int a = points[i].first - points[j].first;
            int b = points[i].second - points[j].second;
            ++m[a * a + b * b];
        }
        
//        for (auto it = m.begin(); it != m.end(); ++it) {
//            res += it->second * (it->second - 1);
//        }
        for (auto p : m  ) {
            res += p.second * (p.second - 1);
        }
    }
    return res;
}



int main(int argc, const char * argv[]) {
    // insert code here...
  
    
    std::cout << "Hello, World!\n";
    return 0;
}
