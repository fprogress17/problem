//
//
// @..*
//
//  Created by Choonghun Lee on 9/11/18.
//  @..
//

#include "stdc++.h"


using namespace std;

//pair<string, int> ;

queue<pair<string, int>> q;
vector<string> WordList;
map<string, bool> m;

bool isAdjacent(string &a, string &b){

   int count = 0;
    for(int i=0;i< a.size();++i){
      if(a[i] == b[i]){
          count++;
      }
    }

    if(a.size() -1 == count)
        return true;
    return false;

}


int check(string  begin, string end){

   while(!q.empty()){

       pair<string,int> here = q.front(); q.pop();

       if( here.first == end )
       {
           return here.second;

       }

       string hStr = here.first;

      for( string str : WordList){

         if(isAdjacent(hStr, str))
         {
             if(m[str] == false){
                 m[str] = true;
                 q.push(make_pair(str, here.second + 1));
             }
         }


      }

   }

    return 0;
}




int ladderLength(string beginWord, string endWord, vector<string>& wordList) {


    WordList = wordList;

    q.push(make_pair(beginWord,1));
    m[beginWord] = true;

    int ret = check(beginWord, endWord);

    return ret;

}

int main(int argc, const char * argv[]) {
    // insert code here...


    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};

    int ret = ladderLength("hit", "cog", wordList);

    std::cout << "Hello, World!\n";
    return 0;
}
