/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day1128_TODO_HARD_reverse-pairs.cpp
 * @Created Time:2020-11-28 14:55:06
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
    int reversePairsRecursive(vector<int> &nums, int left, int right) {
        if (left == right) {
            return 0;
        } else {
            int mid = (left + right) / 2;
            int n1 = reversePairsRecursive(nums, left, mid);
            int n2 = reversePairsRecursive(nums, mid + 1, right);
            int ret = n1 + n2;

            // 首先统计下标对的数量
            int i = left;
            int j = mid + 1;
            while (i <= mid) {
                while (j <= right && (long long)nums[i] > 2 * (long long)nums[j]) j++;
                ret += (j - mid - 1);
                i++;
            }

            // 随后合并两个排序数组
            vector<int> sorted(right - left + 1);
            int p1 = left, p2 = mid + 1;
            int p = 0;
            while (p1 <= mid || p2 <= right) {
                if (p1 > mid) {
                    sorted[p++] = nums[p2++];
                } else if (p2 > right) {
                    sorted[p++] = nums[p1++];
                } else {
                    if (nums[p1] < nums[p2]) {
                        sorted[p++] = nums[p1++];
                    } else {
                        sorted[p++] = nums[p2++];
                    }
                }
            }
            for (int i = 0; i < sorted.size(); i++) {
                nums[left + i] = sorted[i];
            }
            return ret;
        }
    }

    int reversePairs(vector<int> &nums) {
        if (nums.size() == 0) return 0;
        return reversePairsRecursive(nums, 0, nums.size() - 1);
    }
};

class Solution {
    typedef unsigned short uint16;
    uint16 n;
    uint16 m;
    uint16 *s;
    uint16 *p;
    uint16 cnt[256];

    void inc(const int &x) {
        for (int i = x; i <= m; i += i & -i)
            ++s[i];
    }

    uint16 query(const int &x) {
        uint16 sum = 0;
        for (int i = x; i > 0; i -= i & -i)
            sum += s[i];
        return sum;
    }

public:
    int reversePairs(vector<int> &nums) {
        if (nums.empty())
            return 0;
        n = nums.size();

        {
            p = (uint16 *)malloc(n * sizeof(uint16));
            uint16 *pn = (uint16 *)malloc(n * sizeof(uint16));

            for (int i = 0; i < n; ++i)
                p[i] = i;

            for (int _ = 0; _ < 4; ++_) {
                memset(cnt, 0, sizeof(cnt));
                for (int i = 0; i < n; ++i)
                    ++cnt[(nums[i] >> (_ << 3)) & 0xff];
                for (int i = 1; i < 256; ++i)
                    cnt[i] += cnt[i - 1];
                for (int i = n - 1; i >= 0; --i) {
                    pn[--cnt[(nums[p[i]] >> (_ << 3)) & 0xff]] = p[i];
                }
                swap(p, pn);
            }

            uint16 l = 0, r = n, mid;
            while (l < r) {
                mid = l + ((r - l) >> 1);
                nums[p[mid]] < 0 ? r = mid : l = mid + 1;
            }
            memcpy(pn, p + l, (n - l) * sizeof(uint16));
            memcpy(pn + n - l, p, l * sizeof(uint16));
            swap(p, pn);

            free(pn);
        }

        uint16 *id = (uint16 *)malloc(n * sizeof(uint16));
        uint16 *qid = (uint16 *)malloc(n * sizeof(uint16));

        id[p[0]] = m = 1;
        for (int i = 1; i < n; ++i) {
            m += nums[p[i]] > nums[p[i - 1]];
            id[p[i]] = m;
        }

        for (int i = 0, j = -1; i < n; ++i) {
            int k = (nums[p[i]] - 1) >> 1;
            while (j + 1 < n && nums[p[j + 1]] <= k)
                ++j;
            qid[p[i]] = j < 0 ? 0 : id[p[j]];
        }

        s = (uint16 *)calloc(m + 1, sizeof(uint16));

        int ans = 0;
        for (int i = n - 1; i >= 0; --i) {
            auto &&ret = query(qid[i]);
            ans += ret;
            inc(id[i]);
        }
        return ans;
    }
};
class Solution1 {
public:
    vector<int> tr;
    vector<int> data;
    int n;

    // 二分查找，找到数组中小于等于x的第一个元素在tr中的下标
    // 如果返回0，则表示所有元素都比x大
    int bsear(long long x) {
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (data[mid] > x)
                r = mid - 1;
            else
                l = mid;
        }
        if (l == 0 && data[0] > x)
            return 0;
        else
            return l + 1;
    }

    int lowbit(int x) {
        return x & -x;
    }

    int sum(int x) {
        int res = 0;
        for (int i = x; i; i -= lowbit(i)) res += tr[i];
        return res;
    }

    void add(int x, int c) {
        for (int i = x; i <= n; i += lowbit(i)) tr[i] += c;
    }

    int reversePairs(vector<int> &nums) {
        data = nums;
        sort(data.begin(), data.end());
        data.erase(unique(data.begin(), data.end()), data.end());
        n = data.size();
        tr = vector<int>(n + 1);

        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            int inow = bsear(nums[i]);
            int idx = bsear((long long)2 * nums[i]);  // 返回
            if (idx == 0)
                ans += i;
            else
                ans += i - sum(idx);
            add(inow, 1);
        }
        return ans;
    }
};

class BIT {
private:
    vector<int> tree;
    int n;

public:
    BIT(int _n) : n(_n), tree(_n + 1) {}

    static constexpr int lowbit(int x) {
        return x & (-x);
    }

    void update(int x, int d) {
        while (x <= n) {
            tree[x] += d;
            x += lowbit(x);
        }
    }

    int query(int x) const {
        int ans = 0;
        while (x) {
            ans += tree[x];
            x -= lowbit(x);
        }
        return ans;
    }
};

class Solution {
public:
    int reversePairs(vector<int> &nums) {
        set<long long> allNumbers;
        for (int x : nums) {
            allNumbers.insert(x);
            allNumbers.insert((long long)x * 2);
        }
        // 利用哈希表进行离散化
        unordered_map<long long, int> values;
        int idx = 0;
        for (long long x : allNumbers) {
            values[x] = ++idx;
        }

        int ret = 0;
        BIT bit(values.size());
        for (int i = 0; i < nums.size(); i++) {
            int left = values[(long long)nums[i] * 2], right = values.size();
            ret += bit.query(right) - bit.query(left);
            bit.update(values[nums[i]], 1);
        }
        return ret;
    }
};

// 作者：LeetCode-Solution
// 链接：https://leetcode-cn.com/problems/reverse-pairs/solution/fan-zhuan-dui-by-leetcode-solution/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
