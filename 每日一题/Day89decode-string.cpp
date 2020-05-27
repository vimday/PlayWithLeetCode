/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day89decode-string.cpp
 * @Created Time:2020-05-28 00:03:23
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
    int idx = 0, n;
    string help(string& s, int& idx) {
        string res;
        int cnt = 0;
        while (idx < n) {
            if (s[idx] >= '0' && s[idx] <= '9')
                cnt = 10 * cnt + s[idx++] - '0';
            else if (s[idx] == '[') {
                idx++;
                string t = help(s, idx);
                while (cnt--)
                    res += t;
                cnt = 0;
            } else if (s[idx] == ']') {
                idx++;
                return res;
            } else
                res += s[idx++];
        }
        return res;
    }
    string decodeString(string s) {
        n = s.size();
        return help(s, idx);
        int len = s.size();
        int num = 0;
        stack<int> numstack;
        stack<string> strstack;
        string cur = "";
        string result = "";
        for (int i = 0; i < len; ++i) {
            if (s[i] >= '0' && s[i] <= '9') {
                num = 10 * num + s[i] - '0';
            } else if (s[i] == '[') {
                numstack.push(num);
                strstack.push(cur);
                num = 0;
                cur.clear();
            } else if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
                cur += s[i];
            else if (s[i] == ']') {
                int k = numstack.top();
                numstack.pop();
                for (int j = 0; j < k; ++j)
                    strstack.top() += cur;
                cur = strstack.top();
                strstack.pop();
            }
        }
        result = result + cur;
        return cur;
    }

    //         stack<int> nums;
    //         string t,res;int i=0;
    //         for(char &c:s){
    //             if(c>='0'&&c<='9')
    //                 {i=10*i+c-'0';
    //                 if(t.size()){
    //                     res+=t;
    //                     t="";
    //                 }
    //                 }
    //             else if(c=='['){
    //                 nums.push(i);
    //                 t="";
    //                 i=0;
    //             }else if(c==']'){
    //                 int ts=nums.top();nums.pop();
    //                 if(t.size()){
    //                 string tmp=t;
    //                     while(--ts)
    //                     t+=tmp;
    //                     res+=t;
    //                     t="";
    //                 }else{
    //                     string tmp=res;
    //                     while(--ts)
    //                     res+=tmp;
    //                 }

    //             }else{
    //                 t+=c;
    //             }
    //         }
    //         if(t.size())
    //             res+=t;
    //         return res;
};