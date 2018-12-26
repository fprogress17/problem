//
//  maximalRectangle.cpp
// @..*
//
//  Created    on 9/8/18.
//  @..
//

#include <iostream>
#include <vector>

using namespace std;


int dxx[4] = {1,-1 , 0, 0  };
int dyy[4] = {0, 0 , 1, -1 };

vector<vector<char>> matrixx;

bool isValid(int x, int y){
    
   int col = matrixx[0].size();
    int row  = matrixx.size();
    
    if(x < 0 || y < 0)
        return false;
        
     if( x >= row || y >= col )
         return false;
    
    return true;
}


// x => row, y = > column
void count(int x, int y, int &cnt)
{
    
    if(matrixx[x][y] == '1' ){
        
        matrixx[x][y] = '2';
        cnt++;
        
        for(int i=0; i < 4; ++i){
            
            int dx = x + dxx[i];
            int dy = y + dyy[i];
            
            if(isValid(dx,dy)){
                
                if( matrixx[dx][dy] == '1'){
                    
                     cout<< dx << " " << dy << endl;
                    
                   // matrixx[dx][dy] = '2';
                  
                    count(dx, dy, cnt);
                    
                }
            
            }
        }
        
    }
}




int maximalOnesCount(vector<vector<char>>& matrix) {

    int res = 0;
    
    matrixx = matrix;
    
    int col = matrix[0].size();
    int row = matrix.size();
    
    for(int i=0;i<row;++i)
        for(int j=0;j<col; ++j){
            
            int cnt = 0;
            
             count(i,j,cnt);
            
            res = max(res,cnt);
            
        }
    
    return res;
    
}



int main(int argc, const char * argv[]) {
    // insert code here...
    
    string s;
    
    
    
    std::cout << "Hello, World!\n";
    return 0;
}


