/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day1031_insert-delete-getrandom-o1-duplicaates-allowed.cpp
 * @Created Time:2020-10-31 14:21:25
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
class RandomizedCollection {
public:
    unordered_map<int, unordered_set<int>> idx;
    vector<int> nums;

    /** Initialize your data structure here. */
    RandomizedCollection() {
    }

    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        nums.push_back(val);
        idx[val].insert(nums.size() - 1);
        return idx[val].size() == 1;
    }

    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if (idx.find(val) == idx.end()) {
            return false;
        }
        int i = *(idx[val].begin());
        nums[i] = nums.back();
        idx[val].erase(i);
        idx[nums[i]].erase(nums.size() - 1);
        if (i < nums.size() - 1) {
            idx[nums[i]].insert(i);
        }
        if (idx[val].size() == 0) {
            idx.erase(val);
        }
        nums.pop_back();
        return true;
    }

    /** Get a random element from the collection. */
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};
class RandomizedCollection {
public:
    unordered_map<int, unordered_set<int>> midx;
    vector<int> arr;

    /** Initialize your data structure here. */
    RandomizedCollection() {
    }

    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        arr.push_back(val);
        midx[val].insert(arr.size() - 1);
        return midx[val].size() == 1;
    }

    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if (midx.find(val) == midx.end()) {
            return false;
        }
        int idx = *(midx[val].begin());
        arr[idx] = arr.back();
        midx[val].erase(idx);
        midx[arr[idx]].erase(arr.size() - 1);
        if (idx < arr.size() - 1) {
            midx[arr[idx]].insert(idx);
        }
        if (midx[val].size() == 0) {
            midx.erase(val);
        }
        arr.pop_back();
        return true;
    }

    /** Get a random element from the collection. */
    int getRandom() {
        return arr[rand() % arr.size()];
    }
};
