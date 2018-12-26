//
//
// @..*
//
//  Created by Choonghun Lee on 9/11/18.
//  @..
//

#include "stdc++.h"


using namespace std;


list *add(list *l1, list *l2, int gap){

   list res;

   for(int i=0;i<gap;++i){

       list<int>::iterator it = l1->end();
       it;
       int last = *it;

       res.push_front(last);

   }

    int m = l1->size();
    int n = l2->size();

    while(m > 0 || n > 0){

      list<int>::iterator it1;
        if(m>0) {
            = l1->end();
            it;
            int last = *it;
        }


    }




}


string multiply(string num1, string num2) {

    int m = num1.size();
    int n = num2.size();


    for(int i=0; i<n ;i++) {

        list <int>lis;
        int carry= 0;

        for (int j = 0; j < m; j++) {

           int a =  (num1[j] + '0');
           int b =  (num2[i] + '0');

           int res = a*b + carry;
           carry = res/10;
           res = res %10;

           lis.push_front(res) ;

        }

        if(carry>0)
            lis.push_front(carry);

    }

}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cout << "Hello, World!\n";
    return 0;
}
