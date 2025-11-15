class Solution {
public:
    
    int helper( int ind , vector<int>& arr , int k , vector<int>& dp ) {
        
        if(ind == arr.size() ) return 0;

        if(dp[ind] != -1 ) return dp[ind];

        int maxi = 0;

        int maxEl = 0;

        for(int i= ind ; i < min((int) arr.size() , ind+k ) ; i++) {
        
           maxEl = max (maxEl , arr[i]);

           int len = i - ind + 1;

           int sum = (len * maxEl) + helper( i+1 ,arr , k , dp);

           maxi = max(maxi , sum);


           
        }

        return dp[ind]=maxi;
    }



    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        
        int n = arr.size();

        // vector<int> dp ( n  ,-1 );

        // return helper(0 , arr , k , dp);

        vector<int> dp ( n+1 , 0 );

        for(int ind = n-1 ; ind >=0 ; ind--) {
        
        int maxi = 0;

        int maxEl = 0;

        for(int i= ind ; i < min((int) arr.size() , ind+k ) ; i++) {
        
           maxEl = max (maxEl , arr[i]);

           int len = i - ind + 1;

           int sum = (len * maxEl) + helper( i+1 ,arr , k , dp);

           maxi = max(maxi , sum);


           
        }

         dp[ind]=maxi;

      }

        return dp[0];

    }


};