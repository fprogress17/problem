//
//
// @..*
//
//  Created by Choonghun Lee on 9/11/18.
//  @..
//

#include "stdc++.h"


using namespace std;

vector<vector<int>> res;

void subSet(vector<int> &a, vector<int>&path, vector<vector<int>> &res){

    if(path.size() == a.size()){

        res.push_back(path);
        return;
    }

    for(int i=0; i< a.size(); ++i)
    {
        path.push_back(a[i]);
        subSet(a, path, res);
        path.pop_back();
    }
}


// all subsets
void allSubSet(vector<int> &a, int index, vector<int>&path, vector<vector<int>> &res){

   res.push_back(path);

    for(int i=index; i< a.size(); ++i)
    {
        path.push_back(a[i]);
        allSubSet(a, i + 1,  path, res);
        path.pop_back();
    }
}

// length of k from all subset
// equal to pick k from n
//
void subSet(vector<int> &a, int index, int toPick, vector<int>&path, vector<vector<int>> &res){
    
    if(toPick == 0){

        res.push_back(path);
        return;
    }

    for(int i=index; i< a.size(); ++i)
    {
        path.push_back(a[i]);
        subSet(a, i + 1, toPick - 1,  path, res);
        path.pop_back();
    }
}



// all subsets with repeat
void subSetWithRepeat(vector<int> &a, int index, vector<int>&path, vector<vector<int>> &res){

   res.push_back(path);

    for(int i=index; i< a.size(); ++i)
    {
        if(i>0 && a[i] == a[i-1])
            continue;

        path.push_back(a[i]);
        subSetWithRepeat(a, i + 1,  path, res);
        path.pop_back();
    }
}


void subSet3(vector<int> &a, int index, vector<int>&path, vector<vector<int>> &res){
    
    // if(path.size() == a.size()){
    
    res.push_back(path);
    //  return;
    // }
    
    for(int i=index; i< a.size(); ++i)
    {
        path.push_back(a[i]);
        subSet3(a, index + 1,  path, res);
        path.pop_back();
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...

   //vector<int> a = {0,1,2,3,4,5};
    //vector<int> a = {0,1,2};
    vector<int> a = {1,2,3};
   vector<int> path;

   //subSet(a, path,res );
   subSet2(a, 0, 1, path,res );

    for(int i = 0; i<res.size();++i){
        for(int j=0; j< res[i].size(); ++j){
            printf("%d", res[i][j]);
        }
        printf("\n");
    }
    
    std::cout << "Hello, World!\n";
    return 0;
}
