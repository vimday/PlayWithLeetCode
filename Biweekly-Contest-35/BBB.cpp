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
//创建一个list，每次request，在区间开始、结束为止分别 + 1 - 1。当从左往右遍历时，把这些标记累积起来，就是当前为止被访问的次数。
class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        int n = nums.size();
        vector<int> cnt(n);
        int temp[n][2];
        fill(&temp[0][0], &temp[0][0] + n * 2, 0);
        for (int i = 0; i < requests.size(); i++) {
            temp[requests[i][0]][0]++;
            temp[requests[i][1]][1]--;
        }
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += temp[i][0];
            cnt[i] = sum;
            //cout<<i<<" "<<cnt[i]<<endl;
            sum += temp[i][1];
        }
        sort(cnt.begin(), cnt.end(), [](int& a, int& b) {
            return a > b;
        });
        sort(nums.begin(), nums.end(), [](int& a, int& b) {
            return a > b;
        });
        int ans = 0;
        int dev = 1e9 + 7;
        for (int i = 0; i < n; i++) {
            if (cnt[i] == 0) break;
            ans += cnt[i] * nums[i];
            ans %= dev;
        }
        return ans;
    }
};

class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        const int MOL = 1e9 + 7;
        int N = nums.size();
        vector<int> rv(N + 1);
        for (const auto& v : requests) {
            rv[v[0]]++;
            rv[v[1] + 1]--;
        }
        for (int i = 1; i < N; i++) {
            rv[i] += rv[i - 1];
        }
        sort(nums.begin(), nums.end(), greater<int>());
        sort(rv.begin(), rv.end(), greater<int>());
        int res = 0;
        for (int i = 0; i < N && rv[i] != 0; i++) {
            res = (res + nums[i] * rv[i]) % MOL;
        }
        return res;
    }
};
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