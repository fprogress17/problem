//
//
// @..*
//
//  Created    on 9/11/18.
//  @..
//

#include "stdc++.h"


using namespace std;

map<string, vector<pair<string,double>> > adj;
map<string, bool> visited;
map<string, double> distances;

double dfs(string a, string b){

    if(a == b){
        if(distances.find(a) == distances.end())
           return -1.0;
           
        return distances[b];
    }

    visited[a] = true;

   vector<pair<string,double>> v = adj[a];
    double result = -1.0;
   for(int i = 0; i< v.size();++i){

       pair<string, double> there = v[i];
       double ret;
       
       if(!visited[there.first]){

           distances[there.first] = distances[a] * there.second;
          ret = dfs(there.first, b);
           
           if(ret != -1.0){
               result = ret;
           }

       }
   }


    return result;

}






vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {

    vector<double> res;

    for( int i = 0;i < equations.size() ;++i ){

        pair<string, string> p = equations[i];
        double val = values[i];

        adj[p.first].push_back(make_pair(p.second, val));
        adj[p.second].push_back(make_pair(p.first, 1/val));

    }



    map<string, vector<pair<string, double>>>::iterator it;

    for(it = adj.begin(); it!= adj.end(); ++it){

       adj[it->first].push_back(make_pair(it->first,1));
        distances[it->first] = 1.0;
    }

    for(int i=0; i< queries.size(); ++i){

        pair<string , string> p = queries[i];
       
        for(it = adj.begin(); it!= adj.end(); ++it){
            
            visited[it->first] = false;
            distances[it->first] = 1.0;
            
       
        }
      //  visited.clear();
       // distances.clear();
        
        double ret = dfs(p.first, p.second);
        res.push_back(ret);


    }

    return res;
}





int main(int argc, const char * argv[]) {
    // insert code here...

    vector<pair<string,string>> equations = { {"a", "b"}, {"b", "c"} };
    vector<double> values = {2.0, 3.0};
    vector<pair<string,string>> queries = { {"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"} };


    vector<double> res = calcEquation(equations, values, queries);

    std::cout << "Hello, World!\n";
    return 0;
}
