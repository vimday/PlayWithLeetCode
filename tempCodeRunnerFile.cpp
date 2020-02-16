#include<bits/stdc++.h>
using namespace std;
bool solve(string &s,string &res){
    int n=s.size();
    if(n<2){
        res="abcdefghijklmnopqrstuvwxyz";
        return true;
    }
    vector<set<char>> mm(26);
    mm[s[0]-'a'].insert(s[1]);
    mm[s[n-1]-'a'].insert(s[n-2]);
    for(int i=1;i<n-1;i++){
        mm[s[i]-'a'].insert(s[i-1]);
        mm[s[i]-'a'].insert(s[i+1]);
    }
    bool f=false;int idx=0;
    for(int i=0;i<26;i++)
        if(mm[i].size()==1){
           f=true;
           idx=i; 
        }
            
    if(!f)
        return false;
    int m[26]={};
    res.push_back('a'+idx);
    m[idx]=true;
    queue<int> q;q.push(idx);
    while(!q.empty()){
        int t=q.front();q.pop();
        for(auto &c:mm[t]){
            if(!m[c-'a']){
                m[c-'a']=true;
                res.push_back(c);
                q.push(c-'a');
            }
        }
    }
    for(int i=0;i<26;i++)
        if(!m[i])
            res.push_back('a'+i);
    return true;
}
int main(int argc, char const *argv[])
{
    /* code */
    int T;
    cin>>T;
    string s;
    while(T--&&cin>>s){
        string res;
        if(solve(s,res)){
            cout<<"YES"<<endl;
            cout<<res<<endl;
        }else
        {
            cout<<"NO"<<endl;
        }
        
    }
    return 0;
}