/*
Q-912, Sort an Array
Given an array of integers nums, sort the array in ascending order and return it.

You must solve the problem without using any built-in functions in O(nlog(n)) time complexity and with the smallest space complexity possible.


*/

// This code is giving memory limit exceed, so use standard sorting algo 
class Solution {
private:
    void insert(vector<int>& nums, int last_ele) {
        if (nums.size() == 0 || last_ele > nums.back()) {
            nums.push_back(last_ele);
            return;
        }
        int val = nums.back();
        nums.pop_back();
        insert(nums, last_ele);
        nums.push_back(val);
    }
    vector<int> sort(vector<int>& nums) {
        if (nums.size() <= 1) {
            return nums;
        }
        int last_ele = nums.back();
        nums.pop_back();
        sort(nums);
        insert(nums, last_ele);
        return nums;
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        return sort(nums);
    }
};