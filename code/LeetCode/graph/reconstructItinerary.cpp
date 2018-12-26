//
//
// @..*
//
//  Created    on 9/11/18.
//  @..
//

#include "stdc++.h"


using namespace std;

map<string, int> m;
vector< vector<bool>> adj;

vector<string> res;

int getIntFromStr(string str){

    return m[str];
}

string getStringFromInt(int index){

    for( pair<string, int> p : m)
    {
       if(p.second == index)
           return p.first;

    }
    return "";
}


void dfs(string s){


  int here = getIntFromStr(s);

  for(int i =0; i < adj[here].size(); ++i){

    if(adj[here][i] == true) {

       adj[here][i] = false;

       string there = getStringFromInt(i);
       dfs(there);
    }

  }


  res.push_back(s);



}


vector<string> findItinerary(vector<pair<string, string>> tickets) {

    int count = 0;

    vector<string> s ;

    for (pair<string, string> p : tickets) {

//        if (m.find(p.first) == m.end()) {
//
//            m[p.first] = count++;
//
//        }
//
//        if (m.find(p.second) == m.end()) {
//
//            m[p.second] = count++;
//
//        }


    if(find(s.begin(), s.end(), p.first )== s.end() ){

        s.push_back(p.first);

    }

        
        if(find(s.begin(), s.end(), p.second )== s.end() ){
            
            s.push_back(p.second);
            
        }
   }

   sort(s.begin(), s.end()) ;

   for( string str : s){

      m[str] = count++;


   }

    adj = vector<vector<bool>>(count + 1, vector<bool>(count+1,false));

    for (pair<string, string> p : tickets) {

        adj[getIntFromStr(p.first)][getIntFromStr(p.second)] = true;

    }


    dfs("JFK");

    reverse(res.begin(), res.end());

    return res;
}


#if 0

map<string, vector<string>> adj;
map<string, bool> visited;

vector<string> res;

//void dfs(string a, vector<string> res){
void dfs(string a){

    visited[a] = true;

    //bool vi = false;

   vector<string> v = adj[a];
    vector<string> cv = adj[a];

    //vector<string>::iterator it;
   //for( it = v.begin(); it != v.end() ; ++it){

       //vector<string>::iterator it;
    for( int i = 0; i <  adj[a].size() ; ++i){
    //for( int i = 0; i < v.size() ; ++i){
       //string str = v[i];
       string str = adj[a][i];

        cv.erase(find(cv.begin(), cv.end(), str)) ;   //the v[i] which is deleted here is not reflected in above v = adj[a]; after getting bac from below layer.
      adj[a] = cv; ///
      dfs(str);

   }
//
//    for ( string str : adj[a]){
//
//        //if(/*!visited[str] && */ vi == false){
//
//            //res.push_back(str);
//
//         //   vi = true;
//            dfs(str);
//            //dfs(str,  res);
//            //res.pop_back();
//        //}
//    }


    res.push_back(a);


}


vector<string> findItinerary(vector<pair<string, string>> tickets) {

    for( pair<string, string> p : tickets)
    {
        adj[p.first].push_back(p.second);
    }

    for( pair<string, vector<string>> p : adj){
        vector<string> v = p.second;
        sort(v.begin(), v.end());
        adj[p.first] = v;
        
        //sort(p.second.begin(), p.second.end());
        

    }

    dfs("JFK");

    reverse(res.begin(), res.end());
    return res;


}

#endif

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<string> s = { "abc", "acd", "aca"};
    sort(s.begin(), s.end());

    // vector<pair<string, string>> t = {{"MUC", "LHR"}, {"JFK", "MUC"}, {"SFO", "SJC"}, {"LHR", "SFO"}};
   // vector<pair<string, string>> t = {{"JFK","SFO"},{"JFK","ATL"},{"SFO","ATL"},{"ATL","JFK"},{"ATL","SFO"}};
    vector<pair<string, string>> t = {{"MUC","LHR"},{"JFK","MUC"},{"SFO","SJC"},{"LHR","SFO"}};
    
    vector<string> ret = findItinerary(t);
    
    std::cout << "Hello, World!\n";
    return 0;
}
