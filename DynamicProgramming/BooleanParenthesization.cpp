// User function Template for C++
class Solution {
  public:
  
    // int helper ( int start , int end , int isTrue ,  string &  s , vector<vector<vector<int>>>& dp ) {
        
    //     if(start > end ) return 0;
        

    //     if(start == end )  {
            
    //         if( isTrue ) return  s[start]=='T';
            
    //         else return  s[start]=='F';
    //     }
        
        
    //     if( dp[start][end][isTrue] != -1 ) return dp[start][end][isTrue];
        
        
    //     int ways = 0;
        
    //     for(int k = start+1 ; k < end ; k+=2) {
            
    //       int left_false = helper(start , k-1 , 0 , s , dp);
          
    //       int left_true = helper( start , k-1 , 1 , s , dp);
          
    //       int right_false = helper(k+1 , end , 0 , s , dp);
          
    //       int right_true  = helper(k+1 , end , 1 , s , dp);
          
    //       if(s[k] == '&') {
              
    //         if(isTrue)  ways+= ( left_true * right_true );
            
    //         else ways+= ((left_true *right_false) + (left_false * right_true) +
            
    //         (left_false * right_false));
            
    //       }
          
    //       else if(s[k]=='|') {
              
    //           if(isTrue) ways+= ((left_true * right_false )+
              
    //           (left_false * right_true) + (left_true * right_true));
              
    //           else ways+= (left_false * right_false);
    //       }
          
    //       else {
              
    //           if(isTrue) ways+=((left_true * right_false) + (left_false * right_true));
              
    //           else ways+= ((left_true* right_true) + (left_false * right_false));
              
    //       }
          
          
    //     }
        
    //     return dp[start][end][isTrue] = ways;
    // }
    
    
    int countWays(string &s) {
        
        int n = s.size();
        
        // vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, -1)));
      
        // return helper( 0 , n-1 , 1 , s , dp);
        
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, 0 )));
        
        for(int ind = 0 ; ind < n ; ind++ ) {
            
        dp[ind][ind][0] =  (s[ind]=='F');
        
        dp[ind][ind][1] = (s[ind] =='T');
            
        }
        
        for(int start= n-1; start >=0 ; start-- ) {
            
            for(int end = start+1 ; end< n ; end++ ) {
                
               for(int isTrue = 0 ; isTrue <=1 ; isTrue++) {
                   
                   int ways = 0;
        
                   for(int k = start+1 ; k < end ; k+=2) {
            
                   int left_false =dp[start][ k-1] [0];
          
                   int left_true = dp[ start ][ k-1 ] [1];
          
                   int right_false = dp[k+1] [ end ] [0];
          
                   int right_true  = dp[k+1][ end ] [1];
          
                   if(s[k] == '&') {
              
                   if(isTrue)  ways+= ( left_true * right_true );
            
                   else ways+= ((left_true *right_false) + (left_false * right_true) +
            
                   (left_false * right_false));
            
                   }
          
                  else if(s[k]=='|') {
                      
                      if(isTrue) ways+= ((left_true * right_false )+
                      
                      (left_false * right_true) + (left_true * right_true));
                      
                      else ways+= (left_false * right_false);
                  }
                  
                  else {
                      
                      if(isTrue) ways+=((left_true * right_false) + (left_false * right_true));
                      
                      else ways+= ((left_true* right_true) + (left_false * right_false));
                      
                  }
                  
                  
                }
                
                dp[start][end][isTrue] = ways;
                   
               }
            }
        }
        
        return dp[0][n-1][1];
    }
};