//
//
// @..*
//
//  Created    on 9/11/18.
//  @..
//

#include "stdc++.h"


using namespace std;


 struct Interval {
         int start;
         int end;
         Interval() : start(0), end(0) {}
         Interval(int s, int e) : start(s), end(e) {}
     };


bool comparator(Interval a, Interval b) {

    if(a.start < b.start)
        return true;

    if(a.start == b.start)
        return a.end < b.end ;
    
    return false;
}


bool comparator2(Interval a, Interval b) {
    
    if(a.start != b.start)
        return a.start-b.start;
    
    else
        return a.end-b.end;
}



vector<Interval> merge(vector<Interval>& intervals) {


    vector<Interval> res;
    int n = (int)intervals.size();

    sort(intervals.begin(), intervals.end(), comparator);

   // for(int i = 0; i< intervals.size();++i){
    int i =0;
    while(i < n){

        Interval s = intervals[i];

        int  j = i + 1;
        
        if(j >= n){
            res.push_back(s);
            break;
        }

       while(j < n) {

           Interval next = intervals[j];

           if (s.end >= next.start) {
               s.end = max(s.end, next.end);
                       ++j;
               
               if(j >= n) {
                   res.push_back(s);
                   return res;
               }
            }else{

               res.push_back(s);

               i=j;
               
                if(i>=n){
                    res.push_back(s);
                    return res;
                }
                
               break;

           }

       }

    }

    return res;

}

int main(int argc, const char * argv[]) {
    // insert code here...

    vector<Interval> intervals = {{1,3},{2,6},{8,10},{15,18}};
   //  vector<Interval> intervals = {{1,4},{4,5} };
    vector<Interval> res = merge(intervals);
    
    std::cout << "Hello, World!\n";
    return 0;
}
