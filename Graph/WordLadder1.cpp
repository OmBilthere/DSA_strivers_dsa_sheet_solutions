class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
         
         int n = wordList.size();

         set<string> s(wordList.begin() , wordList.end());

         queue<pair<string , int>>q;

         q.push({beginWord , 1});

         if (s.find(endWord) == s.end()) return 0;

         while(!q.empty()) {
            
            auto [word , cnt] = q.front();

            q.pop();

            if(word == endWord) return cnt; 

            if(s.find(word) != s.end())

            s.erase(word);

            int size = word.size();
            
            for(int i = 0 ; i < size ; i++ ) {

                string temp = word;

                for( char alph = 'a' ; alph <= 'z' ; alph++ ) {
                     
                   temp[i] = alph;
                        
                   if(s.find(temp) != s.end())  {
                 
                   q.push( {temp, cnt+1 });

                   s.erase(temp);

                   }


                   }

                }
           
              }
        

         return 0;


    }
};