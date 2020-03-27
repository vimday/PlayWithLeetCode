/*
 * @Author      :vimday
 * @Desc        :lc day 28 short-encoding-of-words
 * @Url         :https://leetcode-cn.com/problems/short-encoding-of-words/
 * @File Name   :Day28short-encoding-of-words.cpp
 * @Created Time:2020-03-28 00:25:58
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
struct trie {
    trie* next[26] = {};
    int dh = 0;
    bool f = false;
};

void trieadd(trie* root, string& s, int idx) {
    if (idx >= s.size())
        return;
    char c = s[idx++];
    root->f = true;
    trie* cur = root->next[c - 'a'];
    if (cur == nullptr) {
        cur = root->next[c - 'a'] = new trie();
        cur->dh = root->dh + 1;
    }
    trieadd(cur, s, idx);
}
class Solution {
public:
    int res = 0;
    void dfs(trie* root) {
        if (!root) return;
        if (!root->f) {
            res += root->dh + 1;
            return;
        } else {
            for (int i = 0; i < 26; i++) {
                if (root->next[i]) {
                    dfs(root->next[i]);
                }
            }
        }
    }
    int minimumLengthEncoding(vector<string>& ws) {
        trie* root = new trie();
        for (string& s : ws) {
            reverse(s.begin(), s.end());
            trieadd(root, s, 0);
        }
        dfs(root);
        return res;
    }
};