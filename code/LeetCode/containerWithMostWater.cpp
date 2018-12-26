//
//
// @..*
//
//  Created    on 9/11/18.
//  @..
//

#include "stdc++.h"


using namespace std;

int maxArea(vector<int>& height) {

    int mValue = INT_MIN;

    int lo = 0; int hi = (int)height.size() -1;

    while(lo < hi){

        int w = hi - lo ; // int w = hi - lo + 1;

        mValue = max(mValue, w * min(height[lo], height[hi]));

        if(height[lo] < height[hi]){
            ++lo;
        }else{
            --hi;
        }

    }

    if(mValue == INT_MIN)
        mValue = 0;

    return mValue;

}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cout << "Hello, World!\n";
    return 0;
}
