//
//
// @..*
//
//  Created by Choonghun Lee on 9/11/18.
//  @..
//

#include "stdc++.h"


using namespace std;

int cap ;

/*
LRUCache(int capacity) {
    
}
*/

map<int, int> m;
list<int> lis;


int get(int key) {


    if(m.find(key) == m.end())
        return -1;

    int val  = m[key];

    lis.remove(val);
    lis.push_front(val);

    return val;

}

void put(int key, int value) {

   if(lis.size() == cap){


       int tar = *(--lis.end());
       lis.pop_back();


       map<int,int>::iterator it = m.begin();
     

       for(;it!= m.end();++it){

           if(it->second == tar){
              
              break;
           }

       }

       m.erase(it);

   }

       m[key] = value;

       lis.push_front(value);


}



int main(int argc, const char * argv[]) {
    // insert code here...

    cap = 2;

    put(1, 1);
    put(2, 2);
   int ret =  get(1);       // returns 1
    put(3, 3);    // evicts key 2
    ret =get(2);       // returns -1 (not found)
    put(4, 4);    // evicts key 1
    ret =get(1);       // returns -1 (not found)
    ret =get(3);       // returns 3
    ret =get(4);
    
    std::cout << "Hello, World!\n";
    return 0;
}
