//
//
// @..*
//
//   ..
//  @..
//

#include "stdc++.h"


using namespace std;

 
var judgeCircle = function(moves) {
    var x = 0;
    var y = 0;
    for(var i = 0; i < moves.length; i++){
        
        if(moves.charAt(i) === 'R'){
            x++;
        }
        if(moves.charAt(i) === 'L'){
            x--;
        }
        if(moves.charAt(i) === 'U'){
            y++;
        }
        if(moves.charAt(i) === 'D'){
            y--;
        }
    }
    if( x===0 && y===0){
        return true;
    }
    else{return false;}
};


int main(int argc, const char * argv[]) {
    // insert code here...
  
    
    std::cout << "Hello, World!\n";
    return 0;
}
