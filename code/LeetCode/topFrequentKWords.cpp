//
//
// @..*
//
//   ..
//  @..
//

#include "stdc++.h"


using namespace std;

struct cmp{
    bool operator()(pair<string,int> a, pair<string,int> b){

      //  return (a.second > b.second || ((a.second == b.second) && (a.first < b.first)));
          return (a.second < b.second || ((a.second == b.second) && (a.first > b.first)));
    };
};

vector<string> topKFrequent(vector<string>& words, int k) {

    map<string, int> m;
    priority_queue< pair<string,int>, vector<pair<string,int>>, cmp> pq;

    vector<string> res;

    for(string word : words){
       m[word]++;
    }

    for(auto ma : m){

        pq.push(ma);

    }

   for(int i = 0; i<k; ++i){

      res.push_back(pq.top().first);
      pq.pop();

   }

    return res;

}



int main(int argc, const char * argv[]) {
    // insert code here...
  
    
    std::cout << "Hello, World!\n";
    return 0;
}
