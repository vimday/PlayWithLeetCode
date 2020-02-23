#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int nxa[50005],nxb[50005],nxc[50005];

    int numberOfSubstrings(string s) {
        int n=s.size();
        nxa[n]=-1;nxb[n]=-1;nxc[n]=-1;
        for(int i=n-1;i>=0;--i){
            nxa[i]=nxa[i+1];
            nxb[i]=nxb[i+1];
            nxc[i]=nxc[i+1];
            if(s[i]=='a')
                nxa[i]=i;
            else if(s[i]=='b')
                nxb[i]=i;
            else nxc[i]=i;
        }
        int res=0;
        for(int i=0;i<n-2;i++){
            char c=s[i];
            if(c=='a'){
                int r1=nxb[i];
                int r2=nxc[i];
                if(r1==-1||r2==-1)
                    return res;
                int r=max(r1,r2);
                res+=n-r;
            }
            if(c=='b'){
                int r1=nxa[i];
                int r2=nxc[i];
                if(r1==-1||r2==-1)
                    return res;
                int r=max(r1,r2);
                res+=n-r;
            }
            if(c=='c'){
                int r1=nxb[i];
                int r2=nxa[i];
                if(r1==-1||r2==-1)
                    return res;
                int r=max(r1,r2);
                res+=n-r;
            }
        }
        return res;

    }
};
//双指针解法
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int cnt[5];
        cnt[0] = cnt[1] = cnt[2] = 0;
        int r = -1;
        int ans = 0;
        for (int l = 0; l < n; l++) {
            while ((cnt[0] == 0 || cnt[1] == 0 || cnt[2] == 0) && r < n - 1) {
                r++;
                cnt[s[r] - 'a']++;
            }
            //printf("%d %d\n", l, r);
            if (cnt[0] > 0 && cnt[1] > 0 && cnt[2] > 0) {
                ans += (n - 1 - r + 1);
            }
            cnt[s[l] - 'a']--;
        }
        return ans;
    }
};
//第一种方法的优化改良版 tql
// class Solution {
//     public int numberOfSubstrings(String s) {
//         int res = 0;
//         // 记录 'a', 'b', 'c' 上次出现的位置
//         int[] record = {-1, -1, -1}; 
//         for (int i = 0; i < s.length(); i++) {
//             if (s.charAt(i) == 'a') {
//                 res += Math.min(record[1], record[2]) + 1;
//             } else if (s.charAt(i) == 'b') {
//                 res += Math.min(record[0], record[2]) + 1;
//             } else {
//                 res += Math.min(record[0], record[1]) + 1;
//             }
//             // 更新 'a', 'b', 'c' 最近出现的位置
//             record[s.charAt(i) - 'a'] = i;
//         }
//         return res;
//     }
// }
// 以索引 i 遍历字符串 s ，考虑子串 (k, i) 满足条件的最大 k，那么此时子串(0, i), ...(k-1, i) 也是符合条件的子串