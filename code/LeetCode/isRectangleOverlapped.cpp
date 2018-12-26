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

A rectangle is represented as a list [x1, y1, x2, y2],
where (x1, y1) are the coordinates of its bottom-left corner,
and (x2, y2) are the coordinates of its top-right corner.

Two rectangles overlap if the area of their intersection is positive.
To be clear, two rectangles that only touch at the corner or edges do not overlap.

Given two (axis-aligned) rectangles, return whether they overlap.

Example 1:
              [x1,y1,x2,y2]        [x1,y1,x2,y2]
Input: rec1 = [0, 0, 2, 2], rec2 = [1, 1, 3, 3]
Output: true

#endif

bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
   
    
    if ( rec2[0] >= rec1[2] )    // rec2 is right of rec1
        return false;
    else if (rec2[2] <= rec1[0] )  // rec1 is left of rec1
        return false;
    else if ( rec1[1] >= rec2[3] ) // rec1 is above rec2
        return false;
    else if ( rec1[3] <= rec2[1] ) // rec2 is above rec1
        return false;
    else
            return true;
    
    
    // hard to read
//    return  rec1[0] < rec2[2] &&   // r1.x1 < r2.x2
//            rec2[0] < rec1[2] &&   // r2.x1 < r1.x2
//            rec1[1] < rec2[3] &&   // r1.y1 < r2.y2
//            rec2[1] < rec1[3];     // r2.y1 < r1.y2

}

#if 0
return not (rec1_x1 >= rec2_x2 or rec1_x2 <= rec2_x1 or rec1_y1 >= rec2_y2 or rec1_y2 <= rec2_y1)
#endif

int main(int argc, const char * argv[]) {
    // insert code here...
  
    
    std::cout << "Hello, World!\n";
    return 0;
}
