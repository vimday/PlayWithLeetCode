/*
 * @Author      :vimday
 * @Desc        :lc day30
 * @Url         :
 * @File Name   :Day30.cpp
 * @Created Time:2020-03-29 23:43:04
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

//https://blog.csdn.net/u011500062/article/details/72855826

//f(n,m)=(f(n-1,m)+m)%n
class Solution {
public:
    int lastRemaining(int n, int m) {
        int res = 0;
        for (int i = 2; i <= n; i++) {
            //i个数,删除的idx是(res+m-1)%i
            res = (res + m) % i;
        }
        return res;
    }
};

//可以分析下纯暴力的做法，每次找到删除的那个数字，需要 O(m)O(m) 的时间复杂度，然后删除了 n-1n−1 次。但实际上我们可以直接找到下一个要删除的位置的！

// 假设当前删除的位置是 idxidx ,下一个删除的数字的位置是 idx + midx+m 。但是，由于把当前位置的数字删除了，后面的数字会前移一位，所以实际的下一个位置是 idx + m - 1idx+m−1。由于数到末尾会从头继续数，所以最后取模一下，就是 (idx + m - 1) \pmod n(idx+m−1)(modn)。

// 至于这种思路的代码实现，我尝试了下 LinkedList 会超时，我猜是因为 LinkedList 虽然删除指定节点的时间复杂度是 O(1)O(1) 的，但是在 remove 时间复杂度仍然是 O(n)O(n) 的，因为需要从头遍历到需要删除的位置。那 ArrayList 呢？索引到需要删除的位置，时间复杂度是 O(1)O(1)，删除元素时间复杂度是 O(n)O(n)（因为后续元素需要向前移位）， remove 整体时间复杂度是 O(n)O(n) 的。看起来LinkedList 和 ArrayList 单次删除操作的时间复杂度是一样的 ？所累哇多卡纳！ArrayList 的 remove 操作在后续移位的时候，其实是内存连续空间的拷贝的！所以相比于LinkedList大量非连续性地址访问，ArrayList的性能是很OK的！

// 作者：sweetieeyi
// 链接：https://leetcode-cn.com/problems/yuan-quan-zhong-zui-hou-sheng-xia-de-shu-zi-lcof/solution/javajie-jue-yue-se-fu-huan-wen-ti-gao-su-ni-wei-sh/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
// class Solution {
//     public int lastRemaining(int n, int m) {
//         ArrayList<Integer> list = new ArrayList<>(n);
//         for (int i = 0; i < n; i++) {
//             list.add(i);
//         }
//         int idx = 0;
//         while (n > 1) {
//             idx = (idx + m - 1) % n;
//             list.remove(idx);
//             n--;
//         }
//         return list.get(0);
//     }
// }