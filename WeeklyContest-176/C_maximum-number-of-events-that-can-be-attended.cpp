#include<bits/stdc++.h>
using namespace std;
//贪心暴力BF，按结束时间排序
// 方法：按照结束时间排序，然后依次对每个会议选择能开始的最早时间，与此同时用visited数组记住某一天是否已被使用过；

// 原理：结束时间相同，从最早开始时间开始选择，选完即止； 结束时间排在后面的，如果开始时间与排在前面的相同，选择参加前面的会议，因为后面的开始时间可选范围较大，如果开始时间比前面的慢，同样满足

// 缺陷：如果存在某个会议时间是【1,100000】且会议个数为100000，则会导致超时，但测试用例中没有出现
class Solution {
public:
    bool m[100005];
    int maxEvents(vector<vector<int>>& es) {
        memset(m,false,sizeof m);
        sort(es.begin(),es.end(),[](vector<int>&a,vector<int>&b){return a[1]==b[1]?a[0]<b[0]:a[1]<b[1];}) ;
        int res=0;
        for(vector<int>&v:es)
            for(int i=v[0];i<=v[1];i++)
                if(!m[i]){
                    m[i]=true;
                    res++;
                    break;
                }
        return res;
    }
};