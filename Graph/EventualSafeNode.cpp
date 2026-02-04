class Solution {
public:
    
    // bool dfs( int node , vector<int>& vis , vector<int>& pathvis , vector<vector<int>>& graph , vector<int>& safeNodes ) {
      
    //      vis[node] = 1;

    //      pathvis[node] = 1;

    //      for(auto it: graph[node]) {
             
    //          if(!vis[it]) {

    //             if(!dfs(it , vis , pathvis , graph , safeNodes)) return false;

    //          }

    //          else if(pathvis[it] == 1 ) return false;
      
            
    //      }

    //      pathvis[node] = 0;

    //      safeNodes[node] = 1;

    //      return true;

    // }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        int n = graph.size();

        // vector<int>vis(n , 0);

        // vector<int>pathvis(n ,0);

        vector<int>safeNodes(n , 0);

        vector<int>ans;
        
        // for(int i=0; i<n; i++) {

        //     if(!vis[i])

        //     dfs(i , vis , pathvis , graph , safeNodes);

        // }

        // for(int i= 0 ; i<n ; i++) 
        
        // if(safeNodes[i]) 

        // ans.push_back(i);

        // return ans;

        vector<int> outdegree(n , 0);

        vector<vector<int>>rev(n);

        for(int i=0; i<n ; i++) {

            outdegree[i] = graph[i].size();

             for(auto it: graph[i]) {
                  
                rev[it].push_back(i);

             }

        }
          
       queue<int>q;  

       for(int i=0 ; i< n ; i++ ) {
       
          if(!outdegree[i])

          q.push(i);

       }


       while(!q.empty()) {
          
          int node = q.front();

          q.pop();

          safeNodes[node] = 1;

          for(auto it: rev[node]) {

            outdegree[it]--;

            if(!outdegree[it])

            q.push(it);

          }

       }

       for(int i=0 ; i< n ; i++ ) 
       
       if(safeNodes[i])

       ans.push_back(i);


       return ans;
    
    }


};