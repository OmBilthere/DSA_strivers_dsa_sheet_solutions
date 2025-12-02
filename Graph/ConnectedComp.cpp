class Solution {
    
       public:
  
       void helper (int node  , vector<int> & comp , vector<int> adj [] , vector<int> & vis ) {
        
      
        vis[node] = 1;
        
        comp.push_back(node);
        
        
        for(int i = 0 ; i < adj[node].size() ; i++ ) {
            
           int nbr = adj[node][i];    
            
           if( !vis[nbr])
           
           helper( nbr , comp , adj , vis );
           
           
            
        }
        
    }
    
    
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {

     
     vector<int> adj[V];
     
     for(int i=0 ; i< edges.size() ; i++  ) {
         
         int edge1 = edges[i][0];
         
         int edge2 = edges[i][1];
         
         adj[edge1].push_back(edge2);
         
         adj[edge2].push_back(edge1);
        
     }
     
     vector<vector<int>> ans ;
     
     vector<int> vis ( V , 0);
    
     
     for(int i = 0 ; i < V ; i++ ) {
    
     
     if(!vis[i]) {
      
         vector<int>comp;     
         
         helper ( i , comp , adj , vis );
         
         ans.push_back(comp);
     
       }
       
     
      }
     
     return ans;
        
    }
    
    
};
 