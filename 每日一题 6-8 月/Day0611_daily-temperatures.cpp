/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day0611_daily-temperatures.cpp
 * @Created Time:2020-06-11 00:04:44
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
    vector<int> dailyTemperatures(vector<int>& t) {
        int n = t.size();
        vector<int> res(n);
        stack<int> s;
        for (int i = 0; i < n; i++) {
            while (!s.empty() && t[i] > t[s.top()]) {
                res[s.top()] = i - s.top();
                s.pop();
            }
            s.push(i);
        }
        return res;
        // vector<int> res(n);
        // for(int i=n-2;i>=0;i--){
        //     if(t[i+1]>t[i])
        //         res[i]=1;
        //     else if(res[i+1]==0)
        //         res[i]=0;
        //     else{
        //         int j=i+1+res[i+1];
        //         while(t[j]<=t[i]&&res[j])
        //             j=j+res[j];
        //         res[i]=t[j]>t[i]?j-i:0;
        //     }
        // }
        // return res;
    }
};