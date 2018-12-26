//
//
// @..*
//
//  Created    on 9/11/18.
//  @..
//

#include "stdc++.h"


using namespace std;

vector<int> res;


//Solution(vector<int> nums) {
//
//}
//
///** Resets the array to its original configuration and return it. */
//vector<int> reset() {
//
//    return v;
//}

/** Returns a random shuffling of the array. */
vector<int> shuffle() {

   // vector<int> res = v;
    
    for(int i = 0; i< res.size(); ++i){


        int j = (rand() % (res.size()  - i ) ) + i  ;

        swap(res[i], res[j]);

    }

    return res;
}



int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cout << "Hello, World!\n";
    return 0;
}
