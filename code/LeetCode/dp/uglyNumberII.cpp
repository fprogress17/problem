//
//
// @..*
//
//  Created by Choonghun Lee on 9/11/18.
//  @..
//

#include "stdc++.h"


using namespace std;




int nthUglyNumber(int n) {

    //vector<int> v(n+1, 0);
    vector<int> v;
    //v[0] = 1;
    v.push_back(1);


    int c2 = 0;
    int c3 = 0;
    int c5 = 0;

    int n2 = v[c2]*2;
    int n3 = v[c3]*3;
    int n5 = v[c5]*5;

    for(int i = 1; i<= n;++i)
    {

        int res = min( min(n2, n3), n5);

        v.push_back(res);


        if(res == n2){

           c2++;
           n2 = v[c2]*2;

        }

        if(res == n3){

           c3++;
           n3 = v[c3]*3;

        }


        if(res == n5){

           c5++;
           n5 = v[c5]*5;

        }

        cout<< res << endl;
    }
    

    return v[n-1]    ;
}



int main(int argc, const char * argv[]) {
    // insert code here...
    
    int res = nthUglyNumber(10);
    
    std::cout << "Hello, World!\n";
    return 0;
}
