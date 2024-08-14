/*
719. Find K-th Smallest Pair Distance

The distance of a pair of integers a and b is defined as the absolute difference between a and b.

Given an integer array nums and an integer k, return the kth smallest distance among all the pairs nums[i] and nums[j] where 0 <= i < j < nums.length.

*/


class Solution {
private:
bool isPossible(vector<int>& nums, int k, int ans){
    int count=0; int i=0; int j=0;
    int n=nums.size();
    while(i<n || j<n){
        while(j<nums.size() && nums[j]-nums[i]<=ans){
            j++;
        }
        count+=j-i-1;
        i++;
    }
    return count>=k;
}
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int left=0;
        int right=nums[n-1]-nums[0];
        while(left<=right){
            int mid=left + (right-left)/2;
            if(isPossible(nums,k,mid)){
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
        return left;
    }
};