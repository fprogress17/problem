//
//
// @..*
//
//  Created    on 9/11/18.
//  @..
//

#include "stdc++.h"


using namespace std;

  struct UndirectedGraphNode {
        int label;
         vector<UndirectedGraphNode *> neighbors;
         UndirectedGraphNode(int x) : label(x) {};
      };

UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    
    unordered_map<int, UndirectedGraphNode*> umap;
    
    return clone(node, umap);
    
}
// leetcode passed
UndirectedGraphNode *clone(UndirectedGraphNode *node, unordered_map<int, UndirectedGraphNode*> &umap) {
    
    if (!node)
        return node;
    
    if (umap.count(node->label))
        return umap[node->label];
    
    UndirectedGraphNode *newNode = new UndirectedGraphNode(node->label);
    
    umap[node->label] = newNode;
    
    for (int i = 0; i < node->neighbors.size(); ++i) {
        
        (newNode->neighbors).push_back(clone(node->neighbors[i], umap));
    }
    
    return newNode;
}




// leetcode didn't pass
map< UndirectedGraphNode* , UndirectedGraphNode *> m;
map< UndirectedGraphNode* , bool> visited;
map< UndirectedGraphNode* , bool> cloned;

UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    
    
    
    if(node == nullptr)
        return nullptr;
    
    visited[node] = true;
    
    UndirectedGraphNode *nCloned ;
    if(m.find(node) == m.end() ){
        nCloned = new UndirectedGraphNode(node->label);
        
        m[node] = nCloned;
        cloned[node] = true;
    }else{
        
        nCloned = m[node];
        
    }
    
    for(int i=0; i< node->neighbors.size();++i){
        
        UndirectedGraphNode *there = node->neighbors[i];
        
        UndirectedGraphNode * thereCloned;
        
        if(cloned.find(there) == cloned.end() || cloned[there] == false){
            thereCloned= new UndirectedGraphNode(there->label);
            
            m[there] = thereCloned;
            cloned[there] = true;
        }  else{
            thereCloned = m[there];
            
        }
        
        nCloned->neighbors.push_back(thereCloned);
        
        
        if(visited.find(there) == visited.end() || visited[there] == false){
            
            return   cloneGraph(there);
            
        }
        
        
        
    }
    
    return nCloned;
}
    

UndirectedGraphNode *cloneGraphBFS(UndirectedGraphNode *node) {
    
    if(node == nullptr)
        return nullptr;
    
    
    if(node->neighbors.size() == 0){
        return new UndirectedGraphNode(node->label);
    }
    
    
    UndirectedGraphNode *nCloned = new UndirectedGraphNode(node->label);
    map< UndirectedGraphNode* , UndirectedGraphNode *> m;
    map< UndirectedGraphNode* , bool> visited;
    set<UndirectedGraphNode*> queueSet;
    
    m[node]  = nCloned;
    
    queue<UndirectedGraphNode*> q;
    q.push(node);
    queueSet.insert(node);
    
    while(!q.empty()){
        
        UndirectedGraphNode* here = q.front(); q.pop();
        
        queueSet.erase ( queueSet.find(here) );
        
        UndirectedGraphNode* hereCloned = m[here];
        visited[here] = true;
        
        vector<UndirectedGraphNode*> queuedChild;
        
        for(int i=0; i < here->neighbors.size(); ++i){
            
            UndirectedGraphNode *there = here->neighbors[i];
            
            UndirectedGraphNode *thereClone;
            
            if(m.find(there) == m.end()){
                thereClone = new UndirectedGraphNode(there->label);
                m[there] = thereClone;
            }else{
                
                thereClone = m[there];
                
            }
            
          
            hereCloned->neighbors.push_back(thereClone);
            
            
            
            if( queueSet.find(there) == queueSet.end() &&(find(queuedChild.begin(), queuedChild.end(), there) == queuedChild.end() ) &&  (visited.find(there) == visited.end() || visited[there] == false ) ){
                
                q.push(there);
                queuedChild.push_back(there);
                queueSet.insert(there);
            }
            
            
        }
    }
    
    UndirectedGraphNode *ret = m[node] ;
    
    return ret;
}




UndirectedGraphNode* makeGraph1(){// 0,0,1
    
    
    UndirectedGraphNode *root = new UndirectedGraphNode(11);
    
    root->neighbors.push_back(root);
    root->neighbors.push_back(root);
    
    return root;
}


UndirectedGraphNode* makeGraph2() {// -1,1,#1
    
    
    UndirectedGraphNode *root0 = new UndirectedGraphNode(-1);
    UndirectedGraphNode *root1 = new UndirectedGraphNode(1);
    
    root0->neighbors.push_back(root1);
    
    return root0;
}

UndirectedGraphNode* makeGraph3() {// {0,1#1,2#2,2}
    
    
    UndirectedGraphNode *root0 = new UndirectedGraphNode(0);
    UndirectedGraphNode *root1 = new UndirectedGraphNode(1);
    UndirectedGraphNode *root2 = new UndirectedGraphNode(2);
    
    root0->neighbors.push_back(root1);
    root1->neighbors.push_back(root2);
    root2->neighbors.push_back(root2);
    
    return root0;
}

UndirectedGraphNode* makeGraph() {// {-1,1#1}
    
    
    UndirectedGraphNode *rootM = new UndirectedGraphNode(-1);
    UndirectedGraphNode *root1 = new UndirectedGraphNode(1);
    
    
    rootM->neighbors.push_back(root1);
    
    
    
    return rootM;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    UndirectedGraphNode *root = makeGraph();
    
    cloneGraph(root);
    
    std::cout << "Hello, World!\n";
    return 0;
}
