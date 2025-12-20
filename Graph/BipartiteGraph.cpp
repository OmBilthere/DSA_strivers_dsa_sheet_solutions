class Solution {
public:

    bool dfs( int node , vector<vector<int>>& graph , int currColor , vector<int>& color ) {
    
       
       color[node] = currColor;
       
       for(auto it: graph[node]) {
        

        if(color[it] == -1)  {
            
           if( ! dfs(it , graph , !currColor , color) )

           return false;


        }
        
        else if (color[it] == color[node])

        return false;


       }

       return true;

    }
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n = graph.size();

        int m = graph[0].size();

        vector<vector<int>>adj(n);     
            
        vector<int> color( n , -1);

  
            for( int i = 0 ; i< n ; i++ ) {

                if( color[i] == -1 )   {  

                  if ( !dfs( i , graph , 0 , color ) )

                  return false;
              }
                
            }

             return true;

        }

      

    
};