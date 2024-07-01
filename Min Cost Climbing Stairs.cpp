//Bottom-Up(Memoization)
class Solution {
public:
    int dp[1001];
    int solve(int ind,vector<int>&cost){
        if(ind>=cost.size())
            return 0;
        if(dp[ind]!=-1)
            return dp[ind];
        return dp[ind]=cost[ind]+min(solve(ind+1,cost),solve(ind+2,cost));
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        memset(dp,-1,sizeof(dp));
        int ans1=solve(0,cost);
        memset(dp,-1,sizeof(dp));
        int ans2=solve(1,cost);
        return min(ans1,ans2);
    }
};

/*
    You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.    
    You can either start from the step with index 0, or the step with index 1.
    Return the minimum cost to reach the top of the floor.
    
    Example 1:
    Input: cost = [10,15,20]
    Output: 15
    Explanation: You will start at index 1.
    - Pay 15 and climb two steps to reach the top.
    The total cost is 15.
    
    Example 2:
    Input: cost = [1,100,1,1,1,100,1,1,100,1]
    Output: 6
    Explanation: You will start at index 0.
    - Pay 1 and climb two steps to reach index 2.
    - Pay 1 and climb two steps to reach index 4.
    - Pay 1 and climb two steps to reach index 6.
    - Pay 1 and climb one step to reach index 7.
    - Pay 1 and climb two steps to reach index 9.
    - Pay 1 and climb one step to reach the top.
    The total cost is 6.

    T.C : O(2n)
    S.C : O(n)
*/
