class Solution {
  public:
    int dp[101][101];
    int solve(int i,int j,string str1,string str2){
        if(j>=str2.size())
            return str1.size()-i;
        if(i>=str1.size())
            return str2.size()-j;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(str1[i]==str2[j])
            return dp[i][j]=solve(i+1,j+1,str1,str2);
        else{
            int x1=INT_MAX,x2=INT_MAX,x3=INT_MAX;
            x1=1+solve(i,j+1,str1,str2);
            x2=1+solve(i+1,j,str1,str2);
            x3=1+solve(i+1,j+1,str1,str2);
            return dp[i][j]=min({x1,x2,x3});
        }
    }
    int editDistance(string str1, string str2) {
        memset(dp,-1,sizeof dp);
        return solve(0,0,str1,str2);
    }
};

/*
    Given two strings str1 and str2. Return the minimum number of operations required to convert str1 to str2.
    The possible operations are permitted:    
    Insert a character at any position of the string.
    Remove any character from the string.
    Replace any character from the string with any other character.
    
    Examples:
 
    Input: str1 = "geek", srt2 = "gesek"
    Output: 1
    Explanation: One operation is required, inserting 's' between two 'e'.
    
    Input : str1 = "gfg", str2 = "gfg"
    Output: 0
    Explanation: Both strings are same.
    
    T.C : O(n*n)
    S.C : O(n*n)
*/
