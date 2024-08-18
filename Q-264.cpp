/*
264. Ugly Number II

An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.

Given an integer n, return the nth ugly number.

*/

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int>dp(n);
        dp[0]=1;
        int ptr1=0;
        int ptr2=0;
        int ptr3=0;
        for(int i=1; i<n; i++){
            int two=dp[ptr1]*2;
            int three=dp[ptr2]*3;
            int five=dp[ptr3]*5;
            dp[i]=min(two,min(three,five));
            if(dp[i]==two)ptr1++;
            if(dp[i]==three)ptr2++;
            if(dp[i]==five)ptr3++;
        }
        return dp[n-1];
    }
};