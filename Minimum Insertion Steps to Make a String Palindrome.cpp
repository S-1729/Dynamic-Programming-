//Bottom-Up(Memoization)
class Solution {
public:
    int dp[501][501];
    int solve(string s,int i,int j){
        if(i>=j)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(s[i]==s[j])
            return dp[i][j]=solve(s,i+1,j-1);
        else
            return dp[i][j]=1+min(solve(s,i+1,j),solve(s,i,j-1));
    }
    
    int minInsertions(string s) {
        memset(dp,-1,sizeof dp);
        return solve(s,0,s.size()-1);
    }
};

/*
    Given a string s. In one step you can insert any character at any index of the string.  
    Return the minimum number of steps to make s palindrome.
    A Palindrome String is one that reads the same backward as well as forward.
    
    Example 1:
    Input: s = "zzazz"
    Output: 0
    Explanation: The string "zzazz" is already palindrome we do not need any insertions.
    
    Example 2:
    Input: s = "mbadm"
    Output: 2
    Explanation: String can be "mbdadbm" or "mdbabdm".
    
    Example 3:
    Input: s = "leetcode"
    Output: 5
    Explanation: Inserting 5 characters the string becomes "leetcodocteel".

    T.C : O(n*n)
    S.C : O(n*n)
*/
