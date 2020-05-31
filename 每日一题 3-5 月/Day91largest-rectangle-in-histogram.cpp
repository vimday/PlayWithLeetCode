/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day91largest-rectangle-in-histogram.cpp
 * @Created Time:2020-05-30 00:10:46
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
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        stack<int> s;
        int res = 0, n = heights.size();
        for (int i = 0; i < n; ++i) {
            //             if(s.empty()||heights[s.top()]<=heights[i])
            //                 s.push(i);
            //             else {
            //                 while(!s.empty()&&heights[s.top()]>heights[i]){
            //                     int h=heights[s.top()];s.pop();
            //                     int idx=s.empty()?0:s.top();
            //                     res=max(res,s.empty()?i*h:(i-idx-1)*h);

            //                 }
            //                 s.push(i);

            //             }
            while (!s.empty() && heights[s.top()] > heights[i]) {
                int h = heights[s.top()];
                s.pop();
                int idx = s.empty() ? 0 : s.top();
                res = max(res, s.empty() ? i * h : (i - idx - 1) * h);
            }
            s.push(i);
        }
        return res;
    }
};
class Solution {
public:
    int largestRectangleArea(vector<int>& hts) {
        //单调栈 递增栈
        hts.push_back(0);
        stack<int> s;
        int n = hts.size(), res = 0;
        for (int i = 0; i < n; i++) {
            //最大值肯定是以摸个矩形的高度为最大高度,
            //长度为其左右第一个小于其高度的索引之差相乘得出
            //故只需要枚举每个索引即可，递增的话就入栈，出现减少则就可以枚举栈顶元素了！
            while (!s.empty() && hts[s.top()] > hts[i]) {
                int cur = s.top();
                s.pop();
                int pre = s.empty() ? -1 : s.top(), h = hts[cur];  //左边第一个小于 cur 的 idx，右边的为 i
                res = max(res, (i - pre - 1) * h);
            }
            s.push(i);
        }
        return res;
    }
};