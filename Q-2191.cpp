/*
Q-2191, Sort the Jumbled Numbers

You are given a 0-indexed integer array mapping which represents the mapping rule of a shuffled decimal system. mapping[i] = j means digit i should be mapped to digit j in this system.

The mapped value of an integer is the new integer obtained by replacing each occurrence of digit i in the integer with mapping[i] for all 0 <= i <= 9.

You are also given another integer array nums. Return the array nums sorted in non-decreasing order based on the mapped values of its elements.

Notes:

Elements with the same mapped values should appear in the same relative order as in the input.
The elements of nums should only be sorted based on their mapped values and not be replaced by them.


*/

class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        multimap<int,int>mp;
        for(int i=0; i<nums.size(); i++){
            string temp=to_string(nums[i]);
            string newNumber="";
            for(int j=0; j<temp.size(); j++){
                int k=temp[j]-'0';
                newNumber+=to_string(mapping[k]);
            }
            int x=stoi(newNumber);
            mp.insert({x, nums[i]});
        }
        vector<int>ans;
        for(auto x:mp){
            ans.push_back(x.second);
        }
        return ans;
    }
};