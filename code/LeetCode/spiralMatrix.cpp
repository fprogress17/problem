//
//
// @..*
//
//  Created by Choonghun Lee on 9/11/18.
//  @..
//

#include <iostream>
#include <vector>

using namespace std;



vector < int > spiralOrder(vector<vector< int >>& matrix) {
    
    if (matrix.empty() || matrix[ 0 ].empty()) return {};
    
    int m = matrix.size(), n = matrix[ 0 ].size();
    
    vector < int > res;
    
    int up = 0 , down = m - 1 , left = 0 , right = n - 1 ;
    
    while ( true ) {
    
        for ( int j = left; j <= right; ++ j)
            res.push_back(matrix[up][j]);
        if (++up > down)
            break ;
        
        for ( int i = up; i <= down; ++ i)
            res.push_back(matrix[i][right]);
        if (--right < left) break ;
        
        for( int j = right; j >= left; -- j)
            res.push_back(matrix[down][j]);
        if (--down < up) break ;
        
        for ( int i = down; i >= up; -- i)
            res.push_back(matrix[i][left]);
        if (++left > right) break ;
    }
    
    return res;
}


#if 0 // below didn't pass leet
Your input
[[1,2,3],[4,5,6],[7,8,9]]
stdout

Output
[1,2,3,6,9,8,7,4]
Expected
[1,2,3,6,9,8,7,4,5]


vector<int> res;
vector<vector<int>> ma;

int m;
int n;


void toRight(int r, int c, int cCnt){
    for(int j=c; j< c+cCnt; ++j)
    {
      //  printf("%d", ma[r][j]);
        res.push_back(ma[r][j]);
    }
    
}

void toDown(int r, int c, int rCnt){
    for(int i=r; i< r+rCnt; ++i)
    {
     //  printf("%d", ma[i][c]);
        res.push_back(ma[i][c]);
    }
    
}

void toLeft(int r, int c, int cCnt){
    for(int j=c; cCnt >0; --j, --cCnt)
    {
      //  printf("%d", ma[r][j]);
        res.push_back(ma[r][j]);
    }
    
}

void toUp(int r, int c, int rCnt){
    for(int i=r; rCnt> 0; --rCnt, i--)
    {
     //   printf("%d", ma[i][c]);
        res.push_back(ma[i][c]);
    }
    
}

vector<int> spiralMatrix(vector<vector<int>>& matrix)
{
    
    m = matrix.size();
    n = matrix[0].size();
    
    ma = matrix;
    
    for(int k=0;k< m/2;++k){
   
            toRight(k,k,n - k*2);
            toDown(k+1,n-k-1,m-k*2-1);
            toLeft(m-k-1,n-k-1-1,n-k*2-1);
            toUp(m-k-1-1,k,m-k*2-1-1);

        printf("\n");
    }
    
    return res;
}

#endif

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<vector<int>> mat = {{1,2,3,4}
                            ,  {5,6,7,8},
                               {9,10,11,12},
                               {13,14,15,16},
                               {17,18,19,20}};
    
  //  spiralMatrix(mat);
    vector<int> ret = spiralOrder(mat);
    
    std::cout << "Hello, World!\n";
    return 0;
}


