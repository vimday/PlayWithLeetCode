#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string sortString(string s) {
        string res;int m[26]={},cnt=0;
        for(char&c:s){
            m[c-'a']++;
            cnt++;
        }
        while(cnt>0) {   
        for(int i=0;i<26;i++)
            if(m[i]>0){
                m[i]--;
                cnt--;
                res.push_back(i+'a');
            }
        for(int i=25;i>=0;i--)
            if(m[i]>0){
                m[i]--;
                cnt--;
                res.push_back(i+'a');
            }
        }
    
        return res;
    }
};
class Solution {
    int cnt[30];
public:
    string sortString(string s) {
        for (char c: s) 
            ++cnt[c - 'a'];
        string ans;
        int left = s.length();
        for (; left > 0; ){
            for (int i = 0; i < 26; ++i)
                if (cnt[i]) --cnt[i], --left, ans.push_back(i + 'a');
            for (int i = 25; i >= 0; --i)
                if (cnt[i]) --cnt[i], --left, ans.push_back(i + 'a');
        }
        return ans;
    }
};

//wlp 4min就搓出来这么多代码 手速tql

class Solution {
    multiset<char> m;
    string ans;
public:
    string sortString(string s) {
        m.clear();
        for(auto c:s)m.insert(c);
        ans="";
        while(!m.empty())
        {
            ans+=*m.begin();
            m.erase(m.begin());
            for(;;)
            {
                auto it=m.upper_bound(ans.back());
                if(it==m.end())break;
                ans+=*it;
                m.erase(it);
            }
            if(m.empty())break;
            ans+=*m.rbegin();
            m.erase(m.lower_bound(ans.back()));
            for(;;)
            {
                auto it=m.lower_bound(ans.back());
                if(it==m.begin())break;
                ans+=*--it;
                m.erase(it);
            }
        }
        return ans;
    }
};