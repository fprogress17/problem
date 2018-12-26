//
//
// @..*
//
//  Created by Choonghun Lee on 9/11/18.
//  @..
//

#include "stdc++.h"


using namespace std;

class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1.size() != s2.size())
            return false;
        if(s1 == s2)
            return true;
        int n = s1.size();
        if(n == 1)
        {
            return s1[0] == s2[0];
        }
        // check char distribution
        int dist1[256]={0};
        for(int i = 0; i<n; ++i)
        {
            dist1[s1[i]]++;
            dist1[s2[i]]--;
        }
        for(int i = 0; i<256; ++i) // test 0
            if(dist1[i]!=0)
                return false;
        // check every possible division
        for(int i = 1; i <n; ++i)
        {
            string s11 = s1.substr(0,i);
            string s21 = s2.substr(0,i);
            string s22 = s2.substr(i);
            string s12 = s1.substr(i);
            if(isScramble(s11,s21) && isScramble(s12, s22))
                return true;

            s22 = s2.substr(0, n-i); // check the swapped order
            s21 = s2.substr(n-i);
            if(isScramble(s11,s21) && isScramble(s12, s22))
                return true;
        }
        
        return false;
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    
    
    std::cout << "Hello, World!\n";
    return 0;
}
