// User function Template for C++

class Solution {
  public:
  
    void dfs( int row , int col , int baseRow , int baseCol , vector<vector<int>>& vis ,
    vector<vector<int>>& grid , vector<pair<int , int>>& shape ) {
      
        vis[row][col] = 1;
        
        shape.push_back({row-baseRow , col-baseCol});   
        
        vector<int> dx = { 0 , 0 , 1 , -1 };
        
        vector<int> dy = { 1 , -1 , 0 , 0 };
        
        for(int i = 0 ; i< 4 ; i++ ) {
            
        int nx = row+ dx[i];
        
        int ny = col+ dy[i];
            
        if( nx >= 0 && nx < grid.size() && ny >= 0 &&
             
        ny < grid[0].size() && grid[nx][ny] == 1 && !vis[nx][ny])   {
            
              dfs( nx , ny , baseRow , baseCol , vis , grid , shape);
            
           }
        
       }
        
    }
    
    
    int countDistinctIslands(vector<vector<int>>& grid) {
     
        
        int n = grid.size();
        
        int m = grid[0].size();
       
        set< vector<pair<int , int>>> s;

        vector<vector<int>>vis( n, vector<int>(m , 0 ));
        
        for(int i = 0 ; i < n ; i ++ ) {
            
            for(int j = 0 ; j < m ; j++ ) {
                
                if( grid[i][j] == 1 && !vis[i][j] ) {
                  
                  vector<pair<int , int>> shape;    
                    
                  dfs( i , j , i , j , vis , grid , shape );
                  
                  s.insert( shape );
                  
                }
                
                
            }
        }
        
        return s.size();
        
    }
};
