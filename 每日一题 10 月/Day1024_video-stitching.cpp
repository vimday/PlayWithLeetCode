/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day1024_video-stitching.cpp
 * @Created Time:2020-10-24 14:53:52
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
    int videoStitching(vector<vector<int>>& cs, int T) {
        sort(cs.begin(), cs.end(), [](vector<int>& a, vector<int>& b) { return a[1] > b[1]; });
        int n = cs.size();
        int cur = T, cnt = 0, i = 0;
        while (T != 0) {
            if (i < n && cs[i][1] >= T) {
                cur = min(cur, cs[i][0]);
                i++;
            } else {
                if (cur < T) {
                    T = cur;
                    cnt++;
                } else
                    return -1;
            }
        }
        return cnt;
        // sort(cs.begin(),cs.end());
        // int n=cs.size(),dp[101];memset(dp,0x3f,sizeof(dp));
        // dp[0]=0;
        // for(int i=0;i<n;++i){
        //     int s=cs[i][0],e=cs[i][1];
        //     if(s>T) break;
        //     if(dp[s]==INT_MAX) return -1;
        //     for(int ii=s+1;ii<=e;++ii){
        //         dp[ii]=min(dp[ii],dp[s]+1);
        //     }
        // }
        // //for(int i:dp) cout<<i;
        // return dp[T]==0x3f3f3f3f?-1:dp[T];
    }
};