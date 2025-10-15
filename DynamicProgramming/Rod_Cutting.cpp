// User function Template for C++

class Solution {
    
  public:
  
    // int helper(  int size , vector<int> & price , vector<int>& dp ) {
      
    //   if(size == 0 ) return 0;
      
    //   if( dp[size] != -1 ) return dp[size];
      
    //   int maxi=0;
      
    //   for(int cut = 1 ; cut <= size ; cut++ ) 
        
    //   maxi = max (maxi , price[cut-1] + helper( size - cut , price , dp));  
        
      
        
    //   return dp [size] = maxi;
        
        
    // }
    
    int cutRod(vector<int> &price) {
      
      int n = price.size(); 
      
    //   vector<int> dp (n+1, -1);
       
    //   return helper(  n ,  price , dp);
    
        vector<int>dp (n+1 , 0);
        
        for(int size =1 ; size <= n ; size++  ) {
        
                  int maxi=0;
      
                  for(int cut = 1 ; cut <= size ; cut++ ) 
                      
                  maxi = max (maxi , price[cut-1] + dp [ size - cut ] );
                      
                  dp [size] = maxi;
        
            
        }
        
        return dp[n];
    }
};