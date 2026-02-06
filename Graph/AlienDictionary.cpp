class Solution {
    
  public:
  
    string findOrder(vector<string> &words) {
        
        vector<int>indegree(26 , 0);
        
        vector<vector<int>>adj(26);
        
        vector<bool> present(26, false);

        for (auto &word : words) {
            
          for (char ch : word)
         
          present[ch - 'a'] = true;
        
        
        }

        
        for( int i=0 ; i<words.size()-1 ; i++)  {
            
            string curr = words[i];
            
            string next = words[i+1];
            
            int len= min(curr.size() , next.size());
            
            bool found = false;
            
            for(int j=0 ; j<len ; j++) {
                
                if(curr[j] != next[j]) {
                    
                    indegree[next[j]-'a']++;
                
                    adj[curr[j]-'a'].push_back(next[j]-'a');
                    
                    found = true;
                    
                    break;
                    
                    
                }
                
               
                
            } 
            
            if(!found && curr.size() > next.size())
                
            return "";
        }
        
       
        
        queue<int>q;
        
        int presentCount = 0;
        
        for(int i=0; i<26; i++) {
            
           if (present[i] ) {
               
                if(!indegree[i])
              
                q.push(i);
                
                presentCount++;
           }
            
           
            
        }
        
        
        
        string order ="";
        
        while(!q.empty()) {
            
            int node = q.front();
            
            q.pop();
            
            order.push_back(node + 'a');
            
            for(auto it: adj[node]) {
                
                indegree[it]--;
                
                if(!indegree[it])
                
                q.push(it);
                
            }
            
        }
       
        if( order.length() != presentCount) 
        
        return "";
        
        return order;
        
    }
};