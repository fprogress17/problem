//
//
// @..*
//
//  Created    on 9/11/18.
//  @..
//

#include "stdc++.h"


using namespace std;

vector < int > nextGreaterElements(vector< int >& nums) {

    int n = nums.size();

    vector < int > res(n, - 1 );
    stack < int > st;

    for ( int i = 0 ; i < 2 * n; ++ i) {

        int num = nums[i % n];

        while (!st.empty() && nums[st.top() ] < num) {
            res[st.top()] = num; st.pop();
        }

        if (i < n) st.push(i);
    }

    return res;
}


int main(int argc, const char * argv[]) {
    // insert code here...


    vector<int> r = {1, 4, 3,2,1};

    vector<int> ret = nextGreaterElements(r);

    std::cout << "Hello, World!\n";
    return 0;
}
