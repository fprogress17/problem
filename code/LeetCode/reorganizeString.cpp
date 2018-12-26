//
//
// @..*
//
//  Created    on 9/11/18.
//  @..
//

#include "stdc++.h"


using namespace std;

string reorganizeString( string s) {
    
   string res = "";

   unordered_map<char, int> m;
   priority_queue<pair<int, char>> pq;

   for(char c : s){
       m[c]++;
   }

  for( auto p : m){

      if(p.second > (s.size()+1)/2)
          return "";

      pq.push(make_pair(p.second, p.first));
  }

  while(pq.size() >= 2){

      pair<int, char> p1 = pq.top(); pq.pop();
      pair<int, char> p2 = pq.top(); pq.pop();

      res += p1.second;
      res += p2.second;

      if(--p1.first > 0)
          pq.push(p1);

      if(--p2.first > 0)
          pq.push(p2);

  }

 if(pq.size() > 0)
    res += pq.top().second;

 return res;

}




int main(int argc, const char * argv[]) {
    // insert code here...
  
    
    std::cout << "Hello, World!\n";
    return 0;
}
