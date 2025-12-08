class Solution {
  public:
    
    bool dfs ( int node , vector<int>adj[] , vector<int>& vis , vector<int>& parent) {
        
        vis[node] = 1;
        
        for ( auto nbr : adj[node] ) {
            
          if( !vis[nbr] ) {
              
           parent[nbr] = node;
          
           if ( dfs( nbr , adj , vis , parent) )  return true;
          
          }
          
          else {
              
              if( nbr != parent[node] )  
              
              return true;
          }
          
            
        }
        
        return false;
    }
    
    bool isCycle(int V, vector<vector<int>>& edges) {
       
  
       vector<int> adj[V];
       
       for(int i = 0 ; i < edges.size() ; i++) {
           
               
               int u = edges[i][0];
               
               int v = edges[i][1];
               
               adj[u].push_back(v);
               
               adj[v].push_back(u);
               
           
       }
       
       vector<int>vis( V  , 0 );
       
       vector<int>parent(V , -1 ); 
       
       for(int i = 0 ; i< V ; i++ ) {
           
         if(!vis[i])
         
         if( dfs (i , adj , vis  , parent)) return true;
           
       }
      
       return false;
        
    }
};