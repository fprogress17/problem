//
//
// @..*
//
//  Created by Choonghun Lee on 9/11/18.
//  @..
//

#include "stdc++.h"
//https://blog.csdn.net/Cloudox_/article/details/53905485

using namespace std;

int numberOfArithmeticSlices(vector<int> &A){

    int result = 0;
    int n = A.size();

    for(int i =0; i<n-2;++i){

        int gap = A[i+1] - A[i];

        for(int j = i+2; j< n;++j){

            if(A[j] - A[j-1] == gap)
                ++result;
            else{
                break;
            }
        }

    }

    return result;

}


int numberOfArithmeticSlices2(vector<int> &A){

    int sum = 0;
    int curr = 0;

    for(int i = 2; i<A.size();++i){

        if(A[i-1] - A[i-2] == A[i] - A[i-1])
        {
            ++curr;
            sum += curr;
        }else{
            curr = 0;
        }
    }
  return sum;
  }




int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cout << "Hello, World!\n";
    return 0;
}
