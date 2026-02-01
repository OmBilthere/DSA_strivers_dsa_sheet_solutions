class Solution {
  public:
  
    // void dfs (int node , vector<int> & vis , vector<vector<int>>& adj , stack<int>& st) {
        
    //     vis[node] = 1;
        
    //     for(auto it: adj[node]) {
            
    //         if (!vis[it]) 
            
    //         dfs( it , vis , adj , st);
            
    //     }
        
    //     st.push(node);
        
    // }
    
    
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        
        // vector<int> vis (V , 0 );
        
        // stack<int> st;
        
        vector<vector<int>> adj(V);
        
        vector<int>indegree(V , 0);
        
        for(int i = 0 ; i < edges.size() ; i++ ) {
            
            int u = edges[i][0];
            
            int v = edges[i][1];
            
            adj[u].push_back(v);
            
            indegree[v]++;
            
          
        }
        
        // for( int i = 0 ; i < V ; i ++ ) {
            
        //     if( !vis[i] )
            
        //     dfs( i , vis , adj , st );
        // }
        
        // vector<int> ans;
        
        // while( !st.empty()) {
            
        //     ans.push_back(st.top());
            
        //     st.pop();
        // }
        
        // return ans;
        
        queue<int>q;
        
        for(int i=0 ; i<V; i++) {
            
            if(indegree[i]== 0 ) 
            
            q.push(i);
        }
        
        vector<int>topo;
        
        while(!q.empty()) {
            
            int node = q.front();
            
            q.pop();
            
            topo.push_back(node);
            
            for(auto it : adj[node]) {
            
            indegree[it]--;
            
            if(!indegree[it])
            
            q.push(it);
        
           }
            
        }
        
        return topo;
    }
};