/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day0724_divisor-game.cpp
 * @Created Time:2020-07-24 00:07:44
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
    bool divisorGame(int N) {
        cache_ = vector<int>(N + 1, -1);
        return canWin(N);
    }

private:
    vector<int> cache_;
    bool canWin(int N) {
        bool res = false;
        if (N == 1)
            return false;
        if (cache_[N] != -1)
            return cache_[N];
        for (int i = 1; i <= sqrt(N); ++i) {
            if (N % i == 0)
                res |= !(canWin(N - i));
        }
        return cache_[N] = res;  //dp 如果不存起来将会造成指数级的复杂度如fibonacci级数.
    }
};
class Solution {
public:
    int m[1005];
    bool divisorGame(int N) {
        memset(m, 0, sizeof m);
        m[1] = -1;
        return help(N);
    }
    bool help(int n) {
        if (m[n])
            return m[n] == 1;
        bool res = false;
        for (int i = 1; i <= sqrt(n); i++)
            if (n % i == 0)
                res |= !help(n - i);
        m[n] = res ? 1 : -1;
        return res;
    }
};
class Solution {
public:
    //     如果N是奇数，因为奇数的所有因数都是奇数，因此 N 进行一次 N-x 的操作结果一定是偶数，所以如果 a 拿到了一个奇数，那么轮到 b 的时候，b拿到的肯定是偶数，这个时候 b 只要进行 -1， 还给 a 一个奇数，那么这样子b就会一直拿到偶数，到最后b一定会拿到最小偶数2，a就输了。

    // 所以如果游戏开始时Alice拿到N为奇数，那么她必输，也就是false。如果拿到N为偶数，她只用 -1，让bob 拿到奇数，最后bob必输，结果就是true。
    bool divisorGame(int N) {
        return !(N & 1);
    }
};