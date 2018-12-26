//
//
// @..*
//
//   ..
//  @..
//

#include "stdc++.h"

//valid Parenthesis String

using namespace std;
#if 0
So when can the asterisk be used as parentheses?
Let's look at two examples *) and *( ,
in the first case, the asterisk can be used as the left parenthesis,
and in the second case, The asterisk is the left parenthesis, the right parenthesis, or the empty, * (all are wrong.
Of course, this situation is limited to the positional relationship between the asterisk
and the left parenthesis, and as long as the asterisk is in front of the right parenthesis, it must be eliminated.
Right parenthesis. Then we use two stacks to store the position of the left parenthesis
and the asterisk respectively, traverse the string, press the star stack star when encountering the asterisk,
and press the left parenthesis stack when the left parenthesis is encountered.
#endif

bool checkValidString( string s) {
    
    stack<int> left;
    stack<int> star;  // stack int not char, ie. put the index of left and star
    
    for ( int i = 0 ; i < s.size(); ++ i) {
    
        if (s[i] == '*' )
            star.push(i);
        else  if ( s[i] == '(' )
            left.push(i);
        else {
            
            if (left.empty() && star.empty())
                return  false ;
            
            if (!left.empty())
                left.pop() ;
            else star.pop();
        }
    }
    
#if 0
When the loop is over, we want to have no extra left parenthesis in the left,
even if there is, we can try to use the asterisk to offset,
when both star and left are not empty, loop,
if The top left bracket of the left stack is at st Ar on the right side of the stack asterisk,
then it constitutes * (pattern,
directly returns false;
otherwise it means that the asterisk can offset the left parenthesis, each pop an element.
#endif
                                                                                                                                                                                                                                                                                                                   
    while (!left.empty() && ! star.empty()) {
        
        int a = left.top();
        int b = star.top();
        
        if(a > b)
        
        //if (left.top() > star.top())     // check if left index is greater than index of star ie. left is right of star or not
            return  false ;
        
        left.pop();
        star.pop();
    }
    
    return left.empty();
}


int main(int argc, const char * argv[]) {
    // insert code here...
    
    //bool ret = checkValidString("()(*") ;
    bool ret = checkValidString("()(*") ;
   
    std::cout << "Hello, World!\n";
    return 0;
}
