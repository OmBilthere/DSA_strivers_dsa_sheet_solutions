
class Solution {
    
  public:
  
    int LongestBitonicSequence(int n, vector<int> &nums) {
        
     
     vector<int>dp1(n , 1 );
     
     vector<int>dp2(n , 1);
     
     for(int ind =0 ; ind < n ; ind++ ) {
         
         for(int prev=0 ; prev< ind ; prev++ ) {
             
             if((nums[prev] < nums[ind]) && (dp1[ind] < (1 + dp1[prev])))
             
             dp1[ind] =  1 + dp1[prev];
             
         } 
     }
     
     for (int ind = n-1 ; ind >=0 ; ind--) {
         
         for(int next = n-1 ; next > ind ; next--) {
             
             if((nums[next] < nums[ind]) &&( dp2[ind] <(1+dp2[next])))
             
             dp2[ind] = 1 + dp2[next];
         }
     }
      
     
     int maxi = 0;
     
     for(int ind =0 ; ind < n ; ind ++ ) 
     
     if(dp1[ind] > 1 && dp2[ind] > 1)

     maxi = max (maxi , dp1[ind] + dp2[ind] -1);
     
     
     return maxi;
      
        
    }
};
