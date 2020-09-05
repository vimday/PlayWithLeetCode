/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day0905_TODO_permutation-sequence.cpp
 * @Created Time:2020-09-05 22:02:40
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
    string getPermutation(int n, int k) {
        string str;
        if (n == 0)
            return str;
        else if (n == 1)
            return "1";
        vector<int> vec_cofficient = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
        int cur = 0;

        vector<char> single;
        for (int i = 0; i < n; i++)
            single.push_back('1' + i);
        //从0开始，往后每一位进行循环
        for (int i = 0; i < n; i++) {
            int curpos = n - i - 1;  //根据当前位置匹配vec_cofficient里的值
            for (int j = 0; j < n; j++) {
                //进行累加，如果小于K就继续加
                if (cur + vec_cofficient[curpos] < k) {
                    cur += vec_cofficient[curpos];
                    continue;
                } else {
                    //如果大于等于K则收手，把对应的值加进去，同时把single里这个用过的值删掉
                    str.push_back(single[j]);
                    single.erase(single.begin() + j);
                    break;
                }
            }
        }
        return str;
    }
};
// 康托展开
class Solution {
public:
    string getPermutation(int n, int k) {
        vector<char> chs = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
        const int factor[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
        string str;
        for (--k; n--; k %= factor[n]) {
            const int i = k / factor[n];
            str.push_back(chs[i]);
            chs.erase(chs.begin() + i);
        }
        return str;
    }
};

template <unsigned int n>
struct _fac { static const inline int val = n * _fac<n - 1>::val; };
template <>
struct _fac<0> { static const inline int val = 1; };

const int fac[10]{_fac<0>::val, _fac<1>::val, _fac<2>::val, _fac<3>::val, _fac<4>::val,
                  _fac<5>::val, _fac<6>::val, _fac<7>::val, _fac<8>::val, _fac<9>::val};  //储存阶乘值

class Solution {
public:
    string solve(int n, int k) {
        vector<int> num;
        string res;
        for (int i = 1; i <= n; ++i)
            num.emplace_back(i);
        for (int len = n - 1; len > 0; --len) {
            int numPerGroup = fac[len];
            int firstPos = k / numPerGroup;
            k %= numPerGroup;
            res += num[firstPos] + '0';
            num.erase(num.begin() + firstPos);
        }
        res += num[0] + '0';
        return res;
    }
    string getPermutation(int n, int k) {
        if (n == 1) return "1";
        return solve(n, k - 1);
    }
};