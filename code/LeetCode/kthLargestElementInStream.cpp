//
//
// @..*
//
//  Created    on 9/11/18.
//  @..
//

#include "stdc++.h"


using namespace std;

//https://zxi.mytechroad.com/blog/heap/leetcode-703-kth-largest-element-in-a-stream/



class KthLargest {
public:

    priority_queue<int, vector<int>, greater<int>> pq;
    int lim;

    KthLargest(int k, vector<int> nums) {

        lim = k;

        for(int i =0;i<nums.size(); i++){

            add(nums[i]);

        }

    }

    int add(int val) {

        pq.push(val);

        if(pq.size() > lim)
        {
            pq.pop();
        }

        return pq.top();
    }
};


#if 0


// Author: Huahua
// Running time: 32 ms
class KthLargest {
public:
  KthLargest(int k, vector<int> nums): k_(k) {
    for (int num : nums)
      add(num);
  }

  int add(int val) {
    s_.insert(val);
    if (s_.size() > k_)
      s_.erase(s_.begin());
    return *s_.begin();
  }
private:
  const int k_;
  multiset<int> s_;
};



#endif

int main(int argc, const char * argv[]) {
    // insert code here...
  
    
    std::cout << "Hello, World!\n";
    return 0;
}
