//
//
// @..*
//
//  Created    on 9/11/18.
//  @..
//

#include <iostream>
#include <vector>

using namespace std;

int numRow;

vector<vector<char>>  res;
string fin;


vector<char> placeColumn(string str, int numRow){
    
    vector<char> target;
    for(int i=0; i< numRow; ++i){
        target.push_back(str[i]);
    }
    
    return target;
}

vector<char> placePoint(char a, int index, int numRow){
    vector<char> target;
    for(int i=0; i< numRow; ++i){
        if(i == index){
            target.push_back(a);
        }
        else{
            target.push_back(' ');
        }
    }
    
    return target;
    
}


string zigZagconversion(string str, int numRow){
    
    
    for(int i=0; i< str.length()/numRow;++i){
        
        if(i % numRow == 0){
    
            vector<char> ret = placeColumn(str.substr(i*numRow, numRow), numRow);
            res.push_back(ret);
        }else{
        
            string target = str.substr(i*numRow, numRow);
            
            for(int j=0; j< numRow; ++j){
                vector<char> ret = placePoint(target[j],numRow-j, numRow);
                res.push_back(ret);
                
            }
        }
        
    }
    
    int m = res.size();
    int n = res[0].size();
    
    for(int j=0;j <n;++j)
        for(int i=0; i< m; ++j){
            
            if(res[i][j] != ' ')
                fin.push_back(res[i][j]);
        }
    
    return fin;
    
}






int main(int argc, const char * argv[]) {
    // insert code here...
    
    
    std::cout << "Hello, World!\n";
    return 0;
}


