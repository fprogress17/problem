//
//
// @..*
//
//   ..
//  @..
//

#include "stdc++.h"


using namespace std;
#if 0

 some example. If given 4321,

4321    k=1 -->    321
4321    k=2 --> 21
4321    k=3 --> 1
If given 2341,

2341    k=1 --> 231
2341    k=2 --> 21
2341    k=3 --> 1

From the previous examples,
if the number is decreasing, we remove the first one;
if the number is increasing, we remove the last one.

#endif

string removeKdigits(string num, int k) {
    
    if( k >= num.size() )
        return string("0");
    
    num += '0';
    
    vector<char> vec;
    
    for( int i=0; i<num.size(); i++ ){
        while( !vec.empty() && num[i] < vec.back() && k ){
            k--;
            vec.pop_back();
        }
        vec.push_back( num[i] );
    }
    
    string ans;
    for( int i=0; i<vec.size()-1; i++ ){
        if( !ans.empty() || vec[i]!='0' )
            ans += vec[i];
    }
    return ans.empty() ? "0" : ans;
}



/* the following didnt pass

Input
"10"
2
Output
""
Expected
"0"
 */

string removeKdigits2(string num, int k) {
    
    if(k == 0)
        return num;
    
    int inx = 0;
    while(num.size() > 0 && k > 0){
        
        if(num.size() > 1 && num[inx] >= num[inx+1] ){
            
            num = num.substr(inx+1,num.size()-1);
            --k;
        }else if(num.size() > 1 ){
            
            int tInx = inx;
            while(num[tInx] < num[tInx+1]){
                tInx++;
            }
            
            num = num.substr(inx, tInx- inx ) + num.substr(tInx+1,num.size()- 1 -inx + 1 );
            --k;
            
            
        }else  {
            
            
                num = "";
           
            
        }
        
        while(num[0] == '0' && num.size() != 1){
            num = num.substr(1, num.size()-1);
        }
        
    }
    
    while(num[0] == '0' && num.size() != 1){
        num = num.substr(1, num.size()-1);
    }
    
    
    return num;
}



int main(int argc, const char * argv[]) {
    // insert code here...
    //string num = "1432219"; ///k=3
     //string num = "10200";  // k=1
     //string num = "10";  // k=2
    string num = "10200"; // k = 1;
    
    
    int k = 1;
    
    string ret = removeKdigits(num,k);
    std::cout << "Hello, World!\n";
    return 0;
}
