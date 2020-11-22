/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day1122_valid-anagram.cpp
 * @Created Time:2020-11-22 14:55:54
 * @E-mail      :lwftx@outlook.com
 * @GitHub      :https://github.com/vimday
 */
#include<bits/stdc++.h>
using namespace std;
void debug(){
    #ifdef LOCAL
         freopen("E:\\Cpp\\in.txt", "r", stdin);
         freopen("E:\\Cpp\\out.txt", "w", stdout);
    #endif
}
class Solution {
public:
    int me[26];
    bool isAnagram(string s, string t) {
        for(char c:s){
            me[c-'a']++;
        }
        for(char c:t)
            me[c-'a']--;
        for(int i=0;i<26;++i)
            if(me[i]!=0)
                return false;
        return true;
    }
};