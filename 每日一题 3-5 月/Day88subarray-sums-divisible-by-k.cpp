/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day88subarray-sums-divisible-by-k.cpp
 * @Created Time:2020-05-27 00:11:24
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
    int subarraysDivByK(vector<int>& A, int K) {
        int sum_map[K] = {0};
        int sum = 0;
        sum_map[0] = 1;
        int ans = 0;
        for (int i = 0; i < A.size(); ++i) {
            sum += A[i];
            int tmp = ((sum % K) + K) % K;
            /*if (tmp < 0) {
                tmp += K;
            }*/
            ans += sum_map[tmp];
            ++sum_map[tmp];
        }
        return ans;

        //         vector<int> count(K);
        // 	count[0]++;
        // 	int sum = 0;
        // 	for (size_t i = 0; i < A.size(); i++)
        // 	{
        // 		sum += A[i];
        // 		int s = sum % K;
        // 		if (s < 0) s += K;
        // 		count[s]++;
        // 	}

        // 	int ans = 0;
        // 	for (auto c : count)
        // 	{
        // 		ans += c * (c - 1) / 2;
        // 	}
        // 	return ans;

        // unordered_map<int, int> mp;
        // mp[0] = 1;
        // int sum = 0, ans = 0;
        // for (int a : A) {
        //     sum = (sum + a%K + K) % K;
        //     if (mp.count(sum)) ans += mp[sum];
        //     mp[sum]++;
        // }
        // return ans;

        // int n=A.size();
        // unordered_map<int,int> pre,cur;int res=0;
        // int t=A[0]%K;
        // pre[t]++;
        // res+=pre[0];
        // for(int i=1;i<n;i++){
        //     int t=A[i]%K;
        //     for(auto&p:pre)
        //         cur[(p.first+t)%K]=p.second;
        //     cur[t]++;
        //     res+=cur[0];
        //     pre=cur;
        //     cur.clear();
        // }
        // return res;
        // int n=A.size();
        // vector<unordered_map<int,int>> m(n);int res=0;
        // int t=A[0]%K;
        // m[0][t]++;
        // res+=m[0][0];
        // for(int i=1;i<n;i++){
        //     int t=A[i]%K;
        //     for(auto&p:m[i-1])
        //         m[i][(p.first+t)%K]=p.second;
        //     m[i][t]++;
        //     res+=m[i][0];
        // }
        // return res;
    }
};