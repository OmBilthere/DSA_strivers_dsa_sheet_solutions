class Solution {

public:

    // int helper(int ind1 ,  int ind2 , int n , int m , string & text1 , string & text2 ,  vector<vector<int>>& dp  ) {
       
    //    if (ind1 == n || ind2 == m )

    //    return 0 ;

    //    if(dp[ind1][ind2] != -1 ) return dp[ind1][ind2];
    
    //    if(text1 [ ind1 ] == text2 [ ind2] )
       
    //   return 1 + helper(ind1+1 , ind2+1 , n , m , text1 , text2 ,dp );

    //    int skip1 = helper(ind1+1 , ind2 , n , m , text1 , text2 , dp );

    //    int skip2 = helper (ind1 , ind2+1 , n, m , text1 , text2 , dp);

    //    return dp[ind1] [ind2] = max( skip1 , skip2 );

    // }


    // Recursion 2 (from last indices to 0 ) Shifted right by 1 place to write tabulation easily
    // Shifting is commented after code line

    // int helper(int ind1 , int ind2 , string & s1 , string & s2 , vector<vector<int>>& dp) {
      
    //     if(ind1< 0 || ind2 < 0) // if(ind1==0 || ind2==0)
          
    //     return 0;
        
    //     if(dp[ind1][ind2] != -1 ) return dp[ind1][ind2];

    //     if(s1[ind1] == s2[ind2] ) // if(s1[ind-1] == s1[ind2-1])
    //     return dp[ind1][ind2] = 1 + helper(ind1-1 , ind2-1 , s1 , s2 , dp);

    //     return max ( helper(ind1-1 , ind2 , s1 ,s2 ,dp ) , helper(ind1 , ind2-1 , s1 ,s2 , dp));


    // }
  

    




    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        // // vector<vector<int>>dp( n , vector<int>( m , -1)); // vector<vector<int>>dp(n+1 , vector<int>(m+1 , -1));

        // // return helper( 0 , 0 , n , m , text1 , text2 , dp ); // return helper(n , m , text1 , text2 , dp);

       

        // vector<vector<int>>dp( n+1 , vector<int>( m+1 , 0 ) );

        // for(int ind1 = n-1 ; ind1 >=0 ; ind1-- ) {
            
        //     for(int ind2 = m-1 ; ind2 >=0 ; ind2-- ) {
   
        //         if(text1 [ ind1 ] == text2 [ ind2] )
                
        //         dp[ind1][ind2] = 1 + dp[ind1+1 ] [ ind2+1 ];

        //         else {

        //         int skip1 = dp [ind1+1 ] [ ind2 ];

        //         int skip2 =dp[ind1] [ ind2+1];
               
        //         dp[ind1] [ind2] = max( skip1 , skip2 );

        //         }

        //     }

        // }

        // return dp[0][0];


    //         Optimization 

    //         vector<int> next (m+1 , 0);
       

    //         for(int ind1 = n-1 ; ind1 >=0 ; ind1-- ) {
            
    //         vector<int> curr (m+1 , 0 );
            
    //         for(int ind2 = m-1 ; ind2 >=0 ; ind2-- ) {
   
    //             if(text1 [ ind1 ] == text2 [ ind2] )
                
    //             curr[ind2] = 1 + next [ ind2+1 ];

    //             else {

    //             int skip1 = next[ ind2 ];

    //             int skip2 = curr[ ind2+1];
               
    //              curr [ind2] = max( skip1 , skip2 );

    //        }


    //      }
              
    //     next = curr;

    // }

    //   return next[0];



    // Tabulation for Recursion 2 
    //    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    //     for (int i = 1; i <= n; i++) {
    //         for (int j = 1; j <= m; j++) {
    //             if (text1[i - 1] == text2[j - 1])
    //                 dp[i][j] = 1 + dp[i - 1][j - 1];
    //             else
    //                 dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    //         }
    //     }

    //     return dp[n][m];

    vector<int> prev(m + 1, 0), curr(m + 1, 0);

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (text1[i - 1] == text2[j - 1])
                    curr[j] = 1 + prev[j - 1];
                else
                    curr[j] = max(prev[j], curr[j - 1]);
            }
            prev = curr;
        }

        return prev[m];

    }
};