class Solution {
public:

    // int helper (int n, vector<int>& dp ) {
    //      if(n<0) return 0;
    //     if(dp[n]!=-1) return dp[n];
    //     if(n==0) return 1;
       
    //     int oneStep =helper(n-1,dp);
    //     int twoStep = helper(n-2,dp);
        
    //     return dp[n]=oneStep+twoStep;

    // }

    int climbStairs(int n) {
    //   vector<int>dp(n+1, -1);
    //   return helper(n,dp);
    if(n==0 || n==1) return 1;

    int prev2= 0;
    int prev=1;

    for(int i=1;i<=n;i++) {
       int curr= prev2+prev;
       prev2=prev;
       prev=curr;
    }
    return prev;
      
    }
};