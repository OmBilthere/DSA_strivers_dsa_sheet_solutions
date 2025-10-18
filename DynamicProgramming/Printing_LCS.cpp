

// string helper ( int ind1 , int ind2 , string & s1 , string & s2 , vector<vector<string>>& dp) {

// if(ind1==0 || ind2 == 0 ) return ""; //	if(ind1 < 0 || ind2 < 0 ) 	return "";

// 	if(dp[ind1][ind2] != "") return dp[ind1][ind2];

// 	if(s1[ind1-1] == s2[ind2-1] ) 
	
//  return dp[ind1][ind2] = helper(ind1-1 , ind2-1 , s1 , s2 , dp) + s1[ind1-1] ;


// 	string not_take_1 = helper (ind1-1 , ind2 , s1 , s2 , dp);
// 	string not_take_2 = helper (ind1 , ind2-1 , s1 , s2 , dp );
    
// 	return  dp[ind1][ind2] = (not_take_1.size() > not_take_2.size() ) ? not_take_1 : not_take_2;

	
// }

string findLCS(int n, int m,string &s1, string &s2){

    // vector<vector<string>>dp(n+1 , vector<string> ( m+1 , ""));// vector<vector<string>>dp(n , vector<string> ( m , "")); 

	//  return helper ( n , m , s1 , s2 , dp); // return helper ( n-1 , m-1 , s1 , s2 , dp);

        vector<vector<int>>dp(n+1 , vector<int> (m+1 , 0));

		for(int ind1 =1 ; ind1<=n ; ind1++ ) {

        for(int ind2 = 1 ; ind2 <= m ; ind2++  ) {
           
		   
		   if(s1[ind1-1] == s2[ind2-1])
		   dp[ind1][ind2] = 1 + dp[ind1-1][ind2-1];

		   else 
		   dp[ind1][ind2] = max( dp[ind1-1][ind2], 	dp[ind1][ind2-1]);

		}

	}
	 
	 int ans = "";

	 while( n > 0 && m > 0 ) {

		 if(s1[n-1]==s2[m-1]) {

			 ans+= s1[n];
			 n-- , m--;

		 }
		
		 else	{
 
            if ( dp[n-1]> dp[m-1]) n--;
			else n--;

		 } 

		
	 }

     reverse (ans.begin() , ans.end());

		 return ans;
		 





        
    
}