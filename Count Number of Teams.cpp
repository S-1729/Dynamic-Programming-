class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n=rating.size(),ans=0;
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                for(int k=j+1;k<n;k++){
                    if((rating[i]<rating[j] && rating[j]<rating[k]) || (rating[i]>rating[j] && rating[j]>rating[k])){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};

//T.C : O(n*n)
class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size(),teams = 0;
        for(int j = 1; j < n-1; j++) {
            int countSmallerLeft = 0;
            int countLargerLeft  = 0;
            int countSmallerRight = 0;
            int countLargerRight = 0;

            for(int i = 0; i < j; i++) {
                if(rating[i] < rating[j]) {
                    countSmallerLeft++;
                } else if(rating[i] > rating[j]) {
                    countLargerLeft++;
                }
            }

            for(int k = j+1; k < n; k++) {
                if(rating[j] < rating[k]) {
                    countLargerRight++;
                } else if(rating[j] > rating[k]) {
                    countSmallerRight++;
                }
            }

            teams += (countLargerLeft * countSmallerRight) + (countSmallerLeft * countLargerRight);
        }
        return teams;
    }
};

/*
    There are n soldiers standing in a line. Each soldier is assigned a unique rating value.  
    You have to form a team of 3 soldiers amongst them under the following rules:
    Choose 3 soldiers with index (i, j, k) with rating (rating[i], rating[j], rating[k]).
    A team is valid if: (rating[i] < rating[j] < rating[k]) or (rating[i] > rating[j] > rating[k]) where (0 <= i < j < k < n).
    Return the number of teams you can form given the conditions. (soldiers can be part of multiple teams).
    
    Example 1:
    Input: rating = [2,5,3,4,1]
    Output: 3
    Explanation: We can form three teams given the conditions. (2,3,4), (5,4,1), (5,3,1). 
    
    Example 2:
    Input: rating = [2,1,3]
    Output: 0
    Explanation: We can't form any team given the conditions.
    
    Example 3:
    Input: rating = [1,2,3,4]
    Output: 4
    
    T.C : O(n*n*n)
*/
