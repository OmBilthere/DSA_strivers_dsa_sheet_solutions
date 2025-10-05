class Solution {
public:
    // int helper(  int greed , int cookie , vector<int>& g , vector<int> & s , int n , int m ,    vector<vector<int>> & dp ) {

    //     if(greed == n || cookie == m) return 0;

    //     if(dp[greed][cookie] != -1) return dp[greed][cookie];

    //     int take = 0;
    //     if( g[greed] <= s[cookie] )
    //     take = 1 + helper( greed+1 , cookie+1 , g , s , n , m , dp);


    //     int not_take = helper( greed , cookie+1 , g , s , n , m , dp );

            
    //     return dp[greed] [cookie] = max(take , not_take);
    // }


    int findContentChildren(vector<int>& g, vector<int>& s) {

        // Greedy Solution

           int n = g.size() , m = s.size();

           sort(g.begin(),g.end());

           sort(s.begin(),s.end());

        // int cnt=0, i=0, j=0;

        // while(i<n && j<m){

        //     if(g[i]<=s[j])  cnt++  , i++ ,j++;
        //     else j++;

        // }

        // return cnt;

        //  Recursion (TLE) 

        
        // vector < vector< int>> dp( n+1 , vector<int>( m+1 , -1));

        // return helper( 0 , 0 , g , s , n , m , dp);


        // Tabulation (MLE)
        
        // vector<vector<int>>dp(n+1 , vector<int>(m+1 , 0));

        // for(int greed = n-1 ; greed >=0 ; greed--) {

        //     for(int cookie = m -1 ; cookie >=0 ; cookie--) {

        //     int take = 0;
        //     if( g[greed] <= s[cookie] )
        //     take = 1 + dp [greed + 1 ] [ cookie + 1];


        //     int not_take = dp [ greed ] [ cookie + 1 ];

                
        //      dp[greed] [cookie] = max(take , not_take); 
             
        //     }

        // } 

        // return dp [0][0];

        // Space Optimization 

        vector<int>dp (m+1 , 0);

        for(int greed = n-1 ; greed >=0 ; greed--) {

            for(int cookie = m-1 ; cookie >=0 ; cookie++) {

            int take = 0;
            if( g[greed] <= s[cookie] )
            take = 1 + dp [ cookie + 1];


            int not_take = dp [ cookie + 1 ];

                
             dp [cookie] = max(take , not_take); 
             
            }
        } 
        return dp [0];
    }
};