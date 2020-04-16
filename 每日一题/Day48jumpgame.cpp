/*
 * @Author      :vimday
 * @Desc        :跳跃游戏 dp
 * @Url         :https://leetcode-cn.com/problems/jump-game/
 * @File Name   :Day48jumpgame.cpp
 * @Created Time:2020-04-17 00:02:54
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
    bool canJump(vector<int>& nums) {
        int aa = 0;
        for (int i = 0; i < nums.size(); ++i) {
            aa = max(aa, nums[i] + i);
            if (aa <= i && i != nums.size() - 1) return false;
        }
        return true;
    }
};