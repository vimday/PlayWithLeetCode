/*
 * @Author      :vimday
 * @Desc        :lc day60
 * @Url         :https://leetcode-cn.com/problems/find-in-mountain-array/submissions/
 * @File Name   :Day60find_in_mount_arr.cpp
 * @Created Time:2020-04-29 00:19:19
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
/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */
class MountainArray {
public:
    int get(int index);
    int length();
};
class Solution {
public:
    int findInMountainArray(int t, MountainArray &ma) {
        int n = ma.length();
        int l = 0, h = n, tmp;
        while (l < h) {
            int mi = l + (h - l >> 1);
            tmp = ma.get(mi);
            mi == n - 1 || tmp > ma.get(mi + 1) ? h = mi : l = mi + 1;
        }

        //l--; cout<<l;
        tmp = ma.get(l);
        if (tmp == t)
            return l;
        if (tmp < t)
            return -1;

        int minl = ma.get(0), minr = ma.get(n - 1);
        if ((minl > t && minr > t))
            return -1;
        tmp = h;

        l = 0;
        //cout<<l<<" "<<h<<endl;
        while (l < h) {
            int mi = l + (h - l >> 1);
            int tt = ma.get(mi);
            if (tt == t)
                return mi;
            tt < t ? l = mi + 1 : h = mi;
        }

        l = tmp;
        h = n;
        while (l < h) {
            int mi = l + (h - l >> 1);
            int tt = ma.get(mi);
            if (tt == t)
                return mi;
            tt < t ? h = mi : l = mi + 1;
        }
        return -1;
    }
};