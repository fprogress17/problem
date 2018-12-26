//
//
// @..*
//
//  Created by Choonghun Lee on 9/11/18.
//  @..
//

#include "stdc++.h"


using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
    
     if (matrix.empty() || matrix[ 0 ].empty())
         return ;
    
    int m = matrix.size();
    int n = matrix[0].size();
    
    bool firstRowZero = false;
    bool firstColZero = false;
    
    for(int i= 0; i< m; ++i){
        if(matrix[i][0] == 0){
            firstColZero = true;
            break;
        }
    }
    
    for(int i= 0; i< n; ++i){
        if(matrix[0][i] == 0){
            firstRowZero = true;
            break;
        }
    }
    
    for(int i=1;i<m;++i)
        for(int j=1;j<n;++j){
            if(matrix[i][j] == 0){
                matrix[0][j] = 0;
                matrix[i][0] = 0;
            }
        }
    
    for(int i=1;i<m;++i)
        for(int j=1;j<n;++j){
            if(matrix[0][j] == 0 || matrix[i][0]==0){
                matrix[i][j]=0;
            }
        }
    
    if(firstColZero == true){
        for(int j=0;j<m;++j)
            matrix[j][0] = 0;
    }
    if(firstRowZero == true){
        for(int i=0;i<n;++i)
            matrix[0][i] = 0;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
   vector<vector<int>> m =  {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    //vector<vector<int>> m =  {{1,0,3}};//{{1,0}};
    setZeroes(m);
    
    std::cout << "Hello, World!\n";
    return 0;
}


