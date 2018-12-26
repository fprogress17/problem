//
//
// @..*
//
//  Created by Choonghun Lee on 9/11/18.
//  @..
//

#include "stdc++.h"


using namespace std;
#define V 55

int state = 0;
//vector<int >visited(V, false);
map<int, bool> visited;
vector<vector<int>> adj(55, vector<int>());

int getMousePos(int state){

    int a = (state >> 16);
    int ret = (state >> 16) & 0xff;
 
    return ret;

}

int getCatPos(int state){
   int a = (state >> 8);
    int ret = (state >> 8) & 0xff;

    return ret;

}

int setMousePos(int state, int p){

    int b = p << 16;
    
    state = (state & 0x0000ffff) | (p << 16 );
    
    int r =getMousePos(state);
    
    if(r != p){
        cout << "wrong setMousePos" << endl;
    }
    
    
    return state;
}


int setCatPos(int state, int p){

    int b = p << 8;
    state = (state & 0xffff00ff) | (p << 8 );
    
    int r = getCatPos(state);
    
    if(r != p){
        cout << "wrong setCatPos" << endl;
    }
    
    return state;
}


int setCatTurn(int state){

    state = (state & 0xfffffffe) | (1 );
    return state;
}

int  setMouseTurn(int state){

    state = (state & 0xfffffffe) | (0 );
    return state;
}

bool isCatTurn(int state){

    if(state & 0x01)
        return true;
    return false;
}

bool isMouseTurn(int state){

    return ~isCatTurn(state);
}

bool isCatWin(int state){

    if(isMouseTurn(state) ){

        int mPos = getMousePos(state);
        int cPos = getCatPos(state);

        if(mPos == cPos){
            return true;
        }

    }

    return false;

}

bool isMouseWin(int state){
    
   if(isCatTurn(state)){

      int mPos = getMousePos(state);
      return mPos == 0;
   }

   return false;
}


int bfs(void){

    state = setMousePos(state, 1);
    state = setCatPos(state, 2) ;
    state = setMouseTurn(state);
    visited[state] = true;
    queue<int> q;
    bool mouseWin = false;
    bool catWin = false;

    q.push(state);

    while(!q.empty()){

        int here = q.front(); q.pop();

        if(isMouseWin(here))
        {
           //return 1;
           mouseWin = true;
        }

        if(isCatWin(here)){
            //return 2;
            catWin = true;
        }



        int catPos = getCatPos(here);
        int mousePos = getMousePos(here);

        visited[here] = true;
        cout<< mousePos << " " << catPos << endl;
        
       if(isCatTurn(here)){

           for(int i = 0;i < adj[catPos].size();++i){

               int there = adj[catPos][i];

               if( there == 0)
                   continue;

               int nstate = setCatPos(state, there);
               nstate = setMouseTurn(nstate);
               if(visited[nstate] == false){

                   q.push(nstate);
               }

           }
       } else{// mouse turn
           for(int i = 0;i < adj[mousePos].size();++i){

               int there = adj[mousePos][i];

               if( there == catPos)
                   continue;

               int nstate = setMousePos(state, there);
               nstate = setCatTurn(nstate);
               if(visited[nstate] == false){

                   q.push(nstate);
               }

           }

       }

    }

    if(mouseWin && catWin)
        return 1;

    if(mouseWin && !catWin)
        return  1;


    if(!mouseWin && catWin)
        return  2;

    return 0;
}


int dfs(int state){
    
    int here = state;
 
    int catPos = getCatPos(here);
    int mousePos = getMousePos(here);
    
    // visited[here] = true;
    cout<<"m :  " << mousePos << " " << "c :  " << catPos << endl;
    
    
    if(isMouseWin(state))
    {
        return 1;
       // mouseWin = true;
    }
    
    if(isCatWin(state)){
        return 2;
        //catWin = true;
    }

    
 
    int ret = 0;
    vector<int> rets ;
    if(isCatTurn(here)){
        
        for(int i = 0;i < adj[catPos].size();++i){
            
            int there = adj[catPos][i];
            
            if( there == 0)
                continue;
            
            int nstate = setCatPos(state, there);
            nstate = setMouseTurn(nstate);
            
            if(visited[nstate] == false){
                visited[nstate] = true;
                int r = dfs(nstate);
                rets.push_back(r);
                visited[nstate] = false;
            }

        }
        
        if(find(rets.begin(), rets.end(), 2) != rets.end()){
            return 2;
        }
    
        if(find(rets.begin(), rets.end(), 0) != rets.end()){
            return 0;
        }
        
        return 1;
    }else{// mouse turn
        
        for(int i = 0;i < adj[mousePos].size();++i){
            
            int there = adj[mousePos][i];
            
            if( there == catPos)
                continue;
            
            int nstate = setMousePos(state, there);
            nstate = setCatTurn(nstate);
            if(visited[nstate] == false){
                
                visited[nstate] = true;
                int r = dfs(nstate);
                rets.push_back(r);
                visited[nstate] = false;
            }
            
        }

        
        if(find(rets.begin(), rets.end(), 1) != rets.end()){
            return 1; // mouse win
        }
        
        if(find(rets.begin(), rets.end(), 0) != rets.end()){
            return 0;
        }
        
        return 2; // cat win
        
        
    }

    return 0;
}



int catMouseGame(vector<vector<int>>& graph) {

  for(int i =0 ;i < graph.size(); ++i){

     vector<int> v = graph[i];

     adj[i] = v;

  }

   //int ret = bfs();
    state = setMousePos(state, 1);
    state = setCatPos(state, 2) ;
    state = setMouseTurn(state);
    visited[state] = true;
    queue<int> q;
    bool mouseWin = false;
    bool catWin = false;
    int ret = dfs(state);

  return ret;


}

int main(int argc, const char * argv[]) {
    // insert code here...

    int a = 66048;
    int b = a >> 8;
    int c = a>> 16;
    
    int k = 1;
    int j = 0;
    for(int i =0; i< 32; ++i){
        
        j = k << i;
        
    }

  // vector<vector<int>> graph =     {{2,3},{3,4},{0,4},{0,1},{1,2}};

    vector<vector<int>> graph =  {{2,5},{3},{0,4,5},{1,4,5},{2,3},{0,2,3}}; // ->1

    int ret = catMouseGame(graph);

    std::cout << "Hello, World!\n";
    return 0;
}
