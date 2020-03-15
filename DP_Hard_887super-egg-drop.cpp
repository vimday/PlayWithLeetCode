/*
 * @Author      :vimday
 * @Desc        :经典的双蛋问题
 * @Url         :https://leetcode-cn.com/problems/super-egg-drop/
 * @File Name   :DP_Hard_887super-egg-drop.cpp
 * @Created Time:2020-03-15 18:23:29
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
//理论时间复杂度：O(N)，空间复杂度：O(N)。
//大致思想：使用队列构造决策树。当最优决策树的叶子节点个数大于N时，停止构建，此时决策树的树高就是答案。
class Solution {
public:
    vector<pair<int, int>> q;  // egg used, depth

    int superEggDrop(int K, int N) {
        int ans = 0, tail = 1;
        q.resize(N + 2);
        q[0].first = 0;
        q[0].second = 1;

        for (int cnt = 0; tail < N; cnt++) {
            int egg_used = q[cnt].first, depth = q[cnt].second;

            //加入左孩子（鸡蛋不碎为左）
            q[tail].first = egg_used;
            q[tail].second = q[cnt].second + 1;
            tail++;

            //加入右孩子（鸡蛋碎为右）
            if (egg_used < K - 1) {
                q[tail].first = egg_used + 1;
                q[tail].second = q[cnt].second + 1;
                tail++;
            }
        }

        return q[N - 1].second;
    }
};

//DP
class Solution {
public:
    int superEggDrop(int K, int N) {
        vector<vector<int>> dp(N + 1, vector<int>(K + 1, 0));
        int m = 0;
        while (dp[m][K] < N) {
            m++;
            for (int k = 1; k <= K; ++k)
                dp[m][k] = dp[m - 1][k - 1] + dp[m - 1][k] + 1;
        }
        return m;
    }
};

// 根据https://github.com/Shellbye/Shellbye.github.io/issues/42换角度思考得到

// dp[k][m] 的含义是k个鸡蛋 移动m次最多能够确定多少楼层
// 这个角度思考
// dp[k][m] 最多能够确定的楼层数为L
// 那么我选定第一个扔的楼层之后，我要么碎，要么不碎
// 这就是把L分成3段
// 左边是碎的那段 长度是dp[k][m - 1]
// 右边是没碎的那段 长度是dp[k-1][m - 1] 因为已经碎了一个了
// 中间是我选定扔的楼层 是1
// 所以递推公式是
// dp[k][m] = dp[k - 1][m - 1] + dp[k][m - 1] + 1
// 根据递推公式 如果采用k倒着从大到小计算 就可以只存一行的dp[k] 直接原地更新dp[k] 不影响后续计算 只需要O(K)空间复杂度 O(KlogN) 鸡蛋完全够用的时候 就是走LogN步 最差情况是1个鸡蛋走N步 O(KN)

// def superEggDrop(self, K: int, N: int) -> int:
//         dp = [0] * (K + 1)
//         m = 0
//         while dp[K] < N:
//             m += 1
//             for k in range(K, 0, -1):
//                 # print(m, k)
//                 dp[k] = dp[k - 1] + dp[k] + 1
//         return m

//TLE
// class Solution {
//     private Integer[][] memo;
//     public int superEggDrop(int K, int N) {
//         if(K == 1) return N;
//         if(N == 1) return 1;
//         if(memo == null) memo = new Integer[K+1][N+1];
//         if(memo[K][N] != null) return memo[K][N];
//         int ans = N;
//         // 选一个分割点k，扔下鸡蛋
//         for(int k=1;k<=N;k++) {
//             //    max("在第k层碎了，还有K-1个鸡蛋，剩下n-1层楼要尝试"，"没碎，剩下N-k层要尝试") + 1
//             ans = Math.min(ans, Math.max(superEggDrop(K-1, k-1), superEggDrop(K, N-k)) + 1);
//         }
//         return memo[K][N] = ans;
//     }
// }

//可以使用binary search优化找k的部分。
//因为superEggDrop(K-1, k-1)是单调递增函数，superEggDrop(K, N-k)是单调递减函数（关于k）
//我们只需要找到一个k使得这两个函数的值尽可能的接近，那么就可以保证能取到最小值，而不用傻傻的枚举k=1...N
// class Solution {
//     private Integer[][] memo;
//     public int superEggDrop(int K, int N) {
//         if(K == 1) return N;
//         if(N == 1) return 1;
//         if(memo == null) memo = new Integer[K+1][N+1];
//         if(memo[K][N] != null) return memo[K][N];
//         int ans = N, lo = 1, hi = N;
//         while(lo < hi) {
//             int m = lo + (hi - lo) / 2;
//             int left = superEggDrop(K-1, m-1); // 递增函数
//             int right = superEggDrop(K, N-m);  // 递减函数
//             // 寻找一个m使得left和right尽可能的接近，才能使得max最小
//             ans = Math.min(ans, Math.max(left, right) + 1);
//             if(left < right) {
//                 lo = m + 1;
//             } else if(left > right)
//                 hi = m;
//             else break;
//         }
//         return memo[K][N] = ans;
//     }
// }
