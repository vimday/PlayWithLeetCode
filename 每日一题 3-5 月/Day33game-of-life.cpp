/*
 * @Author      :vimday
 * @Desc        :lc day33
 * @Url         :https://leetcode-cn.com/problems/game-of-life/
 * @File Name   :Day33game-of-life.cpp
 * @Created Time:2020-04-02 00:16:19
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
    int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    void gameOfLife(vector<vector<int>>& bd) {
        int m = bd.size(), n = bd[0].size();
        //0表示死，1表示活
        //四种状态01,00,11,10,第二位表示第二次的情况
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                int cnt = 0;
                for (int k = 0; k < 8; k++) {
                    int r = i + dx[k], c = j + dy[k];
                    if (r >= 0 && r < m && c >= 0 && c < n && (bd[r][c] & 1))
                        cnt++;
                }
                if (bd[i][j]) {
                    if (cnt == 2 || cnt == 3)
                        bd[i][j] = 3;
                } else if (cnt == 3)
                    bd[i][j] = 2;
            }
        for (vector<int>& v : bd)
            for (int& i : v)
                i >>= 1;
    }
};

// public class Solution {
//     private static final int[] DX = {0, 0, 1, -1, 1, 1, -1, -1};
//     private static final int[] DY = {1, -1, 0, 0, 1, -1, 1, -1};

//     public void gameOfLife(int[][] board) {
//         if (board.length == 0) {
//             return;
//         }
//         int n = board.length;
//         int m = board[0].length;
//         for (int i = 0; i < n; ++i) {
//             for (int j = 0; j < m; ++j) {
//                 int cnt = 0;
//                 for (int k = 0; k < 8; k++) {
//                     int x = i + DX[k];
//                     int y = j + DY[k];
//                     if (x < 0 || x >= board.length || y < 0 || y >= board[0].length) {
//                         continue;
//                     }
//                     // 这里不能直接加board[x][y]，因为 board[x][y] 的倒数第二位是可能有值的。
//                     cnt += board[x][y] & 1;
//                 }
//                 if ((board[i][j] & 1) > 0) {
//                     // 这个是活细胞
//                     if (cnt >= 2 && cnt <= 3) {
//                         // 周围有2/3个活细胞，下一个状态还是活细胞。
//                         board[i][j] = 0b11;
//                     }
//                     // 周围活细胞过多或过少都会死，因为原数据是0b01，所以这里不用额外赋值。
//                 } else if (cnt == 3) {
//                     // 这个是死细胞，周围有3个活细胞，下一个状态变为活细胞。
//                     board[i][j] = 0b10;
//                 }
//             }
//         }
//         // 最后一位去掉，倒数第二位变为更新后的状态。
//         for (int i = 0; i < n; ++i) {
//             for (int j = 0; j < m; ++j) {
//                 board[i][j] >>= 1;
//             }
//         }
//     }
// }

// class Solution {
//     public void gameOfLife(int[][] board) {

//         /*
//          * 0 一直死亡
//          * 1 一直存活
//          * 2 将要复活(现在是死亡)
//          * 3 将要死亡(现在是存活)
//          */
//     	int[][] d = new int[][]{{0,-1},{0,1},
//     							{1,0},{1,-1},{1,1},
//     							{-1,0},{-1,-1},{-1,1},};
//     	int n = board.length;
//     	int m = board[0].length;
//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
//            	 	int cnt = 0;
//                  for(int k=0;k<d.length;k++){
//                 	 int x = i+d[k][0];
//                 	 int y = j+d[k][1];
//                 	 if(x>=0&&x<n&&y>=0&&y<m){
//                 		 if(board[x][y]==1||board[x][y]==3)cnt++;
//                 	 }
//                  }
//                  if(board[i][j]==1&&(cnt>3||cnt<2))board[i][j]=3;
//                  else if(board[i][j]==0&&cnt==3)board[i][j]=2;
//             }
//         }
//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
//             	if(board[i][j]==2)board[i][j]=1;
//             	else if(board[i][j]==3)board[i][j]=0;
//             }
//         }

//     }
// }