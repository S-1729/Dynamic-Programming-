class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int>arr(n+1);
        arr[1]=1;
        int i2,i3,i5;
        i2=i3=i5=1;
        for(int i=2;i<=n;i++){
            arr[i]=min({arr[i2]*2,arr[i3]*3,arr[i5]*5});
            if(arr[i]==arr[i2]*2)
                i2++;
            if(arr[i]==arr[i3]*3)
                i3++;
            if(arr[i]==arr[i5]*5)
                i5++;
        }
        return arr[n];
    }
};

/*
    An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.
    Given an integer n, return the nth ugly number.
    
    Example 1:
    Input: n = 10
    Output: 12
    Explanation: [1, 2, 3, 4, 5, 6, 8, 9, 10, 12] is the sequence of the first 10 ugly numbers.
    
    Example 2:
    Input: n = 1
    Output: 1
    Explanation: 1 has no prime factors, therefore all of its prime factors are limited to 2, 3, and 5.
    
    T.C : O(n)
    S.C : O(n)
*/
