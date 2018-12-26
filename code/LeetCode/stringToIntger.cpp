//
//
// @..*
//
//  Created by Choonghun Lee on 9/11/18.
//  @..
//

#include "stdc++.h"


using namespace std;

int myAtoi(string str) {
    
    
    int index = 0;
    int n = str.size();
    int minus = false;
    
    while(index < n){
        
        if( str[index] == ' '){
            ++index;
        }else{
            break;
        }
        
    }
    
    if(index == n){
        return 0;
    }
    
    if(str[index] == '-'){
        ++index;
        minus = true;
        
    }

    if(str[index] == '+'){
        ++index;
        
        if(minus)
            return 0;
        
        
    }
    
    if(!(str[index] >= '0' &&  str[index] <= '9' )){

        return 0;
    }

    str = str.erase(0,index);
    index = 0;
    n = str.size();

    while(index < n){
        if(str[index] >= '0' &&  str[index] <= '9' ){

        }else{
            break;
        }


        ++index;
    }

    str = str.substr(0, index);


    double res = 0;
    n = str.size();

    index = 0;

    while(index < n){

        res *= 10;
        res += double(str[index] - '0');
        ++index;
    }

    if(minus){
        res = -res;

        if(res <= INT_MIN)
            return INT_MIN;

        return res;
    }


    if(res >= INT_MAX)
        return INT_MAX;

    return (int)res;

 
    
    
}


int myAtoi2(string str) {


    int index = 0;
    int n = str.size();
    int minus = false;

    while(index < n){

       if( str[index] == ' '){
           ++index;
       }else{
           break;
       }

    }

   if(index == n -1){
       return 0;
   }

   if(str[index] == '-'){
       ++index;
      minus = true;
   }

  if( str[index] < '0' ||  str[index] > '9' ){

      return 0;
  }


  str = str.substr(index);

  index = 0;
  n = str.size();

  while(index < n){

      if( str[index] >= '0' &&  str[index] <= '9' ) {
        ++index;
      }else{
          break;
      }
  }

  str = str.substr(0, index + 1);
  n = str.size();
  if(str.size() == 0){
      return 0;
  }


  if( minus == false){

      int mx = INT_MAX;
      int count = 0;

      while( mx > 0){

          mx = mx/10;
          ++count;
      }

      if( n > count )
      {
          return INT_MAX;
      }

      if( n == count){
          int i = 0;
          int cnt = n;
          while( n > 0){

              if( str[i] - '0' > INT_MAX/pow(10,n-1)){
                  return INT_MAX;
              }else{

                  ++i;
                  --n;
              }
          }
      }

  }else{

      int mx = INT_MIN;
      int count = 0;

      while( mx != 0){

          mx = mx/10;
          ++count;
      }

      if( n > count )
      {
          return INT_MIN;
      }

      if( n == count){
          int i = 0;
          int cnt = n;
          while( n > 0){

             if( str[i] - '0' > INT_MIN/pow(10,n-1)){
                  return INT_MIN;
              }else{

                  ++i;
                  --n;
              }
          }
      }



      if( n == count){
          int i = 0;
          int cnt = n;
          while( n > 0){

             if( str[i] - '0' == INT_MIN/pow(10,n-1)){
                  ++i;
                  --n;
              }
          }

          if(cnt == i)
              return INT_MIN;
      }


  
  }

    index = 0;
    n = str.size();
    int res = 0;
    
    while(index < n){
        
        res = res * 10;
        res += str[index] + '0';
        
    }
    
    if(minus)
        res *= -1;
    
    return (int)res;
}


int main(int argc, const char * argv[]) {
    // insert code here...
   // string s = "   -42";
     //string s = "1";
      //string s = "+1";
       string s = "-+1";
    //string s = "-4193 with words";
   // string s = "words and 987";
   // string s = "-91283472332";
    
   int res = myAtoi(s);
    std::cout << "Hello, World!\n";
    return 0;
}
