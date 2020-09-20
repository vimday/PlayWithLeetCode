/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :https://leetcode-cn.com/problems/strange-printer-ii/submissions/
 * @File Name   :DDD.cpp
 * @Created Time:2020-09-20 17:51:47
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
    bool isPrintable(vector<vector<int>>& t) {
        int i, j, k, m, n;
        m = t.size();
        n = t[0].size();
        int top[61], bottom[61], left[61], right[61];
        memset(top, 0x3f, sizeof(top));
        memset(bottom, 0xff, sizeof(bottom));
        memset(left, 0x3f, sizeof(left));
        memset(right, 0xff, sizeof(right));
        //对每种颜色的顶、底、左、右边界进行初始化
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                k = t[i][j];
                top[k] = min(top[k], i);
                bottom[k] = max(bottom[k], i);
                left[k] = min(left[k], j);
                right[k] = max(right[k], j);
            }
        }
        //遍历矩阵，获取每种颜色的上下左右边界

        bool haveedge[61][61] = {0};
        //haveedge用于避免重复建边
        vector<int> edgefrom[61];
        //edgefrom[i]表示从i出发的有向边
        int rudu[61] = {0};
        //rudu[i]表示颜色i的入度
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                //用i,j做下标遍历图中每个像素
                k = t[i][j];
                for (int color = 1; color <= 60; color++) {
                    if (top[color] <= i && i <= bottom[color] && left[color] <= j && j <= right[color]) {
                        if (color != k && !haveedge[color][k]) {
                            edgefrom[color].push_back(k);
                            rudu[k]++;
                            haveedge[color][k] = true;
                        }
                    }
                    //若t[i][j]位于颜色为color的矩形内部，颜色却不为color为k
                    //说明先染成color，再染成k
                    //建立有向边color → k
                }
            }
        }

        vector<int> v;
        while (true) {
            for (i = 1; i <= 60; i++) {
                if (rudu[i] == 0) {
                    v.push_back(i);
                    rudu[i] = -1;
                    for (int a : edgefrom[i]) {
                        rudu[a]--;
                    }
                    break;
                }
            }
            if (i == 61) break;
        }
        //将入度为0的颜色放入v，最后看1~60是不是都能放入v
        return v.size() == 60;
    }
};

// 作者：oldyan
// 链接：https://leetcode-cn.com/problems/strange-printer-ii/solution/cyi-chong-qi-guai-de-si-lu-jian-tu-tuo-bu-pai-xu-b/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

int inf = 111;
class Solution {
public:
    bool isPrintable(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size();
        vector<int> vst(111);
        for (;;) {
            bool ok = 0;
            for (int c = 1; c <= 60; c++) {
                if (vst[c]) continue;
                int mxx = -1, mnx = inf, mxy = -1, mny = inf;
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++) {
                        if (a[i][j] == c) {
                            mxx = max(mxx, i);
                            mnx = min(mnx, i);
                            mxy = max(mxy, j);
                            mny = min(mny, j);
                        }
                    }
                }
                if (mxx == -1) continue;
                bool flag = true;
                for (int i = mnx; i <= mxx; i++) {
                    for (int j = mny; j <= mxy; j++) {
                        if (a[i][j] != c && a[i][j] != -1) {
                            flag = false;
                            break;
                        }
                    }
                }
                if (flag) {
                    //cout << mnx << ' ' << mxx << ' ' << mny << ' ' << mxy << endl;
                    for (int i = mnx; i <= mxx; i++) {
                        for (int j = mny; j <= mxy; j++) {
                            a[i][j] = -1;
                        }
                    }
                    vst[c] = 1;
                    ok = 1;
                    break;
                }
            }
            if (!ok) break;
        }
        int cnt = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                if (a[i][j] == -1) cnt++;
            }
        return cnt == n * m;
    }
};

class Solution {
public:
    bool isPrintable(vector<vector<int>>& g) {
        int n = g.size(), m = g[0].size();
        using pii = pair<int, int>;

        vector<vector<int>> vx(66), vy(66);

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) {
                vx[g[i][j]].push_back(i);
                vy[g[i][j]].push_back(j);
            }

        for (int i = 1; i <= 60; ++i) {
            sort(vx[i].begin(), vx[i].end());
            sort(vy[i].begin(), vy[i].end());
        }

        while (1) {
            int flag = 0;
            for (int i = 1; i <= 60; ++i) {
                if (vx[i].empty()) continue;
                int lx = vx[i].front(), rx = vx[i].back();
                int ly = vy[i].front(), ry = vy[i].back();
                int ok = 1;
                for (int x = lx; x <= rx; ++x)
                    for (int y = ly; y <= ry; ++y) {
                        if (g[x][y] != 0 && g[x][y] != i) {
                            ok = 0;
                            break;
                        }
                    }
                if (ok) {
                    flag = 1;
                    for (int x = lx; x <= rx; ++x)
                        for (int y = ly; y <= ry; ++y)
                            g[x][y] = 0;
                    vx[i].clear();
                    vy[i].clear();
                }
            }
            if (!flag) break;
        }

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (g[i][j]) return false;
        return true;
    }
};