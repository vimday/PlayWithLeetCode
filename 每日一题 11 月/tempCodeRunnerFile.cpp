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