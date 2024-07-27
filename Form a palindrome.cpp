//Top-Down(Memoization)
class Solution{
  public:
    int dp[501][501];
    int solve(string str,int i,int j){
        if(i>j)
        return 0;
        if(dp[i][j]!=-1)
        return dp[i][j];
        if(str[i]==str[j])
        return dp[i][j]=solve(str,i+1,j-1);
        else
        return dp[i][j]=1+min(solve(str,i+1,j),solve(str,i,j-1));
    }
    int countMin(string str){
        memset(dp,-1,sizeof dp);
        return solve(str,0,str.size()-1);
    }
};

/*
    Given a string, find the minimum number of characters to be inserted to convert it to a palindrome.
    
    Examples :
    
    Input: str = "abcd"
    Output: 3
    Explanation: Inserted character marked with bold characters in dcbabcd, here we need minimum three characters to make it palindrome.
    
    Input: str = "aa"
    Output: 0
    Explanation: "aa" is already a palindrome.
    
    T.C : O(n*n)
    S.C : O(n*n)
*/
