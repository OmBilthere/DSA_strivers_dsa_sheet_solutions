class Solution {
public:
    // int helper ( int start , int end , vector<int>& nums , vector<int>& dp ) {
    //     int  ind = end-start;
    //     if(start > end ) return 0;
    //     if(dp[ind]!=-1) return dp[ind];
    //     if(end==start) return nums[start];

    //     int take= nums[end] + helper(start, end-2, nums, dp);
    //     int not_take= helper(start, end-1 , nums , dp );

    //     return dp[ind]= max(take , not_take);

    // }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        // vector<int> dp1(n-1,-1) , dp2(n-1 , -1);

        // int case1 =  helper(0,n-2,nums,dp1);
        // int case2 = helper(1,n-1,nums,dp2);

           int case1 = helper (0,n-2, nums);
           int case2 = helper (1,n-1, nums);
           return  max(case1, case2);


    }

    int helper(int start , int end , vector<int>& nums) {

         int len = end-start+1;

    //      vector<int>dp(len,0);

    //      dp[0]=nums[start];

    //      for(int i=1;i<len ; i++) {
        
    //     int take= nums[start+i];

    //     if(i>1) take+=dp[i-2];

    //     int not_take= dp[i-1];

    //     dp[i] = max(take, not_take);

    //    }

    //     return dp[len-1]; 
    
        int prev2 = 0, prev1 = 0;
        for (int i = start; i <= end; i++) {
            int take = nums[i] + prev2;
            int not_take = prev1;
            int cur = max(take, not_take);
            prev2 = prev1;
            prev1 = cur;
        }
        return prev1;

   
    }
};