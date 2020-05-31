/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day82longest-palindromic-substring.cpp
 * @Created Time:2020-05-21 00:20:59
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
    string longestPalindrome(string s) {
        string ns = "$#";
        int n = s.size();
        for (int i = 0; i < n; i++) {
            //ns += s[i];
            //ns += '#';
            ns.push_back(s[i]);
            ns.push_back('#');
        }

        int L = 2 * n + 2;
        vector<int> RL(L, 0);
        int pos = 0, center = 0, maxRight = 0, maxL = 0;
        for (int i = 1; i < L; i++) {
            if (i < maxRight)
                RL[i] = min(RL[2 * pos - i], maxRight - i);
            else
                RL[i] = 1;
            while (ns[i + RL[i]] == ns[i - RL[i]])
                RL[i]++;
            if (i + RL[i] > maxRight) {
                maxRight = i + RL[i];
                pos = i;
            }
            if (maxL < RL[i]) {
                center = i;
                maxL = RL[i];
            }
        }
        return s.substr((center - maxL) / 2, maxL - 1);
    }
};
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int res = 0, si = 0;
        for (int i = 0; i < n; i++) {
            int l = i - 1, r = i + 1, cur = 1;
            while (l >= 0 && r < n && s[l] == s[r]) {
                l--;
                r++;
                cur += 2;
            }
            if (cur > res) {
                si = l + 1;
                res = cur;
            }
            l = i, r = i + 1;
            cur = 0;
            while (l >= 0 && r < n && s[l] == s[r]) {
                l--;
                r++;
                cur += 2;
            }
            if (cur > res) {
                si = l + 1;
                res = cur;
            }
        }
        return s.substr(si, res);
    }
};
