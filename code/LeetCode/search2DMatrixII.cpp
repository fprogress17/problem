//
//
// @..*
//
//  Created by Choonghun Lee on 9/11/18.
//  @..
//

#include "stdc++.h"


using namespace std;


// the following 2 func happened to be used for Search Matrix I, not II
// since II is not sequential, scan the value carefully and realize that this bsearch is not working


int bSearchLessEqual(vector<int>&v, int target){

    int lo = 0; int hi = v.size()-1;

    while(lo<hi){

       //if(lo+ 1 == hi)
         //  break;

        int mid = (lo+hi)/2;

        if(v[mid] == target){
            return mid;
        }

        if(v[mid] < target){
            lo=mid ;
        }else{
            hi = mid-1;
        }
    }

//   if(v[lo] <= target && target < v[hi])
       return lo;

//    return -1;

}

int bSearch(vector<int>&v, int target){

    int lo = 0; int hi = v.size()-1;

    while(lo<=hi){

        int mid = (lo+hi)/2;

        if(v[mid] == target){
            return mid;
        }

        if(v[mid] < target){
            lo=mid+1;
        }else{
            hi = mid-1;
        }
    }

    return -1;

}

bool searchMatrix00(vector<vector<int>>& matrix, int target) {

    int m = matrix.size();

    if(m ==0 )
        return false;


    int n = matrix[0].size();


    vector<int> col;

    for(int i=0;i <  m; ++i)
    {
       col.push_back(matrix[i][0]);

    }


    int r = bSearchLessEqual(col, target);

    if(r == -1)
        return false;

    int res = bSearch(matrix[r], target);

    if(res == -1)
        return false;

    return  true;




}

bool searchMatrix (vector<vector<int>>& matrix, int target) {
    
    int m = matrix.size();
    
    if(m ==0 )
        return false;
    
    
    int n = matrix[0].size();
    
    if(n == 0)
        return false;
    
    int i=m-1; int j=0;

    while(i>=0 && j<n){

       if(target == matrix[i][j]){

           return true;
       }

       if(target < matrix[i][j]){
           --i;
       }else{
           ++j;
       }


    }

    return false;
   
   
    
    
    
    
}


int main(int argc, const char * argv[]) {
    // insert code here...

//    vector<vector<int>> m = {
//    {1,   4,  7, 11, 15},
//    {2,   5,  8, 12, 19},
//    {3,   6,  9, 16, 22},
//    {10, 13, 14, 17, 24},
//    {18, 21, 23, 26, 30}
//    };

    
    bool ret = searchMatrix(m, 6);

    std::cout << "Hello, World!\n";
    return 0;
}
