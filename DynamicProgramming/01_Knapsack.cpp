class Solution {
  public:
  
    // int helper( int ind , int weight , vector<int>& val , vector<int>& wt , vector<vector<int>>& dp) {
      
    //     if(ind == 0 ) {
          
    //       if(wt[ind] <= weight)
    //       return val[ind];
          
    //       return 0;
            
            
    //     }
        
        
    //     if(dp[ind][weight] != -1 ) return dp[ind][weight];
        
        
    //     int take = 0 ;
        
    //     if(wt[ind] <= weight ) 
        
    //     take = val[ind] + helper(ind-1 , weight-wt[ind] , val , wt , dp );
        
    //     int not_take = helper(ind-1 , weight , val , wt , dp );
        
        
    //     return dp[ind][weight] = max(take , not_take);
        
    // }
    
    
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
    
        int n = val.size();
        
        // // vector<vector<int>>dp( n , vector<int>(W+1 , -1));
        
        // // return helper( n-1 , W , val , wt , dp );
        
        // vector<vector<int>>dp(n , vector<int>(W+1 , 0 ));
        
        // for(int weight = 0 ; weight<= W ; weight++ ) 
        
        //   if(wt[0] <= weight)
          
        //   dp[0][weight] = val[0];
          

        
        
        // for(int ind =1 ; ind < n ; ind++ ) {
            
        //     for(int weight = 0 ; weight <= W ; weight ++ ) {
                
        //     int take = 0 ;
            
        //     if(wt[ind] <= weight ) 
            
        //     take = val[ind] + dp[ind-1 ][ weight-wt[ind]];
            
        //     int not_take = dp [ind-1 ] [ weight ];
            
            
        //     dp[ind][weight] = max(take , not_take);
                
                
        //     }
        
        // }
        
        // return dp[n-1][W];
        
        vector<int>dp (W+1 , 0 );
        
        for(int weight = 0 ; weight<= W ; weight++ ) 
        
          if(wt[0] <= weight)
          
          dp[weight] = val[0];
          

        
        
        for(int ind =1 ; ind < n ; ind++ ) {
            
            for(int weight = W ; weight >=0 ; weight -- ) {
                
            int take = 0 ;
            
            if(wt[ind] <= weight ) 
            
            take = val[ind] + dp [ weight-wt[ind] ];
            
            int not_take = dp [ weight ];
            
            
            dp [weight] = max(take , not_take);
                
                
            }
        
        }
        
        return dp[W];
        
    }
};