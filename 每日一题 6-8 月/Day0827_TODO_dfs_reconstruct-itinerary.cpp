/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day0827_reconstruct-itinerary.cpp
 * @Created Time:2020-08-27 23:13:02
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
    int len;
    bool flag;
    string tmp, res;
    vector<string> ans;
    unordered_map<string, int> vis;         //标记访问过程中边的剩余量
    unordered_map<string, set<string>> mp;  //记录边,第二项要排序这样找到的第一个解就是正解（大大节省时间）
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        len = tickets.size();
        for (auto& it : tickets) {
            mp[it[0]].insert(it[1]);
            vis[it[0] + it[1]]++;
        }
        vis["JFK"] = 1;
        dfs("", "JFK", 0);
        for (int i = 0; i < res.length(); i += 3) ans.push_back(string(res.begin() + i, res.begin() + i + 3));
        return ans;
    }
    void dfs(string last, string site, int cnt) {
        if (!vis[last + site] || res != "") return;  //如果这条边已经使用完毕或者已经找到解就不需要继续访问了
        tmp += site;
        vis[last + site]--;
        for (auto& next : mp[site]) dfs(site, next, cnt + 1);
        if (cnt == len) res = tmp;
        vis[last + site]++;
        tmp.erase(tmp.end() - site.length(), tmp.end());
    }
};

// '''1.比较容易理解的方式：'''
// # 类似大部分基本深搜，每次对当前出发点的“剩余可用目的地”循环，优先去名字值小的
// # 但无论以递归入参还是全局变量的方式，每次进递归需层数+1，选择的ticket要暂时标为已用，即当前form-to的剩余可用次数-1
// # 结束条件是层数达到完全遍历，若未达到又无可用目的地，说明这条路走不通了，回溯时需还原层数、可用次数

// '''2.更烧脑但更简洁的方式：'''
// # 因题目强调了“假定所有机票至少存在一种合理的行程”，所以可利用深搜一定会有结果这一点，无需任何标记、判定，仅单纯对每层进行循环及扣除
// # 也就是每次进递归，还是对当前“剩余可用目的地”循环，但选择名字值小的进入下层时直接扣除这张机票
// # 这样任意循环若还能进行，说明还有机票没用；反之一定是“基于已经出现的终点，自身成为更早部分的终点”
// # 这里有点绕，举例来说第一个结束循环的一定是唯一一个这样的机场：他作为机票的终点的总次数，比作为起点的总次数多1
// # 也就是说JFK恰好是唯一相反的机场，而其它机场作为起点和终点的总次数一定相同
// # 所以最早结束循环的递归，一定是入参为终点时，将其加入行程数组；第二个出现的，则是之前行程中，唯一可作为终点的
// # 以此类推……最后行程数组反向，即为答案

// # 本人py3的代码：
// import collections

// class Solution:
//     def findItinerary(self, tickets):
//         paths = collections.defaultdict(list)
//         for start, tar in tickets:
//             paths[start].append(tar)
//         for start in paths:
//             paths[start].sort(reverse=True)
//         s = []

//         def search(start):
//             while paths[start]:
//                 search(paths[start].pop())
//             s.append(start)

//         search("JFK")
//         return s[::-1]

class Solution {
private:
    unordered_map<string, multiset<string>> mp;
    vector<string> ans;

public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (auto x : tickets) {
            mp[x[0]].insert(x[1]);
        }

        string start = "JFK";
        if (mp.count(start) == 0) {
            return ans;
        }
        dfs(start);
        reverse(ans.begin(), ans.end());
        return ans;
    }

    void dfs(string start) {
        while (mp[start].size()) {
            string next = *mp[start].begin();
            mp[start].erase(mp[start].begin());
            dfs(next);
        }
        ans.push_back(start);
    }
};

class Solution {
    vector<string> res;
    int curidx;

    int idx[18000] = {0};
    int value[80];
    char stringlist[80][4];
    int M[80][50], len[80] = {0};
    int cursor[80] = {0};

public:
    inline int trans(string& s) {
        return (s[0] - 'A') * 676 + (s[1] - 'A') * 26 + (s[2] - 'A');
    }
    void fun(int i) {
        while (cursor[i] < len[i]) {
            int j = M[i][cursor[i]++];
            fun(j);
        }
        res[curidx--] = stringlist[i];
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        int i, j, k = 0;
        for (vector<string>& A : tickets) {
            int a = trans(A[0]);
            int b = trans(A[1]);
            if (!(i = idx[a])) {
                i = idx[a] = ++k;
                value[i] = a;
                memcpy(stringlist[i], A[0].c_str(), 4);
            }
            if (!(j = idx[b])) {
                j = idx[b] = ++k;
                value[j] = b;
                memcpy(stringlist[j], A[1].c_str(), 4);
            }
            M[i][len[i]++] = j;
        }
        for (i = 1; i <= k; i++) sort(M[i], M[i] + len[i], [&](int x, int y) -> bool { return value[x] < value[y]; });
        res.resize(tickets.size() + 1);
        curidx = tickets.size();
        fun(idx[6224]);
        return res;
    }
};