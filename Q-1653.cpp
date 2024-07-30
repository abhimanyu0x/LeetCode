/*
Q-1653, Minimum Deletions to Make String Balanced


You are given a string s consisting only of characters 'a' and 'b'​​​​.

You can delete any number of characters in s to make s balanced. s is balanced if there is no pair of indices (i,j) such that i < j and s[i] = 'b' and s[j]= 'a'.

Return the minimum number of deletions needed to make s balanced.

*/

class Solution {
public:
    int minimumDeletions(string s) {
        stack<char>a;
        a.push(s[0]);
        int ans=0;
        for(int i=1; i<s.length(); i++){
            if(!a.empty() && (a.top()=='b' && s[i]=='a')){
                a.pop();
                ans+=1;
            }else{
                a.push(s[i]);
            }
        }
        return ans;
    }
};