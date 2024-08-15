//Top-Down
class Solution {
  public:
    int ans=0;
    int dp[1001][1001];
    int solve(string str1,string str2,int i,int j){
        if(i>=str1.size() || j>=str2.size())
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int res=0;
        if(str1[i]==str2[j]){
            res=1+solve(str1,str2,i+1,j+1);
            ans=max(ans,res);
        }
        solve(str1,str2,i,j+1);
        solve(str1,str2,i+1,j);
        return dp[i][j]=res;
    }
    int longestCommonSubstr(string str1, string str2) {
        memset(dp,-1,sizeof dp);
        solve(str1,str2,0,0);
        return ans;
    }
};


//Bottom-Up
class Solution {
  public:
    int longestCommonSubstr(string str1, string str2) {
        int n=str1.size(),m=str2.size(),ans=0;
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(str1[i-1]==str2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                    if(dp[i][j]>ans)
                        ans=dp[i][j];
                }
            }
        }
        return ans;
    }
};

/*
    You are given two strings str1 and str2. Your task is to find the length of the longest common substring among the given strings.
    
    Examples:
    
    Input: str1 = "ABCDGH", str2 = "ACDGHR"
    Output: 4
    Explanation: The longest common substring is "CDGH" which has length 4.
    
    Input: str1 = "ABC", str2 = "ACB"
    Output: 1
    Explanation: The longest common substrings are "A", "B", "C" all having length 1.

    T.C : O(n*m)
    S.C : O(n*m)
*/
