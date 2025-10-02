class Solution {
public: 
     
    
    // int helper (int ind , int arr , vector<int>& nums , int size ) {

    // if(size == 0 ) return abs(2*arr - totalsum);
    // if(ind == nums.size()) return INT_MAX;
    // int take   = helper(ind+1 , arr + nums[ind] , nums , size-1);

    // int not_take   = helper(ind+1 , arr, nums , size);
    
    // return min(take , not_take);

    //  }


    int minimumDifference(vector<int>& nums) {
    
    //     int totalsum =0;
    //     int n = nums.size();

    //     for(int i=0 ; i<n; i++) 
    //     totalsum+=nums[i]; 

    //     // return helper ( 0 ,0 , nums , n/2 );
        
     
    //     below solution is for only positive in this case we have both -ve and +ve

    //     vector< bool > prev ( totalsum + 1 , false) ;
      
    //     prev[0] = true;

    //    if (nums[0] <= totalsum) 

    //    prev[nums[0]] = true;


    //     for(int ind=1 ; ind<n ; ind++) {

    //          vector< bool > curr ( totalsum+1 , false) ;
    //          curr[0]= true;
    //         for(int target=1 ; target<=totalsum; target++ ) {

    //          bool not_take = prev[target];
    //          bool take = false;
    //          if(nums[ind] <= target) take = prev[target - nums[ind]];
            
    //          curr[target] = take ||  not_take;

    //         }

    //         prev=curr;
    //     }
        
    //     int ans= INT_MAX;

    //     for(int target = 0 ;  target <= totalsum; target++) 
    //     if(prev[target] == true){
    //         int diff = abs (target- (totalsum-target));
    //         ans = min(ans ,diff);
    //     }
      
        

    //     return ans;

    //   Both above solution will give TLE & SLE because size in constraint is given 10^7....
    

  
    int n = nums.size()/2;

    int tot = 0;

    vector<int> num1 , num2; 

    for(int i=0 ; i< n ; i++) {
        num1.push_back( nums[i]);
        num2. push_back(nums[i+n]);
        tot += nums[i]+nums[i+n];

    }
     

    vector<vector<int>> sum1 (n+1) , sum2 (n+1);

    generate_subset( 0 , 0 , 0 , sum1 , num1 );
    generate_subset( 0 , 0 , 0 , sum2 , num2 );
    
    for(int i= 0 ; i < n ; i++ )
    sort(sum2[i].begin() , sum2[i].end());

    int minDiff = INT_MAX;

    for(int i=0 ; i< n ; i ++) 

     minDiff = min (minDiff , solve(sum1[i] , sum2[n-i] , tot));
    


    return minDiff;

   
    }

    int solve(vector<int>& sum1, vector<int>& sum2, int tot) {
    int n = sum1.size(), m = sum2.size();
    int minDiff = INT_MAX;
    for(int i = 0; i < n; ++i) {
        int target = tot / 2 - sum1[i];
        int lb = lower_bound(sum2.begin(), sum2.end(), target) - sum2.begin();
        if(lb < m) {
            minDiff = min(minDiff, abs(tot - 2 * (sum1[i] + sum2[lb])));
        }
        if(lb > 0) {
            minDiff = min(minDiff, abs(tot - 2 * (sum1[i] + sum2[lb - 1])));
        }
    }
    return minDiff;
}



   void generate_subset ( int ind , int cnt , int currSum ,  vector<vector<int>>& arr ,  
   
   vector<int> & num) {

      if( ind == num.size()) {
         arr[cnt].push_back(currSum);
         return;
      }
      generate_subset (ind+1 , cnt , currSum , arr , num );

      generate_subset (ind+1 , cnt+1 , currSum+num[ind] , arr , num );

   }
}; 