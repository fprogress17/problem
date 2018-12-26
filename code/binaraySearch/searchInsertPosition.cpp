//
//
// @..*
//
//  Created by Choonghun Lee on 9/11/18.
//  @..
//

#include "stdc++.h"


using namespace std;


int searchInsertPosition(vector<int> a, int target){
    int lo = 0;
    int hi = a.size()-1;

    while(lo<=hi){

        int m = (lo+hi)/2;

        if( a[m]<target){
            lo = m+1;
        } else if(a[m] > target ){
            hi = m-1;
        } else{
            return m;
        }
    }

    return lo;

}


int main(int argc, const char * argv[]) {
    // insert code here...

   vector<int> a = { 1,3,5,6};

   int ret;
   ret = searchInsertPosition(a, 2);
   printf("%d", ret);

   a = {1,3,5,6};
    ret = searchInsertPosition(a, 7);
    printf("%d", ret);

    std::cout << "Hello, World!\n";
    return 0;
}

