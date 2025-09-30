class Solution {
public: 
     
    
    // int helper (int ind , int sum , vector<int>& nums , int size ) {

    // if(size == 0 ) return abs(2*sum - totalsum);
    // if(ind == nums.size()) return INT_MAX;
    // int take   = helper(ind+1 , sum + nums[ind] , nums , size-1);

    // int not_take   = helper(ind+1 , sum, nums , size);
    
    // return min(take , not_take);

    //  }


    int minimumDifference(vector<int>& nums) {
    
    //     int totalsum =0;
    //     int n = nums.size();

    //     for(int i=0 ; i<n; i++) 
    //     totalsum+=nums[i]; 

    //     // return helper ( 0 ,0 , nums , n/2 );
        
     

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
    

    int totalSum = accumulate(begin(nums), end(nums), 0);
    int n = nums.size();

    auto left = findAllSubsetsSum(nums, 0, n / 2 - 1);
    auto right = findAllSubsetsSum(nums, n / 2, n - 1);
    int target = totalSum / 2, ans = INT_MAX;

    //we can take (0 to n/2) length numbers from left
    for (int i = 0; i <= n / 2; i++) {
        //now we take rest - (n/2-i) length from right, we sort it to binary search
        auto r = right[n / 2 - i];
        sort(begin(r), end(r));

        for (int curleftSum : left[i]) {
            int needSumFromRight = target - curleftSum;
            auto it = lower_bound(begin(r), end(r), needSumFromRight);
            if (it != end(r))
                ans = min(ans, abs(totalSum - 2 * (curleftSum + *it)));
        }
    }
    return ans;

    }

    vector<vector<int>> findAllSubsetsSum(vector<int>& nums, int l, int r) {
    int totLengthOfSubarray = r - l + 1;
    vector<vector<int>> res(totLengthOfSubarray + 1);
    for (int i = 0; i < (1 << totLengthOfSubarray); i++) {
        int sum = 0, countOfChosenNos = 0;
        for (int j = 0; j < totLengthOfSubarray; j++) {
            if (i & (1 << j)) {
                sum += nums[l + j];
                countOfChosenNos++;
            }
        }
        res[countOfChosenNos].push_back(sum);
    }
    return res;
}
}; 