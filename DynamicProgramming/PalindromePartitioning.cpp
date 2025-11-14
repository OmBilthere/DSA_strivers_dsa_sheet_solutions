class Solution {

public:

    bool isPalindrome ( int start , int end , string & s) {

        while(start < end ) {

           if(s[start] != s[end]) 

           return false; 

           start++;
        
           end--; 

        }

        return true;
    }
    
    // int helper ( int start , string & s , vector<int>& dp) {


    //     if(start == s.size() || isPalindrome(start , s.size()-1 , s ) ) return 0;

    //     if(dp[start] != -1) return dp[start];

    //     int cut = INT_MAX;

    //     for(int k = start ; k < s.size() ; k++) {
        
    //     if( isPalindrome(start , k , s)) {
            
    //         int cnt = 1 + helper (k+1 , s , dp );

    //         cut = min ( cut , cnt);
    //     } 
           
    //     }

    //     return dp[start] = cut;
    // }

    int minCut(string s) {

         int n = s.size();

        //  vector<int> dp( n , -1);

        //  return helper( 0 , s , dp ); 
        
        vector<int>dp( n+1 , 0 );

        dp[n] = -1;

        if( isPalindrome( 0 , n-1 , s)) 

        return 0;
        
        for(int start = n-1 ; start >=0 ; start--) {
            
        int cut = INT_MAX;

        for(int k = start ; k < n ; k++) {
        
        if( isPalindrome(start , k , s)) {
            
            int cnt = 1 + dp[k+1];

            cut = min ( cut , cnt);
        } 
           
        }

        dp[start] = cut;


        }

      return dp[0];

    }

};