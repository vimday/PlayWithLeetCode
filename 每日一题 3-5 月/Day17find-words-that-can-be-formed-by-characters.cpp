/*
 * @Author      :vimday
 * @Desc        :lc day 17
 * @Url         :https://leetcode-cn.com/problems/find-words-that-can-be-formed-by-characters/
 * @File Name   :Day17find-words-that-can-be-formed-by-characters.cpp
 * @Created Time:2020-03-17 00:09:23
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
    int countCharacters(vector<string>& words, string chars) {
        int res = 0;
        int m[26] = {};
        for (char& c : chars)
            m[c - 'a']++;
        for (string& s : words) {
            for (char& c : s)
                m[c - 'a']--;
            bool f = true;
            for (char& c : s) {
                if (m[c - 'a'] < 0)
                    f = false;
                m[c - 'a']++;
            }
            if (f)
                res += s.size();
        }
        return res;
    }
};
//7个月前提交得
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int m[128] = {};
        for (char c : chars) m[c]++;
        int res = 0;
        for (string& s : words) {
            int n = s.size(), i = 0;
            for (i = 0; i < n; ++i) {
                if (m[s[i]] > 0)
                    m[s[i]]--;
                else
                    break;
            }
            if (i == n) res += n;
            for (int k = 0; k < i; ++k)
                m[s[k]]++;
        }
        return res;
    }
};