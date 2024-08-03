/*
Q-1460, Make Two Arrays Equal by Reversing Subarrays

You are given two integer arrays of equal length target and arr. In one step, you can select any non-empty subarray of arr and reverse it. You are allowed to make any number of steps.

Return true if you can make arr equal to target or false otherwise.


*/


class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        map<int,int>mp;
        for(int i=0; i<target.size(); i++){
            mp[target[i]]++;
        }
        for(int i=0; i<arr.size(); i++){
            if(mp.find(arr[i])==mp.end())return false;
            else{
                mp[arr[i]]--;
                if(mp[arr[i]]==0){
                    mp.erase(arr[i]);
                }
            }
        }
        return true;
    }
};