/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :BBB.cpp
 * @Created Time:2020-09-19 22:35:07
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
const int mod = 1e9 + 7;
const int MAXN = 2e5 + 7;
//BIT - 区间修改，单点查询 - st
struct _BIT {
    int N, C[MAXN];
    int lowbit(int x) { return x & (-x); }
    void init(int n)  //初始化共有n个点
    {
        N = n;
        for (int i = 1; i <= N; i++) C[i] = 0;
    }
    void add(int pos, int val) {
        while (pos <= N) C[pos] += val, pos += lowbit(pos);
    }
    void range_add(int l, int r, int x)  //区间[l,r]加x
    {
        add(l, x);
        add(r + 1, -x);
    }
    int ask(int pos)  //查询pos点的值
    {
        int ret = 0;
        while (pos > 0) {
            ret += C[pos];
            pos -= lowbit(pos);
        }
        return ret;
    }
} BIT;
class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        int n = nums.size();
        BIT.init(n + 1);
        for (vector<int>& v : requests) {
            int b = v[0] + 1, e = v[1] + 1;
            BIT.range_add(b, e, 1);
        }
        priority_queue<int> pq;
        for (int i = 1; i <= n; i++)
            pq.push(BIT.ask(i));
        long long res = 0;
        sort(nums.begin(), nums.end());
        reverse(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            long long cnt = pq.top();
            pq.pop();
            res += cnt * nums[i];
            res %= mod;
        }
        return res;
    }
};