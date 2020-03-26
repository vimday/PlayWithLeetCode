/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day27x-of-a-kind-in-a-deck-of-cards.cpp
 * @Created Time:2020-03-27 00:21:34
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
    bool hasGroupsSizeX(vector<int>& deck) {
        std::ios::sync_with_stdio(false);
        if (deck.size() == 1) {
            return false;
        }
        int arr[10001] = {0};
        for (int item : deck) {
            arr[item]++;
        }
        for (int i = 1; i < 10001; i++) {
            if (arr[i] != arr[i - 1] && __gcd(arr[i - 1], arr[i]) == 1) {
                return false;
            }
        }
        return true;
    }
};

class Solution {
public:
    int gcd(int x, int y) {
        if (y == 0) return x;
        return gcd(y, x % y);
    }
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> m;
        for (int& i : deck)
            m[i]++;
        int f = -1;
        for (auto& p : m) {
            int t = p.second;
            if (f == -1) {
                f = t;
            } else {
                f = gcd(f, t);
            }
        }
        return f >= 2;
    }
};