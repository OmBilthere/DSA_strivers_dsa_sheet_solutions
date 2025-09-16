class Solution {
public:
//    int countPath(int row , int col , int m , int n , vector<vector<int>>& dp) {

//     if(row >= m || col >= n ) return 0;

//     if(row == m-1 && col == n-1) return 1;

//     if(dp[row][col] != -1 ) return dp[row][col];

//     return dp[row][col]= countPath(row+1 , col , m , n  , dp) + countPath(row , col+1, m , n , dp);

//    }
  
    int uniquePaths(int m, int n) {

    //     // int row =0;
    //     // int col =0;
    //     // vector<vector<int>>dp(m, vector<int>(n,-1));

    //     // return countPath(row , col , m , n , dp);
         
    //   vector<vector<int>>dp(m, vector<int>(n , 1));
   
    //   for (int row=1 ;row<m ; row++) 

    //   for (int col=1 ;col<n ;col++) 
  
    //   dp[row][col] = dp [row-1] [ col ] + dp [ row ] [ col-1 ];
       

    //    return dp[m-1][n-1];

     
     vector<int>prev(n,1);

    
      for (int row=1 ;row<m ; row++) {
      
      vector<int>temp(n,1);

      for (int col=1 ;col<n ;col++) {

        int left = temp[col-1];
         
        int top = prev[col];

        temp[col] = top+left;

       }

         prev= temp;

      }

       return prev[n-1];

   }

};