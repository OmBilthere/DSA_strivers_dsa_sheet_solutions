class Solution {
  public:
      void dfs(int node, vector<int>& vis, vector<vector<int>>& adj) {
        vis[node] = 1;

        for(int i = 0; i < adj[node].size(); i++) {
           int nbr = adj[node][i];
            if (!vis[nbr]) {
                dfs(nbr, vis, adj);
            }
        }
    }

    int findNumberOfComponent(int V, vector<vector<int>> &edges) {
    
    int n = edges.size();

    vector<vector<int>> adj(V) ;

    for(int i = 0 ; i < n ; i++ ) {
    
    int u = edges[i][0];
    int v = edges[i][1];

    adj[u].push_back(v);
    adj[v].push_back(u);

    }

    int cnt = 0 ;

    vector<int> vis(V , 0 ) ;

    for(int i = 0 ; i< V ; i++ ) {
       if(!vis[i])  {
        cnt++;
        dfs( i ,vis , adj );
       }
    }
    return cnt;
    }
}; 