//
//
// @..*
//
//  Created    on 9/11/18.
//  @..
//

#include "stdc++.h"


using namespace std;


void swapp( string &s,int lo, int hi){

    while( lo < hi){

        swap(s[lo], s[hi]);

        ++lo; --hi;

    }

}

void reverseWords(string &s) {

    int index = 0;
    int n = s.size();

   while( index < n ) {

       if(s[index] == ' '){
           s.erase(index, 1);
           n = s.size();
       }else{
           break;
       }

    //   ++index;
   }

   index = (int)s.size()-1;;

   while( index >= 0  ) {

       if(s[index] == ' '){
           s.erase(index, 1);
            n = s.size();
           
       }else{
           break;
       }

       --index;
   }

    

    
   index = 0;

    while( index < n-1 ) {

       if( s[index] == ' ' && s[index + 1] == ' '){
           s.erase(index + 1, 1);
           n = s.size();
       }else{

       ++index;
       }
   }


    
    int lo = 0; int hi = s.size()-1;
    
    if(lo == hi){
        if(s[lo] == ' ')
            s = "";
        return  ;
    }
    
    if(s.size() == 0)
        return  ;
    




      
  swapp(s, lo, hi);

  int st = 0;
  int e = st;

  while( st < s.size()) {

      while (e < s.size()) {
          if (s[e] != ' ') {
              ++e;
          } else {
              break;
          }
      }

      swapp(s, st, e - 1);
      st = e + 1;
      e = st;
  }
    n = s.size();

}

int main(int argc, const char * argv[]) {
    // insert code here...

    //string s = "  the sky  is blue  ";
    string s = "   a   b ";

    reverseWords(s);
    

    std::cout << "Hello, World!\n";
    return 0;
}
