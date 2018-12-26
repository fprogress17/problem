//
//  maximalRectangle.cpp
// @..*
//
//  Created by Choonghun Lee on 9/8/18.
//  @..
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;


int maxRectInHisto(vector<int> height){
    
 
    stack<int> s;
    height.push_back(0); ///  not s.push(0);
    int res = 0;

    for (int i=0; i< height.size(); ++i){

        while(!s.empty() && height[s.top()] >= height[i]){

            int j = s.top();
            s.pop();

            int width = -1;

            if(s.empty()){
                width = i;
            }else{
                width = i-s.top() -1;
            }

            int area = width * height[j];

            res = max(res, area);
        }

        s.push(i);
    }

    return res;
    
}


int maximulRectangle(vector<vector<char>> &matrix){
 
    int s = matrix.size();
    
    if(s == 0)
        return 0;
    
    vector<int> h(matrix[0].size(),0);
    int res = 0;

    for(int i=0; i < matrix.size(); ++i){
        for(int j=0; j< matrix[i].size(); ++j){

            if(matrix[i][j] == '0'){
                h[j]=0;
            }else{
                h[j] = h[j] + 1;
            }
        }

        int area = maxRectInHisto(h);

        res = max(res, area);

    }

    return res;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    vector<vector<char>> matrix ={};
    maximulRectangle(matrix);
  
    std::cout << "Hello, World!\n";
    return 0;
}
