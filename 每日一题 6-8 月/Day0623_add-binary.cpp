/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day0623_add-binary.cpp
 * @Created Time:2020-06-23 00:18:05
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
    string addBinary(string a, string b) {
        string res;
        int i = a.size() - 1, j = b.size() - 1, tmp = 0;
        stack<char> s;
        while (tmp == 1 || i >= 0 || j >= 0) {
            if (i >= 0 && a[i--] == '1')
                tmp++;
            if (j >= 0 && b[j--] == '1')
                tmp++;
            //res=(char)(tmp%2+'0')+res;
            s.push('0' + tmp % 2);
            //cout<<s.top();
            tmp /= 2;
        }
        while (!s.empty()) {
            res += s.top();
            s.pop();
        }
        return res;
    }
};