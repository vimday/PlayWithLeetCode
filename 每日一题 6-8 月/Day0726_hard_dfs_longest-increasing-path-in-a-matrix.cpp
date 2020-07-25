/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day0726_hard_dfs_longest-increasing-path-in-a-matrix.cpp
 * @Created Time:2020-07-26 00:05:52
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
    int longestIncreasingPath(std::vector<std::vector<int>>& m) {
        matrix = std::move(m);
        R = matrix.size();
        if (R == 0) return 0;
        C = matrix[0].size();
        if (C == 0) return 0;

        memo.resize(R, std::vector<int>(C, 0));
        int result = 1;

        for (int r = 0; r < R; ++r)
            for (int c = 0; c < C; ++c)
                result = std::max(result, getLongestPath(r, c));

        return result;
    }

private:
    std::vector<std::vector<int>> matrix;
    int R;
    int C;
    std::vector<std::vector<int>> memo;

    static constexpr std::array<int, 5> D = {{0, +1, 0, -1, 0}};

    int getLongestPath(int r, int c) {
        if (memo[r][c])
            return memo[r][c];

        int longestSuffix = 0;

        for (int d = 0; d < 4; ++d) {
            int r2 = r + D[d];
            int c2 = c + D[d + 1];
            if (r2 < 0 || r2 >= R || c2 < 0 || c2 >= C) continue;
            if (matrix[r][c] >= matrix[r2][c2]) continue;
            longestSuffix = std::max(longestSuffix, getLongestPath(r2, c2));
        }

        return memo[r][c] = longestSuffix + 1;
    }
};

static const auto magic = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();