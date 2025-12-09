class Solution {

public:

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        queue<pair<int, int>>q;
        
        int n = mat.size();

        int m = mat[0].size();

        vector<vector<int>> updated ( n , vector<int>( m , INT_MAX) );

       for ( int i = 0 ; i< n ; i++ ) {

        for(int j = 0 ; j< m ; j++ ) {

            if(!mat[i][j]) {

            q.push({i , j });
            
            updated[i][j] = 0;

            }

        }
       }

        int dx[4] = { 0 , 0 , -1 , 1 };

        int dy[4] = { 1 , -1 , 0 , 0 };
       
       while(!q.empty()) {

     
         int row = q.front().first;

         int col = q.front().second;

         q.pop();
         
         for(int i = 0 ; i < 4 ; i ++ ) {

          int nx = row + dx[i];

          int ny = col + dy[i];

          if( nx >= 0 && ny >= 0 && nx < n && ny < m && ( updated[row][col] + 1 ) < updated[nx][ny] ) {

          updated[nx][ny] = updated[row][col] +1 ;

          q.push({nx, ny}); 
          
          }

         }


        

       }

       return updated;
      
    }
};