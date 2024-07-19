/*

Q-2751, Robot Collisions

There are n 1-indexed robots, each having a position on a line, health, and movement direction.

You are given 0-indexed integer arrays positions, healths, and a string directions (directions[i] is either 'L' for left or 'R' for right). All integers in positions are unique.

All robots start moving on the line simultaneously at the same speed in their given directions. If two robots ever share the same position while moving, they will collide.

If two robots collide, the robot with lower health is removed from the line, and the health of the other robot decreases by one. The surviving robot continues in the same direction it was going. If both robots have the same health, they are both removed from the line.

Your task is to determine the health of the robots that survive the collisions, in the same order that the robots were given, i.e. final heath of robot 1 (if survived), final health of robot 2 (if survived), and so on. If there are no survivors, return an empty array.

Return an array containing the health of the remaining robots (in the order they were given in the input), after no further collisions can occur.

Note: The positions may be unsorted.


*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n=positions.size();
        map<int,pair<char,int>>mp;
        for(int i=0; i<n; i++){
            pair<char,int>temp=make_pair(directions[i],i);
            mp[positions[i]]=temp;
        }
        sort(positions.begin(),positions.end());
        stack<int>s;
        for(int i=0; i<n; i++){
            char curr_dir=mp[positions[i]].first;
            if(curr_dir=='R'){
                s.push(positions[i]);
            }else if(curr_dir=='L'){
                int curr_index=mp[positions[i]].second;
                while(!s.empty() && healths[curr_index]>0){
                    int last_ele=s.top();
                    if(healths[curr_index]==healths[mp[last_ele].second]){
                        healths[curr_index]=0;
                        healths[mp[last_ele].second]=0;
                        s.pop();
                    }else if(healths[curr_index]>healths[mp[last_ele].second]){
                        healths[curr_index]-=1;
                        healths[mp[last_ele].second]=0;
                        s.pop();
                    }else{
                        healths[curr_index]=0;
                        healths[mp[last_ele].second]-=1;
                    }
                }
            }
        }
        vector<int>ans;
        for(int i=0; i<n; i++){
            if(healths[i]>0){
                ans.push_back(healths[i]);
            }
        }
        return ans;
    }
};