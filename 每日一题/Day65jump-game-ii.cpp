/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day65jump-game-ii.cpp
 * @Created Time:2020-05-04 00:47:58
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
    int jump(vector<int>& nums) {
        //贪心
        int n = nums.size();
        if (n == 1) return 0;
        int pm = 0, cm = 0, res = 0;
        for (int i = 0; i < n; i++) {
            cm = max(cm, i + nums[i]);
            if (cm >= n - 1) return res + 1;
            if (i == pm) {
                res++;
                pm = cm;
            }
        }
        return 0;
    }
};