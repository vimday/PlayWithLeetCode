/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day1115_remove-k-digits.cpp
 * @Created Time:2020-11-16 13:22:10
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
    string removeKdigits(string num, int k) {
        vector<int> s;
        int t = k;
        if (k == num.size()) return "0";
        for (char i : num) {
            while (s.size() && i - '0' < s.back() && k > 0) {
                s.pop_back();
                k--;
            }
            if (k == 0) break;
            s.push_back(i - '0');
        }
        //cout<<k;
        if (k == 0 && s.size() + t < num.size()) {
            for (char i : num.substr(s.size() + t))
                s.push_back(i - '0');
        }
        while (k != 0) {
            s.pop_back();
            k--;
        }

        string res;
        for (int i : s) {
            //cout<<i;
            if (i || res.size())
                res += to_string(i);
        }
        //cout<<res;
        return res.size() ? res : "0";
    }
};