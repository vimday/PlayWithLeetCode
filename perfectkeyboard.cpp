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
    int f=0;int idx1=0,idx2=0;
    for(int i=0;i<26;i++)
        if(mm[i].size()==1){
           f++;
           if(f==1)
                idx1=i;
            else
            {
                idx2=i;
            }
            
        }
            
    if(f<2)
        return false;
    int m[26]={};
    res.push_back('a'+idx1);
    m[idx1]=true;
    queue<int> q;q.push(idx1);
    while(!q.empty()){
        int t=q.front();q.pop();
        for(auto &c:mm[t]){
            if(!m[c-'a']&&c-'a'!=idx2){
                m[c-'a']=true;
                res.push_back(c);
                q.push(c-'a');
            }
        }
    }
    res.push_back(idx2+'a');
    for(int i=0;i<26;i++){
        int sz=res.size();
        if(mm[i].size()){
            int j=0,jj=-1;
            for(;j<sz;j++){
                if(res[j]==i+'a'){
                    jj=j;
                    break;
                }
                    
            }
            if(jj==-1)
                return false;
            for(const char &c:mm[i])
                if((jj-1>=0&&res[jj-1]==c)||(jj+1<sz&&res[jj+1]==c))
                    continue;
                else
                {
                    return false;
                }
                
        }
    }
    m[idx2]=true;
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
