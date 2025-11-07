class Solution {
  public:
  
    // int helper ( int start , int end , vector<int>& arr , vector<vector<int>> & dp ) {
      
    //   if( start == end )  return 0 ;
      
    //   if( dp[start][end] != -1 ) return dp[start][end];
      
    //   int mini = 1e9;
      
    //   for( int k = start ; k <= end-1 ; k++ ) {
          
    //       int operations = ( arr[start -1 ] * arr[k] * arr[end] ) +
    //                       helper( start , k , arr , dp) + helper( k+1 , end ,arr , dp);
                           
    //       mini = min( mini , operations);                
    //   }
      
    //   return dp[start][end] = mini;
         
    // }
    
    int matrixMultiplication(vector<int> &arr) {
        
        int n = arr.size();
        
        // vector<vector<int>> dp ( n , vector<int>( n , -1) );
        
        // return helper( 1 , n-1 , arr , dp );
        
        vector<vector<int>> dp ( n , vector<int> (n , 0 ));
        
        for(int ind = 0 ; ind < n ; ind++) 
       
        dp[ind][ind]=0;
         
        for(int start = n-1 ; start >=1 ; start-- ) {
            
            for(int end = start+1 ; end < n ; end++ ) {
                
               int mini = 1e9;
      
                for( int k = start ; k <= end-1 ; k++ ) {
                    
                  int operations = ( arr[start -1 ] * arr[k] * arr[end] ) + dp[ start ][ k ] + dp[ k+1 ][ end];
                           
                  mini = min( mini , operations); 
                    
               
                }
                  
                 dp[start][end] = mini;
         
            }
            
        }
        
        return dp[1][n-1];
        
    }
};