class Solution {
public:

    void dfs (int node , vector<int>& vis , vector<vector<int>>& isConnected ) {
       
       vis[node] = 1;

       for(int nbr = 0 ; nbr < isConnected[node].size() ; nbr++) {

        if(!vis[nbr] && isConnected[node][nbr])

        dfs(nbr , vis , isConnected );

       }

    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        

       int n = isConnected.size() ;
       
       int cnt = 0;
       
       vector<int>vis(n , 0 );

       for(int node = 0 ; node < n ; node++ )  {

        if( !vis[node]) {
         
         cnt++;

         dfs( node , vis , isConnected );

        }

       }
       
       return cnt;

    }

};