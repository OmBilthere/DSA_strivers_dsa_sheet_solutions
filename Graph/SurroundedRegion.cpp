class Solution {
public:
    void dfs ( int row , int col , vector<vector<char>>& board) {

    if(  row < 0 || col < 0 || row >= board.size() || col >= board[0].size() || board[row][col] != 'O') return ;

    board[row][col] = 'T';

    dfs(row+1 , col , board);

    dfs(row-1 , col , board);

    dfs(row , col +1 , board);

    dfs(row , col-1 , board);

    }

    void solve(vector<vector<char>>& board) {
        
        int n = board.size();

        int m = board[0].size();

        queue<pair<int ,int>>q;

        for(int i = 0 ; i < n ; i++ ) {
            
            if(board[i][0] =='O') dfs( i , 0 , board);

            if(board[i][m-1] =='O') dfs( i , m-1 , board);

        }

        for(int i = 0 ; i< m ; i++ ) {

            if(board[0][i] == 'O') dfs( 0 , i , board);

            if(board[n-1][i] == 'O') dfs( n-1 , i , board);

        }
       
       for ( int i = 0 ; i < n ; i++ ) {

         for( int j = 0 ; j< m ; j++ ) {
            
            if ( board [i][j] == 'T')

             board [i][j] = 'O';

            else if ( board[i][j] == 'O') 
             
             board[i][j] = 'X';

         }

     }
        
   }


};