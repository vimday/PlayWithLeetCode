/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :https://leetcode-cn.com/problems/ji-qi-ren-de-yun-dong-fan-wei-lcof/
 * @File Name   :Day39jiqirendeyundongfanwei.cpp
 * @Created Time:2020-04-08 00:07:32
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
    int d[5] = {-1, 0, 1, 0, -1};
    int gets(int i, int j) {
        int res = 0;
        while (i) {
            res += i % 10;
            i /= 10;
        }
        while (j) {
            res += j % 10;
            j /= 10;
        }
        return res;
    }
    int movingCount(int m, int n, int kk) {
        int me[m][n];
        memset(me, 0, sizeof me);
        queue<int> q;
        q.push(0);
        me[0][0] = 1;
        int res = 1;
        while (!q.empty()) {
            int t = q.front();
            q.pop();
            int i = t / n, j = t % n;  //cout<<i<<"------ "<<j<<endl;
            for (int k = 0; k < 4; k++) {
                int r = i + d[k], c = j + d[k + 1];

                if (r >= 0 && r < m && c >= 0 && c < n && me[r][c] == 0 && gets(r, c) <= kk) {
                    me[r][c] = 1;
                    res++;
                    q.push(r * n + c);
                }
            }
        }

        return res;
    }
};
