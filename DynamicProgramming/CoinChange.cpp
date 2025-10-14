class Solution {
public:
    // int helper(int ind , vector<int>& coins , int amount , vector<vector<int>>& dp ) {

    //    if(ind == 0 ) {

    //    if(amount % coins[ind] == 0 )
    //    return amount / coins[ind];
    //     else
    //    return 1e9;


    //    }

    //    if(dp[ind][amount] != -1 ) return dp[ind][amount];

    //   int take = 1e9;

    //   if(coins [ind] <= amount) 

    //   take = 1 + helper(ind, coins , amount-coins[ind] , dp );

      

    //   int not_take = helper(ind-1 , coins , amount , dp);

    //   return dp[ind][amount] = min (take , not_take);

    // }

    int coinChange(vector<int>& coins, int amount) {

        int n = coins.size();

        sort(coins.begin() , coins.end());

    //     // vector<vector<int>>dp(n , vector<int>(amount+1 , -1));

    //     // int ans = helper(n-1 , coins , amount , dp );

    //     // if(ans< 1e9 ) return ans;

    //     // return -1;

    //    vector<vector<int>>dp(n , vector<int>(amount+1 , 1e9));

    //     for(int i=0 ; i<= amount ; i++)  {

    //        if( i % coins[0] == 0 )
    //         dp[0][i] = i / coins[0];  
        
    //     }
     

    //    for(int ind = 1 ; ind < n ; ind ++ ) {
        
    //     for(int amt = 0 ; amt <= amount ; amt++ ) {
             
    //         int take = 1e9;

    //         if(coins [ind] <= amt) 

    //         take = 1 + dp[ind] [ amt - coins[ind] ];
            

    //         int not_take = dp[ind-1]  [ amt ];

    //         dp[ind][amt] = min (take , not_take);

    //     }

    //    }

    //  if (dp[n-1][amount] < 1e9 ) return dp[n-1][amount];

    //  return -1;


        vector<int>dp (amount+1 , 1e9);

        for(int i=0 ; i<= amount ; i++)  {

           if( i % coins[0] == 0 )
            dp[i] = i / coins[0];  
        
        }
     

       for(int ind = 1 ; ind < n ; ind ++ ) {
        
        for(int amt = 0 ; amt <=amount ; amt++ ) {
             
            int take = 1e9;

            if(coins [ind] <= amt) 

            take = 1 + dp[ amt - coins[ind] ];
            

            int not_take = dp[ amt ];

            dp[amt] = min (take , not_take);

        }

       }

     if (dp[amount] < 1e9 ) return dp[amount];

     return -1;


    }

     
};