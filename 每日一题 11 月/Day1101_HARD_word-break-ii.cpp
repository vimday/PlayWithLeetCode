/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day1101_HARD_word-break-ii.cpp
 * @Created Time:2020-11-01 19:19:56
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
    struct TrieNode {
        bool flag;
        map<char, TrieNode*> next;
        TrieNode() : flag(false) {}
    };
    TrieNode* root;
    void init(const vector<string>& words) {
        root = new TrieNode;
        for (auto& w : words) {
            auto node = root;
            for (auto c : w) {
                if (!node->next.count(c)) {
                    node->next[c] = new TrieNode;
                }
                node = node->next[c];
            }
            node->flag = true;
        }
    }

    void dfs(const string& s, const vector<vector<int> >& dp, int i, vector<string>& v, vector<string>& res) {
        if (i == 0) {
            string t;
            for (auto it = v.rbegin(); it != v.rend(); ++it) {
                t += *it + " ";
            }
            t.pop_back();
            res.push_back(t);
            return;
        }
        for (auto j : dp[i]) {
            v.push_back(s.substr(j, i - j));
            dfs(s, dp, j, v, res);
            v.pop_back();
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        // 构建字典树
        init(wordDict);
        unordered_set<char> cs;
        for (auto& w : wordDict) {
            for (auto c : w) {
                cs.insert(c);
            }
        }
        for (auto c : s) {
            if (cs.count(c) == 0) {
                return {};
            }
        }
        // 动态规划部分
        int N = s.size();
        vector<vector<int> > dp(N + 1);
        dp[0] = vector<int>{-1};
        for (int i = 0; i < N; ++i) {
            if (dp[i].empty()) continue;
            int j = i;
            auto node = root;
            while (j < N && node->next.count(s[j])) {
                node = node->next[s[j++]];
                if (node->flag) {
                    dp[j].push_back(i);
                }
            }
        }
        // 路径回溯构建所有可能的结果字符串
        vector<string> v;
        vector<string> res;
        dfs(s, dp, N, v, res);
        return res;
    }
};
class Solution {
public:
    vector<string> res, ms;
    unordered_set<string> me;
    int n;
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        n = s.size();
        if (!wordBreak2(s, wordDict)) return res;
        me = unordered_set<string>(wordDict.begin(), wordDict.end());
        help(s, 0);
        return res;
    }
    bool wordBreak2(string s, vector<string>& wordDict) {
        if (wordDict.empty()) return false;
        unordered_set<string> sstr(wordDict.begin(), wordDict.end());
        int dp[s.size() + 1]{0};
        dp[0] = 1;
        int maxl = wordDict[0].size();
        for (int i = 1; i < wordDict.size(); i++)
            maxl = max(maxl, (int)wordDict[i].size());
        for (int i = 1; i <= s.size(); i++) {
            for (int j = max(i - maxl, 0); j < i; j++) {
                if (dp[j] == 1 && sstr.find(s.substr(j, i - j)) != sstr.end()) {
                    dp[i] = 1;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
    void help(string& s, int idx) {
        if (idx == n) {
            string t;
            for (string& tmp : ms)
                t += tmp + " ";
            t.pop_back();
            res.emplace_back(t);
            return;
        }
        for (int i = idx; i < n; i++) {
            if (me.count(s.substr(idx, i - idx + 1))) {
                ms.push_back(s.substr(idx, i - idx + 1));
                help(s, i + 1);
                ms.pop_back();
            }
        }
    }
};