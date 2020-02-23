#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string largestMultipleOfThree(vector<int>& ds) {
        vector<int> v[3];
        int sum=0;
        for(int&i:ds){
            sum+=i;
            v[i%3].push_back(i);
        }
        for(int i=0;i<3;i++){
            sort(v[i].begin(),v[i].end());
            reverse(v[i].begin(),v[i].end());
        }
        sum%=3;
        if(sum==1)
            if(v[1].size())
                v[1].pop_back();
            else{
                // if(v[2].size()<2)
                //     v[2].clear();//多余
                v[2].pop_back();
                v[2].pop_back();
            }
        else if(sum==2)
            if(v[2].size())
                v[2].pop_back();
            else{
                v[1].pop_back();
                v[1].pop_back();
            }
        string res;
        for(int i=0;i<3;i++)
            for(int &j:v[i])
                res.push_back(j+'0');
        sort(res.begin(),res.end());
        reverse(res.begin(),res.end());
        return res.size()==0?res:res[0]=='0'?"0":res;

    }
};
//dalaode
// 分情况讨论，

// 首先如果每个数字和加起来是3，那么这些数字肯定能被3 整除， 从大到小排序所有数字组成字符串输出即可
// 如果数字和sum%3==2 那么去除掉最小的%3==2的数字，如果没有这类数字，则去除掉两个最小的%3==1的数字
// sum%3==1 则类似于sum%3==2的思路即可
// ps第一次参加这个比赛，中间还做了一会儿别的事情，最后一题做完后比赛已经结束了tat



class Solution {
public:    
    string vec2str(int n, vector<int>& f, vector<bool> bo)
    {
        string res = "";
        for (int i=0; i<n; i++)
        {
            if (bo[i]) res+= '0' + f[i];
        }
        return res;
    }
    
    string largestMultipleOfThree(vector<int>& digits) {
        int sum = 0;
        int n = digits.size();
        if (n==0) return "";
        sort(digits.begin(), digits.end(), greater<int>() );
        if (digits[0]==0) return "0";
        
        for (int i=0; i<n; i++)
            sum+=digits[i];
        
        vector<bool> bo(n, true);
        if (sum%3==0) return vec2str(n, digits, bo);
        if (sum%3==1)
        {
            bool find = false;
            for (int i=n-1; i>=0; i--)
            {
                if (digits[i]%3==1) 
                {
                    bo[i] = false;
                    find = true;
                    break;
                }
            }
            if (!find)
            {
                int cnt = 0;
                for (int i=n-1; cnt<2 && i>=0; i--)
                    if (digits[i]%3==2)
                    {
                        bo[i] = false;
                        cnt++;
                    }
            }
            return vec2str(n, digits, bo);
        }else{
            bool find = false;
            for (int i=n-1; i>=0; i--)
            {
                if (digits[i]%3==2) 
                {
                    bo[i] = false;
                    find = true;
                    break;
                }
            }
            if (!find)
            {
                int cnt = 0;
                for (int i=n-1; cnt<2 && i>=0; i--)
                    if (digits[i]%3==1)
                    {
                        bo[i] = false;
                        cnt++;
                    }
            }
            return vec2str(n, digits, bo);
        }
            
    }
};