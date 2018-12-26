//
//
// @..*
//
//  Created    on 9/11/18.
//  @..
//

#include "stdc++.h"


using namespace std;

int romanToInt(string& s) {
    
    int res = 0;
    
    unordered_map<char, int> m{{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
    
    for (int i = 0; i < s.size(); ++i) {
    
        if (i == s.size() - 1 || m[s[i]] >= m[s[i + 1]])
            res += m[s[i]];
        else
            res -= m[s[i]];
    }
    
    return res;
}



int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cout << "Hello, World!\n";
    
    string s = "MCMXCIV";
    cout<< romanToInt(s) << endl;
    
    
    return 0;
}
