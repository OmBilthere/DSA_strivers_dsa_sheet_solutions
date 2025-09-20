class Solution {
public:
    // int helper(int row , int col , int n , int m ,vector<vector<int>>& grid , 
    // vector<vector<int>>& dp ) {

    //     if(row == m-1 && col== n-1) return grid[m-1][n-1];

    //    if(row >= m || col >= n) return INT_MAX;

    //    if(dp[row][col] != -1 ) return dp[row][col];


    //     int right = helper (row , col+1 , n , m , grid , dp );
    //     int bottom = helper (row+1 , col , n , m , grid , dp );
       
    //    return dp[row][col] = grid[row][col] + min (right , bottom );

    // }
    int minPathSum(vector<vector<int>>& grid) {

        int m = grid.size() ,  n = grid[0].size();

        // // int row = 0 , col =0 ;

        // // vector<vector<int>>dp (m , vector<int> (n, -1));

        // // return helper ( row , col , n , m , grid , dp) ; 
        
        // vector<vector<int>>dp(m , vector<int>(n , 0));

        // for (int i = 0 ; i < m ; i ++ ) {

        // for (int j = 0  ; j < n ; j ++ ) {
             
        //      if(i==0 && j==0 ) 

        //      dp[i][j] = grid[i][j];

        //      else  {

        //         int up = i>0 ? dp[i-1][j] : INT_MAX;
        //         int left = j>0 ?  dp[i][j-1] : INT_MAX;
        //         dp[i][j] = grid[i][j] + min (left , up );

        //         }

        //      }

        //  }

        // return dp[m-1][n-1];

        vector<int> prev(n , 0);

        for (int i = 0 ; i < m ; i ++ ) {
         
         vector<int> curr( n , 0 );
         
        for (int j = 0  ; j < n ; j ++ ) {
             
             if(i==0 && j==0 ) 

             curr[j] = grid[i][j];

             else  {

                int up = i>0 ? prev[j]: INT_MAX;
                int left = j>0 ?  curr[j-1] : INT_MAX;
                curr[j] = grid[i][j] + min (left , up );

                }

             }
           prev = curr;
         }

        return prev[n-1];
    }

};