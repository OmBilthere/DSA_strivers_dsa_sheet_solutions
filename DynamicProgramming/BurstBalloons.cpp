class Solution {
public:
    // int helper (int start , int end , vector<int>& nums)  {
        
    //     if(start > end) return 0;

        // int maxi = INT_MIN;

        // for(int k= start ; k<= end ; k++ ) {

        //  int coins = nums[start-1]*nums[k]*nums[end+1] + helper( start , k-1 , nums )  + helper(k+1 , end , nums) ;
         
        //  maxi = max(maxi , coins);

        // }

        // return maxi;
    // }

    int maxCoins(vector<int>& nums) {
        
        nums.insert(nums.begin(), 1);

        nums.push_back(1);

        int n = nums.size();

        // return helper(1, n - 2, nums);

        vector<vector<int>>dp( n , vector<int> ( n , 0));

        for(int start = n-2 ; start >=1 ; start--  ) {

            for(int end = start ; end <= n-2 ; end++ ) {

               int maxi = INT_MIN;
  
               for(int k= start ; k<= end ; k++ ) {

               int coins = nums[start-1]*nums[k]*nums[end+1] + dp[ start ][k-1 ]  + dp[k+1][ end ];
         
               maxi = max(maxi , coins);

              }

              dp[start][end] = maxi;

            }


        } 
      
      return dp[1][n-2];

    }


};