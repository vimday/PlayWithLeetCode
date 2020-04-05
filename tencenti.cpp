/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :tencenti.cpp
 * @Created Time:2020-04-05 14:26:55
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

int cmpver(string v1, string v2) {
    while (v1.size() && v1.back() == '0') {
        if (v1.size() > 1) {
            if (v1[v1.size() - 2] == '.') {
                v1.pop_back();
                v1.pop_back();
            }

        } else {
            break;
        }
    }

    while (v2.size() && v2.back() == '0') {
        if (v2.size() > 1) {
            if (v2[v2.size() - 2] == '.') {
                v2.pop_back();
                v2.pop_back();
            }

        } else {
            break;
        }
    }
    if (v1 < v2)
        return -1;
    return 0;
}