//Bottom-Up(Memoization)
class Solution {
public:
    long long Mod=1e9+7;
    int dp[1001];
    int solve(int n){
        if(n<=2)
            return n;
        if(n==3)
            return 5;
        if(dp[n]!=-1)
            return dp[n];
        return dp[n]=solve(n-3)%Mod+(2*(solve(n-1)%Mod))%Mod;
    }
    
    int numTilings(int n) {
        memset(dp,-1,sizeof dp);
        return solve(n)%Mod;
    }
};

/*
    You have two types of tiles: a 2 x 1 domino shape and a tromino shape. You may rotate these shapes.  
    Given an integer n, return the number of ways to tile an 2 x n board. Since the answer may be very large, return it modulo 109 + 7.
    In a tiling, every square must be covered by a tile. Two tilings are different if and only if there are two 4-directionally adjacent cells on the board such that exactly one of the tilings has both squares occupied by a tile.
    
    Example 1:
    Input: n = 3
    Output: 5
    Explanation: The five different ways are show above.
    
    Example 2: 
    Input: n = 1
    Output: 1

    T.C : O(n)
    S.C : O(n)
*/
