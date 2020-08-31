/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day0831_keys-and-rooms.cpp
 * @Created Time:2020-08-31 11:49:11
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
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size(), cnt = 0, ch = 1;
        bool m[n];
        memset(m, 0, sizeof m);
        m[0] = true;
        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            int t = q.front();
            q.pop();
            for (int nb : rooms[t])
                if (!m[nb]) {
                    ch++;
                    m[nb] = true;
                    q.push(nb);
                }
        }
        return ch == n;
    }
};