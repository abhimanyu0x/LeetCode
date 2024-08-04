/*
Q-1508, Range Sum of Sorted Subarray Sums

You are given the array nums consisting of n positive integers. You computed the sum of all non-empty continuous subarrays from the array and then sorted them in non-decreasing order, creating a new array of n * (n + 1) / 2 numbers.

Return the sum of the numbers from index left to index right (indexed from 1), inclusive, in the new array. Since the answer can be a huge number return it modulo 109 + 7.


*/
class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        long long mod=1000000007;
        vector<int>sumArr;
        int i=0; int j=0; long long sum=0;
        while(i<n){
            if(j<n){
                sum+=nums[j];
                sumArr.push_back(sum);
                j++;
            }else{
                i++;
                j=i;
                sum=0;
            }
        }
        sort(sumArr.begin(),sumArr.end());
        long long ans=0;
        for(int i=left-1; i<right; i++){
            ans+=sumArr[i];
        }
        return ans%mod;
    }
};

