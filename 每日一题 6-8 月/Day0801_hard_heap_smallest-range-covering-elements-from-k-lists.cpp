/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day0801_hard_heap_smallest-range-covering-elements-from-k-lists.cpp
 * @Created Time:2020-08-01 15:05:35
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
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;
        int mx = INT_MIN, n = nums.size();
        for (int i = 0; i < n; i++) {
            pq.push({nums[i][0], i, 0});
            mx = max(mx, nums[i][0]);
        }
        vector<int> res{pq.top()[0], mx};
        while (1) {
            auto t = pq.top();
            pq.pop();
            if (++t[2] >= nums[t[1]].size()) break;
            pq.push({nums[t[1]][t[2]], t[1], t[2]});
            mx = max(mx, nums[t[1]][t[2]]);
            int d = mx - pq.top()[0];
            if (d < res[1] - res[0]) {
                res[0] = pq.top()[0];
                res[1] = mx;
            }
        }
        return res;
    }
};

struct NUM {
    int val;
    int pos;
};
struct INTERVAL_RST {
    int start;
    int end;
};
bool comparenum(NUM& num1, NUM& num2) {
    if (num1.val < num2.val) {
        return true;
    }
    return false;
}
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int size = nums.size();
        vector<NUM> allNum;
        NUM tmp = {0};
        for (int i = 0; i < size; i++) {
            int size_interv = nums[i].size();
            for (int j = 0; j < size_interv; j++) {
                tmp.val = nums[i][j];
                tmp.pos = i;
                allNum.push_back(tmp);
            }
        }
        sort(allNum.begin(), allNum.end(), comparenum);
        int numsize = allNum.size();
        vector<int> IntervalFlag(size, 0);
        int left = 0;
        int right = 0;
        int calculate = 0;
        int mindif = allNum[numsize - 1].val - allNum[0].val;
        int start = allNum[0].val;
        int end = allNum[numsize - 1].val;
        int starttmp = 0;
        int endtmp = 0;
        for (int i = 0; i < numsize; i++) {
            int pos = allNum[i].pos;
            if (IntervalFlag[pos] == 0) {
                IntervalFlag[pos] = 1;
                calculate++;
            } else {
                IntervalFlag[pos]++;
            }

            while (calculate == size) {
                starttmp = allNum[left].val;
                endtmp = allNum[i].val;
                int dif = endtmp - starttmp;
                if (dif < mindif) {
                    start = starttmp;
                    end = endtmp;
                    mindif = dif;
                } else if (dif == mindif) {
                    if (starttmp < start) {
                        start = starttmp;
                        end = endtmp;
                    }
                }
                //收缩左边
                int pos2 = allNum[left].pos;
                if (IntervalFlag[pos2] == 1) {
                    calculate--;
                }
                IntervalFlag[pos2]--;
                left++;
            }
        }

        vector<int> Rst = {start, end};
        return Rst;
    }
};