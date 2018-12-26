//
//
// @..*
//
//  Created by Choonghun Lee on 9/11/18.
//  @..
//

#include "stdc++.h"


using namespace std;


vector<int> num;
vector<int> dpPlus;
vector<int> dpMinus;

int optPlus(int n);
int optMinus(int n);

int wiggleMaxLength(vector<int>& nums) {

    num = nums;
 
    dpPlus.resize(nums.size()+1,-1);
    dpMinus.resize(nums.size()+1,-1);
    
    int p = optPlus(nums.size()-1);
    int m = optMinus(nums.size()-1);

    return max(p,m);

}



int optPlus(int n){


   if(n == 1){

      if(num[n] > num[0]){
          return 2;
      } else{
          return 0;
      }

   }

  if(dpPlus[n] != -1)
      return dpPlus[n];


   int ret = INT_MIN;
  for(int i=0;i<n; ++i){
      if(num[i] < num[n]){

          ret = max(ret, optMinus(i));
      }
  }

  if(ret != INT_MIN){

      dpPlus[n] = ret+1;
      return ret+1;
  }

    dpPlus[n] = 0;
  return 0;

}


int optMinus(int n){


   if(n == 1){

      if(num[n] <num[0]){
          return 2;
      } else{
          return 0;
      }

   }


  if(dpMinus[n] != -1)
      return dpMinus[n];

   int ret = INT_MIN;
  for(int i=0;i<n; ++i){
      if(num[i] > num[n]){

          ret = max(ret, optPlus(i));
      }
  }

  if(ret != INT_MIN){

      dpMinus[n] = ret+1;
      return ret+1;
  }

    dpMinus[n] = 0;
  return 0;

}

int wiggleMaxLength(vector<int>& nums) {
    if (nums.empty()) return 0;
    vector<int> p(nums.size(), 1);
    vector<int> q(nums.size(), 1);
    for (int i = 1; i < nums.size(); ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[i] > nums[j]) p[i] = max(p[i], q[j] + 1);
            else if (nums[i] < nums[j]) q[i] = max(q[i], p[j] + 1);
        }
    }
    return max(p.back(), q.back());
}
int main(int argc, const char * argv[]) {
    // insert code here...
    
   // vector<int> nums = {1,17,5,10,13,15,10,5,16,8};
    vector<int> nums = { 1,2,3,4,5,6,7,8,9};
    int ret=wiggleMaxLength(nums);
    
    std::cout << "Hello, World!\n";
    return 0;
}
