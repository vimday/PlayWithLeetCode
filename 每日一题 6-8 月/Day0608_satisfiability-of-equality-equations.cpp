/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day0608_satisfiability-of-equality-equations.cpp
 * @Created Time:2020-06-08 00:21:27
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
    int m[128] = {};
    bool equationsPossible(vector<string> &eq) {
        //并查集
        for (string &s : eq) {
            char a = s[0], op = s[1], b = s[3];
            if (m[a] == 0 && m[b] == 0) {
                if (op == '!') {
                    if (a == b)
                        return false;
                    m[a] = a;
                    m[b] = b;
                } else {
                    m[a] = a;
                    m[b] = a;
                }
            } else if (m[a] == 0) {
                if (op == '!')
                    m[a] == a;
                else
                    m[a] = findf(b);
            } else if (m[b] == 0) {
                if (op == '!')
                    m[b] == b;
                else
                    m[b] = findf(a);
            } else {
                if (op == '!' && findf(a) == findf(b)) return false;
                if (op == '=') m[findf(a)] = findf(b);
            }
        }
        for (string &s : eq) {
            char a = s[0], op = s[1], b = s[3];
            if (op == '!' && findf(a) == findf(b)) return false;
        }
        return true;
    }
    int findf(int i) {
        if (m[i] == i) return i;
        return m[i] = findf(m[i]);
    }
};