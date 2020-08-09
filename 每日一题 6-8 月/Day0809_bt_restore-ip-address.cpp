/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day0809_bt_restore-ip-address.cpp
 * @Created Time:2020-08-09 12:16:40
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
    vector<string> restoreIpAddresses(string s) {
        vector<int> mem;
        vector<string> res;
        string subRes;
        if (s.size() < 4)
            return {};
        core(s, 0, s.size(), res, subRes, 4);
        return res;
    }
    void core(string& s, int i, const int size, vector<string>& res, string& subRes, int seg) {
        if (i >= size)
            return;
        if (seg == 1) {
            string item = s.substr(i, string::npos);
            if (item.size() > 1 && item[0] == '0')  // item = 0XXX 不合法！
                return;

            //去除前缀零
            int k = 0;
            while (item[k] == '0')
                k++;
            item.substr(k, string::npos);
            if (item.empty()) {
                item = "0";
            }
            if (item.size() > 3)
                return;

            if (stoi(item) < 256)  //int at ± 2.14 · 109
            {
                int originSize = subRes.size();
                subRes += item;
                res.push_back(subRes);
                subRes.erase(originSize, string::npos);
            }
            return;
        }
        for (int j = 1; j + i - 1 < size; j++) {
            string item = s.substr(i, j);
            if (stoi(item) < 256) {
                int originSize = subRes.size();
                subRes += item;
                subRes += '.';
                core(s, i + j, size, res, subRes, seg - 1);
                subRes.erase(originSize, string::npos);
                if (item == "0")  // item = 0XXX 不合法！
                    return;
            } else
                return;
        }
    }
};