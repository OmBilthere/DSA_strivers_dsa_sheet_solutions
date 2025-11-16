class Solution {
public:
    int HistogramArea ( vector<int>& heights) {
      
        int n = heights.size();

        stack<int> st;  
        
        int maxArea = 0;

        for (int i = 0; i <= n; i++) {

            int currHeight = (i == n ? 0 : heights[i]);

            while (!st.empty() && currHeight < heights[st.top()]) {

                int h = heights[st.top()];

                st.pop();

                int right = i - 1;

                int left = st.empty() ? 0 : st.top() + 1;

                int width = right - left + 1;

                maxArea = max(maxArea, h * width);
                
            }

            st.push(i);
        }

        return maxArea;
    }


    int maximalRectangle(vector<vector<char>>& matrix) {

        int n = matrix.size();

        int m = matrix[0].size();

        int maxi = 0;
    
        vector<int>height( m );

        for( int i = 0 ; i < n ; i++ ) {

            for(int j = 0 ; j < m ; j++ ) {

                 if(matrix[i][j] == '1')

                 height[j]++;

                 else 

                 height[j] = 0;

            }

           int area = HistogramArea(height);

           maxi = max ( maxi , area);  


        }

        return maxi;

    }


};