class Solution {
public:
    // bool helper(int ind , int total , vector<int> & nums , vector<vector<int>>& dp  ) {

    //     if(total == 0 ) return true;   
      
    //     if( ind == 0) return ( nums[0] == total);

    //     if(dp[ind][total] != -1 ) return dp[ind][total];
        
    //     bool take = false;

    //     if( nums[ind] <= total )
    //     take =  helper(ind-1 , total - nums[ind] , nums , dp);

    //     bool not_take = helper (ind-1 , total , nums , dp );

    //     return dp[ind][total] = take || not_take;

    // }

    bool canPartition(vector<int>& nums) {

        int totalSum = 0;
        int n = nums.size();

   
         for(int i=0; i<n ; i++) 
         totalSum+=nums[i];
     
        if(totalSum % 2 != 0) return false;

        int target = totalSum/2;

    //     // vector<vector<int>> dp( n , vector<int> (target+1 , -1));

    //     //  return helper(n-1 , totalSum/2 , nums , dp);

    //     vector<vector<int>>dp( n , vector<int>(target+1 , false));

    //     dp[0][0]= true;

    //    if(nums[0] <= target) 
    //    dp[0][nums[0]] = true;

    //     for(int i= 1 ; i< n ; i++ ) {
    //         for(int j=1 ; j<= target ; j++) {
               
    //             bool take = false;

    //             if( nums[i] <= j )

    //             take =  dp [i-1 ] [ j - nums[i] ];

    //             bool not_take = dp[ i-1 ] [ j ];

    //             dp[i][j] = take || not_take;
    //         }
    //     }

    //     return dp[n-1][target];

    // Space optimization

         vector<bool>prev(target+1 , false);

        prev[0]= true;

       if(nums[0] <= target) 
       prev[nums[0]] = true;

        // for(int i= 1 ; i< n ; i++ ) {

        //     vector<bool>curr(target+1 ,false) ;

        //     for(int j=1 ; j<= target ; j++) {
               
        //         bool take = false;

        //         if( nums[i] <= j )

        //         take =   prev [ j - nums[i] ];

        //         bool not_take = prev [ j ];

        //         curr[j] = take || not_take;
        //     } 

        //        prev = curr;

        //   }

       //    return prev[target];
    
       //   More Clean version 

        vector<bool> dp(target+1, false);
        dp[0] = true;
        if(nums[0] <= target) dp[nums[0]] = true;

       for(int i = 1; i < n; i++) 
       for(int j = target; j >= nums[i]; j--) 
        dp[j] = dp[j] || dp[j - nums[i]];
  
        return dp[target];
    }
};