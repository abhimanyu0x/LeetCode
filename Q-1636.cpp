/*
Q-1636, Sort Array by Increasing Frequency

Given an array of integers nums, sort the array in increasing order based on the frequency of the values. If multiple values have the same frequency, sort them in decreasing order.

Return the sorted array.

*/

typedef pair<int,int> pi;
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        vector<int>ans;
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        priority_queue<pi,vector<pi>,greater<pi>>p;
        for(auto x:mp){
            p.push({x.second,-(x.first)});
        }
        while(p.size()>0){
            int f=p.top().first;
            int n=p.top().second;
            p.pop();
            while(f!=0){
                ans.push_back(-(n));
                f--;
            }
        }
        return ans;
    }
};