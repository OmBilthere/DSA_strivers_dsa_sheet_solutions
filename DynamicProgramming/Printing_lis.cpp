class Solution {
  public:
    vector<int> getLIS(vector<int>& arr) {
        
        int n = arr.size();
        
        int maxi = 0;
        
        int lastInd = 0;

        vector<int>dp (n , 1 ) , hash(n);

        for(int ind=0 ; ind<n ; ind++) {
            
            hash[ind] = ind;

            for(int prev=0; prev< ind ; prev++) {

                if( arr [prev] < arr[ind] &&( 1 + dp[prev] ) >  dp[ind]) {
     
                hash[ind] = prev;
                
                dp[ind] = 1 + dp[prev];  
                    
               }


            }

           if(dp[ind] > maxi ) {
               
               maxi = dp[ind];
               
               lastInd = ind;
               
           }
           

        }
       
          vector<int> lis;
          
         
          while(hash[lastInd]!= lastInd) {
              
              lis.push_back(arr[lastInd]);
              
              lastInd = hash[lastInd];
              
          }
          
          lis.push_back(arr[lastInd]);
          
          reverse(lis.begin() , lis.end());
     
        return lis;  
        
        
      
    }
};