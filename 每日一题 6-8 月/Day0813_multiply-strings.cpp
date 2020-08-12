/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day0813_multiply-strings.cpp
 * @Created Time:2020-08-13 00:08:59
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
    string multiply(string num1, string num2) {
        int n1 = num1.size() - 1, n2 = num2.size() - 1;
        if (n1 < 0 || n2 < 0) return "";
        int res[n1 + n2 + 2];
        memset(res, 0, sizeof res);
        for (int i = n1; i >= 0; --i)
            for (int j = n2; j >= 0; --j) {
                int t = (num1[i] - '0') * (num2[j] - '0');
                t += res[i + j + 1];
                res[i + j] += t / 10;
                res[i + j + 1] = t % 10;
            }
        int i = 0;
        while (i < n1 + n2 + 1 && res[i] == 0) i++;
        string ret;
        while (i < n1 + n2 + 2) {
            ret += to_string(res[i++]);
        }
        return ret;
    }
};