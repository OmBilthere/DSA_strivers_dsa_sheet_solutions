class Solution {
public:
    int minDistance(string word1, string word2) {

        int n = word1.size() ,   m = word2.size();

        vector<int> prev (m+1 , 0);

        for(int ind1 = 1 ; ind1 <= n ; ind1 ++ ) {

            vector<int>curr(m+1 , 0);
            
            for(int ind2 = 1 ; ind2 <= m; ind2++ ) {
              
               if( word1[ind1-1] == word2[ind2-1])
               
               curr[ind2] = 1 + prev[ind2-1];

               else   
               
               curr[ind2] = max (curr[ind2-1] , prev[ind2]);

               
            }

            prev = curr;

        }

        return (n + m)-(2*prev[m]) ;


    }
};