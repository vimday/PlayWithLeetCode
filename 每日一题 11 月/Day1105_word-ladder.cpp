/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day1105_word-ladder.cpp
 * @Created Time:2020-11-05 16:21:01
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
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordDict(wordList.begin(), wordList.end());
        if (wordDict.find(endWord) == wordDict.end()) {
            return 0;  //Not FOUND 404
        }
        unordered_set<string> beginSet{beginWord};
        unordered_set<string> endSet{endWord};
        int step = 1;
        for (; !beginSet.empty();) {
            unordered_set<string> tempSet;
            ++step;
            for (auto s : beginSet) {
                wordDict.erase(s);
            }
            for (auto s : beginSet) {
                for (int i = 0; i < s.size(); ++i) {
                    string str = s;
                    for (char c = 'a'; c <= 'z'; ++c) {
                        str[i] = c;
                        if (wordDict.find(str) == wordDict.end()) {
                            continue;
                        }
                        if (endSet.find(str) != endSet.end()) {
                            return step;
                        }
                        tempSet.insert(str);
                    }
                }
            }
            if (tempSet.size() < endSet.size()) {
                beginSet = tempSet;
            } else {
                beginSet = endSet;
                endSet = tempSet;
            }
        }
        return 0;
    }
};
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (wordSet.count(endWord) == 0) return 0;

        unordered_set<string> from({beginWord});
        unordered_set<string> to({endWord});
        int ans = 2;

        while (!from.empty()) {
            unordered_set<string> next;
            for (auto& word : from) {
                wordSet.erase(word);
            }
            for (auto& word : from) {
                for (int i = 0; i < word.size(); i++) {
                    string s = word;
                    for (char c = 'a'; c <= 'z'; c++) {
                        s[i] = c;
                        if (wordSet.count(s) == 0) continue;
                        next.insert(s);
                        if (to.count(s) == 0) continue;
                        return ans;
                    }
                }
            }
            from = next;
            if (from.size() > to.size()) {
                swap(from, to);
            }
            ans++;
        }
        return 0;
    }
};