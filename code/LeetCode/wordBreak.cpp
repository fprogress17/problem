//
//
// @..*
//
//  Created by Choonghun Lee on 9/11/18.
//  @..
//

#include "stdc++.h"


using namespace std;


vector<string> WordDict;
map<string, bool>m;
string S;

vector<int> dp;

bool check(int index){

    if(index == S.size())
    {
        return true;
    }

    if(dp[index] != -1){

        if(dp[index] == 1)
            return true;

        return false;
    }

    for(int i = index; i<S.size();++i)
    {

       string sub = S.substr(index,i-index+1);

        if(find(WordDict.begin(), WordDict.end(), sub) != WordDict.end()) { // && m[sub] == false){

           //m[sub] = true;
           string tar = S.substr(i-index+1);

           if(check(i+1)){
               dp[index] = 1;
               return true;
           }
          // m[sub] = false;
       }



    }

          dp[index] = 0;
    return false;
}

//bool check2(string s){
//
//    if(s.size() == 0)
//    {
//        return true;
//    }
//
//
//    for(int i = 0; i<s.size();++i)
//    {
//
//       string sub = s.substr(0,i+1);
//
//       if(find(WordDict.begin(), WordDict.end(), sub) != WordDict.end() }// && m[sub] == false){
//
//           //m[sub] = true;
//           string tar = s.substr(i+1);
//           if(check(tar)){
//               return true;
//           }
//          // m[sub] = false;
//       }
//
//
//
//    }
//
//    return false;
//}

bool wordBreak(string s, vector<string>& wordDict) {


    WordDict = wordDict;
    dp = vector<int>(s.size()+1, -1);

    bool ret = check(0);

    return ret;

}


int main(int argc, const char * argv[]) {
    // insert code here...
//
//   vector<string> wordDict = {"leet", "code"};
//   string s = "leetcode";

    
//    vector<string> wordDict = {"cats", "dog", "sand", "and", "cat"};
//    string s = "catsandog";


    vector<string> wordDict = {"cats","dog","sand","and","cat"};
    string s = "catsandog";


    
//    vector<string> wordDict = {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
//    string s =  "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";

    WordDict = wordDict;
    S = s;
    
    bool ret = wordBreak(s, wordDict);
    

    std::cout << "Hello, World!\n";
    return 0;
}
