class Solution {
  public:
    int alternatingMaxLength(vector<int>& arr) {
        if(arr.size()==1)
        return 1;
        if(arr.size()==2){
            if(arr[0]==arr[1])
            return 1;
        }
        int ans=1;
        int prev=arr[0];
        for(int i=1;i<arr.size()-1;i++){
            if((arr[i]>prev&&arr[i]>arr[i+1]) || (arr[i]<prev&&arr[i]<arr[i+1])){
                prev=arr[i];
                ans++;
            }
        }
        return ans+1;
    }
};

/*
    You are given an array arr. Your task is to find the longest length of a good sequence. A good sequence {x1, x2, .. xn} is an alternating sequence if its elements satisfy one of the following relations :
    1.  x1 < x2 > x3 < x4 > x5. . . . . and so on
    2.  x1 >x2 < x3 > x4 < x5. . . . . and so on
    
    Examples:
    
    Input: arr= [1, 5, 4]
    Output: 3
    Explanation: The entire sequenece is a good sequence.
    
    Input: arr= [1, 17, 5, 10, 13, 15, 10, 5, 16, 8]
    Output: 7
    Explanation: There are several subsequences that achieve this length. 
    One maximum length good subsequences is [1, 17, 10, 13, 10, 16, 8].
    
    T.C : O(n)
*/
