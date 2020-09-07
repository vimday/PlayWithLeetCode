/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day0907_top-k-frequent-elements.cpp
 * @Created Time:2020-09-07 12:08:30
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
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // pair<count, val>
        // top k, min heap(小根堆)
        using E = std::pair<int, int>;
        std::priority_queue<E, std::vector<E>, std::greater<E>> minHeap;
        map<int, int> counter;

        for (auto e : nums) {
            ++counter[e];
        }

        for (auto& x : counter) {
            auto pair = make_pair(x.second, x.first);
            if (minHeap.size() == k) {
                if (pair < minHeap.top()) continue;
                minHeap.pop();
            }
            minHeap.push(std::move(pair));
        }
        std::vector<int> res(minHeap.size());
        k = res.size();
        while (!minHeap.empty()) {
            res[--k] = minHeap.top().second;
            minHeap.pop();
        }
        return res;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (int& i : nums)
            m[i]++;
        function<bool(int, int)> cmp = [&m](int a, int b) { return m[a] > m[b]; };
        vector<int> res(k);
        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
        for (auto& p : m) {
            if (pq.size() < k)
                pq.push(p.first);
            else if (p.second > m[pq.top()]) {
                pq.pop();
                pq.push(p.first);
            }
        }
        while (!pq.empty()) {
            res[--k] = pq.top();
            pq.pop();
        }
        return res;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ret;
        unordered_map<int, int> mp;
        priority_queue<pair<int, int>> pq;
        for (auto i : nums) mp[i]++;
        for (auto p : mp) {
            pq.push(pair<int, int>(-p.second, p.first));
            if (pq.size() > k) pq.pop();
        }
        while (k--) {
            ret.push_back(pq.top().second);
            pq.pop();
        }
        return ret;
    }
};
