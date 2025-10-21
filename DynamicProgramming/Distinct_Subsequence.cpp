class Solution {
public:


    //   int helper (int ind1 , int ind2 , string &s , string & t ) {
        
    //     if(ind2 == t.size()) return 1;

    //     if(ind1 == s.size() ) return 0;

    //    int not_take = helper(ind1+1 , ind2 , s , t  );

    //    int take=0;
       
    //    if(s[ind1] == t[ind2])

    //    take = helper (ind1+1 , ind2+1 , s , t );

    //    return not_take + take;
        
    //  }

    int numDistinct(string s, string t) {

        int n = s.size(); 
        int m = t.size();
    
//    //   return helper( 0 , 0 , s , t );
        
//     //     vector<vector<double>>dp(n+1 , vector<double>(m+1 , 0));
        
//     //     for(int ind = 0 ; ind <= n ; ind ++ )

//     //     dp[ind][m] = 1 ;      

//     //     for(int ind1 = n-1 ; ind1 >=0 ; ind1-- ) {

//     //         for(int ind2 = m-1 ; ind2 >=0 ; ind2-- ) {
                
//     //             double not_take = dp[ind1+1] [ ind2 ];

//     //             double take=0;
                
//     //             if(s[ind1] == t[ind2])

//     //             take = dp[ ind1 + 1 ][ ind2 + 1 ];

//     //             dp[ind1][ind2] = not_take + take;

//     //         }

//     //     }
       
//     //    return (int) dp[0][0];

    //       vector<double>next (m+1 , 0);

    //       next[m] = 1 ;      

    //     for(int ind1 = n-1 ; ind1 >=0 ; ind1-- ) {

    //         vector<double>curr(m+1 , 0);
            
    //         curr[m] = 1 ;

    //         for(int ind2 = m-1 ; ind2 >=0 ; ind2-- ) {
                
    //             double not_take = next [ ind2 ];

    //             double take=0;
                
    //             if(s[ind1] == t[ind2])

    //             take = next[ ind2 + 1 ];

    //             curr[ind2] = not_take + take;

    //         }
             
    //          next = curr;

    //     }
       
    //    return (int) next[0];

         vector<double>dp (m+1 , 0);

          dp[m] = 1 ;      

        for(int ind1 = n-1 ; ind1 >=0 ; ind1-- ) {

            for(int ind2 = 0 ; ind2 < m ; ind2++ ) {
             
                if(s[ind1] == t[ind2])

                dp[ind2] += dp [ ind2 + 1 ];

             

            }
             
           

        }
       
       return (int) dp[0];
    }

};