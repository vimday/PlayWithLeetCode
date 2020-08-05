/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day0806_todo_hard_palindrome-pairs.cpp
 * @Created Time:2020-08-06 01:17:23
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
    bool f(string& s, int left, int right) {
        while (left < right) {
            if (s[left++] != s[right--]) return false;
        }
        return true;
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> m;
        set<int> s;
        int n = words.size();
        for (int i = 0; i < n; i++) {
            m[words[i]] = i;
            s.insert(words[i].size());
        }
        vector<vector<int>> res;
        for (int i = 0; i < n; i++) {
            string tmp = words[i];
            reverse(tmp.begin(), tmp.end());
            if (m.count(tmp) && m[tmp] != i) {
                res.push_back({m[tmp], i});
            }
            int length = tmp.size();
            for (auto it = s.begin(); *it != length; it++) {
                int d = *it;
                if (f(tmp, 0, length - d - 1) && m.count(tmp.substr(length - d))) {
                    res.push_back({i, m[tmp.substr(length - d)]});
                }
                if (f(tmp, d, length - 1) && m.count(tmp.substr(0, d))) {
                    res.push_back({m[tmp.substr(0, d)], i});
                }
            }
        }
        return res;
    }
};
struct Node {
    Node* children[26];
    vector<int> words;
    vector<int> suffixs;

    Node() {
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
    }
};

class Solution {
public:
    //Manacher判断回文后缀
    void judgePalindrome(string& s, vector<bool>& palindrome_suffix) {
        int mx = 1;
        int mid = 0;
        int limit = 2 * s.length() + 1;
        vector<int> dp(limit, 0);
        dp[0] = 1;  //初始字符串的右边界
        for (int i = 1; i < limit; i++) {
            if (i < mx) {
                dp[i] = min(dp[2 * mid - i], mx - i);
            } else {
                if (i % 2) {
                    dp[i] = 2;
                } else {
                    dp[i] = 1;
                }
            }
            int maxLen = dp[i];
            //(i-maxLen)/2  与 (i+maxLen)/2 是重点
            while (i - maxLen >= 0 && i + maxLen < limit && s[(i - maxLen) / 2] == s[(i + maxLen) / 2]) {
                maxLen += 2;
            }
            dp[i] = maxLen;
            if (i + dp[i] > mx) {  //更新右边界
                mid = i;
                mx = i + dp[i];
            }

            if (i + maxLen == limit) {  //后缀为回文串
                int len = maxLen - 1;   //回文串长度
                palindrome_suffix[s.length() - len] = true;
            }
        }
    }

    vector<vector<int>> palindromePairs(vector<string>& words) {
        Node* root = new Node();
        for (int i = 0; i < words.size(); i++) {
            string word = words[i];
            reverse(word.begin(), word.end());
            vector<bool> palindrome_suffix(word.length() + 1, false);
            judgePalindrome(word, palindrome_suffix);
            Node* curr = root;
            if (palindrome_suffix[0]) {
                curr->suffixs.emplace_back(i);
            }
            for (int j = 0; j < word.length(); j++) {
                int pos = word[j] - 'a';
                if (curr->children[pos] == NULL) curr->children[pos] = new Node();
                curr = curr->children[pos];
                if (palindrome_suffix[j + 1]) {
                    curr->suffixs.emplace_back(i);
                }
            }
            curr->words.emplace_back(i);
        }
        vector<vector<int>> ans;
        for (int i = 0; i < words.size(); i++) {
            string& word = words[i];
            vector<bool> palindrome_suffix(word.length() + 1, false);
            judgePalindrome(word, palindrome_suffix);
            Node* curr = root;
            int j = 0;
            //X字符串不长于Y字符串
            for (; j < word.length(); j++) {
                if (palindrome_suffix[j]) {
                    for (int k : curr->words) {
                        if (k != i) ans.emplace_back(vector<int>({i, k}));
                    }
                }
                int pos = word[j] - 'a';
                if (curr->children[pos] == NULL) break;
                curr = curr->children[pos];
            }
            //X字符串不短于Y字符串
            if (j == word.length()) {
                for (int k : curr->suffixs) {
                    if (k != i) ans.emplace_back(vector<int>({i, k}));
                }
            }
        }
        return ans;
    }
};