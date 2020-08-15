/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day0815_TODO_hard_lrdp_dfs_remove-boxes.cpp
 * @Created Time:2020-08-15 22:06:43
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
    int removeBoxes(vector<int>& boxes) {
        int n = boxes.size();
        int dp[100][100][101] = {0};
        for (int i = 0; i < n; i++)
            for (int k = i; k < n; k++)
                dp[i][i][n - k] = (n - k) * (n - k);
        for (int d = 1; d < n; d++)
            for (int i = 0; i < n - d; i++) {
                int j = i + d;
                for (int k = 1; k <= n - j; k++) {
                    if (boxes[j] == boxes[j - 1])
                        dp[i][j][k] = dp[i][j - 1][k + 1];
                    else {
                        dp[i][j][k] = dp[i][j - 1][1] + k * k;
                        for (int m = i; m < j; m++)
                            if (boxes[m] == boxes[j])
                                dp[i][j][k] = max(dp[i][j][k], dp[i][m][k + 1] + dp[m + 1][j - 1][1]);
                    }
                }
            }
        return dp[0][n - 1][1];
    }
    // int removeBoxes(vector<int>& boxes) {
    // 	int n = boxes.size();
    // 	int dp[100][100][100] = { 0 };
    // 	return helper(boxes, 0, n - 1, 0, dp);
    // }
    // int helper(vector<int>& boxes, int i, int j, int k, int dp[100][100][100]) {
    // 	if (j < i) return 0;
    // 	if (dp[i][j][k] > 0) return dp[i][j][k];
    // for (; i + 1 <= j && boxes[i + 1] == boxes[i]; i++, k++);
    // 	int res = (1 + k) * (1 + k) + helper(boxes, i+1 , j, 0, dp);
    // //cout<<res<<endl;
    // 	for (int m = i + 1; m <= j; ++m) {
    // 		if (boxes[m] == boxes[i]) {
    // 			res = max(res, helper(boxes, i+1 , m-1 , 0, dp) + helper(boxes, m, j, k + 1, dp));
    // 		}
    // 	}
    // 	return dp[i][j][k] = res;
    // }
};

// class Solution {
// public:
//     int removeBoxes(vector<int>& boxes) {
//         len=vector<int>(boxes.size());
//         for(int i=1;i<boxes.size();++i){
//             if(boxes[i]==boxes[i-1]) len[i]=len[i-1]+1;//记录boxes中连续相同的直接跳过，肯定比单个remove分数高
//         }
//         return dfs(boxes,0,boxes.size()-1,0);
//     }
// private:
//     unordered_map<int,int> m;
//     vector<int> len;
//     int dfs(const vector<int>& boxes,int l ,int r,int k){//k代表在[l,r]后跟着的k个与boxes[r]相同的元素
//         if(l>r) return 0;
//         k+=len[r];//跳过原数组中连续相同的
//         r-=len[r];
//         int key = (l*100+r)*100+k;//将位置转换为一维用作hash值
//         auto it = m.find(key);
//         if(it!=m.end()) return it->second;//已经记忆过
//         int& ans =m[key];
//         ans = dfs(boxes,l,r-1,0)+(k+1)*(k+1);//递归l,r-1加上后面k+1个相同的remove
//         for(int i =l;i<r;++i){
//             if(boxes[i]==boxes[r])
//                 ans=max(ans,dfs(boxes,l,i,k+1)+dfs(boxes,i+1,r-1,0));//在[l,r-1]中截断一次
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int dp[101][101][101];
    vector<int> mmp[101];
    struct Node {
        int pos;
        int num;
        int posinv;
        int pre;
    };
    int cal(vector<Node>& record, int start, int end, vector<int>& boxes) {
        //cout<<"in"<<endl;
        if (start >= end) return 0;
        if (dp[start][end][0] != 0) return dp[start][end][0];
        int iend = end - 1;
        int num = record[iend].num, pos = boxes[record[iend].pos];
        //int sum = cal(record,start+1,end,boxes) + num*num;
        dp[start][end][0] = dp[start][end][record[iend].num] = cal(record, start, iend, boxes) + num * num;
        //int isize = mmp[pos].size();
        for (int i = record[iend].posinv - 1; i >= 0 && mmp[pos][i] >= start; --i) {
            int sstart = mmp[pos][i];
            int istart = sstart + 1;
            int mid = cal(record, istart, iend, boxes);
            cal(record, start, istart, boxes);
            int j = record[sstart].num, jend = record[sstart].num + record[sstart].pre;
            for (; j <= jend; ++j) {
                if (dp[start][istart][j] == 0) continue;
                //int rnum = dp[mmp[pos][i]][end][3][j];
                int right = dp[start][istart][j] + mid + num * num + 2 * num * j;
                if (right > dp[start][end][0]) {
                    dp[start][end][0] = right;
                    dp[start][end][j + num] = right;
                } else if (right > dp[start][end][j + num]) {
                    dp[start][end][j + num] = right;
                }
            }
        }
        return dp[start][end][0];
    }
    int removeBoxes(vector<int>& boxes) {
        vector<Node> record;
        Node head;
        head.pos = 0;
        head.num = 0;
        head.posinv = 0;
        head.pre = 0;
        mmp[boxes[0]].push_back(0);
        record.push_back(head);
        int last = boxes[0];
        for (auto a : boxes) {
            if (a == last) {
                record.back().num += 1;
            } else {
                Node tmp;
                tmp.pos = record.back().pos + record.back().num;
                tmp.num = 1;
                tmp.posinv = mmp[boxes[tmp.pos]].size();
                //record.back.pre += record.back().num;
                tmp.pre = mmp[boxes[tmp.pos]].empty() ? 0 : record[mmp[boxes[tmp.pos]].back()].num + record[mmp[boxes[tmp.pos]].back()].pre;
                mmp[boxes[tmp.pos]].push_back(record.size());
                record.push_back(tmp);
            }
            last = a;
        }
        return cal(record, 0, record.size(), boxes);
    }
};
class Solution {
public:
    int dp[100][100][101];
    int removeBoxes(vector<int>& bs) {
        memset(dp, 0, sizeof dp);
        return dfs(bs, 0, bs.size() - 1, 1);
    }
    int dfs(vector<int>& bs, int l, int r, int k) {
        if (l > r) return 0;
        if (dp[l][r][k]) return dp[l][r][k];
        while (r > l && bs[r] == bs[r - 1]) {
            r--;
            k++;
        }
        dp[l][r][k] = dfs(bs, l, r - 1, 1) + k * k;
        for (int i = l; i < r - 1; i++)
            if (bs[i] == bs[r])
                dp[l][r][k] = max(dp[l][r][k], dfs(bs, l, i, k + 1) + dfs(bs, i + 1, r - 1, 1));
        return dp[l][r][k];
    }
};