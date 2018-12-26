//
//
// @..*
//
//  Created    on 9/11/18.
//  @..
//

#include "stdc++.h"


using namespace std;


int findMinInRotatedArray(vector<int>a){

    int lo = 0;
    int hi = a.size()-1;

    while(lo <= hi){

        if(a[lo] < a[hi]){
            return a[lo]; // no rotated
        }
        int mid = (hi + lo)/2;

        if( a[mid] > a[mid+1])
            return mid+1;

        if( a[mid] < a[hi])
        {
            hi = mid;  // not mid+1, since ...
        }else{
            lo = mid;
        }
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    
    std::cout << "Hello, World!\n";
    return 0;
}


