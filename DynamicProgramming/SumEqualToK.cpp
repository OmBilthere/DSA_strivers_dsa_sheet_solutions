class Solution {
  public:
  
    // 2 Recursion 
    
    // int helper( int ind , int target , vector<int>& arr  , vector<vector<int>>dp) {
        
    //      if(ind == arr.size()) {
    
    //         return (target == 0) ? 1 : 0;
    
    //     }
        
        
    //     if(dp[ind][target] != -1 ) return dp[ind][target];
        
    //     int take = 0;
        
    //     if(arr[ind] <= target)
        
    //     take = helper(ind+1 , target-arr[ind] , arr , dp );
        
    //     int not_take = helper(ind+1 , target, arr , dp );
        
    //     return take + not_take;
        
    //  }
    
    //  Another Recursion ----
    
    //     int helper( int ind , int target , vector<int>& arr  , vector<vector<int>>dp) {
        
    //     if (ind == 0) {
             
    //     if (target == 0 && arr[0] == 0) return 2; 
        
    //     if (target == 0 || target == arr[0]) return 1;
        
    //     return 0;
    
    //   }
        
        
    //     if(dp[ind][target] != -1 ) return dp[ind][target];
        
    //     int take = 0;
        
    //     if(arr[ind] <= target)
        
    //     take = helper(ind - 1 , target-arr[ind] , arr , dp );
        
    //     int not_take = helper(ind - 1 , target, arr , dp );
        
    //     return take + not_take;
        
    //  }
    
      int perfectSum(vector<int>& arr, int target) {
     
          int n = arr.size();
          
    // //     vector<vector<int>>dp( n, vector<int>(target+1 , -1));
     
    // //      return helper ( 0 , target , arr , dp);
    
    // //      return helper ( n-1 , target , arr , dp);
    
    //         vector<vector<int>>dp( n , vector<int>(target+1 , 0));
        
    //         if(arr[0] == 0 ) dp[0][0] = 2;
            
    //         else {
                
    //             dp[0][0] = 1;
                
    //             if(arr[0]<=target)
                
    //             dp[0][arr[0]] = 1;
    //         }

        
    //      for(int ind = 1 ; ind < n; ind++ ) {
            
    //         for(int sum = 0 ; sum <= target ; sum++ ) {
                
    //           int take = 0;
        
    //           if(arr[ind] <= sum)
        
    //           take =dp[ ind - 1 ] [ sum-arr[ind] ];
        
    //           int not_take = dp [ind -1 ] [ sum ];
        
    //           dp[ind] [sum ] = take + not_take;
         
    //         }
    //     }
        
    //   return dp[n-1][target];  
    
    //         Space optimization ---
    
            vector<int> prev (target+1 , 0);
        
            if(arr[0] == 0 ) prev[0] = 2;
            
            else {
                
                prev[0] = 1;
                
                if(arr[0]<=target)
                
                prev[arr[0]] = 1;
            }

        
         for(int ind = 1 ; ind < n; ind++ ) {
            
            for(int sum = target ; sum >=0 ; sum-- ) {
                
              int take = 0;
        
              if(arr[ind] <= sum)
        
              take = prev [ sum-arr[ind] ];
        
              int not_take = prev[ sum ];
        
              prev [sum ] = take + not_take;
         
            }
        }
        
      return  prev [target];  
    }
};