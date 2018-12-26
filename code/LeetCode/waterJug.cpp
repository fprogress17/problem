//
//
// @..*
//
//  Created by Choonghun Lee on 9/11/18.
//  @..
//

#include "stdc++.h"
#include <iostream>
#include <queue>
#include <utility>
#include <map>

using namespace std;

//pair<int, int> pairr;

int gcd(int p, int q){
    
    printf("%d, %d \n", p, q);
    
    if(q != 0){
        return gcd(q, p%q);
    }
    
    return p;
}


bool canMeasureWater(int x, int y, int z) {
    
 
    
    if(z==0)
        return true;
    
    if(x == 0 && y == 0)
        return 0;
    
    
    
    if(x>y)
        swap(x,y);
    
    if(x == 0 ){
        if(y== z )
            return true;
        else
            return false;
    }
    
    if(x + y < z)
        return false;
    
    if(y == z || x == z)
        return true;
    
    if(z%(y-x) == 0)
        return true;
    
    if(x + y == z)
        return true;
    
    
 
    
    queue<pair<int,int>> q;
    //queue<pairr> q;
    
    map<pair<int,int>, bool> visited;
    
    q.push(make_pair(0,0));
    
    while(!q.empty()){
        
        pair<int,int> here =  q.front(); q.pop();
        
        if(here.first == z || here.second == z)
            return true;
        
        if(here.first + here.second == z)
            return true;
        
        if(here.first <0 || here.second < 0)
            continue;
        
        if(here.first > x || here.second > y)
            continue;
        
        
        visited[here] = true;
        
      //  printf("%d, %d\n", here.first, here.second);
        
        
        
        pair<int,int> there = make_pair(0,here.second);
        if(visited.find(there) == visited.end() || visited[there] == false)
            q.push(there);
        
        
        there = make_pair(here.first,0);
        if(visited.find(there) == visited.end() || visited[there] == false)
            q.push(there);
        
        
        
        there = make_pair(x,here.second);
        if(visited.find(there) == visited.end() || visited[there] == false)
            q.push(there);
        
        
        there = make_pair(here.first,y);
        if(visited.find(there) == visited.end() || visited[there] == false)
            q.push(there);
        
        
        if(here.first >= y - here.second){
            
            there = make_pair(here.first - (y-here.second), y );
            if(visited.find(there) == visited.end() || visited[there] == false)
                q.push(there);
            
        }else{
            
            there = make_pair(0, here.second + here.first);
            if(visited.find(there) == visited.end() || visited[there] == false)
                q.push(there);
        }
        
        if(here.second >= x - here.first){
            
            there = make_pair(x, here.second - (x-here.first));
            
        }else{
            
            there = make_pair(here.first + here.second, 0);
            
        }
        
        if(visited.find(there) == visited.end() || visited[there] == false)
            q.push(there);
#if 0
        if(here.first == 0 && here.second == 0){
            
            pair<int,int> there = make_pair(0,y);
            if(visited.find(there) == visited.end() || visited[there] == false)
                q.push(there);
            
            
            there = make_pair(x,0);
            if(visited.find(there) == visited.end() || visited[there] == false)
                q.push(there);
        }
        
        if(here.first == 0 && here.second !=0 ){
            
            pair<int,int> there = make_pair(0,0);
          //  q.push(there);
            //there = make_pair(x, hear.second - hear.firsty-x);
            if(here.second - x >=0){
                there = make_pair(x, here.second - x);
                if(visited.find(there) == visited.end() || visited[there] == false)
                    q.push(there);
            }
            
            if(here.second - x >=0){
                there = make_pair(0, here.second - x);
                if(visited.find(there) == visited.end() || visited[there] == false)
                    q.push(there);
            }
            
                there = make_pair(x, here.second );
            if(visited.find(there) == visited.end() || visited[there] == false)
                q.push(there);
            
        }
        
        if(here.first != 0 && here.second ==0 ){
            
            pair<int,int> there = make_pair(0,0);
           // q.push(there);
            
            //there = make_pair(0,x);
            there = make_pair(0,here.first);
            if(visited.find(there) == visited.end() || visited[there] == false)
                q.push(there);
            
            there = make_pair(here.first, y);
            if(visited.find(there) == visited.end() || visited[there] == false)
                q.push(there);
            
            there = make_pair(x,0);
            if(visited.find(there) == visited.end() || visited[there] == false)
                q.push(there);
            
            
            there = make_pair(x,y);
            if(visited.find(there) == visited.end() || visited[there] == false)
                q.push(there);
            
            
        }
        
        if(here.first != 0 && here.second != 0 ){
            
            pair<int,int> there = make_pair(0,0);
            //q.push(there);
            
            there = make_pair(here.first,0);
            if(visited.find(there) == visited.end() || visited[there] == false)
                q.push(there);
            
            //there = make_pair(x,y);
            there = make_pair(0,here.second);
            if(visited.find(there) == visited.end() || visited[there] == false)
                q.push(there);
            
            
            if(here.first < x && here.second - (x-here.first) >= 0){
                there = make_pair( x, here.second - (x-here.first) );
                if(visited.find(there) == visited.end() || visited[there] == false)
                    q.push(there);
            }
            
            
            if( x == here.first && here.second - here.first >= 0){
                there = make_pair( 0,here.second - here.first );
                if(visited.find(there) == visited.end() || visited[there] == false)
                    q.push(there);
            
            }
            
            if( y - here.second >= here.first){
                there = make_pair( 0,here.second + here.first );
                if(visited.find(there) == visited.end() || visited[there] == false)
                    q.push(there);
            }
            
            if( y > here.second ){
                if(here.first <= y - here.second){
                    there = make_pair(0 ,here.second + here.first );
                    if(visited.find(there) == visited.end() || visited[there] == false)
                        q.push(there);
                }
                
                if( here.first > y- here.second){
                     there = make_pair(here.first -( y- here.second ),y );
                    if(visited.find(there) == visited.end() || visited[there] == false)
                        q.push(there);
                }
                
                
                there = make_pair(x - ( y-here.second) ,here.second + here.first );
                if(visited.find(there) == visited.end() || visited[there] == false)
                    q.push(there);
            }
        }
#endif
    }
    
    return false;
    
}

