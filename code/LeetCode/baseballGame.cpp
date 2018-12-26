//
//
// @..*
//
//   ..
//  @..
//

#include "stdc++.h"


using namespace std;

 
int calPoints(vector<string>& ops) {
    
    vector<int> v;
    
    for (string op : ops) {
    
        if (op == "+") {
            v.push_back(v.back() + v[v.size() - 2]);
        }
        else if (op == "D") {
            v.push_back(2 * v.back());
        }
        else if (op == "C") {
            v.pop_back();
        }
        else {
            v.push_back(stoi(op));
        }
    }
    return accumulate(v.begin(), v.end(), 0);
}


int main(int argc, const char * argv[]) {
    // insert code here...
  
    
    std::cout << "Hello, World!\n";
    return 0;
}
