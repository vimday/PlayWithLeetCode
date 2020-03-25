/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :https://leetcode-cn.com/problems/four-divisors/submissions/
 * @File Name   :B-four-divisors.cpp
 * @Created Time:2020-03-25 16:32:22
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
    int sumFourDivisors(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int cm = nums[n - 1], res = 0;
        int me[cm + 1];
        memset(me, 0, sizeof me);
        reverse(nums.begin(), nums.end());

        for (int& i : nums)
            if (me[i] == 0)
                res += help(i, me);
            else if (me[i] > 0)
                res += me[i];
        return res;
    }
    int help(int t, int* me) {
        int f = 0, s = 0, tt = sqrt(t) + 1;
        for (int i = 2; i < tt; i++) {
            if (t % i == 0) {
                if (i * i == t) {
                    me[t] = -1;
                    return 0;
                }
                int j = t / i;
                if (f == 0) {
                    f = i, s = j;
                } else {
                    me[t] = -1;
                    return 0;
                }
            }
        }
        if (f != 0) {
            me[f] = me[s] = -1;
            return me[t] = f + s + t + 1;
        }
        me[t] = -1;
        return 0;
    }
};

class Solution {
public:
    unordered_map<int, int> table;
    int judge(int n) {
        int a = 0, b = 0;
        for (int i = 2; i <= pow(n, 0.5); i++) {
            if (n % i == 0) {
                if (a == 0 && b == 0) {
                    a = n / i;
                    b = i;
                    if (n / i == i) {
                        return 0;
                    }
                } else if (a != i && b != i) {
                    return 0;
                }
            }
        }
        if (a != 0 && b != 0) {
            table[a] = 1;
            table[b] = 1;
            return a + b + 1 + n;

        } else {
            return 0;
        }
    }
    int sumFourDivisors(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 0;
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (table.find(nums[i]) == table.end()) {
                res += judge(nums[i]);
            }
        }
        return res;
    }
};