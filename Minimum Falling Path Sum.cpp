//Top-Down(Memoization)
class Solution {
public:
    int dp[101][101];
    int solve(int i,int j,int n,int m,vector<vector<int>>& matrix){
        if(i==n-1)
            return matrix[i][j];
        if(dp[i][j]!=-1)
            return dp[i][j];
        int result=INT_MAX;
        for(int x=-1;x<=1;x++){
            if(j+x>=0 && j+x<m)
                result=min(result,matrix[i][j]+solve(i+1,j+x,n,m,matrix));
        }
        return dp[i][j]=result;
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size(),ans=INT_MAX;
        for(int i=0;i<m;i++){
            memset(dp,-1,sizeof dp);
            ans=min(ans,solve(0,i,n,m,matrix));
        }
        return ans;
    }
};

/*
    Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.
    A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).
     
    Example 1:
    Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
    Output: 13
    Explanation: There are two falling paths with a minimum sum as shown.
    
    Example 2:
    Input: matrix = [[-19,57],[-40,-5]]
    Output: -59
    Explanation: The falling path with a minimum sum is shown.
    
    T.C : O(n*n*n)
    S.C : O(n*n)
*/
