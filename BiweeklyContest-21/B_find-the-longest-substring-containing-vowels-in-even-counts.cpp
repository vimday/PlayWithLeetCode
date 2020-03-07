#include<bits/stdc++.h>
using namespace std;

//by zqy1018
class Solution {
    int lst[100];
public:
    int findTheLongestSubstring(string s) {
        memset(lst, -1, sizeof(lst));
        int h = 0;
        lst[h] = 0;
        int ans = 0, cur = 0;
        for (char c: s){
            ++cur;
            if (c == 'a') h ^= (1 << 0);
            else if (c == 'e') h ^= (1 << 1);
            else if (c == 'i') h ^= (1 << 2);
            else if (c == 'o') h ^= (1 << 3);
            else if (c == 'u') h ^= (1 << 4);
            if (lst[h] >= 0) ans = max(ans, cur - lst[h]);
            else lst[h] = cur;
        }
        return ans;
    }
};

//by wlp
class Solution {
    int a[300],d[500005],l[32];
public:
    int findTheLongestSubstring(string s) {
        memset(a,-1,sizeof(a));
        memset(l,-1,sizeof(l));
        a['a']=0;
        a['e']=1;
        a['i']=2;
        a['o']=3;
        a['u']=4;
        int n=s.size(),i,ans=0;
        l[0]=0;
        for(i=0;i<n;i++)
        {
            d[i+1]=d[i];
            if(~a[s[i]])d[i+1]^=1<<a[s[i]];
            if(!~l[d[i+1]])l[d[i+1]]=i+1;
            ans=max(ans,i+1-l[d[i+1]]);
        }
        return ans;
    }
};

//by liuzhou

class Solution {
public:
    int findTheLongestSubstring(string s) {
        auto get = [](char c)
        {
            if (c == 'a') return 0;
            if (c == 'e') return 1;
            if (c == 'i') return 2;
            if (c == 'o') return 3;
            if (c == 'u') return 4;
            return -1;
        };
        int n = s.size();
        vector<int> f(n+1);
        unordered_map<int, int> H;
        H[0] = 0;
        int ret = 0;
        for (int i = 0; i < n; ++ i)
        {
            int x = get(s[i]);
            if (x == -1)
                f[i+1] = f[i];
            else
                f[i+1] = f[i]^(1<<x);
            if (H.count(f[i+1]))
            {
                ret = max(ret, i+1-H[f[i+1]]);
            }
            else
                H[f[i+1]] = i+1;
        }
        return ret;
    }
};

//by xiaobai2
class Solution {
public:
    int findTheLongestSubstring(string s) {
        vector<int> pos((1 << 5), -1);
        int ret = 0;
        int now = 0;
        pos[now] = 0;
        for (int i = 0;i < s.size();i++) {
            int a = -1;
            if (s[i] == 'a') {
                a = 0;
            } else if (s[i] == 'e') {
                a = 1;
            } else if (s[i] == 'i') {
                a = 2;
            } else if (s[i] == 'o') {
                a = 3;
            } else if (s[i] == 'u') {
                a = 4;
            }
            if (a != -1) {
                now ^= (1 << a);
            }
            if (pos[now] == -1) {
                pos[now] = i + 1;
            } else {
                ret = max(ret, i + 1 - pos[now]);
            }
        }
        return ret;
    }
};