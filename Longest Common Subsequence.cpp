class Solution {
public:
    int dp[1001][1001];
    int solve(string text1, string text2,int i,int j,int m,int n)
    {
        if(i>=m || j>=n)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(text1[i]==text2[j])
            return dp[i][j]=1+solve(text1,text2,i+1,j+1,m,n);
        else
            return dp[i][j]=max(solve(text1,text2,i+1,j,m,n),solve(text1,text2,i,j+1,m,n));
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.size(),n=text2.size();
        memset(dp,-1,sizeof dp);
        return solve(text1,text2,0,0,m,n);
    }
};

/*
    Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.   
    A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.
    For example, "ace" is a subsequence of "abcde".
    A common subsequence of two strings is a subsequence that is common to both strings.
    
    Example 1:
    Input: text1 = "abcde", text2 = "ace" 
    Output: 3  
    Explanation: The longest common subsequence is "ace" and its length is 3.
    
    Example 2:
    Input: text1 = "abc", text2 = "abc"
    Output: 3
    Explanation: The longest common subsequence is "abc" and its length is 3.
    
    Example 3:
    Input: text1 = "abc", text2 = "def"
    Output: 0
    Explanation: There is no such common subsequence, so the result is 0.

    T.C : O(n*m)
    S.C : O(n*m)
*/
