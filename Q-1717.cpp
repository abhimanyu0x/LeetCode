/*

Q-1717, Maximum Score From Removing Substrings

You are given a string s and two integers x and y. You can perform two types of operations any number of times.

Remove substring "ab" and gain x points.
For example, when removing "ab" from "cabxbae" it becomes "cxbae".
Remove substring "ba" and gain y points.
For example, when removing "ba" from "cabxbae" it becomes "cabxe".
Return the maximum points you can gain after applying the above operations on s.

*/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximumGain(string s, int x, int y) {
        stack<char> a;
        int ans = 0;
        if (x > y) {
            for (int i = 0; i < s.length(); i++) {
                if (s[i] == 'b' && !a.empty()) {
                    char temp = a.top();
                    if (temp == 'a') {
                        ans += x;
                        a.pop();
                    } else {
                        a.push(s[i]);
                    }
                } else {
                    a.push(s[i]);
                }
            }
            string r="";
            while(!a.empty()){
                char x=a.top();
                a.pop();
                r+=x;
            }
            reverse(r.begin(),r.end());
            for (int i = 0; i < r.length(); i++) {
                if (r[i] == 'a' && !a.empty()) {
                    char temp = a.top();
                    if (temp == 'b') {
                        ans += y;
                        a.pop();
                    } else {
                        a.push(r[i]);
                    }
                } else {
                    a.push(r[i]);
                }
            }
        } else{
            for (int i = 0; i < s.length(); i++) {
                if (s[i] == 'a' && !a.empty()) {
                    char temp = a.top();
                    if (temp == 'b') {
                        ans += y;
                        a.pop();
                    } else {
                        a.push(s[i]);
                    }
                } else {
                    a.push(s[i]);
                }
            }
            string r="";
            while(!a.empty()){
                char x=a.top();
                a.pop();
                r+=x;
            }
            reverse(r.begin(),r.end());
            for (int i = 0; i < r.length(); i++) {
                if (r[i] == 'b' && !a.empty()) {
                    char temp = a.top();
                    if (temp == 'a') {
                        ans += x;
                        a.pop();
                    } else {
                        a.push(r[i]);
                    }
                } else {
                    a.push(r[i]);
                }
            }
        }
        return ans;
    }
};

/*

This same logic can also be implemented using lambda function in c++

class Solution {
public:
    int maximumGain(string s, int x, int y) {
        auto gain = [&](char c1, char c2, int value) -> int {
            stack<char> st;
            int ans = 0;
            for (char c : s) {
                if (!st.empty() && st.top() == c1 && c == c2) {
                    ans += value;
                    st.pop();
                } else {
                    st.push(c);
                }
            }
            s.clear();
            while (!st.empty()) {
                s += st.top();
                st.pop();
            }
            reverse(s.begin(), s.end());
            return ans;
        };

        if (x > y) {
            return gain('a', 'b', x) + gain('b', 'a', y);
        } else {
            return gain('b', 'a', y) + gain('a', 'b', x);
        }
    }
};
*/