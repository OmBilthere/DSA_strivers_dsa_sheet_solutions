class Solution {
    
  public:
  
//   bool dfs ( int node , vector<int> & vis , vector<int> & pathVis , 
   
//   vector<vector<int>> & adj ) {
       
//       vis[node] = 1;
       
//       pathVis[node] = 1;
       
//       for(auto it : adj[node] ) {
           
//           if(!vis[it]) {
               
//              if  (  dfs( it , vis , pathVis , adj) ) return true;
               
//           }
             
//              else if ( pathVis[it] ) return true;
             
          
//       } 
       
//       pathVis[node] = 0;
       
//       return false;

//   }
  
  
    bool isCyclic(int V, vector<vector<int>> &edges) {
      
      vector<vector<int>>adj(V);
      
      // for bfs
      
      vector<int>indegree(V , 0);
      
      for(int i= 0 ; i< edges.size() ; i++ ) {
          
          int u = edges[i][0];
          
          int v = edges[i][1];
          
          adj[u].push_back(v);
          
          indegree[v]++;
          
          
      }
      
    //   vector<int>vis(V , 0 );
      
    //   vector<int> pathVis(V , 0);
      
    //   for(int i = 0 ; i < V ; i++ ) {
          
    //       if(!vis[i]) {
              
    //           if( dfs ( i , vis , pathVis , adj ))
              
    //           return true;
    //       }
    //   }
        
    //     return false;
    
         queue<int> q;
         
         for(int i = 0 ; i< V ; i++ )  {
             
             if(!indegree[i])
             
             q.push(i);
             
         }
         
         int size = 0;
         
         while(!q.empty()) {
             
             int node = q.front();
             
             q.pop();  
             
             size++;
             
             for(auto it : adj[node]) {
                
                indegree[it]--; 
                 
                if(!indegree[it]) {
                    
                     q.push(it);
                     
                   
                }
                
               
                 
             }
             
             
         }
         
         
         return size != V ;
         
    }
};