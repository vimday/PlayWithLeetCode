/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day50.cpp
 * @Created Time:2020-04-19 00:07:02
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
    string getHappyString(int n, int k) {
        string tmp(n, 'a');
        for (int i = 0; i < n; i++)
            if (i % 2 == 0)
                tmp[i] = 'a';
            else
                tmp[i] = 'b';
        for (int i = 1; i < k; i++) {
            bool f = false;
            for (int j = n - 1; j >= 0; j--) {
                char c = tmp[j];
                for (int ad = 1; ad < 3; ad++) {
                    tmp[j]++;
                    if (tmp[j] < 'd' && (j == 0 || tmp[j] != tmp[j - 1])) {
                        f = true;
                        if (tmp[j] != 'a') {
                            int cnt = 1;
                            for (int ab = j + 1; ab < n; ab++)
                                if (cnt++ % 2)
                                    tmp[ab] = 'a';
                                else
                                    tmp[ab] = 'b';
                        } else {
                            if (j + 1 < n) {
                                tmp[j + 1] = 'b';
                                int cnt = 1;
                                for (int ab = j + 2; ab < n; ab++)
                                    if (cnt++ % 2)
                                        tmp[ab] = 'a';
                                    else
                                        tmp[ab] = 'b';
                            }
                        }
                        //cout<<tmp<<endl;
                        break;
                    }
                }
                if (f)
                    break;
                else
                    tmp[j] = c;
            }
            if (f == false)
                return "";
        }
        return tmp;
    }
};