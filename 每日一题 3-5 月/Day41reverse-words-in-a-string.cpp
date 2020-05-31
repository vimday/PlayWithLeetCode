/*
 * @Author      :vimday
 * @Desc        :lc day41
 * @Url         :https://leetcode-cn.com/problems/reverse-words-in-a-string/submissions/
 * @File Name   :Day41reverse-words-in-a-string.cpp
 * @Created Time:2020-04-10 00:13:40
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
    string reverseWords(string s) {
        while (s.size() && s.back() == ' ') s.pop_back();

        string res;
        int n = s.size();
        if (n == 0) return s;
        int bi = 0;
        for (; bi < n; bi++)
            if (s[bi] != ' ') {
                break;
            }

        for (int i = n - 1; i >= bi;) {
            while (s[i] == ' ') i--;
            int j = i;
            while (j >= bi && s[j] != ' ') j--;
            res += s.substr(j + 1, i - j) + " ";
            i = j;
        }

        res.pop_back();
        return res;
    }
};
class Solution {
public:
    string reverseWords(string s) {
        stringstream ss;
        string ans = "", temp;
        ss << s;
        while (ss >> temp) {
            ans = " " + temp + ans;
        }
        if (ans != "")
            ans.erase(ans.begin());
        return ans;
    }
};
class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());  //整体反转
        int start = 0, end = s.size() - 1;
        while (start < s.size() && s[start] == ' ') start++;  //首空格
        while (end >= 0 && s[end] == ' ') end--;              //尾空格
        if (start > end) return "";                           //特殊情况

        for (int r = start; r <= end;) {  //逐单词反转
            while (s[r] == ' ' && r <= end) r++;
            int l = r;
            while (s[l] != ' ' && l <= end) l++;
            reverse(s.begin() + r, s.begin() + l);
            r = l;
        }

        int tail = start;  //处理中间冗余空格
        for (int i = start; i <= end; i++) {
            if (s[i] == ' ' && s[i - 1] == ' ') continue;
            s[tail++] = s[i];
        }
        return s.substr(start, tail - start);
    }
};
#define swap(a, b)  \
    {               \
        {           \
            a ^= b; \
            b ^= a; \
            a ^= b; \
        }           \
    }

void reve(char* s, int l, int r) {
    if (r <= l) return;
    while (l < r) {
        swap(s[l], s[r]);
        l++, r--;
    }
}

char* reverseWords(char* s) {
    int l = 0, r = strlen(s) - 1;
    reve(s, l, r);
    while (s[0] == ' ') s++;  //除掉前导空格
    int i = 0, j = 0;
    int a = 0;
    char* temp = s;
    while (j <= r) {
        while (s[j] != ' ' && s[j] != 0) j++;  //计算单词长度
        reve(s, i, j - 1);                     //翻转
        for (int k = 0; k < j - i; k++) {
            *(temp + k) = s[i + k];
        }
        //strncpy(temp, s + i,j - i);//赋值
        temp = temp + j - i;
        printf("%d %d\n", j, i);
        while (s[j] == ' ') j++;
        i = j;
        if (s[j] == 0) {
            *temp = 0;
            break;
        }
        *temp = ' ';  //默认处理完一个单词，加一个空格，如果第一个是空格不会不会加一个单词仍然会加一个空格，所以在前面除掉前导空格
        temp++;
    }
    return s;
}
