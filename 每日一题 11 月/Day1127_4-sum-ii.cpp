/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day1127_4-sum-ii.cpp
 * @Created Time:2020-11-27 20:47:43
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
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> m;
        int res = 0;
        for (int& i : A)
            for (int& j : B)
                m[i + j]++;
        for (int& i : C)
            for (int& j : D)
                res += m[-i - j];
        return res;
    }
};
const int N = 360007;
class Hash {
    int keys[N] = {0}, values[N] = {0};

public:
    Hash() {
        memset(values, 0, sizeof(values));
    }
    int& operator[](int n) {
        int idx = (n % N + N) % N, cnt = 1;
        while (keys[idx] != n && values[idx] != 0) {
            idx = (idx + cnt * cnt) % N;
            cnt += 1;
        }
        keys[idx] = n;
        return values[idx];
    }
};

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        if (A.empty()) {
            return 0;
        }
        int N = A.size(), re = 0;
        // map<int, int> m;
        Hash m;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                int ps = A[i] + B[j];
                m[ps] += 1;
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                int ps = C[i] + D[j];
                re += m[-ps];
            }
        }
        return re;
    }
};
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int res = 0;
        unordered_map<int, int> s1, s2, s3, s4, s5, s6, s7;
        for (int num : A) s1[num]++;
        for (int num : B) s2[num]++;
        for (int num : C) s3[num]++;
        for (int num : D) s4[num]++;
        for (auto& a : s1) {
            for (auto& b : s2) {
                s5[a.first + b.first] += a.second * b.second;
            }
        }
        for (auto& a : s3) {
            for (auto& b : s4) {
                if (s5.count(-(a.first + b.first))) res += a.second * b.second * s5[-(a.first + b.first)];
            }
        }
        return res;
    }
};