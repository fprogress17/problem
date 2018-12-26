//
//
// @..*
//
//  Created    on 9/11/18.
//  @..
//

#include "stdc++.h"


using namespace std;


static bool isnum(string s){
    return (s[s.find(' ')+1]<='9' && s[s.find(' ')+1]>='0');
}
static bool cmp(const string& s1,const string& s2){
    return  s1.substr(s1.find(' ')) < s2.substr(s2.find(' '));
}
vector<string> reorderLogFiles(vector<string>& logs) {
    
    vector<string>vnum,vletter;
    
    for(auto str :logs)
        if(isnum(str))
            vnum.push_back(str);
        else
            vletter.push_back(str);
    
    sort(vletter.begin(),vletter.end(),cmp);
    
    vletter.insert(vletter.end(),vnum.begin(),vnum.end());
    
    return vletter;
}

//链接：https://www.jianshu.com/p/07e21b554855



int main(int argc, const char * argv[]) {
    // insert code here...
  
    vector<string> a = {"a1 9 2 3 1","g1 act car","zo4 4 7","ab1 off key dog","a8 act zoo"};
    
    vector<string> r = reorderLogFiles(a);
    
    std::cout << "Hello, World!\n";
    return 0;
}
