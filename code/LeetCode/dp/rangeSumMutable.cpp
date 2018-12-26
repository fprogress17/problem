//
//
// @..*
//
//  Created    on 9/11/18.
//  @..
//

#include "stdc++.h"


using namespace std;


//NumArray(vector<int> nums) {
 //   vector<int>tree(nums.size()+1);
//}
vector<int> tree;
vector<int> num;

void update(int i, int val);

void init(vector<int> nums) {
    
    tree.resize(nums.size()+1);
    num.resize(nums.size());
    
    for(int i=0;i < nums.size(); ++i)
    {
        update(i, nums[i]);
    }
    
}

int sum(int pos){
    
    ++pos;
    int res = 0;
    while(pos > 0)
    {
        res += tree[pos]    ;
        pos &= (pos -1);
        
    }
    
    return res;
}

void update(int i, int val) {
    int o = num[i];
    int diff = val - o;
    
    num[i] = val;
    
    
    int pos = i;
    ++pos;
    while(pos < tree.size()){
        
        tree[pos] += diff;
        
        pos += (pos & -pos);
    }
    
}

int sumRange(int i, int j) {
    
    int res ;
    
    res = sum(j)- sum(i-1);
    
    return res;
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> m = {1,3,5};
    init(m);
    
    int ret = sumRange(0, 2);
    
    update(1,2);
    ret = sumRange(0, 2);
    
    std::cout << "Hello, World!\n";
    return 0;
}
