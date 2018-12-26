//
//
// @..*
//
//  Created by Choonghun Lee on 9/11/18.
//  @..
//

#include "stdc++.h"


using namespace std;
#if 0
A string S of lowercase letters is given. We want to partition this string into as many parts as possible so that each letter appears in at most one part, and return a list of integers representing the size of these parts.

Example 1:
Input: S = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".

#endif


vector < int > partitionLabels( string S) {
    
    vector < int > res;
    unordered_map < char , int > m;
    
    int n = S.size(), start = 0 , last = 0 ;
    
    for ( int i = 0 ; i < n; ++i)
        m[S[i]] = i;
    
    for ( int i = 0 ; i < n; ++ i) {
        last = max(last, m[S[i]]);
        if (i == last) {
            res.push_back(i - start + 1 );
            start = i + 1 ;
        }
    }
    return res;
}



int main(int argc, const char * argv[]) {
    // insert code here...
    
    
    std::cout << "Hello, World!\n";
    return 0;
}
