//
//
// @..*
//
//  Created by Choonghun Lee on 9/11/18.
//  @..
//

#include "stdc++.h"


using namespace std;

vector<int>v;
//
//RandomizedSet() {
//
//}

/** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
bool insert(int val) {

   if(find(v.begin(), v.end(), val) == v.end()){
       v.push_back(val);
       return true;
   }

   return false;
}

/** Removes a value from the set. Returns true if the set contained the specified element. */
bool remove(int val) {

    vector<int>::iterator it = find(v.begin(), v.end(),val);
    if( it == v.end()){
       return false;
    }

    int tmp = v[v.size()-1];

    *it = tmp;

    v.pop_back();

    return true;

}

/** Get a random element from the set. */
int getRandom() {

    return v[rand()%v.size()];

}


int main(int argc, const char * argv[]) {
    // insert code here...
   bool res = insert(0) ;
   res = remove(2) ;
   res = insert(2) ;
   int r = getRandom();
   res = remove(1) ;
   res = insert(2) ;
    r = getRandom();
    std::cout << "Hello, World!\n";
    return 0;
}
