//Bottom-Up(Memoization)
class Solution {
public:
    int dp[2001][10000];
    int solve(int ind,int sum,vector<int>& rewardValues){
        if(ind>=rewardValues.size())
            return sum;
        if(dp[ind][sum]!=-1)
            return dp[ind][sum];
        int take=0;
        if(rewardValues[ind]>sum){
            take=solve(ind+1,sum+rewardValues[ind],rewardValues);
        }
        int not_take=solve(ind+1,sum,rewardValues);
        return dp[ind][sum]=max(take,not_take);
    }
    
    int maxTotalReward(vector<int>& rewardValues) {
        sort(begin(rewardValues),end(rewardValues));
        memset(dp,-1,sizeof(dp));
        return solve(0,0,rewardValues);
    }
};

/*
    You are given an integer array rewardValues of length n, representing the values of rewards. 
    Initially, your total reward x is 0, and all indices are unmarked. You are allowed to perform the following operation any number of times:
    Choose an unmarked index i from the range [0, n - 1].
    If rewardValues[i] is greater than your current total reward x, then add rewardValues[i] to x (i.e., x = x + rewardValues[i]), and mark the index i.
    Return an integer denoting the maximum total reward you can collect by performing the operations optimally.
    
    Example 1:
    Input: rewardValues = [1,1,3,3]
    Output: 4
    Explanation:
    During the operations, we can choose to mark the indices 0 and 2 in order, and the total reward will be 4, which is the maximum.
    
    Example 2:
    Input: rewardValues = [1,6,4,3,2]
    Output: 11
    Explanation:
    Mark the indices 0, 2, and 1 in order. The total reward will then be 11, which is the maximum.

    T.C : O(2001*10000)
    S.C : O(2001*10000)
*/
