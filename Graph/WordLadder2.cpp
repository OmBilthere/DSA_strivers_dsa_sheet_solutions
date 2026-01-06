class Solution {
  public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
            vector<vector<string>>ans;
       
        queue<vector<string>>q;

        q.push({beginWord});

        unordered_set<string> s (wordList.begin() , wordList.end());

        s.erase(beginWord);
        
        int level = 1;
         
        vector<string>usedOnlevel;    


        if( s.find(endWord) == s.end()) return ans;

        while (!q.empty()) {

        vector<string> curr = q.front();

        q.pop();

        if( curr.size() > level ) {

            level = curr.size();

            for(auto it : usedOnlevel) 

            s.erase(it);

            usedOnlevel.clear();

            if (!ans.empty()) break;


        } 
    
        string word = curr.back();

        if( word == endWord) {
           
           if( ans.size() == 0 || curr.size() == ans[0].size() ) 

           ans.push_back(curr);

           continue;

        }

        for(int i = 0 ; i < word.size() ; i++ ) {

          string temp = word;
          
          for( char j = 'a' ; j <= 'z' ; j++) {
              
           temp[i] = j;
           
           if(s.find(temp) != s.end()) {
             
             curr.push_back(temp);

             q.push(curr);

             usedOnlevel.push_back(temp);

             curr.pop_back();
        
                }     

              }
    
            }

        }

   
     return ans;
     
    }
};