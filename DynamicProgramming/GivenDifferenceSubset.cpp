class Solution {
  public:
    // int helper(int ind , int target ,  vector<int> & arr , vector<vector<int>> & dp ) {
        
    //     if(ind == 0 ) {
    //         if(arr[0] == 0 && target == 0 ) return 2;
    //         if(arr[0] == target || target == 0 ) return 1;
    //         return 0;
    //     }
    //     if(dp[ind][target] != -1 ) return dp[ind][target];
        
    //     int take = 0 ;
        
    //     if(arr[ind]<= target)
    //     take = helper(ind-1 , target-arr[ind] , arr , dp );
        
    //     int not_take = helper(ind-1 , target , arr , dp );
        
    //     return dp[ind][target] = take+not_take;
        
    // }
    int countPartitions(vector<int>& arr, int d) {
        
        
        int n = arr.size();
        
        int Sum  = 0; 
        
        for(int i=0 ; i< n ; i++) 
        
        Sum+=arr[i];
        
         if((Sum+d)%2) return 0;
         
         int target = (Sum+d)/2;
         
        // // // OR 
        
        // // // if(sum < d || (sum - d) % 2 != 0) return 0;
        
        // // // int target = (sum - d )/2;
       
        
        // // vector<vector<int>>dp(n , vector<int>(target+1 , -1));
        
        // // return helper( n-1 , target , arr , dp) ;
        
        
        // vector<vector<int>>dp( n , vector<int>(target+1 , 0));
        
        

        //   if(arr[0] == 0) dp[0][0] = 2
        //   else dp[0][0] = 1;             

        //   if(arr[0] != 0 && arr[0] <= target) 
        //   dp[0][arr[0]] = 1;

            
            
            
        
        
        // for(int ind= 1 ; ind< n ; ind++ ) {
            
        //     for(int sum=0 ; sum <= target ; sum++ ) {
                
        //             int take = 0 ;
        
        //             if(arr[ind]<= sum)
                    
        //             take = dp[ind-1] [ sum -arr[ind]];
                    
        //             int not_take = dp[ ind-1 ] [ sum ];      
                    
        //             dp[ind][sum] = take+not_take ;
        
                
        //     }
        // }
        
        
        // return dp[n-1][target];
        
        // Space Optimization ------
        
          vector<int>dp(target+1 , 0);
        
        

          if(arr[0] == 0) dp[0] = 2;
          else dp[0] = 1;             

          if(arr[0] != 0 && arr[0] <= target) 
          dp[arr[0]] = 1;

            
            
            
        
        
        for(int ind= 1 ; ind< n ; ind++ ) {
            
            for(int sum=target ; sum >=0 ; sum-- ) {
                
                    int take = 0 ;
        
                    if(arr[ind]<= sum)
                    
                    take = dp [sum -arr[ind]];
                    
                    int not_take = dp[ sum ];      
                    
                    dp[sum] = take+not_take ;
        
                
            }
        }
        
        
        return dp[target];
        
        
        
    }
};