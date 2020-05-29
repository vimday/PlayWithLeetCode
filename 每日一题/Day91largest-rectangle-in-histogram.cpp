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