#define pii pair<int, int>
#define mp make_pair

void BFS(int a, int b, int target)
{
    // Map is used to store the states, every
    // state is hashed to binary value to
    // indicate either that state is visited
    // before or not
    map<pii, int> m;
    bool isSolvable = false;
    vector<pii> path;
    
    queue<pii> q; // queue to maintain states
    q.push({ 0, 0 }); // Initialing with initial state
    
    while (!q.empty()) {
        
        pii u = q.front(); // current state
        
        q.pop(); // pop off used state
        
        // if this state is already visited
        if (m[{ u.first, u.second }] == 1)
            continue;
        
        // doesn't met jug constraints
        if ((u.first > a || u.second > b ||
             u.first < 0 || u.second < 0))
            continue;
        
        // filling the vector for constructing
        // the solution path
        path.push_back({ u.first, u.second });
        
        // marking current state as visited
        m[{ u.first, u.second }] = 1;
        
        // if we reach solution state, put ans=1
        if (u.first == target || u.second == target) {
            isSolvable = true;
            if (u.first == target) {
                if (u.second != 0)
                    
                    // fill final state
                    path.push_back({ u.first, 0 });
            }
            else {
                if (u.first != 0)
                    
                    // fill final state
                    path.push_back({ 0, u.second });
            }
            
            // print the solution path
            int sz = path.size();
            for (int i = 0; i < sz; i++)
                cout << "(" << path[i].first
                << ", " << path[i].second << ")\n";
            break;
        }
        
        // if we have not reached final state
        // then, start developing intermediate
        // states to reach solution state
        q.push({ u.first, b }); // fill Jug2
        q.push({ a, u.second }); // fill Jug1
        
        for (int ap = 0; ap <= max(a, b); ap++) {
            
            // pour amount ap from Jug2 to Jug1
            int c = u.first + ap;
            int d = u.second - ap;
            
            // check if this state is possible or not
            if (c == a || (d == 0 && d >= 0))
                q.push({ c, d });
            
            // Pour amount ap from Jug 1 to Jug2
            c = u.first - ap;
            d = u.second + ap;
            
            // check if this state is possible or not
            if ((c == 0 && c >= 0) || d == b)
                q.push({ c, d });
        }
        
        q.push({ a, 0 }); // Empty Jug2
        q.push({ 0, b }); // Empty Jug1
    }
    
    // No, solution exists if ans=0
    if (!isSolvable)
        cout << "No solution";
}

bool canMeasureWater1( int x, int y, int z) {
 //   return z == 0 || (x + y >= z && z % gcd(x, y) == 0 );
    
    if(z == 0)
        return true;
    
    if(x + y >= z){
        if( z % gcd(x,y) == 0)
            return true;
    }
    
    return false;
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
   // canMeasureWater(34,5,6);
     //canMeasureWater(11,3,13);
     canMeasureWater(22003,31237,31238);
    
   
    
   //  canMeasureWater(11,3,2);
  //  bool ret =    canMeasureWater1(11,3,13);
    
   //  canMeasureWater(22003,31237,1);
    
  //  BFS(22003,31237,1);
    
    
    
    std::cout << "Hello, World!\n";
    return 0;
}
