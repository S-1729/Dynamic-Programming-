//Bottom-Up(Memoization)
class Solution {
public:
    int dp[101];
    int solve(int ind,vector<int>&nums,int n){
        if(ind>=n)
            return 0;
        if(dp[ind]!=-1)
            return dp[ind];
        int take=0;
        take+= nums[ind]+solve(ind+2,nums,n);
        int not_take=solve(ind+1,nums,n);
        return dp[ind]=max(take,not_take);
    }
    
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return nums[0];
        memset(dp,-1,sizeof dp);
        int startfrom0=solve(0,nums,n-1);
        memset(dp,-1,sizeof dp);
        int startfrom1=solve(1,nums,n);
        return max(startfrom0,startfrom1);
    }
};

/*
    You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.
    Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.
     
    Example 1:
    Input: nums = [2,3,2]
    Output: 3
    Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.
    
    Example 2:
    Input: nums = [1,2,3,1]
    Output: 4
    Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
    Total amount you can rob = 1 + 3 = 4.
    
    Example 3:
    Input: nums = [1,2,3]
    Output: 3

    T.C : O(2n)
    S.C : O(n)
*/
