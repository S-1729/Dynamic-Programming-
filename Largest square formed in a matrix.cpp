//Bottom-Up(Tabulation)
class Solution {
  public:
    int maxSquare(int n, int m, vector<vector<int>> mat) {
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==1 && i-1>=0 && j-1>=0)
                    mat[i][j]=1+min({mat[i-1][j],mat[i][j-1],mat[i-1][j-1]});
                ans=max(ans,mat[i][j]);
            }
        }
        return ans;
    }
};

/*
    Given a binary matrix mat of size n * m, find out the maximum length of a side of a square sub-matrix with all 1s.
    
    Examples:
    
    Input: n = 6, m = 5
    mat = [[0, 1, 1, 0, 1], 
           [1, 1, 0, 1, 0],
           [0, 1, 1, 1, 0],
           [1, 1, 1, 1, 0],
           [1, 1, 1, 1, 1],
           [0, 0, 0, 0, 0]]
    Output: 3
    Explanation: 
    The maximum length of a side of the square sub-matrix is 3 where every element is 1.
    
    Input: n = 2, m = 2
    mat = [[1, 1], 
           [1, 1]]
    Output: 2
    Explanation: The maximum length of a side of the square sub-matrix is 2. The matrix itself is the maximum sized sub-matrix in this case.
    
    Input: n = 2, m = 2
    mat = [[0, 0], 
           [0, 0]]
    Output: 0
    Explanation: There is no 1 in the matrix.

    T.C : O(n*m)
*/
