//
//
// @..*
//
//  Created    on 9/11/18.
//  @..
//

#include "stdc++.h"


using namespace std;


void remove(string &str){

    size_t pos = str.find("/*");

    while(pos < string::npos){

        size_t poe = str.find("*/", pos+2);

        if(poe != string::npos){

            if(pos< poe){
                int l = poe+1 - pos + 1;
                //str = str.erase(pos, poe+2);
                str = str.erase(pos, l);
                pos = str.find("/*");
            }
        }else{
            break;
        }
    }


    pos = str.find("//");
    if(pos != string::npos){
        
        size_t poe = str.find("*/", pos+2);
        
         if(poe != string::npos){
             
             str = str.erase(pos, poe-pos);
             
         }else{
        
             str = str.erase(pos);
         }
    }

}

vector<string> removeComments(vector<string>& source) {


   vector<string> res;
   bool foundS = false;
    bool nextMerge = false;

  for(auto str : source) {

      remove(str);
      
      if(str.size() == 0)
          continue;

     if(foundS == false ){

         size_t pos = str.find("/*");

         if(pos != string::npos){

             str = str.erase(pos);
             
             if(pos > 0 )
                 nextMerge = true;
             
             if(str.size()>0)
                        res.push_back(str);
             
                   foundS=true;
                   continue;

         }else{

             res.push_back(str);
         }

     }else{
            size_t poe = str.find("*/");

            if(poe != string::npos){
                  str = str.erase(0, poe+2);
                
                if(str.size() > 0){
                    
                    if(nextMerge){
                        
                        string ss = res.back(); res.pop_back();
                        str = ss + str;
                        nextMerge = false;
                    }
                    
                     res.push_back(str);
                }
                
                
                foundS = false;
                 }

           }
     }


  return res;


}


int main(int argc, const char * argv[]) {
    // insert code here...

 //vector<string>  source = {"/*Test program */", "int main()", "{ ", "  // variable declaration ", "int a, b, c;", "/* This is a test", "   multiline  ", "   comment for ", "   testing */", "a = b + c;", "}"};

   //vector<string>  source =  {"a/*comment", "line", "more_comment*/b"};

   // vector<string>  source =  {"struct Node{", "    /*/ declare members;/**/", "    int size;", "    /**/int val;", "};"};
  // vector<string>  source =  {"main() {", "/* here is commments", "  // still comments */", "   double s = 33;", "   cout << s;", "}"};
    
     vector<string>  source =  {"main() {",
                                "  Node* p;",
                                "  /* declare a Node",
                                "  /*float f = 2.0",
                                "   p->val = f;",
                                "   /**/",
                                "   p->val = 1;",
                                "   //*/ cout << success;*/",
                                "}",
                                " "};
#if 0
    
                                ["main() {",
                                "  Node* p;",
                                 "  ",
                                 "   p->val = 1;",
                                 "   ",
                                 "}",
                                 " "]
#endif
    
  vector<string> res = removeComments(source);

    std::cout << "Hello, World!\n";
    return 0;
}
