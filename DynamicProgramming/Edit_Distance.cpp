class Solution {
public:
    int minDistance(string word1, string word2) {

        int n = word1.size();

        int m = word2.size();

    //     vector<vector<int>>dp( n+1 , vector<int>(m+1 , 0 ));

    //     for(int i=0; i<=n ; i++ ) 

    //     dp[i][0] = i ;

    //     for(int j=0 ; j<=m ; j++ ) 

    //     dp[0][j] = j;

    //     for(int i = 1 ; i<=n ; i++) {

    //         for(int j=1 ; j<=m ; j++ ) {

    //             if(word1[i-1] == word2[j-1])
    //             dp[i][j] = dp[i-1][j-1]; 

    //             else  
    //             dp[i][j] = 1 + min (dp[i-1][j]  , min( dp[i][j-1] , dp[i-1] [j-1]) );


    //         }

    //     }

   
    // return dp[n][m];

        vector<int>dp (m+1 , 0 );

        
        for(int i=0 ; i<=m ; i++) 

        dp[i] = i;
     
        for(int i = 1 ; i<= n ; i++) {
           
            int diag = dp[0];

            dp[0]= i ;

            for(int j=1 ; j <= m ; j++ ) {

                int temp = dp[j];

                if(word1[i-1] == word2[j-1])
                dp[j] = diag; 

                else  
                dp[j] = 1 + min (dp[j]  , min( dp[j-1] ,  diag) );
                
                diag = temp;

            }

        }

   
    return dp[m];

    }
};