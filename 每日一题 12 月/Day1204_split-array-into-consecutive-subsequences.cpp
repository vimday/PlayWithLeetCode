/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day1204_split-array-into-consecutive-subsequences.cpp
 * @Created Time:2020-12-04 14:38:49
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
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> numsCntMap;     //numsCntMap[num]表示的是num剩余的个数
        unordered_map<int, int> numsEndCntMap;  //numsEndCntMap[num]表示的时以num结尾的连续子序列（长度不小于3）个数
        //统计各个元素出现的次数
        for (auto num : nums) {
            numsCntMap[num] += 1;
        }
        //开始访问各个元素
        for (auto num : nums) {
            if (numsCntMap[num] == 0) {  //此元素没有剩余，已经被使用完了
                continue;
            }
            numsCntMap[num] -= 1;  //剩余个数自减
            if (numsEndCntMap.count(num - 1) && numsEndCntMap[num - 1] > 0) {
                //存在以num - 1结尾的连续子序列（长度不小于3），则将num放入
                numsEndCntMap[num - 1] -= 1;  //以num - 1结尾的连续子序列（长度不小于3）自减，因为被num放入使用了一个
                numsEndCntMap[num] += 1;      //以num结尾的连续子序列（长度不小于3）自增，刚刚创建了一个
            } else if (numsCntMap.count(num + 1) && numsCntMap[num + 1] && numsCntMap.count(num + 2) && numsCntMap[num + 2]) {
                //否则查找后面两个元素，凑出一个合法的序列
                numsCntMap[num + 1] -= 1;
                numsCntMap[num + 2] -= 1;
                numsEndCntMap[num + 2] += 1;
            } else {
                //两种方法都不行，则凑不出，比如[1,2,3,4,4,5]中的第二个4，
                return false;
            }
        }
        return true;
    }
};

// 考虑数组中的每个不同的整数（从小到大）。设当前整数为 xx，前一个整数为 \textit{prev}prev。我们首先统计数组中 xx 的数量。

// 设 dp1dp1 为以 \textit{prev}prev 结尾的长度为 11 的子序列数目， dp2dp2 为以 \textit{prev}prev 结尾的长度为 22 的子序列数目， dp3dp3 为以 \textit{prev}prev 结尾的长度 \ge 3≥3 的子序列数目。

// 如果 x = \textit{prev} + 1x=prev+1，说明当前整数可以加入到所有以 \textit{prev}prev 为结尾的序列中。假设数组中 xx 的数目为 cntcnt：

// 首先，根据贪心的策略，我们要先把 xx 添加到已有的长度 \le 2≤2 的子序列中，从而「尽可能地」保证子序列的长度都度 \ge 3≥3。如果 xx 的数量不够，说明不存在相应的分割方案。
// 前一步结束后，还剩下 \textit{left} = \textit{cnt} - dp1 - dp2left=cnt−dp1−dp2 个 xx。此时，我们既可以将 xx 放入到此前长度 \ge 3≥3 的子序列后，也可以将 xx 作为新序列的起始。
// 然而，开启新序列的选择不会是最优的，因为后面可能不会有足够数量的整数填充这一新序列。
// 因此，我们要尽量将余下的 \textit{left}left 个整数添加到长度 \ge 3≥3 的子序列中，此时最多能添加 \textit{keep} = \min(\textit{left}, dp3)keep=min(left,dp3) 个整数。如果还有剩余，才开启对应数量的新序列。新序列的数目等于 \textit{left}-\textit{keep}left−keep。
// 最后，我们将 dp1,dp2,dp3dp1,dp2,dp3 的取值更新为以当前整数 xx 为结尾的序列数目：

// dp3 \leftarrow \textit{keep} + dp2dp3←keep+dp2：长度为 33 的子序列，就是之前所有长度为 22 的 dp2dp2 个序列，加上 keepkeep 个被保留的长度 \ge 3≥3 的子序列。
// dp2 \leftarrow dp1dp2←dp1：长度为 22 的序列，只可能来自此前长度为 11 的哪些子序列。
// dp1 \leftarrow \textit{left}-\textit{keep}dp1←left−keep：长度为 11 的子序列，就等于前述「新序列」 的数目。
// 对于 x > \textit{prev} + 1x>prev+1 的情形，此时当前整数 xx 无法加入到以 \textit{prev}prev 为结尾的序列中。此时：

// 如果 dp1+dp2>0dp1+dp2>0，说明这些长度 \le 2≤2 的序列无法被满足，因此不存在相应的分割方案。
// 否则，此前的序列全部『作废』，这 cntcnt 个整数开启了 cntcnt 个长度为 11 的序列。

// 作者：Arsenal-591
// 链接：https://leetcode-cn.com/problems/split-array-into-consecutive-subsequences/solution/tan-xin-o1-kong-jian-fu-za-du-de-zui-you-jie-fa-by/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
class Solution {
public:
    bool isPossible(vector<int>& nums) {
        int n = nums.size();
        int dp1 = 0, dp2 = 0, dp3 = 0;
        int i = 0;

        while (i < n) {
            int start = i;
            int x = nums[i];
            while (i < n && nums[i] == x) {
                i++;
            }
            int cnt = i - start;

            if (start > 0 && x != nums[start - 1] + 1) {
                if (dp1 + dp2 > 0) {
                    return false;
                } else {
                    dp1 = cnt;
                    dp2 = dp3 = 0;
                }
            } else {
                if (dp1 + dp2 > cnt) return false;
                int left = cnt - dp1 - dp2;
                int keep = min(dp3, left);
                dp3 = keep + dp2;
                dp2 = dp1;
                dp1 = left - keep;
            }
        }
        return dp1 == 0 && dp2 == 0;
    }
};
class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> mp;
        for (auto& x : nums) {
            if (mp.find(x) == mp.end()) {
                mp[x] = priority_queue<int, vector<int>, greater<int>>();
            }
            if (mp.find(x - 1) != mp.end()) {
                int prevLength = mp[x - 1].top();
                mp[x - 1].pop();
                if (mp[x - 1].empty()) {
                    mp.erase(x - 1);
                }
                mp[x].push(prevLength + 1);
            } else {
                mp[x].push(1);
            }
        }
        for (auto it = mp.begin(); it != mp.end(); ++it) {
            priority_queue<int, vector<int>, greater<int>> queue = it->second;
            if (queue.top() < 3) {
                return false;
            }
        }
        return true;
    }
};

// 作者：LeetCode-Solution
// 链接：https://leetcode-cn.com/problems/split-array-into-consecutive-subsequences/solution/fen-ge-shu-zu-wei-lian-xu-zi-xu-lie-by-l-lbs5/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。