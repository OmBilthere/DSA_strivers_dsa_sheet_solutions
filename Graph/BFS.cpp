class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
     
      queue<int>q;
      
      int n = adj.size();
      
      vector<int>level;
      
      vector<int>vis(n , 0);
      
      q.push(0);
      
      vis[0] = 1;
      
      while( !q.empty()) {
          
          int top = q.front();
          
          q.pop();
          
          level.push_back(top);
          
          
          for(int i = 0 ; i < adj[top].size(); i++) {
              
           int nbr = adj[top][i];      
              
          if(!vis[nbr]) {
          
          q.push(nbr);
          
          vis[nbr]= 1;
          
             }
             
             
          }
          
      }
      
        return level;
    }
};