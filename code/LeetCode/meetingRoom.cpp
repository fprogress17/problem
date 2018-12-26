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

bool intervalSort (Interval i,Interval j) { return (i.start < j.start); }

bool canAttendMeetings(vector<Interval>& intervals) {

    sort(intervals.begin(), intervals.end(), intervalSort);
    
   for(int i=1; i< intervals.size(); ++i){

       Interval prev = intervals[i-1];
       Interval curr = intervals[i];

       if( curr.start < prev.end  )
       {
           return false;
       }

   }

   return true;
}

vector<Interval> meeting = {{7,10},{2,4}};


int main(int argc, const char * argv[]) {
    // insert code here...

   bool ret = canAttendMeetings(meeting) ;
    
    std::cout << "Hello, World!\n";
    return 0;
}


