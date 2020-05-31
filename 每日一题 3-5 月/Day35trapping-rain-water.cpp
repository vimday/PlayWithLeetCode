/*
 * @Author      :vimday
 * @Desc        :接雨水
 * @Url         :https://leetcode-cn.com/problems/trapping-rain-water/submissions/
 * @File Name   :Day35
 * @Created Time:2020-04-04 00:09:07
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
    int trap(vector<int>& ht) {
        int n = ht.size(), sk[n + 1], top = -1, res = 0;
        for (int i = 0; i < n; i++) {
            int h = ht[i];
            while (~top && h > ht[sk[top]]) {
                int ch = ht[sk[top--]];
                if (top == -1) break;
                int ph = ht[sk[top]];
                res += (min(ph, h) - ch) * (i - sk[top] - 1);
            }
            sk[++top] = i;
        }
        return res;
    }
};

class Solution {
public:
    int trap(vector<int>& ht) {
        int n = ht.size();
        stack<int> s;
        int res = 0;
        for (int i = 0; i < n; i++) {
            while (!s.empty() && ht[i] > ht[s.top()]) {
                int ch = ht[s.top()];
                s.pop();
                if (s.size()) {
                    int pi = s.top(), ph = ht[pi];
                    res += (min(ht[i], ph) - ch) * (i - pi - 1);
                }
            }
            s.push(i);
        }
        return res;
    }
};