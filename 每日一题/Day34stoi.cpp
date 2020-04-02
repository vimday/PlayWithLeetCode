/*
 * @Author      :vimday
 * @Desc        :stoi
 * @Url         :https://leetcode-cn.com/problems/string-to-integer-atoi/submissions/
 * @File Name   :Day34stoi.cpp
 * @Created Time:2020-04-03 00:08:04
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
    int myAtoi(string str) {
        std::ios_base::sync_with_stdio(false);

        bool negative = false;
        long res = 0;
        auto it = str.begin();

        while (it != str.end() && *it == ' ')
            ++it;

        if (it == str.end())
            return res;
        else if (*it == '-') {
            negative = true;
            ++it;
        } else if (*it == '+')
            ++it;

        while (it != str.end()) {
            if (!(*it < '0') && (*it <= '9')) {
                res = 10 * res + (*it - '0');
            } else
                break;
            if (negative && -res < INT_MIN)
                return INT_MIN;
            if (!negative && res > INT_MAX)
                return INT_MAX;

            ++it;
        }

        if (negative)
            return -res;
        else
            return res;
    }
};

int myAtoi(char* str) {
    short ssSign = 0;
    long slInterget = 0;

    /* remove the rubbish blank space */
    for (; *str == ' '; str++)
        ;

    /* record the sign */
    ssSign = (*str == '-') ? -1 : 1;  // only consider the negative status
    if (*str == '+' || *str == '-') {
        str++;
    }

    /* get the integer */
    while ((*str >= '0') && (*str <= '9')) {
        slInterget = slInterget * 10 + (*(str++) - '0');

        if ((int)slInterget != slInterget)  // is over length or not
        {
            return (ssSign == 1) ? INT_MAX : INT_MIN;
        }
    }

    slInterget = ssSign * slInterget;

    return slInterget;
}
