//
//
// @..*
//
//  Created    on 9/11/18.
//  @..
//

#include "stdc++.h"


using namespace std;

string digits = "abc";
vector<char> diChar = {'a','b','c'};
vector<string> res;

//int distinctSubseqII(string S) {
//
//}

void generate(string prices, bool taken[15]){
    
    if(prices.size() == digits.size()){
        
        cout<< prices << endl;
        return;
    }

    for(int i=0;i<digits.size(); ++i)
    {
        if(taken[i])
            continue;
        
        taken[i] = true;
        generate(prices + digits[i], taken);
        taken[i] = false;
    }
}


void subset(string prices, int index){
    
    if(index == digits.size()){
        cout << prices << endl;
        return;
    }

    subset(prices, index + 1);

    subset(prices+ digits[index], index + 1);

}

void subsetBackTracking(string prices, int index){


    if(index == digits.size()){
        cout << prices << endl;
        return;
    }

  

    for(int i = index; i< digits.size(); ++i)
    {
        
     //   res.push_back(prices);
           //cout << prices << endl;
        prices = prices + digits[i];
        //subsetBackTracking(prices + digits[i], index+1);
        subsetBackTracking(prices, index+1);
        prices.erase(prices.end()-1);

      // cout << prices << endl;
    }
}


void subsetBackTrackingVector(vector<char> &resv, int index){
    
    
   // if(index == digits.size()){

//        for(int i=0;i < resv.size(); ++i)
//            cout << resv[i] << " " ;
//            cout<< endl;
     //   return;
    //}
    
    
    
    for(int i = index; i< diChar.size(); ++i)
    {
        for(int j=0;j < resv.size(); ++j)
            cout << resv[j] << " " ;
        cout<< endl;
        //   res.push_back(prices);
        //cout << prices << endl;
        char c =  diChar[i];
        resv.push_back(c);
        subsetBackTrackingVector(resv, index+1);
        resv.pop_back( );

        // cout << prices << endl;
    }
}

  //vector<char> a = {'1','2','3'};
//string a = "123";
string a = "aab";

//// this is wrong for repeated element for all set
/// for a = "aab"
/// the output is "a", "ab", "b" which is missing "aa", "aab"
///
void allSubSet(  int index, string path ){
    
   
    
    
            for(int j=0;j < path.size(); ++j)
                cout << path[j] << " " ;
    
    cout<< endl;
    
    for(int i=index; i< a.size(); ++i)
    {
        
        //// this part is wrong for repeated element for all set
        if(i>0 && a[i] == a[i-1])
            continue;
      
        allSubSet( i + 1,  path + a[i]);
      
    }
}


 int distinctSubseqII(string S) {


     unordered_map<char, int> m;
     
     for(int i=0;i<S.size(); ++i){
         
         char c = S[i];
         m[c]++;
     }
     
     
     vector<pair<char,int>> repCharCnt;
     unordered_map<char,int>::iterator it = m.begin();
     int oneCount = 0;
     int nunOneCount = 1;
     
     bool allOnes = false;
     
     if(m.size() == 1)
     {
         return m.begin()->second;
     }
     
     for(;it!=m.end(); ++it){
         
         if(it->second != 1){
             //        repCharCnt.push_back(make_pair(m.first, m.second)) ;
             
             nunOneCount = ( nunOneCount%((int)pow(10,9) + 7) * (it->second + 1)%((int)pow(10,9)+ 7)) %((int)pow(10,9) + 7);
             
         }else{
             ++oneCount;
         }
     }
     
     if(oneCount == S.size()){
         allOnes = true;
     }
     
     // oneCount = (2^oneCount)%(10^9 + 7);
     oneCount = (int)pow(2,oneCount)%( (int)pow(10,9) + 7);
     nunOneCount =   (nunOneCount%((int)pow(10,9) + 7));
     
     nunOneCount = (oneCount * nunOneCount) % ((int)pow(10,9) + 7) ;
     
     
     if(!allOnes){
         
         return nunOneCount - 1;
     }
     
     return nunOneCount  ;
 

}


int main(int argc, const char * argv[]) {
    // insert code here...
    
  
    string path;
    vector<vector<char>> ress;
    
    //string S = {"1223345"};
    // string S = {"12345"};
     //string S = {"211"};
    string S = {"123"};
    
    int ret = distinctSubseqII( S);
    
    allSubSet( 0,path);
    
//    for(int i=0;i < ress.size(); ++i){
//        vector<int> r = ress[i];
//
//        for(int j=0;j < r.size(); ++j)
//            cout << r[j] << " " ;
//
//        cout<< endl;
//
//    }
 
    
    
    string target;
    bool taken[15];
    vector<char> targetV;

    memset(taken, 0, sizeof(taken));
    
    //generate(target,taken);

    //subset(target, 0);
    //subsetBackTracking(target, 0);
    subsetBackTrackingVector(targetV, 0);

    for(int i=0;i < res.size(); ++i){
        cout<< res[i] << endl;
    }
    
    std::cout << "Hello, World!\n";
    return 0;
}
