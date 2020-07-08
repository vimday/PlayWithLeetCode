/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day0709_dp_dictree_strhash_re-space-lcci.cpp
 * @Created Time:2020-07-09 01:11:53
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
    int respace(vector<string>& dic, string ss) {
        unordered_set<string> us(dic.begin(), dic.end());
        int n = ss.size(), mn = INT_MAX, mx = INT_MIN;
        for (string& s : dic) {
            mn = min(mn, (int)s.size());
            mx = max(mx, (int)s.size());
        }

        int dp[n + 1];
        for (int i = 0; i <= n; i++)
            dp[i] = i;
        for (int i = 1; i <= n; i++)
            for (int d = 1; d <= mx && i - d >= 0; d++)
                if (us.count(ss.substr(i - d, d)))
                    dp[i] = min(dp[i], dp[i - d]);
                else
                    dp[i] = min(dp[i], dp[i - d] + d);
        return dp[n];
    }
};
class Solution {
    int N;
    int dp[1000 + 7];
    vector<int> pref[1000 + 7];

public:
    int respace(vector<string>& dictionary, string sentence) {
        if (sentence.size() == 0) return 0;

        N = sentence.size();
        fill(dp, dp + N, 1 << 30), dp[0] = 0;
        sentence.insert(sentence.begin(), '\0');

        for (string& str : dictionary) {
            int pos = 1;

            while ((pos = sentence.find(str, pos)) > 0) {
                pref[pos + str.size() - 1].push_back(pos);
                pos += str.size();
            }
        }

        for (int i = 1; i <= N; i++) {
            dp[i] = dp[i - 1] + 1;

            if (pref[i].size() == 0) {
                dp[i] = dp[i - 1] + 1;
                continue;
            }

            for (int st : pref[i])
                dp[i] = min(dp[i], dp[st - 1]);
        }

        return dp[N];
    }
};
class Trie {
public:
    Trie* next[26] = {nullptr};
    bool isEnd;

    Trie() {
        isEnd = false;
    }

    void insert(string s) {
        Trie* curPos = this;

        for (int i = s.length() - 1; i >= 0; --i) {
            int t = s[i] - 'a';
            if (curPos->next[t] == nullptr) {
                curPos->next[t] = new Trie();
            }
            curPos = curPos->next[t];
        }
        curPos->isEnd = true;
    }
};

class Solution {
public:
    int respace(vector<string>& dictionary, string sentence) {
        int n = sentence.length(), inf = 0x3f3f3f3f;

        Trie* root = new Trie();
        for (auto& word : dictionary) {
            root->insert(word);
        }

        vector<int> dp(n + 1, inf);
        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            dp[i] = dp[i - 1] + 1;

            Trie* curPos = root;
            for (int j = i; j >= 1; --j) {
                int t = sentence[j - 1] - 'a';
                if (curPos->next[t] == nullptr) {
                    break;
                } else if (curPos->next[t]->isEnd) {
                    dp[i] = min(dp[i], dp[j - 1]);
                }
                if (dp[i] == 0) {
                    break;
                }
                curPos = curPos->next[t];
            }
        }
        return dp[n];
    }
};
class Solution {
public:
    using LL = long long;

    static constexpr LL P = (1LL << 31) - 1;
    static constexpr LL BASE = 41;

    LL getHash(const string& s) {
        LL hashValue = 0;
        for (int i = s.size() - 1; i >= 0; --i) {
            hashValue = hashValue * BASE + s[i] - 'a' + 1;
            hashValue = hashValue % P;
        }
        return hashValue;
    }

    int respace(vector<string>& dictionary, string sentence) {
        unordered_set<LL> hashValues;
        for (const auto& word : dictionary) {
            hashValues.insert(getHash(word));
        }

        vector<int> f(sentence.size() + 1, sentence.size());

        f[0] = 0;
        for (int i = 1; i <= sentence.size(); ++i) {
            f[i] = f[i - 1] + 1;
            LL hashValue = 0;
            for (int j = i; j >= 1; --j) {
                int t = sentence[j - 1] - 'a' + 1;
                hashValue = hashValue * BASE + t;
                hashValue = hashValue % P;
                if (hashValues.find(hashValue) != hashValues.end()) {
                    f[i] = min(f[i], f[j - 1]);
                }
            }
        }

        return f[sentence.size()];
    }
};