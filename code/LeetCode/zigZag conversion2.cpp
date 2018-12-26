//
//
// @..*
//
//  Created by Choonghun Lee on 9/11/18.
//  @..
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> indexA;

int getIndex(int i ,int r){

    int ret ;
   int k =  i % (r+r -2);
       ret = indexA[k];
    return  ret;

}

string convert(string s, int numRows) {
    
    vector<string>res (numRows);
    indexA = vector<int>(2*numRows);
    
    if(s.size() == 1)
        return s;

    if(numRows == 1)
        return s;

    indexA[0] = 0;
    for(int i =1;i <  numRows + numRows -2; ++i){

        if(i < numRows)
            indexA[i] = indexA[i-1] + 1;
        else
            indexA[i] = indexA[i-1] - 1;
    }

    for(int i = 0;i< s.size();++i){

        int index = getIndex(i, numRows);
        char c = s[i];

        res[index] += c;

    }

    string ret = "";

   for( string str : res){

       ret += str;


   }

    return  ret ;
    
}




int main(int argc, const char * argv[]) {
    // insert code here...

    string st = "PAYPALISHIRING";

 //   string ret = convert(st, 3);
       string ret = convert("a", 1);

    if(ret != "PAHNAPLSIIGYIR")
        cout<< " wrong" << endl;

    
    std::cout << "Hello, World!\n";
    return 0;
}


