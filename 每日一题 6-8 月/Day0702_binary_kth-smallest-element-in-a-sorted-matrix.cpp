/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day0702_binary_kth-smallest-element-in-a-sorted-matrix.cpp
 * @Created Time:2020-07-02 00:39:57
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
struct cmp2 {
    bool operator()(const array<int, 3>& a, const array<int, 3>& b) {
        return a[2] > b[2];
    }
};
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        // 二分搜索版
        int m = matrix.size(), n = matrix[0].size();
        int l = matrix[0][0], h = matrix[m - 1][n - 1] + 1;  //[l,h)
        while (l < h) {
            int mi = l + (h - l >> 1), cnt = 0;
            // for(int i=0;i<m;++i)   //O(nlgn)
            //     for(int j=0;j<n;++j)
            //         if(matrix[i][j]<=mi)
            //             ++cnt;
            //         else
            //             break;
            int i = n - 1, j = 0;
            while (i >= 0 && j < n)  //O(klgn)
                if (matrix[i][j] <= mi) {
                    cnt += i + 1;
                    j++;
                } else
                    i--;
            cnt < k ? l = mi + 1 : h = mi;
        }
        return l;

        //小顶堆版
        //         priority_queue<array<int,3>,vector<array<int,3>>,cmp2> pq;
        //         for(int j=0;j<n;++j) pq.push({0,j,matrix[0][j]});
        //         for(int i=0;i<k-1;++i){
        //             array<int,3> t=pq.top();pq.pop();
        //             if(t[0]==m-1) continue;
        //             pq.push({t[0]+1,t[1],matrix[t[0]+1][t[1]]});
        //         }
        //         return pq.top()[2];
    }
};