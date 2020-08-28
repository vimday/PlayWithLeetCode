/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day0828_robot-return-to-origin.cpp
 * @Created Time:2020-08-28 12:04:27
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
    bool judgeCircle(string moves) {
        int x = 0, y = 0;
        for (char& c : moves)
            if (c == 'U')
                y++;
            else if (c == 'D')
                y--;
            else if (c == 'R')
                x++;
            else
                x--;
        return x == 0 && y == 0;
    }
};