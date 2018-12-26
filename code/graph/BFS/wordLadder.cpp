//
//
// @..*
//
//  Created by Choonghun Lee on 9/11/18.
//  @..
//

#include "stdc++.h"


using namespace std;

int minDistance = INT_MAX;
vector<string> res;

vector<string> dic = { "hot", "dot", "dog", "lot", "log"};

queue<string> q;
map<string, bool> visited;
map<string, int > distanceMap;

int wordLadder(string s, string e, int index, int dist){


    q.push(s);

    for(string word : dic){
        visited[word] = false;
        distanceMap[word] = 1;
    }

    while(!q.empty()){

        string w = q.front(); q.pop();
        dist = distanceMap[w];

    for (int i = 0; i < s.size() ; ++i) {

        for(int j=0;j< 26; ++j){

            w[j] = 'a' + j;

           if(w == s){
               minDistance = min(minDistance, dist + 1);
               return minDistance;
           }

           if(find(dic.begin(), dic.end(), w) == dic.end()){
               continue;
           }

          if(visited[w] == false){
               visited[w] = true;

               distanceMap[w] = dist + 1;
               q.push(w);
           }


        }

    }
   }

   return -1;
}

#if false
void wordLadder(string s, string e, int index, int dist){

    if(index == s.size()){
        return ;
    }

    for(int i=0;i< 26; ++i){

        s[index] = 'a' + i;

       if(s == e) {

           minDistance = min(minDistance, dist);
           printf("%s", s.c_str());
           printf("%d", minDistance );
           return;

       }

        if(find(dic.begin(), dic.end(), s) == dic.end())
            continue;

        wordLadder(s, e, index + 1, dist + 1);
    }

}
#endif
//
//void wordLadder(string s, string e, int index, int dist){
//    
//    if(s  == e ){
//        
//        minDistance = min(minDistance, dist);
//        printf("%s", s.c_str());
//        return;
//        
//    }
//    
//    if(index == s.size()){
//        return ;
//    }
//    
//    
//    char c = s[index];
//    
//    for(string w : dic){
//        
//        s[index] = w[index];
//        
//        wordLadder(s, e, index + 1, dist + 1);
//        
//    }
//    
//}

int main(int argc, const char * argv[]) {
    // insert code here...


    //wordLadder("hit", "cog", i, 0);
    wordLadder("hit", "cog", 0, 0);
    
    std::cout << "Hello, World!\n";
    return 0;
}
