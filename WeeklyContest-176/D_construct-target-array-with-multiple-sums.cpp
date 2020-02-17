#include "bits/stdc++.h"

#define PB push_back
#define LB lower_bound
#define REP(x, l, u) for(ll x = l;x<u;x++)
#define RREP(x, l, u) for(ll x = l;x>=u;x--)
#define complete_unique(a) a.erase(unique(a.begin(),a.end()),a.end())
#define mst(x, a) memset(x,a,sizeof(x))
#define all(a) begin(a),end(a)
#define PLL pair<ll,ll>
#define MP make_pair
#define se second
#define fi first
#define sz(x) ((int)x.size())

typedef long long ll;
typedef double db;
using namespace std;
typedef vector<ll> VLL;
typedef vector<int> VI;
class Solution {
public:
    bool isPossible(vector<int>& tt) {
        int n=tt.size();
        long ps=0;
        priority_queue<long> pq;
        for(int i=0;i<n;i++){
            pq.push(tt[i]);
            ps+=tt[i];
        }
            
        while(!pq.empty()&&pq.top()>1){
            long t=pq.top();pq.pop();
            long cs=ps-t;
            if(t-cs>=1){
                pq.push(t-cs);
                //cout<<t-cs<<endl;
                ps=t;
            }
            else 
                return false;
        }
        return true;
    }
};
//从输入参数倒推即可，如果是合法的，一定能找到一个数是上一轮的和，那么一定比其他所有元素加起来都大（其实就是最大的）。
// 条件为：
// num*2 - sum 大于0
// 试了下题目的输入情况下比优先队列快，也没有额外占用内存。

// 作者：klaxi
// 链接：https://leetcode-cn.com/problems/construct-target-array-with-multiple-sums/solution/cpp-zhao-dao-shang-yi-lun-de-he-ceng-ceng-dao-tui-/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
class Solution {
public:
    bool isPossible(vector<int>& target, int64_t sum = 0) {     
        if (std::all_of(target.begin(), target.end(), [] (auto num) { return num == 1; })) {
            return true;
        }
        if (!sum) {
            sum = std::accumulate(target.begin(), target.end(), sum);
        }
        for (auto& num : target) {
            auto temp = num * 2 - sum; 
            if (temp > 0) {  
                num = temp;
                return isPossible(target, (num + sum)/2);
            }
        }
        return false;
    }
};

//qc
class Solution {
public:
    bool isPossible(vector<int>& target) {
        ll sum = 0;
        priority_queue<ll>pq;
        for(auto i:target){
            sum += i;
            pq.push(i);
        }
        while(pq.top() > 1){
            auto mx = pq.top();
            pq.pop();
            ll delta = sum-mx;
            if(mx <= delta)return 0;
            mx -= delta;
            sum -= delta;
            pq.push(mx);
        }
        return true;
    }
};