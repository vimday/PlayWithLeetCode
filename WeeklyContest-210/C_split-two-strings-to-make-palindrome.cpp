/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :CCC.cpp
 * @Created Time:2020-10-11 11:35:00
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
    bool isa(string& s) {
        int l = 0, h = s.size() - 1;
        while (l < h)
            if (s[l++] != s[h--])
                return false;
        return true;
    }
    int get(string& s) {
        int n = s.size();
        int res = 1;
        if (n & 1) {
            int idx = n >> 1;
            int i = idx - 1, j = idx + 1;
            while (i >= 0 && j < n)
                if (s[i--] == s[j++])
                    res += 2;
                else
                    return res;
        } else {
            res = 0;
            int idx = n >> 1;
            int i = idx - 1, j = idx;
            while (i >= 0 && j < n)
                if (s[i--] == s[j++])
                    res += 2;
                else
                    return res;
        }
        return 0;
    }
    bool checkPalindromeFormation(string a, string b) {
        if (isa(a) || isa(b))
            return true;
        int n = a.size();
        bool af = true, bf = true;
        int ai = get(a), bi = get(b);
        ai = ai / 2 + ai % 2;
        bi = bi / 2 + bi % 2;
        int ld = (n - 1) >> 1, rd = (n + 1) >> 1;
        for (int i = 0; i < n; i++) {
            if (a[i] != b[n - i - 1])
                af = false;
            if (b[i] != a[n - i - 1])
                bf = false;
            if (af) {
                if ((i + bi >= ld && n - i - 1 - bi <= rd) || (n - i - 1 - ai <= rd && i + ai >= ld))
                    return true;
            }
            if (bf) {
                if ((i + ai >= ld && n - i - 1 - ai <= rd) || (n - i - 1 - bi <= rd && i + bi >= ld))
                    return true;
            }
            if (!af && !bf)
                return false;
        }
        return false;
    }
};
//大佬写的 直接检查换过后的最短的中间是否是回文就行了
class Solution {
public:
    bool pa(const string& a, int l, int r) {
        for (int i = l, j = r; i < j; ++i, --j) {
            if (a[i] != a[j]) {
                return false;
            }
        }
        return true;
    }

    bool check(const string& a, const string& b) {
        int n = a.size();
        for (int i = 0, j = n - 1; i < j; ++i, --j) {
            if (a[i] != b[j]) {
                return pa(a, i, j) || pa(b, i, j);
            }
        }
        return true;
    }

    bool checkPalindromeFormation(string a, string b) {
        return check(a, b) || check(b, a);
    }
};

class Solution {
public:
    bool check(string a, string b) {
        int n = a.size();
        vector<int> aa(n), ab(n), bb(n);
        for (int i = 0; i < n; i++) {
            if (a[i] == b[n - i - 1]) {
                ab[i] = 1;
            }
            if (i > 0) ab[i] += ab[i - 1];
            if (a[i] == a[n - i - 1]) {
                aa[i] = 1;
            }
            if (b[i] == b[n - i - 1]) {
                bb[i] = 1;
            }
        }
        for (int i = n / 2 - 2; i >= 0; i--) {
            aa[i] &= aa[i + 1];
            bb[i] &= bb[i + 1];
        }
        if ((n <= 1 || aa[0])) return true;
        if ((n <= 1 || bb[0])) return true;

        for (int i = 0; i < n / 2; i++) {
            if (ab[i] == i + 1 && (n - (i + 1) * 2 <= 1 || i + 1 < n && aa[i + 1])) return true;
            if (ab[i] == i + 1 && (n - (i + 1) * 2 <= 1 || i + 1 < n && bb[i + 1])) return true;
        }
        return false;
    }
    bool checkPalindromeFormation(string a, string b) {
        int n = a.size();
        return check(a, b) || check(b, a);
    }
};