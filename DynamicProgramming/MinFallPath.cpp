class Solution {
public:
    // int helper (int row , int col , int n , int m ,  vector<vector<int>>& matrix ,  
    //     vector<vector<int>>& dp ) {

    //   if(col< 0 || col >= m ) return INT_MAX; 

    //   if(row == n-1 ) return matrix[row][col]; 
  
    //   if(dp[row][col] != -1) return dp[row][col];

    //  int mini = INT_MAX;

    // for(int i = -1 ; i < 2 ; i++ ) 
   
    // mini  = min( mini , helper(row+1 , col+i , n , m , matrix , dp ) ); 
    
  

    // return dp [row] [col] = matrix[row][col] + mini;

    // }

int minFallingPathSum(vector<vector<int>>& matrix) {

        int n = matrix.size() , m = matrix[0].size() ;

        int ans = INT_MAX ;
        
    //     // vector<vector<int>>dp(n , vector<int>(m , -1));
    //     // for(int i=0 ; i< m ; i++) 
    //     //  ans = min(ans , helper ( 0 , i , n , m , matrix , dp));
    //     // return ans;

    //     vector<vector<int>>dp(n , vector<int>(m , 0));

    //     for(int i=0 ; i<m ; i++) 
    //     dp[n-1][i] = matrix[n-1][i];
        

    //    for(int row = n-2 ;  row >=0 ; row--) {
        
    //     for(int col = 0 ; col < m ; col ++ ) {

    //           int down = dp[row+1][col] ;
    //           int left = col > 0 ? dp[row+1][col-1] : INT_MAX;
    //           int right = col < m-1 ? dp[row+1][col+1] : INT_MAX;
    //           dp[row][col] = matrix[row][col] + min({down , left , right });
             
    //       }

    //    }

    //   for(int i=0; i<m ; i++) 
    //   ans = min( ans , dp[0][i]);

    //   return ans;

    // space optimization

        vector<int>next(m , 0);

    
        for(int i=0 ; i<m ; i++) 
        next[i] = matrix[n-1][i];
        

       for(int row = n-2 ;  row >=0 ; row--) {
         
         vector<int>curr(m,0);

        for(int col = 0 ; col < m ; col ++ ) {

              int down = next[col] ;
              int left = col > 0 ? next[col-1] : INT_MAX;
              int right = col < m-1 ? next[col+1] : INT_MAX;
              curr[col] = matrix[row][col] + min({down , left , right });
             
          }

          next = curr;

       }

      for(int i=0; i<m ; i++) 
      ans = min( ans , next[i]);

      return ans;

    }
};