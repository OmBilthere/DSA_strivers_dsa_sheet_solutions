class Solution {
  public:
    // int findMincost(vector<int>& height , int ind , vector<int>& dp)  {
        
    //     if(dp[ind]!=-1) return dp[ind];
        
    //     if(ind == 0 ) return 0;
        
    //     int onestep = findMincost(height, ind-1, dp) + abs(height[ind]-height[ind-1]);
        
    //     int twostep=INT_MAX;
        
    //     if(ind>1) 
    //     twostep = findMincost(height, ind-2, dp) + abs(height[ind]-height[ind-2]);
      
        
    //     return dp[ind]= min(onestep, twostep);
        
    // }
    int minCost(vector<int>& height) {
      
        // // int ind = height.size()-1;
        
        // // vector<int>dp(ind+2 , -1);
        
        // // return findMincost(height,ind , dp);
        
        
        
         int n=height.size();
         
        //  vector<int> dp(n+1);
         
        //  dp[0] = 0;
        
         
          
        //  for(int i =1; i < n; i++) {
             
        //      int onestep = dp[i-1]+abs(height[i]-height[i-1]);
        //      int twostep=INT_MAX;
        //      if(i>1)
        //      twostep = dp[i-2]+abs(height[i]-height[i-2]);
             
        //      dp[i]= min(onestep,twostep);
             
        //  }
         
        //  return dp[n-1];
               
              int  prev= 0 , prev2 =0;
              
              for(int i =1; i < n; i++) {
             
             int onestep = prev+abs(height[i]-height[i-1]);
             
             int twostep=INT_MAX;
             
             if(i>1)
             
             twostep =prev2+abs(height[i]-height[i-2]);
             
             prev2=prev;
             
             prev= min(onestep,twostep);
             
         }
         
         return prev;
        
    }
};