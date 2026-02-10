class Solution {
  public:
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src) {
        
        vector<vector<int>>adj(V);
        
        for(int i=0 ; i<edges.size() ; i++ ) {
            
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        queue<int> q;
        
        vector<int>shortest(V , -1);
        
        q.push(src);
        
        shortest[src] = 0;
        
        while(!q.empty()) {
            
            
            int node = q.front();
            
            q.pop();
            
            for(auto it: adj[node]) {
                
                if (shortest[it] == -1)  {
                    
                    shortest[it] = shortest[node] + 1;
                    
                    q.push(it);
    
                }
                
            }
        }
        
        
        return shortest;
    }
};
