#include<bits/stdc++.h>
using namespace std;
//数据量小 bf
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n=nums.size();
        vector<int> res(n);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(nums[j]<nums[i])
                    res[i]++;
        return res;
    }
};

//桶排序
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int cnt[101] = {0};
        
        for (auto num: nums) {
            cnt[num]++;
        }
        
        
        int partial[101] = {0};
        partial[0] = 0;
        for (int i = 1; i <= 100; i++) {
            partial[i] = partial[i-1] + cnt[i-1];
        }
        
        vector<int> ans;
        
        for (auto num: nums) {
            ans.push_back(partial[num]);
        }
        
        return ans;
    }
};

//保存nums中每个值及对应的索引至value2index，然后对value2index进行排序，
//然后直接遍历一遍value2index输出结果即可
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<pair<int, int>> value2index;
        for(int i=0; i<nums.size(); i++)
        {
            value2index.push_back(make_pair(nums[i], i));
        }
        sort(value2index.begin(), value2index.end(), cmp);
        
        vector<int> ret(nums.size());
        int old = -11;
        int cur = 0;
        for(int i=0; i<value2index.size(); i++)
        {
            if(value2index[i].first != old)
            {
                cur = i;
            }

            ret[value2index[i].second] = cur;

            old = value2index[i].first;
        }

        return ret;
    }
private:
    struct compare
    {
        bool operator () (pair<int, int>& a, pair<int, int>& b)
        {
            return a.first < b.first;
        }
    }cmp;
};