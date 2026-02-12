class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        
        vector<vector<pair<int , int>>> adj (V);
        
        for(int i=0 ; i< edges.size() ; i++ ) {
            
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            
            adj[u].push_back({v , wt});
            adj[v].push_back({u , wt});
            
        }
        
        vector<int>dist(V , 1e9);
        
        dist[src] = 0;
        
        priority_queue< pair<int , int> ,vector<pair<int , int>> , greater<pair<int , int>>> pq;
        
        pq.push({ 0, src});
        
        while(!pq.empty()) {
            
            auto [ currDist , node] = pq.top();

            
            pq.pop();
            
            if(currDist > dist[node]) continue;
            
            for(auto it: adj[node]) {
                
                int v = it.first;
                
                int wt = it.second;
                
                if( dist[v] > currDist + wt) {
                    
                    dist[v] = currDist + wt;
                    
                    pq.push({dist[v] , v});
                }
                
            }
            
            
        }
        
        return dist;
        
    }
};