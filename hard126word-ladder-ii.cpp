/*
 * @Author      :vimday
 * @Desc        :lc 126 单词接龙二
 * @Url         :https://leetcode-cn.com/problems/word-ladder-ii/
 * @File Name   :hard126word-ladder-ii.cpp
 * @Created Time:2020-03-14 18:06:32
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
//600ms的普通bfs
class Solution {
public:
    vector<vector<string>> findLadders(string bw, string ew, vector<string>& wlt) {
        unordered_set<string> ds(wlt.begin(),wlt.end()),vis;
        vector<vector<string>> res;
        if(ds.count(ew)==0) return res;
        queue<vector<string>> q;
        q.push({bw});bool f=false;ds.erase(bw);
        while(!q.empty()&&!f){
            int n=q.size();unordered_set<string> ts;
            while(n--){
                vector<string> &vs=q.front();
                string s=vs.back();//这里不能用引用 不然会 heap use after free,因为对vs进行了push_back(); 
                for(char&c:s){
                    char cbak=c;
                    for(int i=0;i<26;i++){
                        c='a'+i;
                        if(s==ew){
                            vs.push_back(s);
                            res.push_back(vs);
                            f=true;
                            break;
                        }
                        if(ds.count(s)){
                            ts.insert(s);
                            vs.push_back(s);
                            q.push(vs);
                            vs.pop_back();
                        }
                    }
                    c=cbak;
                    // if(f)
                    //     break; 
                }
                q.pop();
            }
            for(const string&s:ts)
                ds.erase(s);
            
        }
        
        return res;

    }
};
//双端BFS+DFS 40MS
class Solution
{
public:
    vector<vector<string>> res;
    unordered_map<string, vector<string>> hash;

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> dirc(wordList.begin(), wordList.end());
        if (dirc.find(endWord) == dirc.end())
            return res;
        unordered_set<string> beginw{beginWord};
        unordered_set<string> endw{endWord};
        int flag1 = 0, flag2 = 0;//第一个是否找到最短序列标志, 第二个是否反转标志。 
        while (!beginw.empty())
        {
            unordered_set<string> next;
            for (auto str : beginw)
                dirc.erase(str);
            for (auto str : beginw)
            {
                
                for (int i = 0; i < str.size(); ++i)
                {
                    string s = str;
                    for (char j = 'a'; j <= 'z'; ++j)
                    {
                        s[i] = j;

                        if (!dirc.count(s))
                            continue;
                        if (endw.count(s)) //如果两个set相遇了
                            flag1 = 1;
                        else
                            next.insert(s);
                        flag2 ? hash[s].push_back(str) : hash[str].push_back(s); //反转，始终保证hash里key是原string，value是被替换后的string (保证之后树dfs遍历的时候是从beginWord到endWord的顺序)
                    }
                }
            }
            if (flag1) ////已经找到最短序列退出循环。
                break; 
            beginw = next;
            if (beginw.size() > endw.size())
            {
                swap(beginw, endw);
                flag2 = !flag2; //这里需要使用！反转。
            }
        }
        vector<string> ans = {beginWord};
        dfs(ans, beginWord, endWord);
        return res;
    }

    void dfs(vector<string> &ans, string &begin, string &end)
    {
        if (begin == end)
        {
            res.emplace_back(ans);
            return;
        }
        if (!hash.count(begin))
            return;
        for (auto str : hash[begin])
        {
            ans.emplace_back(str);
            dfs(ans, str, end);
            ans.pop_back();
        }
    }
};