//
//
// @..*
//
//  Created by Choonghun Lee on 9/11/18.
//  @..
//

#include "stdc++.h"


using namespace std;


vector<vector<string>> groupAnagrams(vector<string>& strs) {

    map<string, vector<string>> m;

    for( int i=0;i < strs.size() ; ++i){

       string str = strs[i];

       string sorted = str;

       sort(sorted.begin(), sorted.end());

       if( m.find(sorted) == m.end()){

           vector<string> r ;
           r.push_back(str);
           m[sorted] = r;

       }else{

           m[sorted].push_back(str);
       }

    }

    vector<vector<string>> res;
    for(auto  t : m) {

       res.push_back(t.second);


   }

   return res;

}


int main(int argc, const char * argv[]) {
    // insert code here...

    vector<string> v =  {"eat", "tea", "tan", "ate", "nat", "bat"};

    vector<vector<string>> res = groupAnagrams(v);
    
    std::cout << "Hello, World!\n";
    return 0;
}
