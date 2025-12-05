class Solution {
public:
   

    int orangesRotting(vector<vector<int>>& grid) {
       
       int n = grid.size();

       int m = grid[0].size();

       vector<vector<int>>vis = grid ;

       queue<pair<int, int>> q;

       int freshOrange = 0 ;

      for(int i = 0 ; i < n ; i++ ) {

        for(int j = 0 ; j < m ; j++ ) {
           
           if(grid[i][j] == 1 ) freshOrange++;

           else if ( grid[i][j] == 2 ) q.push({i , j });

        }
      }
      
      if( freshOrange == 0 ) return 0 ; 

      if( q.empty()) return -1;
      
      int dx[4] = { 0 , 0 , -1 , 1} ;

      int dy[4] = { 1 , -1 , 0 , 0} ;

      int minute = -1;

      while(!q.empty()) {

        int size = q.size();
        
        for(int i = 0 ; i < size ; i++) {

         int x = q.front().first;

         int y = q.front().second;

         q.pop();
        
         for(int i = 0 ; i< 4 ; i++ ) {

            int nx = x + dx[i];

            int ny = y + dy[i];

            if(nx >=0 && nx < n && ny>=0 && ny< m && vis[nx][ny] ==1 ) {

                vis[nx][ny] = 2 ;
                
                freshOrange--;

                q.push({ nx , ny });

            }

         }   

      }
     
  
       minute++;
    }

       if(!freshOrange) return minute ;

       return -1;
    }
};