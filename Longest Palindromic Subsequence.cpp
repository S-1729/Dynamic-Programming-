//Bottom-Up(Memoization)
class Solution {
public:
    int dp[1001][1001];
    int solve(string s1,string s2,int i,int j,int n,int m){
        if(i>=n || j>=m)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(s1[i]==s2[j])
            return dp[i][j]=1+solve(s1,s2,i+1,j+1,n,m);
        else
            return dp[i][j]=max(solve(s1,s2,i+1,j,n,m),solve(s1,s2,i,j+1,n,m));
    }
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        string s1=s;
        reverse(s.begin(),s.end());
        memset(dp,-1,sizeof dp);
        return solve(s1,s,0,0,n,n);
    }
};

/*
    Given a string s, find the longest palindromic subsequence's length in s.   
    A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.
    
    Example 1:
    Input: s = "bbbab"
    Output: 4
    Explanation: One possible longest palindromic subsequence is "bbbb".
    
    Example 2:
    Input: s = "cbbd"
    Output: 2
    Explanation: One possible longest palindromic subsequence is "bb".

    T.C : O(n*n)
    S.C : O(n*n)
*/
