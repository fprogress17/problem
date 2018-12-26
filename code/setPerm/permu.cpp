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
vector<bool> visited;

void allPerm(vector<int> a, vector<int> &path, vector<bool> &visited){

    if(a.size() == path.size())
    {
        res.push_back(path);
        return;
    }

    for( int i=0; i< a.size();++i){
        if(visited[i] == false){

            path.push_back(a[i]);
            visited[i] = true;

            allPerm(a, path, visited);

            path.pop_back();
            visited[i] = false;

        }

    }

}


void perm(vector<int> a,int toPick, vector<int> &path, vector<bool> &visited){
    
    if(toPick == 0)
    {
        res.push_back(path);
        return;
    }
    
    for( int i=0; i< a.size();++i){
        if(visited[i] == false){
            
            path.push_back(a[i]);
            visited[i] = true;
            
            perm(a,toPick - 1, path, visited);
            
            path.pop_back();
            visited[i] = false;
            
        }
        
    }
    
}


void permuWithRepeat(vector<int> a, vector<int> &path, vector<bool> &visited){

    if(a.size() == path.size())
    {
        res.push_back(path);
        return;
    }

    for( int i=0; i< a.size();++i){
        if(visited[i] == false){

            if( i > 0 && a[i-1] == a[i] && visited[i-1] == false)
                continue;

            path.push_back(a[i]);
            visited[i] = true;

            permuWithRepeat(a, path, visited);

            path.pop_back();
            visited[i] = false;
        }
    }
}



int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> a = {0,1,2,3};
    visited.resize(a.size(), false);
    vector<int> path;

#if 0
     allPerm(a, path, visited);
#endif
    
#if 1
    
    perm(a, 3, path, visited);
    
#endif

#if 0
    path.clear();
    visited.clear();

  //  vector<int> aa = {0,1,1,3};
    vector<int> aa = {1,1,2};
    permuWithRepeat(aa, path, visited);

#endif
    
    for(int i = 0; i<res.size();++i){
        for(int j=0; j< res[i].size(); ++j){
            printf("%d", res[i][j]);
        }
        printf("\n");
    }

    std::cout << "Hello, World!\n";
    return 0;
}
