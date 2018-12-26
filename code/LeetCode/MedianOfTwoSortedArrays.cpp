//
//
// @..*
//
//  Created    on 9/11/18.
//  @..
//

#include <iostream>
#include <vector>

using namespace std;

int findKth(int k, vector<int> a, vector<int> b, int startIndexA, int startIndexB);

int MedianOfTwoSortedArrays(vector<int> a, vector<int> b, int startIndexA, int startIndexB){
    
    int m = a.size();
    int n = b.size();
    
    if((m+n) % 2){
        
        return (findKth( (m+n)/2 + 1, a,b,startIndexA, startIndexB) + findKth((m+n)/2, a,b,startIndexA,startIndexB) )/2;
        
    }else{
        
        return findKth((m+n)/2 + 1, a, b, startIndexA, startIndexB);
    }

}


int findKth(int k, vector<int> a, vector<int> b, int startIndexA, int startIndexB){
    
    if(startIndexA >= a.size()){
        return b[startIndexB + k/2 -1];
        
    }
    
    if(startIndexB >= b.size()){
        return a[startIndexA + k/2 -1];
    }
    
    if(k == 1)
    {
        return min(a[startIndexA], b[startIndexB]);
    }
    
    int m1 = startIndexA + k/2 -1;
    int m2 = startIndexB + k/2 -1;
    
    
    int midA = a[m1];
    int midB = b[m2];
    
    if(midA < midB){
        return findKth(k - k/2, a, b, m1+1, startIndexB);
    }else{
        return findKth(k-k/2, a, b, startIndexA, m2+1);
    }
    
}


int main(int argc, const char * argv[]) {
    // insert code here...
    
    
    std::cout << "Hello, World!\n";
    return 0;
}


