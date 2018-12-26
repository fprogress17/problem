//
//
// @..*
//
//  Created by Choonghun Lee on 9/11/18.
//  @..
//

#include "stdc++.h"


using namespace std;


//NumArray(vector<int> nums) {
 //   vector<int>tree(nums.size()+1);
//}

vector<int> tree(nums.size()+1);

void sum(int pos){

   ++pos;
  int res = 0;

   while(pos>0){

       res += tree[pos];

       pos & = (pos -1)
   }

   return res;
}



void update(int pos, int val)
{
    ++pos;

    while(pos<tree.size()){

       tree[pos] += val;

       pos += (pos &-pos)

    }
}


int sumRange(int i, int j) {

    int res = sum[j] - sum[i-1];

    return res;

}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cout << "Hello, World!\n";
    return 0;
}
