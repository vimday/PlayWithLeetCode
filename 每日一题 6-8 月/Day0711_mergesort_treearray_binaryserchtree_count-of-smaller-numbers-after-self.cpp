/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day0711_mergesort_treearray_binaryserchtree_count-of-smaller-numbers-after-self.cpp
 * @Created Time:2020-07-11 01:16:27
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
    using VecPair = vector<pair<int, int>>;
    using VecPairIt = vector<pair<int, int>>::iterator;
    vector<int> countSmaller(vector<int>& nums) {
        vector<pair<int, int>> v;
        int n = nums.size();
        v.reserve(n);
        for (int i = 0; i < n; ++i) {
            v.emplace_back(nums[i], i);
        }
        vector<int> res(n);
        merge_sort(v.begin(), v.end(), res);
        return res;
    }

    void merge_sort(VecPairIt l, VecPairIt r, vector<int>& res) {
        if (r - l <= 1) return;
        auto mid = l + (r - l) / 2;
        merge_sort(l, mid, res);  // [l, mid)
        merge_sort(mid, r, res);  // [mid, r)

        auto i = l;
        auto j = mid;
        while (i < mid || j < r) {
            if (j == r || (i < mid && i->first <= j->first)) {
                res[i->second] += j - mid;
                ++i;
            } else {
                ++j;
            }
        }

        inplace_merge(l, mid, r);
    }
};

class Solution {
public:
    int bit[200005], n;
    void add(int i, int v) {
        while (i <= n) {
            bit[i] += v;
            i += i & (-i);
        }
    }
    int sum(int i) {
        int res = 0;
        while (i > 0) {
            res += bit[i];
            i -= i & (-i);
        }
        return res;
    }
    vector<int> countSmaller(vector<int>& nums) {
        if (nums.size() == 0)
            return {};
        vector<int> res(nums.size(), 0);
        n = 0;
        int offset = 1;
        for (int i = 0; i < nums.size(); i++)
            offset = min(offset, nums[i]);
        for (int i = 0; i < nums.size(); i++) {
            nums[i] = nums[i] - offset + 1;
            n = max(n, nums[i]);
        }

        for (int i = nums.size() - 1; i >= 0; --i) {
            res[i] = sum(nums[i] - 1);
            add(nums[i], 1);
        }
        return res;
    }
};

class Solution {
public:
    struct Node {
        shared_ptr<Node> left, right;
        int val;
        int cnt = 0;
        Node(int val) : val(val) {}
    };
    vector<int> countSmaller(vector<int>& nums) {
        shared_ptr<Node> root;
        int n = nums.size();
        vector<int> res(n);
        for (int i = n - 1; i >= 0; --i) {
            root = insert(root, nums[i], &res, i);
        }
        return res;
    }
    shared_ptr<Node> insert(shared_ptr<Node> root, int val, vector<int>* res, int idx) {
        if (!root)
            return make_shared<Node>(val);
        auto& r = *res;
        if (val <= root->val) {
            root->cnt++;
            root->left = insert(root->left, val, res, idx);
        } else {
            r[idx] += root->cnt + 1;
            root->right = insert(root->right, val, res, idx);
        }
        return root;
    }
};