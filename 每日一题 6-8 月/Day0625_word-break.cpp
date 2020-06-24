/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day0625_word-break.cpp
 * @Created Time:2020-06-25 01:20:34
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
    bool wordBreak(string s, vector<string>& wordDict) {
        //dp[j] ||=dp[j-nums[i]]
        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        unordered_set<string> m(wordDict.begin(), wordDict.end());
        int maxWordLength = 0, minl = INT_MAX;
        for (int i = 0; i < wordDict.size(); ++i) {
            maxWordLength = std::max(maxWordLength, (int)wordDict[i].size());
            minl = min(minl, (int)wordDict[i].size());
        }
        for (int i = minl; i <= n; ++i) {
            for (int j = max(i - maxWordLength, 0); j < i - minl + 1; ++j) {
                if (dp[j] && m.find(s.substr(j, i - j)) != m.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};