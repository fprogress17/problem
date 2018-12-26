//
//
// @..*
//
//  Created by Choonghun Lee on 9/11/18.
//  @..
//

#include "stdc++.h"
//http://www.cnblogs.com/grandyang/p/6254527.html

using namespace std;

vector<string> res;

bool dfs(int pos,string word,  set<string> s){
    
    if(pos >= word.size())
        return true;
    
    if(pos == 0)
        s.erase(word);
    
        int count = 1;
        bool ret = false;
        for(int i = pos ; i< word.size(); ++i){
            
            string sub = word.substr(pos, count++);
            if(s.count(sub) != 0){
                s.erase(sub);
                bool r = dfs(pos + count - 1,word, s);
//                if(r)
//                    res.push_back(sub);
                ret != r;
                s.insert(sub);
            }
        }
    if(pos == 0)
        s.insert(word);

        return ret;
}


vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {

    set<string> s(words.begin(), words.end());
    for (string word :  words) {

        if (word.size() == 0)
            continue;

        if (dfs(0, word, s)){
            res.push_back(word);
        };

    }

    return res;
}

vector<string> findAllConcatenatedWordsInADictx(vector<string>& words) {


    set<string> s(words.begin(), words.end());



    //for(int i = 0;i < words.size(); ++i) {
    for (string word :  words) {

        s.erase(word);

        //for(int i = 0; i< word.size(); ++i){

        int curr = 0;
        for (int j = 0; j < word.size(); ++j) {

            string sub = word.substr(curr, j- curr+ 1);
            if (s.count(sub) != 0) {
                curr = j + 1;

            }
        }


        if (curr == word.size()) {
            res.push_back(word);
        } else {
            s.insert(word);
        }

        //}

    }

    return res;
}



int main(int argc, const char * argv[]) {
    // insert code here...
 vector<string> words =     {"cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"};

    vector<string> ret = findAllConcatenatedWordsInADict(words);
    std::cout << "Hello, World!\n";
    return 0;
}
