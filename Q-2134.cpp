/*
Q-2134, Minimum Swaps to Group All 1's Together II

A swap is defined as taking two distinct positions in an array and swapping the values in them.

A circular array is defined as an array where we consider the first element and the last element to be adjacent.

Given a binary circular array nums, return the minimum number of swaps required to group all 1's present in the array together at any location.

*/

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int OneCount = count(nums.begin(), nums.end(), 1);
        int zeroCount = count(nums.begin(), nums.begin() + OneCount, 0);
        int minSwaps = zeroCount;
        for (int i = 1; i < n; ++i) {
            if (nums[i - 1] == 0) zeroCount--;
            if (nums[(i + OneCount - 1) % n] == 0) zeroCount++;
            minSwaps = min(minSwaps, zeroCount);
        }
        return minSwaps;
    }
};
