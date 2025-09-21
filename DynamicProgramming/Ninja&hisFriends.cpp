class Solution {
  public:
    
    // int helper(int row , int col1 , int col2 , int n , int m , vector<vector<int>>& grid
    // , vector<vector<vector<int>>>& dp ) {
        
    //     if( col1< 0 || col1>= m || col2 < 0 || col2>=m ) return 0;
        
    //     if(dp[row][col1][col2] != -1) return dp[row][col1][col2];
        
    //     if(row == n-1 ) {
            
    //         if(col1 == col2 ) return dp[row][col1][col2] = grid[row][col1];
    //         return dp[row][col1][col2] = grid[row][col1] + grid[row][col2];
            
            
    //     }
        
        
        
    //     int maxi = -1e9;
        
    //     for(int i = -1 ; i< 2 ; i++) {
            
    //         for(int j = -1 ; j < 2 ; j++ ) {
                
    //           int val = 0 ;
              
    //           if(col1 == col2 ) val = grid[row][col1];
    
    //           else val = grid[row][col1] + grid[row][col2];
              
    //           val+= helper(row+1 , col1 + i , col2 + j , n , m , grid , dp );
              
    //           maxi = max( maxi, val);
              
                
    //         }
            
    //     }
       
    //  return dp[row][col1][col2] = maxi;
        
    // }
    
    int solve(int n, int m, vector<vector<int>>& grid) {
        
    // // vector<vector<vector<int>>>dp ( n , vector<vector<int>>(m , vector<int>( m , -1)));
    
    // // return helper(0 , 0 , m - 1 , n , m , grid , dp ); 
       
    //   vector<vector<vector<int>>>dp ( n , vector<vector<int>>(m , vector<int>( m , 0)));
      
    //   for(int i=0 ; i< m ; i++ ) {
          
    //       for(int j = 0 ; j < m ; j++ ) {
              
    //           if(i==j)
              
    //           dp[n-1][i][j] = grid[n-1][i];
              
    //           else
              
    //           dp[n-1][i][j] = grid[n-1][i] + grid[n-1][j];
              
    //       }
    //   }
      
    //   for(int row = n-2 ; row>= 0 ; row-- ) {
          
    //       for( int col1 = 0 ; col1 <  m ; col1++) {
              
    //           for(int col2 = 0 ; col2 < m; col2++ ) {
              
    //           int maxi = -1e9;
         
    //           for(int i = -1 ; i< 2 ; i++) {
            
    //           for(int j = -1 ; j < 2 ; j++ ) {
                
    //           int val = 0 ;
              
    //           if(col1 == col2 ) val = grid[row][col1];
              
    //           else val = grid[row][col1]+ grid[row][col2];
              
    //           if(col1+i>=0 && col1+i<m && col2+j>=0 && col2+j<m)
              
    //           val+= dp[row+1][col1 + i] [ col2 + j];
              
    //           maxi = max( maxi, val);
              
    //           }
              
    //         }
            
    //       dp[row][col1][col2] = maxi;
            
    //       }
              
    //     }
        
    //   }
      
      
         
    //  return dp[0][0][m-1];  
    
    
    // space optimization 
    
           
      vector<vector<int>> next ( m , vector<int>(m , 0));
      
    // making base cases
      
      for(int i=0 ; i< m ; i++ ) {
          
          for(int j = 0 ; j < m ; j++ ) {
              
              if(i==j)
              
              next [i][j] = grid[n-1][i];
              
              else
              
              next [i][j] = grid[n-1][i] + grid[n-1][j];
              
          }
          
          
      }
      
      
      
      for(int row = n-2 ; row>= 0 ; row-- ) {
          
          vector<vector<int>> curr ( m , vector<int>(m , 0));
          
          for( int col1 = 0 ; col1 <  m ; col1++) {
              
              for(int col2 = 0 ; col2 < m; col2++ ) {
              
              int maxi = -1e9;
         
              for(int i = -1 ; i< 2 ; i++) {
            
              for(int j = -1 ; j < 2 ; j++ ) {
                  
                  
              if(col1+i>=0 && col1+i<m && col2+j>=0 && col2+j<m) {

              int val = 0 ;
              
              if(col1 == col2 ) val = grid[row][col1];
              
              else val = grid[row][col1]+ grid[row][col2];
              
              
              val+= next [col1 + i] [ col2 + j];
              
              maxi = max( maxi, val);
              
                }
              
              }
              
            }
            
          curr [col1][col2] = maxi;
            
          }
           
     }
          next = curr;
              
      
        
      }
      
      
         
     return next[0][m-1];
 
       
       
     
    }
    
};