//
//
// @..*
//
//  Created    on 9/11/18.
//  @..
//

#include "stdc++.h"


using namespace std;

class NestedInteger {
       public:
         // Return true if this NestedInteger holds a single integer, rather than a nested list.
         bool isInteger() const;

       // Return the single integer that this NestedInteger holds, if it holds a single integer
       // The result is undefined if this NestedInteger holds a nested list
       int getInteger() const;

         // Return the nested list that this NestedInteger holds, if it holds a nested list
         // The result is undefined if this NestedInteger holds a single integer
         const vector<NestedInteger> &getList() const;
  };


    list<NestedInteger> lis;


///// for NestedIterator2, in the constructor, all int data extracted and put into list<int>
////  compared with NestedIterator, initialy list has all memory for int data
///   this one passed Leetcode judge

class NestedIterator2 {
public:

    list<int> lisI;
 
    void pushAll(vector<NestedInteger> l){

            for(int i=0;i<l.size(); ++i)
            {
                NestedInteger n = l[i];

                if(n.isInteger()){
                    lisI.push_back(n.getInteger());
                }else{
                    pushAll(n.getList()) ;
                }
            }
    }

    // if in the constructor, if we want unpack all
    // then recursive needed

    NestedIterator2(vector<NestedInteger> &nestedList) {

            for(int i=0;i<nestedList.size(); ++i)
        {
            NestedInteger n = nestedList[i];

             if(n.isInteger()){
                lisI.push_back(n.getInteger());
            }else{

                 pushAll(n.getList());
            }
        }
    }

    int next() {


        int n = lisI.front();
        lisI.pop_front();
        return n;


    }

    bool hasNext() {

        if( lisI.size() != 0)
            { return true;}

            return false;

    }

};


/// this one got memory llimit exceed fro [[1,1],2,[1,1]]
///  compared with NestedIterator2, this one needs less memory since when it meets the nestedList, then it extracts
/// put it list
////
class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {

            for(int i=0;i<nestedList.size(); ++i)
        {
            NestedInteger n = nestedList[i];

               lis.push_back(n) ;
        }
 
    }
    
    int next() {


        NestedInteger n = lis.front();
        lis.pop_front();
        return n.getInteger();


    }
    
    bool hasNext() {

        while( lis.size() != 0) {

            NestedInteger n = lis.front();

            if (n.isInteger()) {
                return true;
            }

            for (int i = 0; i < n.getList().size(); ++i) {
                lis.push_back(n.getList()[i]);
            }
        }

        return false;

    }

};


int main(int argc, const char * argv[]) {
    // insert code here...
    
    
    std::cout << "Hello, World!\n";
    return 0;
}
