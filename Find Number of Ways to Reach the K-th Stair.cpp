//Top_Down(Memoization)
class Solution {
public:
    unordered_map<string,int>mp;
    int solve(int i,int k,int jump,bool notConsecutive){
        if(i>k+1)
            return 0;
        string key=to_string(i)+"-"+to_string(jump)+"-"+to_string(notConsecutive);
        if(mp.find(key)!=mp.end())
            return mp[key];
        int ways=0;
        if(i==k)
            ways+=1;
        if(notConsecutive)
            ways+=solve(i-1,k,jump,false);
        ways+=solve(i+pow(2,jump),k,jump+1,true);
        return mp[key]=ways;
    }
    
    int waysToReachStair(int k) {
        return solve(1,k,0,true);
    }
};

/*
    You are given a non-negative integer k. There exists a staircase with an infinite number of stairs, with the lowest stair numbered 0.
    Alice has an integer jump, with an initial value of 0. She starts on stair 1 and wants to reach stair k using any number of operations. If she is on stair i, in one operation she can:
    Go down to stair i - 1. This operation cannot be used consecutively or on stair 0.
    Go up to stair i + 2jump. And then, jump becomes jump + 1.
    Return the total number of ways Alice can reach stair k.
    Note that it is possible that Alice reaches the stair k, and performs some operations to reach the stair k again.
    
    Example 1:
    Input: k = 0
    Output: 2
    Explanation:
    The 2 possible ways of reaching stair 0 are:
    Alice starts at stair 1.
    Using an operation of the first type, she goes down 1 stair to reach stair 0.
    Alice starts at stair 1.
    Using an operation of the first type, she goes down 1 stair to reach stair 0.
    Using an operation of the second type, she goes up 20 stairs to reach stair 1.
    Using an operation of the first type, she goes down 1 stair to reach stair 0.
    
    Example 2:
    Input: k = 1
    Output: 4
    Explanation:
    The 4 possible ways of reaching stair 1 are:
    Alice starts at stair 1. Alice is at stair 1.
    Alice starts at stair 1.
    Using an operation of the first type, she goes down 1 stair to reach stair 0.
    Using an operation of the second type, she goes up 20 stairs to reach stair 1.
    Alice starts at stair 1.
    Using an operation of the second type, she goes up 20 stairs to reach stair 2.
    Using an operation of the first type, she goes down 1 stair to reach stair 1.
    Alice starts at stair 1.
    Using an operation of the first type, she goes down 1 stair to reach stair 0.
    Using an operation of the second type, she goes up 20 stairs to reach stair 1.
    Using an operation of the first type, she goes down 1 stair to reach stair 0.
    Using an operation of the second type, she goes up 21 stairs to reach stair 2.
    Using an operation of the first type, she goes down 1 stair to reach stair 1.
    
    T.C : O(n)
    S.C : O(n)
*/
