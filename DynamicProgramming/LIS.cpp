class Solution {
public:
    // int helper ( int ind , int prev_ind , vector<int>& nums , vector<vector<int>>& dp ) {

    //    if( ind == nums.size() ) return 0; 

    //    if(dp[ind][prev_ind +1 ] != -1) return dp[ind][ prev_ind +1 ];
    
    //    int not_take = helper(ind+1 , prev_ind , nums , dp );

    //    int take = 0;
       
    //    if( prev_ind == -1  || nums[ind] > nums[prev_ind] ) 
         
    //    take =  1 + helper(ind+1 , ind  , nums , dp);

    //    return dp[ind][prev_ind+1] = max(take , not_take ) ;
       
    // }

    int lengthOfLIS(vector<int>& nums) {

        int n = nums.size();
               
        // // vector<vector<int>>dp ( n , vector<int>(n+1 , -1 ));   
       
        // // return helper (0 , -1 , nums , dp) ;

        // vector<vector<int>>dp ( n+1, vector<int>(n+1 , 0 ));

        // for(int ind = n-1 ; ind >= 0 ; ind--) {

        //     for(int prev_ind = ind-1 ; prev_ind >= -1 ; prev_ind-- ) {

        //            int not_take = dp [ind+1 ] [ prev_ind +1 ];

        //            int take = 0;
                
        //            if( prev_ind == -1  || nums[ind] > nums[prev_ind ] ) 
                    
        //            take =  1 + dp [ind+1] [ ind+1 ];

        //           dp[ind][prev_ind+1] = max(take , not_take ) ;
       

        //     }

        // } 

        //    return dp[0][0];

        vector<int>dp(n+1 , 0 );

        for(int ind = n-1 ; ind >= 0 ; ind--) {

            for(int prev_ind = ind-1 ; prev_ind >= -1 ; prev_ind-- ) {

                   int not_take = dp [ prev_ind +1 ];

                   int take = 0;
                
                   if( prev_ind == -1  || nums[ind] > nums[prev_ind ] ) 
                    
                   take =  1 + dp [ ind+1 ];

                  dp[prev_ind+1] = max(take , not_take ) ;
       

            }

        }   
           return dp[0];

    }
};