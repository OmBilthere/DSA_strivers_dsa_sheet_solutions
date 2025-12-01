class Solution {
  public:
    
    void helper (int node , vector<vector<int>>& adj , vector<int> & ans , vector<int> & vis ) {
        
        ans.push_back(node);
        
        vis[node] = 1;
        
        for(int i = 0 ; i < adj[node].size() ; i++ ) {
            
           int nbr = adj[node][i];    
            
           if( !vis[nbr])
           
           helper( nbr , adj , ans , vis );
           
           
            
        }
        
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        
     int n = adj.size();        
     
     vector<int> ans ;
     
     vector<int> vis ( n , 0);
     
     for(int i = 0 ; i < n ; i++ )
     
     if(!vis[i])
     
     helper ( i , adj , ans , vis);
     
     return ans;
        
    }
};