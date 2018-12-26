//
//
// @..*
//
//   ..
//  @..
//

#include "stdc++.h"


using namespace std;

// Google's guava library source code.
//https://github.com/google/guava/blob/703ef758b8621cfbab16814f01ddcc5324bdea33/guava-gwt/src-super/com/google/common/collect/super/com/google/common/collect/Iterators.java#L1125
 

class Iterator {
    struct Data;
    Data* data;
public:
    Iterator(const vector<int>& nums);
    Iterator(const Iterator& iter);
    virtual ~Iterator();
    // Returns the next element in the iteration.
    int next();
    // Returns true if the iteration has more elements.
    bool hasNext() const;
};


class PeekingIterator : public Iterator {
public:
    PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        // Initialize any member here.
        // **DO NOT** save a copy of nums and manipulate it directly.
        // You should only use the Iterator interface methods.
        hasPeeked = false;
    }
    
    // Returns the next element in the iteration without advancing the iterator.
    int peek() {
        if (!hasPeeked) {
            peekedValue = Iterator::next();
            hasPeeked = true;
        }
        return peekedValue;
    }
    
    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    int next() {
        if (!hasPeeked)
            return Iterator::next();
        
        hasPeeked = false;
        return peekedValue;
    }
    
    bool hasNext() const {
        if (hasPeeked)
            return true;
        
        if (Iterator::hasNext())
            return true;
        
        return false;
    }
private:
    int peekedValue;
    bool hasPeeked;
};


int main(int argc, const char * argv[]) {
    // insert code here...
  
    
    std::cout << "Hello, World!\n";
    return 0;
}
