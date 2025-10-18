class Solution {
  public:
  
    // int helper (int ind1 , int ind2 , string &s1 , string & s2 , int & maxi) {
        
    //      if(ind1 < 0 || ind2 < 0 ) 
        
    //      return 0;
         
    //      int take=0;
        
    //      if(s1[ind1] == s2[ind2])
        
    //      take =  1 + helper(ind1-1 , ind2-1 , s1 , s2 ,maxi );
         
    //      maxi = max(maxi , take );
        
    //      helper(ind1-1 , ind2 , s1, s2 , maxi );
         
    //      helper(ind1 , ind2-1 , s1 , s2 , maxi);
    
    //     return take;
          
        
    // }
    
    int longestCommonSubstr(string& s1, string& s2) {
        // your code here
        int n = s1.size();
        int m = s2.size();
        
        int ans = 0;
        
        // // helper(n-1 , m-1 , s1 , s2 , ans); 
        
        // // return ans;
        
        // vector<vector<int>>dp( n+1 , vector<int>(m+1 , 0));
        
        // for(int ind1 =1 ; ind1 <= n ; ind1++ ) {
            
        //     for(int ind2 =1 ; ind2 <= m ; ind2++ ) {
            
        //          if(s1[ind1-1] == s2[ind2-1])  {
                     
        //          dp[ind1][ind2] = 1 + dp [ind1-1][ ind2-1 ];
                 
        //          ans = max ( ans , dp[ind1][ind2]);
                     
        //          }
                         
        //          else 
                 
        //          dp[ind1][ind2]=0;
                  
               
        
        //     }
            
        // }
        
        // return ans;
        
        
        vector<int>prev(m+1 , 0);
        
        for(int ind1 =1 ; ind1 <= n ; ind1++ ) {
            
          vector<int>curr(m+1 , 0);
            
            for(int ind2 =1 ; ind2 <= m ; ind2++ ) {
            
                 if(s1[ind1-1] == s2[ind2-1])  {
                     
                 curr [ind2] = 1 + prev[ ind2-1 ];
                 
                 ans = max ( ans , curr [ind2] );
                      
                 }
                         
                 else 
                 
                 curr [ind2]=0;
                  
               
        
            }
            
            prev = curr;
            
            
        }
        
        return ans;
    }
};