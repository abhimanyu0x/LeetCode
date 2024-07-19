/*

Q-726, Number of Atoms

Given a string formula representing a chemical formula, return the count of each atom.

The atomic element always starts with an uppercase character, then zero or more lowercase letters, representing the name.

One or more digits representing that element's count may follow if the count is greater than 1. If the count is 1, no digits will follow.

For example, "H2O" and "H2O2" are possible, but "H1O2" is impossible.
Two formulas are concatenated together to produce another formula.

For example, "H2O2He3Mg4" is also a formula.
A formula placed in parentheses, and a count (optionally added) is also a formula.

For example, "(H2O2)" and "(H2O2)3" are formulas.
Return the count of all elements as a string in the following form: the first name (in sorted order), followed by its count (if that count is more than 1), followed by the second name (in sorted order), followed by its count (if that count is more than 1), and so on.

The test cases are generated so that all the values in the output fit in a 32-bit integer.


*/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string countOfAtoms(string formula) {
        stack<map<string, int>> s;
        int i = 0;
        int n = formula.length();    
        while (i < n) {
            if (formula[i] == '(') {
                s.push(map<string, int>());
            } else if (formula[i] == ')') {
                map<string, int> curr_map = s.top();
                s.pop();
                string count = "";
                while (i + 1 < n && isdigit(formula[i + 1])) {
                    count += formula[++i];
                }
                int value = (count == "") ? 1 : stoi(count);
                if (!s.empty()) {
                    map<string, int>& prev_map = s.top();
                    for (auto& z : curr_map) {
                        prev_map[z.first] += z.second * value;
                    }
                } else {
                    for (auto& z : curr_map) {
                        curr_map[z.first] *= value;
                    }
                    s.push(curr_map);
                }
            } else {
                string atom = "";
                atom += formula[i];
                if (i + 1 < n && islower(formula[i + 1])) {
                    atom += formula[++i];
                }
                string count = "";
                while (i + 1 < n && isdigit(formula[i + 1])) {
                    count += formula[++i];
                }
                int value = (count == "") ? 1 : stoi(count);
                map<string, int> temp_mp;
                temp_mp[atom] += value; 
                if (!s.empty()) {
                    map<string, int>& top_map = s.top();
                    for (auto& z : temp_mp) {
                        top_map[z.first] += z.second;
                    }
                } else {
                    s.push(temp_mp);
                }
            }
            i++;
        }    
        map<string, int> last_mp = s.top();
        string ans = "";
        for (auto& a : last_mp) {
            ans += a.first;
            if (a.second > 1) {
                ans += to_string(a.second);
            }
        } 
        return ans;
    }
};