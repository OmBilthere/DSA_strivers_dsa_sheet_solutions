class Solution {
public:

    // bool helper (int ind1 , int ind2 , string s , string p , vector<vector<int>> & dp ) {

    //   if(ind1 == 0 && ind2 == 0 ) return true;

    //   if(ind1 > 0 &&  ind2 == 0  ) return false;

    //   if(ind1 == 0 && ind2 > 0  ) {
        
    //     for(int i=1 ; i<= ind2 ; i++) {
            
    //         if(p[i-1] != '*')
    //         return false;

    //     }

    //     return true;

    //   }
       
    //   if (dp[ind1][ind2] != -1) return dp[ind1][ind2];

      
    //   if(s[ind1-1] == p [ind2 -1 ] || p [ind2 -1 ] == '?')

    //   return dp[ind1][ind2] = helper(ind1-1 , ind2-1 , s , p , dp);

    //   if( p[ind2 -1 ] == '*')

    //   return dp[ind1][ind2] = (helper(ind1-1 , ind2 , s , p ,dp ) || helper(ind1 , ind2-1 , s , p , dp ));  
       
    //   return dp[ind1][ind2] = false;

    // }


    bool isMatch(string s, string p) {

        int n = s.size();
        int m =p.size();
        
    //    // vector<vector<int>> dp (n+1 , vector<int>(m+1 , -1));

    //    // return helper( n , m , s , p , dp );
         
    //            vector<vector<bool>>dp(n+1 , vector<bool>(m+1 , false));

    //             dp[0][0] = true;
                
    //            for (int j = 1; j <= m; j++) {
            
    //             bool flag = true;

    //             for (int i = 1; i <= j; i++) {

    //             if (p[i-1] != '*') {

    //                 flag = false;

    //                 break;

    //             }

    //         }

    //         dp[0][j] = flag;

    //     }

    //        for(int ind1=1 ; ind1<=n ; ind1++  ) {

    //         for(int ind2=1 ; ind2<=m ; ind2++ ) {

    //          if(s[ind1-1] == p [ind2 -1 ] || p [ind2 -1 ] == '?')

    //          dp[ind1][ind2] = dp[ind1-1 ] [ ind2-1 ];

    //          if( p[ind2 -1 ] == '*')

    //         dp[ind1][ind2] = (dp[ind1-1 ] [ ind2 ] || dp[ind1 ] [ ind2-1 ]); 
             
    
            
    //    }


    //    }

    //    return  dp[n][m];

             vector<bool>dp(m+1 , false);

                dp[0] = true;
                
               for (int j = 1; j <= m; j++) {

                if (p[j-1] == '*')

                dp[j] = dp[j-1];

                else

                break;

            }
            
          

            for(int ind1=1 ; ind1<=n ; ind1++  ) {
  
            bool Diag = dp[0];

            dp[0] = false;

            for(int ind2= 1; ind2 <=m ; ind2++) {

            bool temp = dp[ind2];

             if(p [ind2 -1 ] == '?')

             dp[ind2] = Diag;

             else  if( p[ind2 -1 ] == '*')

            dp[ind2] = (dp [ ind2 ] || dp [ ind2-1 ]); 

            else
            
            dp[ind2] = (s[ind1-1] == p[ind2-1]) && Diag;

            Diag = temp;        
       }


       }

       return  dp[m];


    }


};