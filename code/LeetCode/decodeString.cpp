//
//
// @..*
//
//  Created by Choonghun Lee on 9/11/18.
//  @..
//

#include "stdc++.h"


using namespace std;


string decodeString(string s) {

    int ind = 0;
    stack<char> stk;
    
    list<char> subString;
    list<char> resString;
    list<char> resultString;
    
    string result;
    bool beginingBracket = false;
    bool bracketStarting = false;

   while( ind < s.length()){

        char c = s[ind];
       

       
        if(c != ']'){

            stk.push(c);

        }else{

            while(!stk.empty()){

                char pC = stk.top(); stk.pop();

                if(  pC == '['){

                    beginingBracket = true;
                }
                else
                {

                    if(beginingBracket == true){

                       int r = pC - '0';

                       list<char> subRes;
                        resString.clear();

                       for(int i = 0; i< r; ++i){

                        //   subRes.merge(subString);
                           list<char> tmp(subString.begin(), subString.end());
                        //resString.merge(tmp);
                           resString.insert(resString.end(),subString.begin(), subString.end());

                       }

                        subString = resString;
                        
                       //resString.merge(subRes);
                       beginingBracket = false;
                      //  subString.clear();
                     //  break;

                    }else{

                        subString.push_front(pC);
                    }
                }

            }
            
            bracketStarting = false;
            subString.clear();
            resultString.insert(resultString.end(), resString.begin(), resString.end());
            resString.clear();
            
        }
       
       ++ind;
   }

    for( char c : resultString){
        
        string s(1, c);
        result = result.append(s);
        
    }
    
    vector<char> rem;
    while(!stk.empty()){
        
        char c = stk.top(); stk.pop();
    
        rem.push_back(c);
    }
    
    for(int i=rem.size()-1; i>=0 ;--i){
        
        char c = rem[i];
        string s(1, c);
        result = result.append(s);
    }
    
    
    return result;

}



int main(int argc, const char * argv[]) {
    // insert code here...

   // string s = "3[a]2[bc]";
    //string s = "3[c]2[ba]";
    
    //string s = "3[a2[c]]";
   // string s = "3[a2[c]]";
    
  //  string s = "2[abc]3[cd]ef";

    string s =  "100[leetcode]";
    
    string ret = decodeString(s);

    cout<< ret << endl;
    
    std::cout << "Hello, World!\n";
    return 0;
}
