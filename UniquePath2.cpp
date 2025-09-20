class Solution {
public:
    // int countPaths(int row , int col , int n , int m ,vector<vector<int>>& obstacleGrid ,vector<vector<int>>& dp ) {

    //     if(row == n-1 && col == m-1) return 1;

    //     if(row >= n || col >= m || obstacleGrid[row][col]== 1) return 0;

    //     if(dp[row][col]!=-1) return dp[row][col];

    //     return dp[row][col] = countPaths(row+1 , col, n , m ,obstacleGrid , dp ) + 
    //                           countPaths(row ,col+1, n , m ,obstacleGrid ,dp );
  
    // }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int m= obstacleGrid.size();
        int n= obstacleGrid[0].size();

       if(obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) return 0;

    // //     int row =0;
    // //     int col =0;
    // //     vector<vector<int>>dp(n,vector<int>(m,-1));

    // //     return countPaths(row,col, n , m , obstacleGrid , dp);


    //       vector<vector<int>>dp(m, vector<int>(n,0));

    //               for(int i=0; i<m; i++) {
                     
    //                  for(int j=0; j<n ; j++) {
                
    //                  if(obstacleGrid[i][j]==1) dp[i][j]=0;

    //                 else if(i==0 && j == 0) dp[i][j]=1;

    //                 else {
    //                      int up  = 0;
    //                      int left =0;
    //                     if(i>0) up = dp[i-1][j];
    //                     if(j>0) left = dp[i][j-1];
    //                     dp[i][j]=up+left; 
    //                 }
                      

    //                }

    //          }
    //   return dp[m-1][n-1];

    // space optimization 

                  vector<int>prev(n ,0);

                  for(int i=0; i<m; i++) {
                     
                     vector<int>curr(n,0);
                     
                     for(int j=0; j<n ; j++) {
                
                     if(obstacleGrid[i][j]==1) curr[j]=0;

                    else if(i==0 && j == 0) curr[j]=1;

                    else {
                         int up  = 0;
                         int left =0;
                        if(i>0) up = prev[j];
                        if(j>0) left = curr[j-1];
                        curr[j]=up+left; 
                    }
                      

                   }
                   prev=curr;

             }
      return prev[n-1];

          
   
    }
};