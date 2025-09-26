class Solution {
  public:
    // bool isAvailable( int ind ,  int sum , vector<int>&arr , int n , vector<vector<int>>& dp ) {
        
    //     if(sum == 0 ) return true;
        
    //     if(ind == 0) return arr[ind]== sum ;
        
    //     if(dp[ind][sum]!=-1) return dp[ind][sum];
        
    //     bool take = false;
        
    //     if(arr[ind] <= sum)
        
    //     take = isAvailable ( ind-1 , sum - arr[ind] , arr , n , dp );
        
    //     bool not_take = isAvailable ( ind-1 , sum , arr , n , dp );
        
    //     return dp[ind] [sum] = take || not_take;
        
    // }
    
    bool isSubsetSum(vector<int>& arr, int sum) {
        
           int n = arr.size();
           
    //     // vector<vector<int>>dp(n , vector<int> (sum+1 , -1 ));
    
    //     // return isAvailable( n-1 ,sum  , arr , n , dp);
     
    //       vector<vector<bool>>dp(n , vector<bool> (sum + 1 , 0 ));
  
    //       for(int i = 0 ; i< n ; i++) 
      
    //       dp[i] [0] = true;
      
    //       dp[0] [arr[0]] = true;

    //       for(int ind = 1 ; ind < n ; ind++ ) {
         
    //       for ( int target = 1 ; target <= sum ; target ++ )  {
             
    //       bool take = false;
        
    //       if(arr[ind] <= target )
        
    //       take = dp [ind-1] [ target - arr[ind] ];
        
    //       bool not_take = dp [ ind-1 ] [ target ];
        
    //      dp[ind] [target] = take || not_take;
        
             
    //      }
        
      
    //   }
      
    //   return dp [n-1] [sum];
    
   // space optimization
   
      vector<bool>prev ( sum+1 , 0 );
  
     if(arr[0] <= sum) prev[arr[0]] = true;
      
      prev[0] = true;
      

      for(int ind = 1 ; ind < n ; ind++ ) {
          
          vector<bool> curr (sum+1 , 0 );
       
          for ( int target = 1 ; target <= sum ; target ++ )  {
              
          curr[0] = true;

          bool take = false;
        
          if(arr[ind] <= target )
        
          take = prev [ target - arr [ind] ];
        
          bool not_take = prev [ target ];
        
         curr [target] = take || not_take;
        
             
         }
        
        prev = curr;
        
      }
      
      return prev [sum];
      
    }
};