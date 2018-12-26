//
//
// @..*
//
//   ..
//  @..
//

#include "stdc++.h"


using namespace std;

#if 0

Input:
image = [[1,1,1],
         [1,1,0],
         [1,0,1]]
sr = 1, sc = 1, newColor = 2
Output: [[2,2,2],
         [2,2,0],
         [2,0,1]]
Explanation:
From the center of the image (with position (sr, sc) = (1, 1)), all pixels connected
by a path of the same color as the starting pixel are colored with the new color.
Note the bottom corner is not colored 2, because it is not 4-directionally connected
to the starting pixel.

#endif

// dfs

void helper(vector<vector<int>>& image, int i, int j, int color, int newColor) {
    
    int m = image.size(), n = image[0].size();
    
    if (i < 0 || i >= m || j < 0 || j >= n || image[i][j] != color) return;
    
    image[i][j] = newColor;
    
    helper(image, i + 1, j, color, newColor);
    helper(image, i, j + 1, color, newColor);
    helper(image, i - 1, j, color, newColor);
    helper(image, i, j - 1, color, newColor);
}


vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    
    if (image[sr][sc] == newColor)
        return image;
    
    helper(image, sr, sc, image[sr][sc], newColor);
    
    return image;
}


int main(int argc, const char * argv[]) {
    // insert code here...
  
    
    std::cout << "Hello, World!\n";
    return 0;
}
