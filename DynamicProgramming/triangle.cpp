class Solution {
public:
    // int helper(int down , int dig , int n , vector<vector<int>>& triangle , vector<vector<int>>& dp ) {
      
    //     if(dp[down][dig] != -1) return dp[down][dig];

    //     if(down == n-1 ) return dp[down] [dig] = triangle[down][dig];

    //     int down_val = triangle[down][dig] + helper(down+1 , dig , n , triangle , dp );

    //     int dig_val = triangle[down][dig] + helper(down+1 , dig+1 , n , triangle , dp );
        
    //     return dp[down][dig] = min(down_val , dig_val);
        
       
        
    //  }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        // // vector<vector<int>>dp(n , vector<int>(n , -1) );

        // // return helper( 0, 0 , n , triangle , dp );

        // vector<vector<int>>dp(n , vector<int>(n, 0));
         
        //  for(int i=0; i<n ; i++)
        //  dp[n-1][i]= triangle [n-1][i];

        // for(int i=n-2; i>=0 ; i--) {

        //     for(int j =0 ; j<= i ; j++) {
         
        //       dp[i][j] = triangle[i][j] + min( dp[i+1][j+1] , dp[i+1][j]);
                 
        //     }
        // }

        // return dp[0][0];


        vector<int>next(n,0);
         
         next= triangle[n-1];

        for(int i=n-2; i>=0 ; i--) {

           

            for(int j =0 ; j<= i ; j++) {
         
              next[j] = triangle[i][j] + min(next[j] , next[j+1]);
                 
            }
        }
        return next[0];
    }
};