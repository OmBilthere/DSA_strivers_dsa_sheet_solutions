
class Solution {
    
  public:
  
    void dfs( int node , vector<int>& vis , stack<int>& st ,  vector<vector<pair<int , int>>>& adj) {
        
        vis[node] = 1;
        
        for(auto it : adj[node]) {
            
            int v = it.first;
            
            if(!vis[v]) 
            
            dfs(v , vis , st , adj);
        }
        
        st.push(node);
        
    }
    
    
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        
        vector<vector<pair<int , int>>> adj(V);
        
        for(int i = 0 ; i< edges.size(); i++) {
            
            int u = edges[i][0];
            int v = edges[i][1];
            int dis = edges[i][2];
            
            adj[u].push_back({v , dis});
         
        }
        
        stack<int>st;
        
        vector<int>vis(V);
        
        for(int i=0 ; i< V; i++) {
            
            
            if(!vis[i])
            
            dfs( i , vis , st , adj);
        }
        
        vector<int>shortest(V , 1e9);
        
        
        
        shortest[0] = 0;
        
       while(!st.empty()) {
           
           int node = st.top();
           
           st.pop();
           
           for(auto it: adj[node]) {
               
               int next = it.first;
               
               int wt = it.second;
               
              if(shortest[node] != 1e9 && shortest[node] + wt < shortest[next])
              
              shortest[next] = shortest[node]+wt;
              
              
           }
           
         
           
       }
       
       for(int i = 0 ; i < shortest.size() ; i++) {
           
           if(shortest[i] == 1e9) 
           
           shortest[i] = -1;
       }
       
       return shortest;
        
        
    }
};
