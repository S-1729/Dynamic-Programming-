//Bottom-Up(Memoization)
class Solution {
public:
    long ans=-1e9;
    int dp[1001][1001];
    int solve(int i,int j,int n,int m,vector<vector<int>>& grid){
        if(i>=n || j>=m)
            return INT_MIN;
        if(dp[i][j]!=-1)
            return dp[i][j];
        long maxm=max(solve(i+1,j,n,m,grid),solve(i,j+1,n,m,grid));
        ans=max(ans,maxm-grid[i][j]);
        return dp[i][j]=max(maxm,(long)grid[i][j]);
    }
    
    int maxScore(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        memset(dp,-1,sizeof(dp));
        solve(0,0,n,m,grid);
        return ans;
    }
};

/*
    You are given an m x n matrix grid consisting of positive integers. You can move from a cell in the matrix to any other cell that is either to the bottom or to the right (not necessarily adjacent). 
    The score of a move from a cell with the value c1 to a cell with the value c2 is c2 - c1.
    You can start at any cell, and you have to make at least one move.
    Return the maximum total score you can achieve.
    
    Example 1:
    Input: grid = [[9,5,7,3],[8,9,6,1],[6,7,14,3],[2,5,3,1]]
    Output: 9
    Explanation: We start at the cell (0, 1), and we perform the following moves:
    - Move from the cell (0, 1) to (2, 1) with a score of 7 - 5 = 2.
    - Move from the cell (2, 1) to (2, 2) with a score of 14 - 7 = 7.
    The total score is 2 + 7 = 9.
    
    Example 2:
    Input: grid = [[4,3,2],[3,2,1]]
    Output: -1
    Explanation: We start at the cell (0, 0), and we perform one move: (0, 0) to (0, 1). The score is 3 - 4 = -1.

    T.C : O(1001*1001)
    S.C : O(1001*1001)
*/
