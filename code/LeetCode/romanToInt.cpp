//
//
// @..*
//
//  Created by Choonghun Lee on 9/11/18.
//  @..
//

#include "stdc++.h"


using namespace std;

 unordered_map<string, int> m{{"M", 1000}, {"CM", 900}, {"D", 500},  {"CD", 400},{"C", 100},
                             {"XC", 90}, {"L", 50},{"XL", 40},  {"X", 10},
                             {"IX", 9},  {"V", 5},{"IV", 4}, {"I", 1}};


 int romanToInt(string s){


     int  ret = 0;
     int index = 0;
     int l = s.size();

     while( index < l){

         string sub = s.substr(index, 2);

         int target;

         if( sub.length() == 2 && m.find(sub) != m.end()){

             target = m[sub];
             
              ++index;
              ++index;

         }else{

           sub =  s.substr(index,1 ) ;
             target = m[sub];
             
              ++index;
         }

        
        ret += target;

     }



     return ret;
 }


string intToRoman( int num) {
    string res = "" ;
    
    vector < int > val{ 1000 , 900 , 500 , 400 , 100 , 90 , 50 , 40 , 10 , 9 , 5 , 4 , 1 };
    vector < string > str{ " M " , " CM " , " D " , " CD " , " C " , " XC " , " L " , " XL " , " X " , " IX " , " V " , " IV " , "I " };
    
    for( int i = 0 ; i < val.size(); ++ i) {
    
        while (num >= val[i]) {
            
            num -= val[i];
            res += str[i];
        }
    
    }
    return res;
}

string intToRoman(int num) {
    
    string dict[13] =
    {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    int val[13] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
    
    string ret;
    
    for(int i=0; i<13; i++) {
        if(num>=val[i]) {
            
            int count = num/val[i];
            num %= val[i];
            
            for(int j=0; j<count; j++) {
                ret.append(dict[i]);
            }
        }
    }
    return ret;
}



int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cout << "Hello, World!\n";
    
    cout<< romanToInt("MCMXCIV") << endl;
    
    
    return 0;
}
