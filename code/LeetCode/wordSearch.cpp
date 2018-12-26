//
//
// @..*
//
//  Created by Choonghun Lee on 9/11/18.
//  @..
//

#include "stdc++.h"


using namespace std;

vector<vector<char>> Board;
string Word;

int n,m;
#define MAX_LEN 1000
#define MAX_SIZE 100
vector<vector<bool>> visited;

   vector<int> dy = { 0, 0, 1, -1};
   vector<int> dx = { 1, -1, 0, 0};

// int  dp[MAX_SIZE][MAX_SIZE][MAX_LEN];
vector<vector<vector<int>>> dp;


   bool inRange(int y, int x){


       if((x >= 0 && x < n) && (y >= 0 && y < m))
           return true;

       return false;
   }


   bool check(int y, int x, int index, string s){

       cout<<index << ":" <<  s << endl;
       
       if(!inRange(y,x))
           return false;
       
       s  = s + Board[y][x]
       
       if(index == Word.size() - 1){
            cout<<index << ":" <<  s << endl;
           return Board[y][x] == Word[index];

       }

       
       if(dp[y][x][index] != -1){
           
         if( dp[y][x][index] == 1)
             return true;
           
           return false;
       }
       
     bool ret = false;

     visited[y][x] = true;
       
    if( Board[y][x] == Word[index]) {
        
        for(int i =0; i< 4; ++i ){
             
            
                  
                if(!visited[y+dy[i]][x+dx[i]]  ) {
                    
                 // cout<< Board[y][x] << " " << Word[index] << endl;
             //    visited[y+dy[i]][x+dx[i]] = true;
                 
                 ret |= check(y+dy[i], x+dx[i], index + 1, s  );
                 
               //  visited[y+dy[i]][x+dx[i]] = false;

             
            }
        }
         
    }

        visited[y][x] = false;
       s.erase(s.size()-1,1);
       
       dp[y][x][index] = ret? 1:0;
      return ret;

   }

bool exist(vector<vector<char>>& board, string word) {

   m = board.size();
   if(m == 0 ) return false;

   n = board[0].size();

    if(word.size() == 0)
        return true;
    
    Board = board;
    Word = word;
    
    visited = vector<vector<bool>>(m+1, vector<bool>(n+1,false));
    
    
   dp = vector<vector<vector<int>>>(m+1,vector<vector<int> >(n+1,vector<int>(word.size()+1, -1)));


    
//
//        for(int i = 0;i < m+1; ++i)
//            for(int j = 0;j < n+1; ++j)
//                for(int k = 0;k < word.size(); ++k)
//                    cout<<dp[i][j][k] << endl;
//
 
    string str;
 
   for(int i = 0; i<m; ++i)
       for(int j=0;j<n; ++j){
           
        //   visited[i][j] = true;
           
           if(check(i,j,0, str + Board[i][j]))
                return  true;
           
          // visited[i][j] = false;

       }
    
          return false;

}


int main(int argc, const char * argv[]) {
    // insert code here...
//    vector<vector<char>> board =
//    {
//        {'A','B','C','E'},
//        {'S','F','C','S'},
//        {'A','D','E','E'}
//    };


   // bool ret = exist(board, "ABCCED");
   // bool ret = exist(board, "SEE");
    //  bool ret = exist(board, "ABCB");

#if 0
    vector<vector<char>> board =
    {
        {'A','A' }
        
    };

    bool ret = exist(board, "AAA");
#endif
    
    vector<vector<char>> board =
    {
        {'A','B','C','E'},
        {'S','F','E','S'},
        {'A','D','E','E'}
    };


    bool ret = exist(board, "ABCESEEEFS");
    std::cout << "Hello, World!\n";
    return 0;
}
