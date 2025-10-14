class Solution {
public:
    // int helper ( int ind , int amount , vector<int> & coins , vector<vector<int>> & dp) {

    //     if(ind == 0) 
    //     return (amount % coins[0] == 0 );
        
    //     if(dp[ind][amount] != -1 ) return dp[ind][amount];

    //     int take = 0;

    //     if(coins[ind] <= amount) 
    //     take = helper ( ind , amount - coins[ind] , coins , dp);
        
    //     int not_take = helper(ind-1 , amount , coins , dp );

    //     return dp[ind][amount] = take + not_take;

    // }

    int change(int amount, vector<int>& coins) {

        int n = coins.size();
        
    //     // vector<vector<int>> dp( n , vector<int>(amount+1 , -1 ));

    //     // return helper( n-1 , amount , coins , dp );

    //     vector<vector<long>> dp ( n , vector< long> (amount+1 , 0));
        
    //     for(int amt = 0; amt <= amount; amt++) 
    //     if(amt % coins[0] == 0)
    //     dp[0][amt] = 1;
       
        
    //     for(int ind = 1 ; ind < n ; ind++ ) {
            
    //         for(int amt= 0 ; amt <= amount ; amt ++ ) {
                  
    //              long not_take = dp [ind-1 ][ amt ];
                  
    //              long take = 0;

    //             if(coins[ind] <= amt) 
    //             take = dp [ ind ][ amt - coins[ind] ];
                

    //             dp[ind][amt] = take + not_take;

    //         }

    //     }
    // return  dp[n-1][amount]; 


        vector<unsigned long long> dp (amount+1 , 0);
        
        dp[0]=1;
       
        
        for(int ind = 0; ind < n ; ind++ ) {
            
            for(int amt= coins[ind] ; amt <= amount ; amt ++ ) {

                dp[amt] += dp[amt - coins[ind]];

            }

        }
    return  dp[amount]; 

    }
};