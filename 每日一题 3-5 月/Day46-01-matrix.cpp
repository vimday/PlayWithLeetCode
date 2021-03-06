/*
 * @Author      :vimday
 * @Desc        :lc day46
 * @Url         :https://leetcode-cn.com/problems/01-matrix/comments/
 * @File Name   :Day4601-matrix.cpp
 * @Created Time:2020-04-15 00:08:39
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
    vector<vector<int> > updateMatrix(vector<vector<int> >& matrix) {
        int rows = matrix.size();
        if (rows == 0)
            return matrix;
        int cols = matrix[0].size();
        vector<vector<int> > dist(rows, vector<int>(cols, INT_MAX - 100000));

        //First pass: check for left and top
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == 0)
                    dist[i][j] = 0;
                else {
                    if (i > 0)
                        dist[i][j] = min(dist[i][j], dist[i - 1][j] + 1);
                    if (j > 0)
                        dist[i][j] = min(dist[i][j], dist[i][j - 1] + 1);
                }
            }
        }

        //Second pass: check for bottom and right
        for (int i = rows - 1; i >= 0; i--) {
            for (int j = cols - 1; j >= 0; j--) {
                if (i < rows - 1)
                    dist[i][j] = min(dist[i][j], dist[i + 1][j] + 1);
                if (j < cols - 1)
                    dist[i][j] = min(dist[i][j], dist[i][j + 1] + 1);
            }
        }

        return dist;
    }
};

// class Solution {
//     private int row;
//     private int col;
//     private int[][] vector = new int[][]{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

//     /**
//      * DP（两次遍历，可 AC）
//      */
//     public int[][] updateMatrix_1(int[][] matrix) {
//         row = matrix.length;
//         col = matrix[0].length;
//         // 第一次遍历，正向遍历，根据相邻左元素和上元素得出当前元素的对应结果
//         for (int i = 0; i < row; i++) {
//             for (int j = 0; j < col; j++) {
//                 if (matrix[i][j] == 1) {
//                     matrix[i][j] = row + col;
//                 }
//                 if (i > 0) {
//                     matrix[i][j] = Math.min(matrix[i][j], matrix[i - 1][j] + 1);
//                 }
//                 if (j > 0) {
//                     matrix[i][j] = Math.min(matrix[i][j], matrix[i][j - 1] + 1);
//                 }
//             }
//         }
//         // 第二次遍历，反向遍历，根据相邻右元素和下元素及当前元素的结果得出最终结果
//         for (int i = row - 1; i >= 0; i--) {
//             for (int j = col - 1; j >= 0; j--) {
//                 if (i < row - 1) {
//                     matrix[i][j] = Math.min(matrix[i][j], matrix[i + 1][j] + 1);
//                 }
//                 if (j < col - 1) {
//                     matrix[i][j] = Math.min(matrix[i][j], matrix[i][j + 1] + 1);
//                 }
//             }
//         }
//         return matrix;
//     }

//     /**
//      * BFS（迭代实现，可 AC）
//      */
//     public int[][] updateMatrix_2(int[][] matrix) {
//         row = matrix.length;
//         col = matrix[0].length;
//         Queue<int[]> queue = new LinkedList<>();
//         for (int i = 0; i < row; i++) {
//             for (int j = 0; j < col; j++) {
//                 if (matrix[i][j] == 0) {
//                     // 将所有 0 元素作为 BFS 第一层
//                     queue.add(new int[]{i, j});
//                 } else {
//                     matrix[i][j] = row + col;
//                 }
//             }
//         }
//         while (!queue.isEmpty()) {
//             int[] s = queue.poll();
//             // 搜索上下左右四个方向
//             for (int[] v : vector) {
//                 int r = s[0] + v[0], c = s[1] + v[1];
//                 if (r >= 0 && r < row
//                         && c >= 0 && c < col
//                         && matrix[r][c] > matrix[s[0]][s[1]] + 1) {
//                     matrix[r][c] = matrix[s[0]][s[1]] + 1;
//                     queue.add(new int[]{r, c});
//                 }
//             }
//         }
//         return matrix;
//     }

//     /**
//      * DFS（递归实现，解答正确，但是会超时，下方是优化版）
//      */
//     public int[][] updateMatrix_3(int[][] matrix) {
//         row = matrix.length;
//         col = matrix[0].length;
//         for (int i = 0; i < row; i++) {
//             for (int j = 0; j < col; j++) {
//                 if (matrix[i][j] == 1) {
//                     matrix[i][j] = row + col;
//                 }
//             }
//         }
//         for (int i = 0; i < matrix.length; i++) {
//             for (int j = 0; j < matrix[0].length; j++) {
//                 if (matrix[i][j] == 0) {
//                     updateMatrix(matrix, i, j);
//                 }
//             }
//         }
//         return matrix;
//     }

//     /**
//      * DFS（递归实现，优化版，可 AC）
//      */
//     public int[][] updateMatrix(int[][] matrix) {
//         row = matrix.length;
//         col = matrix[0].length;
//         for (int i = 0; i < row; i++) {
//             for (int j = 0; j < col; j++) {
//                 // 优化：如果元素在 0 附近，保留元素值 1，不在 0 附近，初始化为一个较大值
//                 if (matrix[i][j] == 1
//                         && !((i > 0 && matrix[i - 1][j] == 0)
//                         || (i < row - 1 && matrix[i + 1][j] == 0)
//                         || (j > 0 && matrix[i][j - 1] == 0)
//                         || (j < col - 1 && matrix[i][j + 1] == 0))) {
//                     matrix[i][j] = row + col;
//                 }
//             }
//         }
//         for (int i = 0; i < matrix.length; i++) {
//             for (int j = 0; j < matrix[0].length; j++) {
//                 // 优化：将元素值为 1 的点作为深搜起点，降低递归深度
//                 if (matrix[i][j] == 1) {
//                     updateMatrix(matrix, i, j);
//                 }
//             }
//         }
//         return matrix;
//     }

//     /**
//      * DFS 递归函数
//      */
//     private void updateMatrix(int[][] matrix, int r, int c) {
//         // 搜索上下左右四个方向
//         for (int[] v : vector) {
//             int nr = r + v[0], nc = c + v[1];
//             if (nr >= 0 && nr < row
//                     && nc >= 0 && nc < col
//                     && matrix[nr][nc] > matrix[r][c] + 1) {
//                 matrix[nr][nc] = matrix[r][c] + 1;
//                 updateMatrix(matrix, nr, nc);
//             }
//         }
//     }
// }