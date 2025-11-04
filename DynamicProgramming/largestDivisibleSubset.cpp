class Solution {
public:
    // vector<int> helper(int ind , int prev , vector<int>& nums , vector<vector<vector<int>>>& dp) {

    //     if(ind == nums.size() ) return {} ;
        
    //     if(!dp[ind][prev+1].empty())

    //     return dp[ind][prev+1];
        
    //     vector<int> not_take = helper(ind+1 , prev ,nums , dp);

    //     vector<int>take;

    //     if( prev== -1 ||  nums[ind] % nums[prev] == 0) {


    //         take = helper(ind+1  , ind  , nums , dp);
         
    //         take.push_back(nums[ind]);

    //     }

    //    if(take.size() > not_take.size())

    //    dp[ind][prev+1] = take;

    //    else

    //    dp[ind][prev+1] = not_take;


    //    return dp[ind][prev+1];

    // }

    vector<int> largestDivisibleSubset(vector<int>& nums) {

          int n = nums.size();

    //    vector<vector<vector<int>>>dp (n, vector<vector<int>>(n + 1, vector<int>()));

          sort(nums.begin() , nums.end());

    //    return   helper(0 , -1 , nums  , dp );

          vector<int>dp( n , 1 );

          vector<int>hash(n);

          int lastInd = 0 , maxi = 1;

          for(int ind = 0 ; ind < n ; ind++ )  {

          hash[ind] = ind;

          for(int prev = 0 ; prev < ind ; prev++ ) {
               
               if(nums[ind] % nums[prev] == 0 && dp[ind] < ( 1 + dp[prev] )) {

                  dp[ind] = 1+ dp[prev];

                  hash[ind] = prev;

               }

          }

               if(maxi < dp[ind]) {
                
                 maxi = dp[ind];

                 lastInd = ind;

               }

            

          }

       vector<int>ans;

       while( hash[lastInd] != lastInd ) {
         
         ans.push_back(nums[lastInd]);

         lastInd = hash[lastInd];

       }

       ans.push_back(nums[lastInd]);

       return ans;
         

      
    }

};