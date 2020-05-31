/*
 * @Author      :vimday
 * @Desc        :lc day 经典水壶问题
 * @Url         :https://leetcode-cn.com/problems/water-and-jug-problem/comments/
 * @File Name   :Day21water-and-jug-problem.cpp
 * @Created Time:2020-03-21 00:07:21
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
// 设z = a * x + b * y;
// （a和b是整数有且可能是负数）假设x和y的最大公约数为g.

//     且 x = m * g,
//        y = n * g;
// 则等式变为 z = (a * m + b * n) * g;

// 要想等式成立则z必需能被x和y的最大公约数整除。z % g = 0;

// 参考链接 https:  //blog.csdn.net/qq_40636117/article/details/80340421
class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        //x,y 的最打公约数能否被z整除
        int g = gcd(x, y);
        if (g == 0) return z == 0;
        if (x + y < z) return false;
        return z % g == 0;
    }
    int gcd(int x, int y) {
        return y == 0 ? x : gcd(y, x % y);
    }
};

using PII = pair<int, int>;

class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        stack<PII> stk;
        stk.emplace(0, 0);
        auto hash_function = [](const PII& o) { return hash<int>()(o.first) ^ hash<int>()(o.second); };
        unordered_set<PII, decltype(hash_function)> seen(0, hash_function);
        while (!stk.empty()) {
            if (seen.count(stk.top())) {
                stk.pop();
                continue;
            }
            seen.emplace(stk.top());

            auto [remain_x, remain_y] = stk.top();
            stk.pop();
            if (remain_x == z || remain_y == z || remain_x + remain_y == z) {
                return true;
            }
            // 把 X 壶灌满。
            stk.emplace(x, remain_y);
            // 把 Y 壶灌满。
            stk.emplace(remain_x, y);
            // 把 X 壶倒空。
            stk.emplace(0, remain_y);
            // 把 Y 壶倒空。
            stk.emplace(remain_x, 0);
            // 把 X 壶的水灌进 Y 壶，直至灌满或倒空。
            stk.emplace(remain_x - min(remain_x, y - remain_y), remain_y + min(remain_x, y - remain_y));
            // 把 Y 壶的水灌进 X 壶，直至灌满或倒空。
            stk.emplace(remain_x + min(remain_y, x - remain_x), remain_y - min(remain_y, x - remain_x));
        }
        return false;
    }
};

// class Solution {
// public
//     boolean canMeasureWater(int x, int y, int z) {
//         if (x == 0 && y == 0) return z == 0;
//         int a = x, b = y;
//         while (b != 0) {
//             a %= b;
//             a ^= b;
//             b ^= a;
//             a ^= b;
//         }
//         return z == 0 || (z % a == 0 && x + y >= z);
//     }
// }