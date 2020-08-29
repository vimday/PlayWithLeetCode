/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :https://leetcode-cn.com/problems/shortest-palindrome/solution/
 * @File Name   :Day0829_TODO_hard_shortest-palindrome.cpp
 * @Created Time:2020-08-29 20:05:53
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
    string shortestPalindrome(string ss) {
        if (ss.size() == 0 || ss.size() == 1) {
            return ss;
        }
        string s = "#";
        for (auto c : ss) {
            s.push_back('#');
            s.push_back(c);
        }
        s += "#$";
        int n = s.size();
        int p[n];
        int d = 0, c = 0, ri = 0;  //ri记录最长的以第一个字符开头的回文的右端
        for (int i = 1; i < n - 1; i++) {
            int j = 2 * c - i;
            if (i >= d) {
                p[i] = 0;
            } else {
                p[i] = min(d - i, p[j]);
            }
            while (s[i + 1 + p[i]] == s[i - 1 - p[i]]) {
                p[i]++;
            }
            if (i + p[i] > d) {
                d = i + p[i];
                c = i;
            }
            if (i - p[i] <= 1) {
                ri = max(ri, (i + p[i]) / 2 - 1);
            }
        }
        string temp = ss.substr(ri + 1, n - ri - 1);
        reverse(temp.begin(), temp.end());
        return temp + ss;
    }
};
//马拉车
class Manacher {
public:
    Manacher(const std::string &s) {
        construct(s);
    };

    void getLongestPalindromeString(int &position, int &length) {
        // 找到最长的回文子串的位置与长度。
        position = -1, length = -1;
        for (int i = 0; i < len.size(); i++) {
            if (len[i] > length) {
                length = len[i];
                position = i;
            }
        }
        // 映射到原始字符串中的位置。
        position = position / 2 - length / 4;
        length = length / 2;
        return;
    }

    // s[L:R] 是否是回文的
    bool isPalindrome(int L, int R) {
        L = L * 2 + 1;
        R = R * 2 + 1;
        int mid = (L + R) / 2;
        if (0 <= mid && mid < len.size() && R - L + 1 <= len[mid]) {
            return true;
        }
        return false;
    }

private:
    vector<int> len;

    void construct(const std::string &s) {
        vector<char> vec;
        // 用 0 作为分隔符
        vec.resize(s.size() * 2 + 1);
        for (int i = 0; i < s.size(); i++) {
            vec[i << 1 | 1] = s[i];
        }

        int L = 0, R = -1;
        len.resize(vec.size());

        for (int i = 0, n = vec.size(); i < n; i++) {
            if (i <= R) {  // 被覆盖了，尝试加速
                len[i] = min((R - i) * 2 + 1, len[L + R - i]);
            } else {  // 未被覆盖，那就没办法加速了，从 1 开始。
                len[i] = 1;
            }
            // 尝试继续探测
            int l = i - len[i] / 2 - 1;
            int r = i + len[i] / 2 + 1;
            while (0 <= l && r < vec.size() && vec[l] == vec[r]) {
                --l;
                ++r;
            }
            // 更新
            len[i] = r - l - 1;
            if (r > R) {
                L = l + 1;
                R = r - 1;
            }
        }
    }
};

class Solution {
public:
    string shortestPalindrome(string s) {
        if (s.size() <= 0) {
            return s;
        }
        Manacher manacher(s);
        for (int i = s.size() - 1; i >= 0; i--) {
            if (manacher.isPalindrome(0, i)) {
                auto str = s.substr(i + 1);
                reverse(str.begin(), str.end());
                return str + s;
            }
        }
        // s[0:0] 只有一个字符，所以必为回文，所以永远不会执行这个 return。
        return "";
    }
};
//kmp
class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.size();
        vector<int> fail(n, -1);
        for (int i = 1; i < n; ++i) {
            int j = fail[i - 1];
            while (j != -1 && s[j + 1] != s[i]) {
                j = fail[j];
            }
            if (s[j + 1] == s[i]) {
                fail[i] = j + 1;
            }
        }
        int best = -1;
        for (int i = n - 1; i >= 0; --i) {
            while (best != -1 && s[best + 1] != s[i]) {
                best = fail[best];
            }
            if (s[best + 1] == s[i]) {
                ++best;
            }
        }
        string add = (best == n - 1 ? "" : s.substr(best + 1, n));
        reverse(add.begin(), add.end());
        return add + s;
    }
};
// 字符串hash
class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.size();
        int base = 131, mod = 1000000007;
        int left = 0, right = 0, mul = 1;
        int best = -1;
        for (int i = 0; i < n; ++i) {
            left = ((long long)left * base + s[i]) % mod;
            right = (right + (long long)mul * s[i]) % mod;
            if (left == right) {
                best = i;
            }
            mul = (long long)mul * base % mod;
        }
        string add = (best == n - 1 ? "" : s.substr(best + 1, n));
        reverse(add.begin(), add.end());
        return add + s;
    }
};

//tle
class Solution {
public:
    string shortestPalindrome(string s) {
        string rs = s;
        reverse(rs.begin(), rs.end());
        int i = 0, n = s.size();
        while (1) {
            if (rs.substr(i) == s.substr(0, n - i))
                break;
            i++;
        }
        return rs.substr(0, i) + s;
    }
};