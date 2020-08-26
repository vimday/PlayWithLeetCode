/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day0826_letter-combinations-of-a-phone-number.cpp
 * @Created Time:2020-08-26 11:34:45
 * @E-mail      :lwftx@outlook.com
 * @GitHub      :https://github.com/vimday
 */
#include <bits/stdc++.h>
using namespace std;
void debug() {
#ifdef LOCAL
    freopen("E:\\Cpp\\in.txt", "r", stdin);
    freopen("E:\\Cpp\\out.txt", "w", stdout);
#endif
}
class Solution {
public:
    string s[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}, d;
    vector<string> res;
    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        if (n == 0) return {};
        d = digits;
        string tmp = "";
        dfs(tmp);
        return res;
    }
    void dfs(string &t) {
        if (t.size() == d.size()) {
            res.emplace_back(t);
            return;
        }
        int cur = d[t.size()] - '0';
        string l = s[cur];
        for (char c : l) {
            t += c;
            dfs(t);
            t.erase(t.size() - 1);
        }
    }
};