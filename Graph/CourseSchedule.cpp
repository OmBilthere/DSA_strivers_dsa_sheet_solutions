class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        int n = prerequisites.size();

        vector<vector<int>>adj(numCourses);

        vector<int>indegree(numCourses , 0);

        for(int i=0 ; i< prerequisites.size();i++) {
           
           int u = prerequisites[i][0];

           int v = prerequisites[i][1];

           adj[v].push_back(u);

           indegree[u]++;


        }  
        
        queue<int>q;

        for(int i=0 ; i<indegree.size(); i++) {
    
          if(!indegree[i]) 

          q.push(i);

        }

        int size = 0;

        while(!q.empty()) {

            int node = q.front();

            q.pop();

            size++;

            for(auto it : adj[node]) {

                indegree[it]--;

                if(!indegree[it])

                q.push(it);
            }
        }
       
       return numCourses == size;
    }
};