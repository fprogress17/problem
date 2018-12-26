//
//
// @..*
//
//  Created by Choonghun Lee on 9/11/18.
//  @..
//

#include "stdc++.h"

//https://yeqiuquan.blogspot.com/2017/06/418-sentence-screen-fitting.html
using namespace std;

int wordsTyping(vector<string>& sentence, int rows, int cols) {

    vector<int> next(sentence.size());
    vector<int> times(sentence.size());

    for(int i =0; i< sentence.size(); ++i){
        int curr = i;
        int col = 0;
        int time = 0;

        while(col + sentence[curr].size() <= cols){

           col = col + sentence[curr].size() + 1;

            curr++;

            if(curr == sentence.size()){
                curr = 0;
                time++;
            }


        }

        next[i] = curr;
        times[i]= time;


    }

    int res = 0;
    int curr = 0;

    for(int i  =0; i< rows; ++i){
        res += times[curr];
        curr = next[curr];
    }

    return  res;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cout << "Hello, World!\n";
    return 0;
}
