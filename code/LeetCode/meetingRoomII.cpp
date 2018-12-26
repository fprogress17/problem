//
//
// @..*
//
//  Created by Choonghun Lee on 9/11/18.
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



int minMeetingRoomsII(vector<Interval>& intervals) {
    
    
    int n = intervals.size();
    
    if(n==0)
        return 0;
    
    int maxCount = 0;
    
    
    for(int i=0; i< n; ++i)
    {
        
        Interval current = intervals[i];
        int index = i+1;
        int count = 1;
        
        while(index < n){
            
            Interval next = intervals[index];
            
            if( current.end >= next.end){
                ++count;
            }
            
            ++index;
        }
        
        maxCount = max(maxCount, count);
    }
    
    return maxCount;
}


//meeting room II
//Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms required.
int minMeetingRooms1(vector<Interval>& intervals) {


    vector<pair<int, char>> pA;

    for(int i=0;i<intervals.size(); ++i){

        Interval intv = intervals[i];

        pair<int, char> ps = make_pair(intv.start, 's');
        pair<int, char> pe = make_pair(intv.end, 'e');

        pA.push_back(ps);
        pA.push_back(pe);
    }

    sort(pA.begin(), pA.end());

    int count = 0;
    int maxCount = 0;

    for(int i=0; i< pA.size(); ++i){

        pair<int, char> ps = pA[i];

        if(ps.second == 's'){
            ++count;
            maxCount = max(maxCount ,count) ;
        }else{
            --count;
        }


    }
    
   return maxCount;
    
    
}




vector<Interval> meeting = {{0,30},{5,10},{15,20}};

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int ret = minMeetingRooms1(meeting);
    
    
    std::cout << "Hello, World!\n";
    return 0;
}
