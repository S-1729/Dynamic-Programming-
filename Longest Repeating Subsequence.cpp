class Solution {
public:
  int dp[1001][1001];
	int solve(int i,int j,string s1,string s2,int n,int m){
	    if(i>=n || j>=m)
	        return 0;
      if(dp[i][j]!=-1)
          return dp[i][j];
	    if(i!=j && s1[i]==s2[j])
	        return dp[i][j]=1+solve(i+1,j+1,s1,s2,n,m);
	    else
	        return dp[i][j]=max(solve(i+1,j,s1,s2,n,m),solve(i,j+1,s1,s2,n,m));
	}
	
	int LongestRepeatingSubsequence(string str){
		int n=str.size();
    memset(dp,-1,sizeof dp);
		return solve(0,0,str,str,n,n);
	}
};

/*
	Given string str, find the length of the longest repeating subsequence such that it can be found twice in the given string.
	The two identified subsequences A and B can use the same ith character from string str if and only if that ith character has different indices in A and B. 
	For example, A = "xax" and B = "xax" then the index of first "x" must be different in the original string for A and B.
	
	Example 1:
	Input:
	str = "axxzxy"
	Output: 2
	Explanation:
	The given array with indexes looks like
	a x x z x y 
	0 1 2 3 4 5
	The longest subsequence is "xx". 
	It appears twice as explained below.

	Example 2:
	Input:
	str = "axxxy"
	Output: 2
	Explanation:
	The given array with indexes looks like
	a x x x y 
	0 1 2 3 4
	The longest subsequence is "xx". 
	It appears twice as explained below.
	
	T.C : O(n*n)
  S.C : O(n*n)
  
*/
