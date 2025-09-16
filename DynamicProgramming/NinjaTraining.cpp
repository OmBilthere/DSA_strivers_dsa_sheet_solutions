class Solution {
  public:
//   int helper (int ind , vector<vector<int>> & arr , int last , vector<vector<int>>& dp) {
    
//     int maxi=0;
    
//      if(ind==0) {
  
      
//       for(int i=0;i<3;i++) {
          
//       if(i!=last)
       
//         maxi = max(maxi, arr[ind][i]);
         
//       }
       
//         return maxi;
//      }
     
//      if(dp[ind][last]!=-1) return dp[ind][last];
     
//      for(int i=0;i<3;i++) {
    
//      if(i!=last)   {
         
//      int take = arr[ind][i]+helper(ind-1,arr,i,dp);
     
//      maxi=max(maxi,take);
      
//         }
     
//       }
     
     
//      return dp[ind][last] = maxi;
//   }
   
   

    int maximumPoints(vector<vector<int>>& arr) {

        int n=arr.size();
        
        // // vector<vector<int>>dp(n,vector<int>(4,-1)) ;
       
        // // return helper(n-1 , arr , 3, dp);
        
        
        
        // // Tabulation
        
        // vector<vector<int>>dp(n, vector<int>(4,0));
        
        // dp[0][0] = max(arr[0][1] , arr [0][2]);
        // dp[0][1] = max(arr[0][0] , arr [0][2]);
        // dp[0][2] = max(arr[0][1] , arr [0][0]);
        // dp[0][3] = max(arr[0][0],max(arr[0][1],arr[0][2]));
        
       
        
        // for(int day=1 ; day<n ; day++ ) {
            
        //     for(int last=0; last<4 ; last++ ) {
                
        //         int maxi =0;
                
        //         for(int task = 0 ; task <3 ; task++ ) {
                    
                
        //             if(task != last ) {
                   
               
        //                  int take = arr[day][task] + dp[day-1][task];
               
        //                  maxi = max (maxi , take);
           
        //             }
          
        //         }
                
        //         dp[day][last] = maxi;
               
        //     }
        // }
        // return dp[n-1][3];
        
        vector<int>dp(4);
        
        dp[0] = max(arr[0][1] , arr [0][2]);
        dp[1] = max(arr[0][0] , arr [0][2]);
        dp[2] = max(arr[0][1] , arr [0][0]);
        dp[3] = max(arr[0][0],max(arr[0][1],arr[0][2]));
        
        
        for(int day=1 ; day<n ; day++ ) {
            
            vector<int>temp(4,0);
            
            for(int last=0; last<4 ; last++ ) {
                
                int maxi =0;
                
                for(int task = 0 ; task <3 ; task++ ) {
                    
                
                    if(task != last ) {
                   
               
                         int take = arr[day][task] + dp[task];
               
                         maxi = max (maxi , take);
           
                    }
                    
                    
          
                }
      
                temp[last] = maxi;
        
               
            }
            
            dp=temp;
            
        }
        return dp[3];
    }
};