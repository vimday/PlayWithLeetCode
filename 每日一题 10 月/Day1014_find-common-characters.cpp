/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day1014_find-common-characters.cpp
 * @Created Time:2020-10-15 18:03:48
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
    vector<string> commonChars(vector<string>& A) {
        vector<string> res;
        for (int i = 0; i < 26; i++) {
            char c = 'a' + i;
            int cnt = INT_MAX;
            for (string& s : A) {
                int cur = 0;
                for (char& cc : s)
                    if (cc == c)
                        cur++;
                cnt = min(cnt, cur);
                if (cnt == 0)
                    break;
            }
            while (cnt--) res.push_back(string(1, c));
        }
        return res;
    }
};
class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<string> res;
        int pre[26], cur[26];
        memset(pre, 0, sizeof pre);
        memset(cur, 0, sizeof cur);
        for (char& c : A[0])
            pre[c - 'a']++;
        int n = A.size();
        for (int i = 1; i < n; i++) {
            string& s = A[i];
            for (char& c : s)
                cur[c - 'a']++;
            for (int i = 0; i < 26; i++) {
                pre[i] = min(pre[i], cur[i]);
                cur[i] = 0;
            }
        }

        for (int i = 0; i < 26; i++) {
            char c = 'a' + i;
            int cnt = pre[i];

            while (cnt--) res.push_back(string(1, c));
        }
        return res;
    }
};