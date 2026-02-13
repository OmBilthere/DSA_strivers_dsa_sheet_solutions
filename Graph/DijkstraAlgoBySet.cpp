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
        
        // priority_queue< pair<int , int> ,vector<pair<int , int>> , greater<pair<int , int>>> pq;
        
        // pq.push({ 0, src});
        
        set<pair<int,int>>st;
        
        st.insert({0, src});
        
        // while(!pq.empty()) {
        
        while(!st.empty()) {
            
            // auto [ currDist , node] = pq.top();
            
            auto it = st.begin();
            
            int currDist = it->first;
            
            int node = it->second;

            // pq.pop();
            
            st.erase(it);
            
            if(currDist > dist[node]) continue;
            
            for(auto it: adj[node]) {
                
                auto [ v , wt ] = it;
                
                if( dist[v] > currDist + wt) {
                    
                    if(dist[v]!=1e9) 
                    
                    st.erase({dist[v] ,v });
                    
                    dist[v] = currDist + wt;
                    
                    // pq.push({dist[v] , v});
                    
                    
                    
                    st.insert({dist[v],v});
                }
                
            }
            
            
        }
        
        return dist;
        
    }
};