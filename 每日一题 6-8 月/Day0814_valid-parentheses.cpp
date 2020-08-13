/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day0814_valid-parentheses.cpp
 * @Created Time:2020-08-14 00:03:41
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
    bool isValid(string s) {
        stack<char> sk;
        for (char &c : s) {
            if (!sk.empty() && (sk.top() + 1 == c || sk.top() + 2 == c))
                sk.pop();
            else
                sk.push(c);
        }
        return sk.empty();
    }
};