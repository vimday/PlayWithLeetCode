/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day22minimum-increment-to-make-array-unique.cpp
 * @Created Time:2020-03-22 00:22:57
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
    int minIncrementForUnique(vector<int>& A) {
        //排序
        sort(A.begin(), A.end());
        int n = A.size(), cnt = 0;
        for (int i = 1; i < n; i++) {
            if (A[i] <= A[i - 1]) {
                int x = A[i - 1] - A[i] + 1;
                A[i] += x;
                cnt += x;
            }
        }
        return cnt;
        //桶
        //         int m[80007]={};
        //         for(int &i:A)
        //             m[i]++;
        //         int res=0,cnt=0;
        //         for(int i=0;i<80007;i++){
        //             if(m[i]>1)
        //                 {res-=i*(m[i]-1);cnt+=m[i]-1;}
        //             else if(m[i]==0&&cnt>0)
        //             {
        //                 cnt--;
        //                 res+=i;
        //             }

        //         }
        //         return res;
        //bf tle
        // unordered_map<int,int> m;
        // for(int &i:A)
        //     m[i]++;
        // int res=0;
        // for(int i:A)
        //     if(m[i]>1){
        //         int t=
        //         m[i]--;++res;
        //         while(m[++i])
        //             res++;
        //         m[i]=1;
        //     }
        // return res;
    }
};