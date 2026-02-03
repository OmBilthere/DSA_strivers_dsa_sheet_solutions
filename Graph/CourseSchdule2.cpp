class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>>adj(numCourses);

        vector<int>indegree(numCourses);

        for(int i=0 ; i< prerequisites.size(); i++) {
            
            int u = prerequisites[i][0];

            int v = prerequisites[i][1];

            adj[v].push_back(u);

            indegree[u]++;

        }

        queue<int>q;

        for(int i=0; i<numCourses; i++) {

            if(!indegree[i])
            
            q.push(i);

        }

        vector<int>order;

        while(!q.empty()) {

            int node = q.front();

            q.pop();

            order.push_back(node);

            for(auto it: adj[node]) {
               
               indegree[it]--;

               if(!indegree[it])

               q.push(it);

            }

        }
        
        if(numCourses == order.size())

        return order;

        return {};
        


    }
};