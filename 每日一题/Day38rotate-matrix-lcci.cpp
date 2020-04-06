/*
 * @Author      :vimday
 * @Desc        :lc day38
 * @Url         :https://leetcode-cn.com/problems/rotate-matrix-lcci/
 * @File Name   :Day38rotate-matrix-lcci.cpp
 * @Created Time:2020-04-07 00:17:49
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

//实际上就是四个数位置的交换，外层循环代表当前处于哪一个圈，
//内层循环代表当前圈需要交换的哪四个数
class Solution {
public:
    void rotate(vector<vector<int>>& mt) {
        int n = mt.size();
        for (int i = 0; i<n>> 1; i++)
            for (int j = 0; j < n - i * 2 - 1; j++) {
                int t = mt[i][i + j];
                mt[i][i + j] = mt[n - 1 - i - j][i];
                mt[n - 1 - i - j][i] = mt[n - 1 - i][n - 1 - i - j];
                mt[n - 1 - i][n - 1 - i - j] = mt[i + j][n - 1 - i];
                mt[i + j][n - 1 - i] = t;
            }
    }
};

// class Solution {
//     public void rotate(int[][] matrix) {
//         int n = matrix.length;
//         // 先以对角线（左上-右下）为轴进行翻转
//         for (int i = 0; i < n - 1; i++) {
//             for (int j = i + 1; j < n; j++) {
//                 int tmp = matrix[i][j];
//                 matrix[i][j] = matrix[j][i];
//                 matrix[j][i] = tmp;
//             }
//         }
//         // 再对每一行以中点进行翻转
//         int mid = n >> 1;
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < mid; j++) {
//                 int tmp = matrix[i][j];
//                 matrix[i][j] = matrix[i][n - 1 - j];
//                 matrix[i][n - 1 - j] = tmp;
//             }
//         }
//     }
// }