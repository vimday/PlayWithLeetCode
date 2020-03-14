/*
 * @Author      :vimday
 * @Desc        :lc 42 hard 接雨水
 * @File Name   :hard42trapping-rain-water.cpp
 * @Created Time: 2020-03-14 16:05:31
 * @E-mail      :lwftx@outlook.com
 * @Url         :https://github.com/vimday
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
    int trap(vector<int>& ht) {
        int n=ht.size(),sk[n+1],top=-1,res=0;
        for(int i=0;i<n;i++){
            int h=ht[i];
            while(~top&&h>ht[sk[top]]){
                int ch=ht[sk[top--]];
                if(top==-1) break;
                int ph=ht[sk[top]];
                res+=(min(ph,h)-ch)*(i-sk[top]-1);
            }
            sk[++top]=i;
        }
        return res;
    }
};
int main(int argc, char const *argv[])
{
    string ht="0,1,0,2,1,0,1,3,2,1,2,1";
    for(char&c:ht)
        if(c==',')
            c=' ';
    istringstream iss(ht);
    vector<int> v;string h;
    while(iss>>h)
        v.push_back(stoi(h));
    Solution sol=Solution();
    cout<<sol.trap(v)<<endl;

    return 0;
}
