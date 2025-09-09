class Solution {
public:
//    int helper(int ind , vector<int>& heights , int k , vector<int> & dp) {

//     if(ind==0) return 0;
//     if(dp[ind]!=-1) return dp[ind];
//     int minstep=INT_MAX;

//     for(int i=1 ; i<=k ; i++) {
//         if(ind-i >= 0) {
//         int Jump =  helper(ind-i,heights,k)+abs(heights[ind]-heights[ind-i]);
//         minstep  = min( Jump, minstep);
//         }
//     }
//     return dp[ind]=minstep;

//    }
    int frogJump(vector<int>& heights, int k) {
        int n = heights.size();
    //     // vector<int>dp(n, -1);
    //     // return helper(n-1,heights,k,dp);
    //     vector<int>dp(n);
    //     dp[0]=0;
    //     for (int ind=1;ind<n;ind++) {

    //     int minstep=INT_MAX;
       
    //     for(int i=1 ; i<=k ; i++) {
               
    //           if(ind-i >= 0) {

    //            int Jump =  dp[ind-i]+abs(heights[ind]-heights[ind-i]);

    //            minstep  = min( Jump, minstep);
    //         }
    //         dp[ind]=minstep;
    //       }
          
    //     }

    //    return dp[n-1];
       
        vector<int>dp(n);
        
        dp[0] =0;

        for (int ind=1;ind<n;ind++) {

        int minstep=INT_MAX;
       
        for(int i=1 ; i<=k ; i++) {
               
              if(ind-i >= 0) {

               int Jump =  dp[ind-i]+abs(heights[ind]-heights[ind-i]);

               minstep  = min( Jump, minstep);

            }

            dp[ind]=minstep;
             
          }
          
        }

       return dp[n-1];
         

    }
};
