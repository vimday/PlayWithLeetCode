/*
 * @Author      :vimday
 * @Desc        :lc wc180 D
 * @Url         :https://leetcode-cn.com/problems/maximum-performance-of-a-team/
 * @File Name   :D-maximum-performance-of-a-team.cpp
 * @Created Time:2020-03-15 13:34:19
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
    int maxPerformance(int n, vector<int>& sd, vector<int>& ey, int k) {
        vector<pair<int, int>> data;
        for (int i = 0; i < n; i++) {
            data.push_back({ey[i], sd[i]});
        }
        sort(data.begin(), data.end());
        reverse(data.begin(), data.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        long long res = 0, s = 0;
        for (int i = 0; i < n; i++) {
            if (pq.size() < k) {
                s += data[i].second;
                pq.push(data[i].second);
            } else {
                if (data[i].second > pq.top()) {
                    s -= pq.top();
                    pq.pop();
                    pq.push(data[i].second);
                    s += data[i].second;
                }
            }

            res = max(res, data[i].first * s);
        }
        return res % (int)(1e9 + 7);
    }
};
typedef long long LL;

class Solution {
    // 比较效率与速度，大小按 greater 来处理
    // 效率 (efficiency, first) 优先考虑，速度 (speed, second) 随后考虑
    struct PairCompare {
        inline bool operator()(pair<LL, LL>& p1, pair<LL, LL>& p2) {
            if (p1.first == p2.first)
                return p1.second > p2.second;
            else
                return p1.first > p2.first;
        }
    };

public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        // 首先对效率与速度作排序
        vector<pair<LL, LL>> pr;
        pr.reserve(n);
        for (int i = 0; i < n; ++i)
            pr.push_back(make_pair((LL)efficiency[i], (LL)speed[i]));
        sort(pr.begin(), pr.end(), PairCompare());
        // 预定义
        LL spd_sum = 0;   // 最快的 (不多于) k 个速度的和
        multiset<LL> st;  // 最快速度的集合
        LL result = 0;    // 待返回的结果
        // 随后从依效率从高到低顺序，遍历所有员工
        for (int i = 0; i < n; ++i) {
            // 如果员工数没有到最大值 k，则把所有员工的速度都考虑进来
            if (i < k) {
                spd_sum += pr[i].second;
                st.insert(pr[i].second);
            }
            // 如果员工数已经大于 k，且当前员工速度比较快，那么 fire 掉最慢的员工，无论该员工效率如何
            else if (pr[i].second > *st.begin()) {
                spd_sum += pr[i].second - *st.begin();
                st.erase(st.begin());
                st.insert(pr[i].second);
            }
            // 更新一下结果
            result = max(spd_sum * pr[i].first, result);
        }
        return int(result % (LL)1000000007);
    }
};
