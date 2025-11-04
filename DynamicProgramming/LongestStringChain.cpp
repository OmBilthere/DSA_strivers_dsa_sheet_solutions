class Solution {
public:

    static bool cmp ( string & a , string & b) {

        return a.size() < b.size();

     }

      bool compare(string &a, string &b) {

        if (a.size() != b.size() + 1) return false;

        int p = 0 , q = 0;

        while(p < a.size()) {
            
            if(q < b.size() && a[p] == b[q] ) 
            p++ , q++;

            else
            p++;


        }

        return q == b.size();
      
    }

 

    int longestStrChain(vector<string>& words) {

        int n = words.size();
        
        sort (words.begin() , words.end() , cmp);

        vector<int>dp(n , 1);
        
        int maxi = 0 ;

        for(int ind =0 ; ind < n ; ind ++ ) {
            
            for(int prev = 0 ; prev < ind ; prev++  ) {

                if(compare(words[ind] , words[prev]) && dp[ind] < ( 1+ dp[prev])) 
                
                dp[ind] = 1 + dp[prev];

            }

            maxi = max ( maxi , dp[ind]);

 
        }

        return maxi;

    }
};