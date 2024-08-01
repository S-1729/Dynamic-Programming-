class Solution {
  public:
    int dp[201][201];
    int solve(int ind, int n, int w, vector<int> &cost){
        if(w==0)
            return 0;
        if(ind>=n || ind+1>w)
            return 1e9;
        if(dp[ind][w]!=-1)
            return dp[ind][w];
        int take,not_take;
        if(cost[ind]!=-1 && ind+1<=w)
            take=cost[ind]+solve(ind,n,w-ind-1,cost);
        not_take=solve(ind+1,n,w,cost);
        return dp[ind][w]=min(take,not_take);
    }
    int minimumCost(int n, int w, vector<int> &cost) {
        memset(dp,-1,sizeof dp);
        return solve(0,n,w,cost);
    }
};

/*
    Given an array cost[] of positive integers of size n and an integer w, where cost[i] represents the cost of an i kg packet of oranges, the task is to find the minimum cost to buy exactly w kg of oranges. 
    The cost array has a 1-based indexing. If buying exactly w kg of oranges is impossible, then return -1.
    Note:
    1. cost[i] = -1 means that i kg packet of orange is unavailable.
    2. It may be assumed that there is an infinite supply of all available packet types.
    
    Example 1:
    Input: 
    n = 5
    cost[] = {20, 10, 4, 50, 100} 
    w = 5
    Output: 
    14
    Explanation: 
    Purchase the 2kg packet for 10 coins and the 3kg packet for 4 coins to buy 5kg of oranges for 14 coins.
    
    Example 2:
    Input: 
    n = 5
    cost[] = {-1, -1, 4, 3, -1}
    w = 5
    Output: 
    -1
    Explanation: 
    It is not possible to buy 5 kgs of oranges.

    T.C : O(n*w)
    S.C : O(n*w)
*/
