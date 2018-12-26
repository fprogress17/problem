//
//
// @..*
//
//  Created    on 9/11/18.
//  @..
//

#include "stdc++.h"


using namespace std;


int leastInterval(vector<char>& tasks, int n) {
 
   map<char, int> m;

   int mValue=0;
    for (auto c : tasks )
    {
        m[c]++;
        mValue = max(mValue, m[c]);
    }

   int res ;
    res = (n+1) * (mValue-1);

   map<char,int>::iterator it = m.begin();
   int mCount = 0;
   for(;it!= m.end();++it)
   {
      if(it->second == mValue)
          mCount++;

   }

   res += mCount;

    res = max( (int)tasks.size(), res);
    
    return res;


}

int leastInterval2(vector<char>& tasks, int n) {
          unordered_map<char, int> mp;

         int count =0;
          for(auto t : tasks) {
            mp[t]++;
                count = max(count, mp[t]);
              }

          int ans = (count-1)*(n+1);
          // in case multiple tasks hold the same max count
          for(auto e : mp) {
                if(e.second == count) ans++;
              }

          return max((int)tasks.size(), ans);
       }

int main(int argc, const char * argv[]) {
    // insert code here...
    
    
    std::cout << "Hello, World!\n";
    return 0;
}
