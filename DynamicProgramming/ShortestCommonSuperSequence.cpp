class Solution {
public:
    // string helper (int ind1 , int ind2 , string & s1 , string & s2 , int n , int m , vector<vector<string>>& dp ) {

    //     if(ind1 == n || ind2 ==  m ) return "";

    //     if(dp[ind1][ind2] != "" ) return dp[ind1][ind2];

    //     if(s1[ind1 ] == s2[ind2] ) return dp[ind1][ind2] =s1[ind1] + helper(ind1+1 , ind2+1 , s1 , s2 , n , m , dp );

    //     string skip1 = helper(ind1+1 , ind2 , s1 , s2 , n , m , dp );
    //     string skip2 = helper(ind1 , ind2+1 , s1 , s2 , n , m , dp );
       
    //     return dp[ind1][ind2] = skip1.size() > skip2.size() ? skip1 : skip2;

    // }

    string shortestCommonSupersequence(string str1, string str2) {

        int n = str1.size();

        int m = str2.size();

        // vector<vector<string>>dp(n+1 , vector<string>(m+1 , ""));
        // string lcs = helper( 0 , 0 , str1 , str2 , n , m , dp );
        
        vector<vector<int>> dp (n+1 , vector<int>(m+1 , 0));

        for(int ind1= 1 ; ind1 <= n ; ind1++ ) {

            for(int ind2= 1 ; ind2 <=m ; ind2++ ) {
                
                if( str1[ind1-1] == str2[ind2-1] )

                dp[ind1][ind2] = 1 + dp[ind1-1][ind2-1];

                else 

                dp[ind1][ind2] = max(dp[ind1-1][ind2] , dp[ind1][ind2-1]);
            }

        }


            int i = n , j = m;

            string lcs = "";

            while(i>0 && j>0) {

                if(str1[i-1] == str2[j-1])

                lcs+=str1[i-1] , i-- , j--;

                else {

                    if(dp[i-1][j] > dp[i][j-1])

                    i--;

                    else

                    j--;
                
                }
            }

            reverse(lcs.begin() , lcs.end() );

            i = 0 , j = 0 ;

            string ans = "";
                
            for(int k = 0 ; k < lcs.size() ; k++ ) {

                while(str1[i] != lcs[k])

                ans+=str1[i++];

                while(str2[j] != lcs[k])

                ans+=str2[j++];

                ans += lcs[k];

                i++ , j++;
                

            }

            while(i < n) ans += str1[i++];
            
            while(j < m) ans += str2[j++];


            return ans;

            }
};