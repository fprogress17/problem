//
//
// @..*
//
//  Created    on 9/11/18.
//  @..
//

#include "stdc++.h"


using namespace std;

vector<int>pidd;
vector<int>ppidd;

int bsearch(int t){
    
    int lo = 0;
    int hi = ppidd.size()-1;
    
    while(lo<=hi){
        
        int mid = (lo+hi)/2;
        
        if(ppidd[mid] == t){
            return mid;
        }
        
        if(ppidd[mid] < t ){
            lo = mid+1;
        }
        else{
            hi = mid - 1;
        }
        
    }
    
    return -1;
}

vector<int> getChildWith(int parent){
    
    
    vector<int>children;
    
    //children.push_back(parent);
#if 1
    for(int i=0; i< ppidd.size(); ++i){
        
        if(ppidd[i] == parent){
            
            children.push_back(pidd[i]);
            
            vector<int> ret = getChildWith(pidd[i]);
            
             children.insert(children.end(), ret.begin(), ret.end());
//            for(int j = 0; j< ret.size();++j )
//            {
//                children.push_back(ret[j]);
//            }
            
        }
    }
#else
    
    int child = bsearch(parent);
    
    if(child == -1)
    {
        vector<int> a;
            return a;
    }
    
    children.push_back(pidd[child]);
    
    if(ppidd[child] == 0){
        
        vector<int> a(pidd.begin()+1, pidd.end());
        
        return a;
    }
    
    vector<int> ret = getChildWith(pidd[child]);
    
    children.insert(children.end(), ret.begin(), ret.end());
//    for(int j = 0; j< ret.size();++j )
//    {
//        children.push_back(ret[j]);
//    }
    
    
#endif
    
    
    return children;
    
}

vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
    
    int killCount = 0;
    for(int i =0; i< ppid.size() ; ++i){
        
        if(ppid[i] == kill)
            ++killCount;
    }
    
    if(killCount == 0){
        vector<int> a = {kill};
        return a;
    }
    
    int zIndex = -1;
    for(int i =0;i < ppid.size(); ++i){
        if( ppid[i] == 0){
            zIndex = i;
        }
    }

if(zIndex != -1){
    
    int v = pid[zIndex];
    int count = 0;
    for(int i=0; i< ppid.size(); ++i){
        if(ppid[i] == v){
            ++count;
        }
    }
    
    if(count == ppid.size() -1 ){
        return pid;
    }
}
    
    vector<int> ret = getChildWith(kill);
    
    return ret;
    
    
    
    
}


int main(int argc, const char * argv[]) {
    // insert code here...
    
//    vector<int>pid = {1,3,10,5};
//    vector<int>ppid = {3,0,5,3};
//
    vector<int>pid = {1,2,3,4,5};
    vector<int>ppid = {0,1,1,1,1};  //1

//
//    vector<int>pid = {1, 3,10,5};
//    vector<int>ppid = {3,0,5,3}; //5 - > 5, 10
////
    pidd = pid;
    ppidd = ppid;
    
    vector<int> ret = killProcess(  pid,  ppid, 1);
    
    ret.push_back(1);
    std::cout << "Hello, World!\n";
    return 0;
}
