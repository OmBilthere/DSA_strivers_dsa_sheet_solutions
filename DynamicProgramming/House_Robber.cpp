class Solution {
public:
    // int helper (vector<int>&nums , int ind  , vector<int>& dp) {

    //     if(dp[ind]!=-1) return dp[ind];
    //     if(ind==0) return nums[ind]; 
    //     if(ind==1) return max(nums[ind], nums[ind-1]);
       

    
    //     int take = nums[ind]+helper(nums,ind-2,dp);

    //     int not_take = helper(nums, ind-1,dp);

    //     return dp[ind] = max(take , not_take);

    // }
    
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
    //     // vector<int>dp(n,-1);
    //     // return helper(nums , n-1 ,dp);
       
    //     vector<int> dp(n);
    //     dp[0]=nums[0];
    //     dp[1]=max(nums[0],nums[1]);

    //     for(int i=2;i<n;i++) {

    //         int take = nums[i]+dp[i-2];

    //         int not_take = dp[i-1];

    //        dp[i] = max(take , not_take);
    //     }
       
    //    return dp[n-1];
    

       
      /* can also write
        int prev2 = nums[0];
        int prev1 = max(nums[0], nums[1]);

        for (int i = 2; i < n; i++) { 
            int cur = max(nums[i] + prev2, prev1);
            prev2 = prev1;
            prev1 = cur;
        }

        return prev1;

        instead of it ----     */
        
        int prev= nums[0];
        int prev2= 0; 

        for(int i=1;i<n;i++) {

            int take = nums[i]+prev2;

            int not_take= prev;
            
            int curr = max(take,not_take);

            prev2=prev;
            prev=curr;
            
        } 
       return prev;
    }
};