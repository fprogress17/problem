

int V;

vector<pair<int,int>> adj[V];

vector<int> dijkstra(int src){

    vector<int> dist(V, INT_MAX);
    
    dist[src] = 0;
    
    priority_queue<pair(int,int)> pq;
    
    pq.push(make_pair(0,src));
    
    while(!pq.empty()){
        
        int distToHere = -pq.top().first; // previous one put here into pq with dist cal with itself
        int here = pq.top.second;
        
        pq.pop();
        
        if(dist[here] < distToHere)
            continue;
        
        for(int i=0; i< adj[here].size(); ++i){
            
            int there = adj[here][i].first;
            int nextDist = distToHere + adj[here][i].second;
            
            if(dist[there] > nextDist )
            {
                dist[there] = nextDist;
                pq.push(make_pair(-nextDist, there));
            }
            
        }
        
    }
    
    return dist;
}

