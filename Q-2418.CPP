/*
Q-2418, Sort the People

You are given an array of strings names, and an array heights that consists of distinct positive integers. Both arrays are of length n.

For each index i, names[i] and heights[i] denote the name and height of the ith person.

Return names sorted in descending order by the people's heights.

*/


class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n=names.size();
        vector<string>ans;
        map<int,string>mp;
        for(int i=0; i<n; i++){
            mp[heights[i]]=names[i];
        }
        for(auto x:mp){
            ans.push_back(x.second);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};