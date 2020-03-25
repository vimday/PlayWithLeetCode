/*
 * @Author      :vimday
 * @Desc        :分批萨问题
 * @Url         :https://leetcode-cn.com/problems/pizza-with-3n-slices/
 * @File Name   :D_pizza-with-3n-slices.cpp
 * @Created Time:2020-03-22 00:04:29
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

//o(n2)
class Solution {
public:
    int f[500][500][2];

    int maxSizeSlices(vector<int>& slices) {
        memset(f, 0, sizeof(f));
        f[1][1][1] = slices[0];
        for (int i = 2; i <= slices.size(); ++i) {
            for (int j = 1; j <= max(i, (int)slices.size() / 3); ++j) {
                f[i][j][0] = f[i - 1][j][0];
                f[i][j][1] = f[i - 1][j][1];
                f[i][j][0] = max(f[i][j][0], f[i - 2][j - 1][0] + slices[i - 1]);
                f[i][j][1] = max(f[i][j][1], f[i - 2][j - 1][1] + slices[i - 1]);
            }
        }
        return max(f[slices.size()][slices.size() / 3][0], f[slices.size() - 1][slices.size() / 3][1]);
    }
};

//my(o(n2))
class Solution {
public:
    //int dp[500][200][2]={};
    int maxSizeSlices(vector<int>& ss) {
        //dp[i][j][1]=dp[i-1][j-1][0]+nums[i]
        //dp[i][j][0]=max(dp[i-1][j][0],dp[i-1][j][1])
        vector<int> v1(ss.begin(), prev(ss.end())), v2(ss.begin() + 1, ss.end());
        return max(help(v1), help(v2));
    }
    int help(vector<int>& v) {
        int m = v.size(), n = (m + 1) / 3;
        int dp[m + 1][n + 1][2];  //不能直接写={},不能直接初始化
        memset(dp, 0, sizeof dp);
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= min(n, i); j++) {
                dp[i][j][1] = dp[i - 1][j - 1][0] + v[i - 1];
                dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1]);
            }
        return max(dp[m][n][0], dp[m][n][1]);
    }
};
class Solution {
public:
    int maxSizeSlices(vector<int>& slices) {
        int n = slices.size();
        int need = n / 3;
        int ret = 0;
        for (int i = 0; i < need; i++) {
            int max_pos = max_element(slices.begin(), slices.end()) - slices.begin();
            int max_left = (max_pos + slices.size() - 1) % slices.size();
            int max_right = (max_pos + slices.size() + 1) % slices.size();
            int dis = slices[max_left] + slices[max_right] - slices[max_pos];
            ret += slices[max_pos];
            slices[max_pos] = dis;
            slices.erase(slices.begin() + max(max_left, max_right));
            slices.erase(slices.begin() + min(max_left, max_right));
        }
        return ret;
    }
};

// 解题思路
// 这道题目的难点其实在于如何将题意化简。如果我们考虑取披萨的顺序，由于每次取完后，披萨之间的相邻情况还会发生变化，算法的实现将变得非常复杂。试验几次之后，我们不难发现，如果选取的序号存在相邻的（包括首尾相邻），这种选取方式必然不成立；而如果序号都不相邻，似乎总能够找到一种方式取到这些序号。

// 那么，是不是只要不存在相邻的序号，就一定可以取到对应序号的元素呢？答案是肯定的。我们可以把要选取的元素跟它右边的元素绑定，这样总共就变成了n/3n/3个单块的披萨，以及n/3n/3个双块的披萨。每次，我们总可以找到一个左边有单块披萨的双块披萨，然后选取它。这样到最后，我们一定可以取到我们需要的n/3n/3块披萨。

// 这样，问题就简化为：求在nn个首尾相连的元素中，选取n/3n/3个不相邻元素所能获得的最大值。

// 动态规划的方法很好理解，讨论区的其他题解也介绍得很清楚了。这里介绍一种时间复杂度更优的基于双向链表的贪心算法。

// 基于双向链表的贪心算法
// 这道题目中，直观想到的贪心策略是每一步选取最大的一块。但以[8,9,8,1,2,3][8,9,8,1,2,3]为例，如果我们第一步选取了99，剩下的元素就变成了[1,2,3][1,2,3]，我们最大只能选择33，这样的总和就只有1212，而显然选取两个88可以得到1616的总和，是更优的。

// 如果我们可以反悔就好了。问题是，怎么反悔？在上面的例子中，我们第一步选99之后，如果直接删除两个88，那就失去了反悔的机会，因为后面再也不会处理到它们了。所以，我们需要删除两个88对应的节点，同时保留它们的信息。信息保留在哪里？只能是99所对应的节点。

// 我们在选取99之后，将左右两个节点删除，同时将99修改为8+8-9=78+8−9=7，这样我们后面仍然有机会选到这个77，也就相当于反悔了对99的选择，而去选择了左右两边的两个88。

// 重复这样的操作，直到选取了n/3n/3个元素为止，我们就得到了需要的最优解。

// 为什么我们的反悔操作一定是同时选择左右两个元素呢？因为我们是从大到小处理所有元素的，所以左右两边的元素一定不大于中间的元素，如果我们只选取其中的一个，是不可能得到更优解的。

// 实现
// 基于vector实现双向链表
// 基于优先队列获取当前最大值
// 复杂度分析
// 一共有n+n/3n+n/3次入队操作，所以总的时间复杂度为O(n\log n)O(nlogn)。

// 代码
struct Node {
    int value, l, r;
};

vector<Node> a;  // 基于vector实现双向链表

struct Id {
    int id;

    bool operator<(const Id& that) const {
        return a[id].value < a[that.id].value;
    }
};

void del(int i) {
    // 这里不需要更新i的左右指针，因为i已经不会再被使用了
    a[a[i].l].r = a[i].r;
    a[a[i].r].l = a[i].l;
}

class Solution {
public:
    int maxSizeSlices(vector<int>& slices) {
        int n = slices.size();
        int k = n / 3;

        // 初始化双向链表
        a.clear();
        for (int i = 0; i < n; ++i)
            a.emplace_back(Node{slices[i], (i - 1 + n) % n, (i + 1) % n});
        priority_queue<Id> pq;
        vector<bool> can_take(n, true);  // 标记某一序号是否能够选取
        int idx = 0;
        for (int i = 0; i < n; ++i)
            pq.push(Id{i});  // 优先队列初始化
        int cnt = 0, ans = 0;
        while (cnt < k) {
            int id = pq.top().id;
            pq.pop();
            if (can_take[id]) {  // 当前序号可用
                cnt++;
                ans += a[id].value;
                // 标记前后序号
                int pre = a[id].l;
                int nxt = a[id].r;
                can_take[pre] = false;
                can_take[nxt] = false;
                // 更新当前序号的值为反悔值
                a[id].value = a[pre].value + a[nxt].value - a[id].value;
                // 当前序号重新入队
                pq.push(Id{id});
                // 删除前后序号（更新双向链表）
                del(pre);
                del(nxt);
            }
        }
        return ans;
    }
};
// 参考
// 洛谷P1792-种树

// 作者：lucifer1004
// 链接：https://leetcode-cn.com/problems/pizza-with-3n-slices/solution/shuang-xiang-lian-biao-tan-xin-suan-fa-shi-jian-fu/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

// //以下这段代码 必须放到类外面
// struct Node {
//     int val, l, r;
// };
// vector<Node> a;
// struct Id {
//     int id;
//     bool operator<(const Id& that) const {
//         return a[id].val < a[that.id].val;
//     }
// };
// void del(int i) {
//     a[a[i].l].r = a[i].r;
//     a[a[i].r].l = a[i].l;
// }
// class Solution {
// public:
//     int maxSizeSlices(vector<int>& ss) {
//         int n = ss.size(), k = n / 3;
//         a.clear();
//         for (int i = 0; i < n; i++)
//             a.emplace_back(Node{ss[i], (i - 1 + n) % n, (i + 1) % n});
//         priority_queue<Id> pq;
//         for (int i = 0; i < n; i++)
//             pq.push(Id{i});
//         bool me[n];
//         memset(me, 0, sizeof me);
//         int cnt = 0, res = 0;
//         while (cnt < k) {
//             int id = pq.top().id;
//             pq.pop();
//             if (me[id]) continue;
//             res += a[id].val;
//             cnt++;
//             int pre = a[id].l, next = a[id].r;
//             me[pre] = me[next] = true;
//             a[id].val = a[pre].val + a[next].val - a[id].val;
//             del(pre);
//             del(next);
//             pq.push(Id{id});
//         }
//         return res;
//     }
// };