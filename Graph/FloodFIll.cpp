class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
      
        vector<vector<int>> modified = image;

        int initCol = image[sr][sc];

        if (initCol == color) return image;

        queue< pair<int , int>> q;

        modified[sr][sc] = color;

        q.push({sr , sc});

        int n = image.size();
        
        int m = image[0].size();

        int dx[4] = { 0 , 0 , 1 , -1 };

        int dy[4] = { 1 , -1 , 0 , 0 };

        while( !q.empty()) {
          
          int x = q.front().first;

          int y = q.front().second;

          q.pop();

          for( int i = 0 ; i< 4 ; i++ ) {
          
          int nx = x + dx[i];

          int ny = y + dy[i];

          if( nx >= 0 && nx < n && ny >= 0 && ny < m && modified[nx][ny] == initCol ) {

           q.push({ nx , ny });

           modified[nx][ny] = color;

          }

          }
        }

        return modified;
    }
};