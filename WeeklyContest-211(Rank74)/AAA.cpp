/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :AAA.cpp
 * @Created Time:2020-10-18 10:29:43
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
    int maxLengthBetweenEqualCharacters(string s) {
        int n = s.size();
        vector<int> mn(26, n), mx(26, -1);
        for (int i = 0; i < n; i++) {
            int j = s[i] - 'a';
            mn[j] = min(mn[j], i);
            mx[j] = max(mx[j], i);
        }
        int res = -1;
        for (int i = 0; i < 26; i++) {
            if (mn[i] < mx[i])
                res = max(res, mx[i] - mn[i] - 1);
        }
        return res;
    }
};
class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int n = s.size();
        int ans = -1;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (s[i] == s[j]) ans = max(ans, j - i - 1);
            }
        }
        return ans;
    }
};