/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day0803_add-strings.cpp
 * @Created Time:2020-08-03 00:07:10
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
    string addStrings(string num1, string num2) {
        int i = num1.size() - 1, j = num2.size() - 1, carry = 0;
        stack<char> s;
        string res;
        while (carry == 1 || i >= 0 || j >= 0) {
            if (i >= 0) carry += num1[i--] - '0';
            if (j >= 0) carry += num2[j--] - '0';
            s.push(carry % 10 + '0');
            carry /= 10;
        }
        while (!s.empty()) {
            res += s.top();
            s.pop();
        }
        return res;
    }
};