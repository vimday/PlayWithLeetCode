/*
 * @Author      :vimday
 * @Desc        :lc 周赛180 B
 * @Url         :https://leetcode-cn.com/problems/design-a-stack-with-increment-operation/
 * @File Name   :B-design-a-stack-with-increment-operation.cpp
 * @Created Time:2020-03-15 12:40:10
 * @E-mail      :lwftx@outlook.com
 * @GitHub      :https://github.com/vimday
 */
#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int)x.size())
#define PB push_back
void debug() {
#ifdef LOCAL
    freopen("E:\\Cpp\\in.txt", "r", stdin);
    freopen("E:\\Cpp\\out.txt", "w", stdout);
#endif
}

//qc大佬的
class CustomStack {
public:
    int add, mx;
    vector<int> elem, sum;

    CustomStack(int maxSize) {
        add = 0;
        mx = maxSize;
    }

    void push(int x) {
        if (sz(elem) == mx) return;
        x -= add;
        elem.PB(x);
        sum.PB(0);
    }

    int pop() {
        if (!sz(elem)) return -1;
        add += sum.back();
        int ans = add + elem.back();
        elem.pop_back();
        sum.pop_back();
        return ans;
    }

    void increment(int k, int val) {
        if (sz(sum) >= k) {
            sum[k - 1] += val;
        } else {
            add += val;
        }
    }
};

//很蠢的BF，直接用vector就好
class CustomStack {
public:
    stack<int> data;
    int sz = 0;
    CustomStack(int maxSize) { sz = maxSize; }

    void push(int x) {
        if (data.size() == sz) return;
        data.push(x);
    }

    int pop() {
        if (data.size() == 0) return -1;
        int t = data.top();
        data.pop();
        return t;
    }

    void increment(int k, int val) {
        stack<int> as;
        int cur = data.size();
        while (data.size()) {
            if (data.size() <= k) {
                as.push(data.top() + val);
            } else {
                as.push(data.top());
            }

            data.pop();
        }
        while (as.size()) {
            data.push(as.top());
            as.pop();
        }
    }
};
//wlp
class CustomStack {
    int s[1005], t, n;

public:
    CustomStack(int maxSize) {
        t = 0;
        n = maxSize;
    }

    void push(int x) {
        if (t < n) s[++t] = x;
    }

    int pop() {
        if (t) return s[t--];
        return -1;
    }

    void increment(int k, int val) {
        while (k) s[k--] += val;
    }
};