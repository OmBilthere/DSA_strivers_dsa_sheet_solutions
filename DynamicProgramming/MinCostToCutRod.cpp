class Solution {
public:
    
    // int helper(int start , int end , vector<int>& cuts) {
        
    //     if(start > end) return 0;

        // int mini = INT_MAX;

        // for(int k = start ; k <= end ; k++ )  {

        // int cost= (cuts[end+1]-cuts[start-1]) + helper(start , k-1, cuts) + helper( k+1 , end , cuts);

        // mini = min (mini , cost);

        // }

        // return mini;

    // }

    int minCost(int n, vector<int>& cuts) {

       cuts.push_back(0);

       cuts.push_back(n);
       
       sort(cuts.begin(), cuts.end());

    //    return helper( 1 , cuts.size()-2 , cuts );
       
       int c = cuts.size();

       vector<vector<int>>dp ( c , vector<int>( c , 0));

       for(int start = c-2 ; start >=1 ; start-- ) {

        for(int end = start ; end<= c-2 ; end++ ) {
             
         int mini = INT_MAX;

        for(int k = start ; k <= end ; k++ )  {

        int cost= (cuts[end+1]-cuts[start-1]) + dp[start][ k-1]+ dp[ k+1 ][end];

        mini = min (mini , cost);

        }

        dp[start][end] = mini;
      
        }

       }


     return dp[1][c-2];

    }
};