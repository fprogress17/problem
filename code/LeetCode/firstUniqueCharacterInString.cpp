//
//
// @..*
//
//  Created by Choonghun Lee on 9/11/18.
//  @..
//

#include "stdc++.h"


using namespace std;


int firstUniqChar(string s) {

    map<char, int> m;

    int n = (int)s.size();

    for(int i=0; i< n; ++i){
        m[ s[i]]++;
    }


    for(int i=0; i< n; ++i){

        if(m[s[i]] == 1)
            return i;
    }

    return -1;

}



int main(int argc, const char * argv[]) {
    // insert code here...

    //string s = "leetcode";
    string s = "loveleetcode";

    int res = firstUniqChar(s);

    std::cout << "Hello, World!\n";
    return 0;
}
