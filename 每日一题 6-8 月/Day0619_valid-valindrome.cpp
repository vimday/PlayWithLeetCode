/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day0619_valid-valindrome.cpp
 * @Created Time:2020-06-19 01:05:51
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
    bool isPalindrome(string s) {
        if (s.size() == 0) {
            return true;
        }

        int i = 0;
        int j = s.size() - 1;
        while (i < j) {
            while (!std::isalnum(s[i]) && i < j) i++;
            while (!std::isalnum(s[j]) && j > i) j--;

            if (std::isalpha(s[i])) s[i] = (char)std::tolower(s[i]);
            if (std::isalpha(s[j])) s[j] = (char)std::tolower(s[j]);

            if (s[i] != s[j]) {
                return false;
            }

            i++;
            j--;
        }

        return true;
    }
};