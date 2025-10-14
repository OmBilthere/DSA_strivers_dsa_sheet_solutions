class Solution {
public:
    // int helper(int ind , int target , vector<int>& nums ,vector< unordered_map<int , int> >& dp) {
      
    //     if(ind < 0 ) {
    //         if( target == 0 ) return 1;
    //         return 0;
    //     }

    //     if(dp[ind].find(target)!= dp[ind].end()) return dp[ind][target];

    //     int plus   = helper(ind-1 , target-nums[ind] , nums ,dp );

    //     int minus = helper(ind-1 , target+nums[ind] , nums , dp );

    //     return plus+minus;

    // }
    int findTargetSumWays(vector<int>& nums, int target) {

        int n = nums.size()  ;

        // vector< unordered_map<int , int> > dp(n);
        // return helper(n-1 , target , nums , dp );

        // this problm can be done as subset difference equal to k

        int sum = 0;
        for(int i=0; i<n ; i++) 
        sum += nums[i];

        int goal = ( sum - target ) / 2 ;

        if( sum < abs(target) || (sum-target)%2 ) return 0;

        vector<int>prev(goal+1 , 0);

            if ( nums[0]==0 ) 
            prev[0]= 2;

            else prev[0] =1;

            if(nums[0]!=0 && nums[0]<= goal ) prev[nums[0]] = 1;

        

           for(int ind = 1 ; ind< n ; ind ++ ) {

            for(int t = goal ; t >= 0 ; t-- ) {
               
               int take = 0 ;
               if(t-nums[ind] >= 0)
               take = prev[ t - nums[ind]];
               int not_take = prev[t];

               prev[t] = take + not_take;
            }
        }

        return prev[goal];
    }
};