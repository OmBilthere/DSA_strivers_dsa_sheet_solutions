class Solution {
public:
    int minInsertions(string s) {
        
        string s1 = s;

        string s2 = s; 

        reverse(s2.begin() , s2.end());

        int n = s1.size();
        
        int m = s2.size();

        vector<int> prev (m+1 , 0);

        for(int ind1 = 1 ; ind1 <= n ; ind1 ++ ) {

            vector<int>curr(m+1 , 0);
            
            for(int ind2 = 1 ; ind2 <= m; ind2++ ) {
              
               if( s1[ind1-1] == s2[ind2-1])
               
               curr[ind2] = 1 + prev[ind2-1];

               else   
               
               curr[ind2] = max (curr[ind2-1] , prev[ind2]);

               
            }

            prev = curr;

        }

        return n-prev[m];


    }
};