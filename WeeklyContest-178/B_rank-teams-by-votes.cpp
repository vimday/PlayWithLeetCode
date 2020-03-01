#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string rankTeams(vector<string>& vs) {
        int m=vs.size(),n=vs[0].size();
        unordered_map<char,vector<int>> um;
        for(char&c:vs[0])
            um[c]=vector<int>(n,0);
        for(string&s:vs)
            for(int i=0;i<n;i++)
                um[s[i]][i]++;
        string res=vs[0];
        auto cmp=[&](char a,char b)->bool{
            for(int i=0;i<n;i++)
                    if(um[a][i]>um[b][i])
                            return true;
                    else if(um[a][i]<um[b][i])
                        return false;
            return a<b;
        };
        sort(res.begin(),res.end(),cmp);
        return res;
    
    }
};

/*
因为只有A-Z 26个队伍，那排名也就只有26个
完全可以弄一个 [27][27]的数组存放，每个队伍的排名数据

当然，还有额外条件，如果全部的名次都相同，会按照队伍的字符排序，
既然这样的话，我们就将每个队伍的最后一个空格，填上 26-(队伍名-'A')
如果是A队的话 就是 26
B队就是 25

sort里面的默认排序是less，我们需要使用greater
如果在排二维数组的时候，它的特性就是首先对比第二维数组中的第一个数的大小，如果相同就回去比第二个，第三个.....
*/
class Solution {
public:
	string rankTeams(vector<string>& votes) {
		vector<vector<int>> dw(27, vector<int>(27, 0));
		string res;
		for (auto p : votes) {
			for (int i = 0; i < p.length(); i++) {
				//i是名次 p[i]是选择的队伍
				dw[p[i] - 'A'][i] ++;
				dw[p[i] - 'A'].back() = 26-(p[i] - 'A'); 
			}
		}
		sort(dw.begin(), dw.end(), greater<vector<int>>());

		for (int i = 0; i < dw.size(); i++) {
			if (dw[i].back() != 0) 
				res.push_back(26-(dw[i].back()-'A'));
		}
		return res;

	}
};

class Solution {
public:
    string rankTeams(vector<string>& votes) {
        int m = votes.size();
        string v = votes[0];
        map<char, map<int, int>> f;
        for (auto s : votes)
        {
            for (int i = 0; i < s.size(); ++ i)
                f[s[i]][i] ++;
        }
        sort(v.begin(), v.end(), [&](char a, char b) -> bool
        {
            for (int i = 0; i < v.size(); ++ i)
            {
                if (f[a][i] > f[b][i]) return 1;
                if (f[a][i] < f[b][i]) return 0;
            }
            return a < b;
        });
        return v;
    }
};

//wlp

class Solution {
    struct node
    {
        char c;
        int a[26];
        bool operator<(const node& y)const
        {
            for(int i=0;i<26;i++)if(a[i]!=y.a[i])return a[i]>y.a[i];
            return c<y.c;
        }
    }a[26];
    string ans;
public:
    string rankTeams(vector<string>& votes) {
        ans="";
        int m=votes[0].size(),i;
        memset(a,0,sizeof(a));
        for(i=0;i<26;i++)a[i].c=i+'A';
        for(auto v:votes)for(i=0;i<m;i++)a[v[i]-'A'].a[i]++;
        sort(a,a+26);
        for(i=0;i<m;i++)ans+=a[i].c;
        return ans;
    }
};