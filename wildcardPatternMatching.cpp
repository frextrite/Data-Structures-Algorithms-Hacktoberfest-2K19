// wildcard pattern matching
#include<bits/stdc++.h>
using namespace std;
/*
Given a text and a wildcard pattern, implement wildcard pattern matching algorithm that finds
if wildcard pattern is matched with a string or not. The matching should cover the entire text (not partial text).

The wildcard pattern can include the characters ‘?’ and ‘*’
‘?’ – matches any single character
‘*’ – Matches any sequence of characters (including the empty sequence)
*/
bool matchString(string s, string pattern, int n, int m){     // function that checks whether a given string and a pattern
                                                             // are equivalent or not
	if(m==0)
	  return (n==0);
	
	bool dp[n+1][m+1];
	memset(dp,false,sizeof(dp));
	
	dp[0][0] = true;
	for (int j = 1; j <= m; j++) 
        if (pattern[j - 1] == '*') 
            dp[0][j] = dp[0][j - 1]; 
  
    // fill the table in bottom-up fashion 
    for (int i = 1; i <= n; i++) 
    { 
        for (int j = 1; j <= m; j++) 
        { 
            // Two cases if we see a '*' 
            // either ignore ‘*’ character and move 
            // to next  character in the pattern, 
            // i.e., ‘*’ indicates an empty sequence. 
            // or '*' character matches with ith 
            // character in input 
            if (pattern[j - 1] == '*') 
                dp[i][j] = dp[i][j - 1] || dp[i - 1][j]; 
  
            // current characters are considered as 
            // matching in two cases 
            // either current character of pattern is '?' 
            // or characters actually match 
            else if (pattern[j - 1] == '?' || s[i - 1] == pattern[j - 1]) 
                  dp[i][j] = dp[i - 1][j - 1]; 
  
            // If characters don't match 
            else dp[i][j] = false; 
        } 
    } 
  
    return dp[n][m]; 
} 
  
// driver program to test the above function
int main() 
{ 
    string str = "baaabab"; 
    string pattern = "ba*****ab"; 
     
    if (matchString(str, pattern, str.size(), pattern.size())==true) 
        cout<<"Yes"<<endl; 
    else
        cout<<"No"<<endl; 
  
    return 0; 
} 
