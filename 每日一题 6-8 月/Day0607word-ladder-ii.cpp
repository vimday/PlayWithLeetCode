/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day0607word-ladder-ii.cpp
 * @Created Time:2020-06-07 22:28:56
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
    vector<vector<string>> res;
    unordered_map<string, vector<string>> m;  //记录路径
    vector<vector<string>> findLadders(string bw, string ew, vector<string>& wl) {
        //这道题做过 双向 bfs,求最短路一般用 bfs
        unordered_set<string> ws(wl.begin(), wl.end());
        if (ws.find(ew) == ws.end()) return res;

        unordered_set<string> bs{bw}, es{ew};
        bool f = false, swaped = false;
        while (!bs.empty()) {
            for (auto s : bs)
                ws.erase(s);
            unordered_set<string> ns;
            for (auto ps : bs) {
                string s = ps;
                int sz = s.size();
                for (int i = 0; i < sz; i++) {
                    char c = s[i];
                    for (char j = 'a'; j <= 'z'; j++) {
                        s[i] = j;
                        if (ws.count(s) == 0)
                            continue;
                        if (es.count(s))
                            f = true;
                        else
                            ns.insert(s);
                        swaped ? m[s].push_back(ps) : m[ps].push_back(s);
                    }
                    s[i] = c;
                }
            }
            if (f)
                break;
            bs = ns;
            if (bs.size() > es.size()) {
                swap(bs, es);
                swaped = !swaped;
            }
        }
        //这个时候已经搜索完了 需要拼接路径
        vector<string> path{bw};
        dfs(path, bw, ew);
        return res;
    }
    void dfs(vector<string>& path, string& cw, string& ew) {
        if (cw == ew) {
            res.push_back(path);
            return;
        }
        for (auto s : m[cw]) {
            path.push_back(s);
            dfs(path, s, ew);
            path.pop_back();
        }
    }
};