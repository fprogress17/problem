//
//
// @..*
//
//  Created by Choonghun Lee on 9/11/18.
//  @..
//

#include "stdc++.h"


using namespace std;

string path;
vector<string> res;

vector<string> keypad{" ", "", "abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

void pad(vector<int> num, int index, string path){

    if(index == num.size()){
        printf("%s\n", path.c_str());
        return;
    }

    // not this
    // for(i = index ; i < n; ++i
    // ....

    int wordIndex = num[index];
    string word = keypad[wordIndex];
    for(int i=0;i <word.size(); ++i){

        char c = word[i];
        string cs = string(1,c);
        pad(num, index + 1, (path + cs));
    }

}


int main(int argc, const char * argv[]) {
    // insert code here...
    
    pad({2,3}, 0, path);
    
    std::cout << "Hello, World!\n";
    return 0;
}
