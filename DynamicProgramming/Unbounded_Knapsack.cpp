
class Solution {
    
  public:
  
    // int helper(int ind , int cap , vector<int>& val , vector<int>& wt , vector<vector<int>>& dp) {
        
    //     if( ind == 0 ) {
            
    //         if(wt[0] <= cap) 
    //         return (int) (cap/wt[0])* val[0];
            
    //         return 0;
            
    //     }
        
    //     if(dp[ind][cap] != -1) return dp[ind] [cap];
        
    //     int take = 0;
        
    //     if( wt[ind] <= cap ) 
        
    //     take = val[ind] + helper(ind , cap-wt[ind] , val , wt , dp);
        
    //     int not_take = helper(ind-1 , cap , val , wt , dp);
        
        
    //     return dp[ind][cap] = max(take , not_take);
        
    // }
    
    
   
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
       
       int n = val.size();
       
    //   vector<vector<int>>dp(n , vector<int>(capacity+1 , -1));
       
    //   return  helper( n-1 , capacity , val , wt , dp );
         
         
         
         vector<int> dp ( capacity+1 , 0 );
         
         for(int cap = wt[0] ; cap <= capacity ; cap ++ ) 
        
         dp[cap] =  (cap/wt[0])* val[0];
            
         
         for(int ind =1 ; ind < n ; ind ++ ) {
             
             for( int cap = wt[ind] ; cap <=capacity ; cap ++  ) {
              
                dp[cap]  =  max ( dp[cap] , val[ind] + dp [ cap - wt[ind] ] );
                
             }
             
         }
       
        return dp[capacity];
    }
}; 
