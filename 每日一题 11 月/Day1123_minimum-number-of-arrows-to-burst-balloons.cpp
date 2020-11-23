/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day1123_minimum-number-of-arrows-to-burst-balloons.cpp
 * @Created Time:2020-11-23 14:39:31
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
struct Node {
    int begin;
    int end;
};
bool cmp(Node a, Node b) {
    return a.end < b.end;
}
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        Node node[points.size()];
        if (points.size() == 0)
            return 0;
        for (int i = 0; i < points.size(); i++) {
            node[i].begin = points[i][0];
            node[i].end = points[i][1];
        }
        sort(&node[0], &node[points.size()], cmp);
        int count = 1;
        int end = node[0].end;
        for (int i = 1; i < points.size(); i++) {
            if (node[i].begin > end) {
                count++;
                end = node[i].end;
            }
        }
        return count;
    }
};
static const auto io_sync_off = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();

// https://leetcode-cn.com/submissions/detail/16775133/
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        /*
            解題思路：先統計出每箇字符出現的次數，再調用STL庫函數sort()，重寫comparator.
        */
        if (points.empty()) return 0;

        //sort()對pair默認作昇序排列，卽按第一箇數字昇序，第一箇數字相同時，按第二箇數字昇序。
        sort(points.begin(), points.end());
        //sort(points.begin(), points.end(), [](const pair<int, int>& a, const pair<int, int>& b){return a.first < b.first;});

        int cnt = 1;                                    //因為氣球數量不爲0，至少需射一箭
        for (int i = 1, j = 0; i < points.size(); ++i)  // j 表示箭當前射箭之x坐標
        {
            if (points[i][0] <= points[j][1]) {
                if (points[i][1] < points[j][1]) j = i;
            } else {
                ++cnt;
                j = i;
            }
        }

        return cnt;
    }
};
class Solution {
public:
    struct node {
        int start;
        int end;
    };

    static bool compare(const node a, const node b) {
        if (a.start != b.start) {
            return a.start < b.start;
        } else {
            return a.end < b.end;
        }
    }

    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.size() == 0) {
            return 0;
        }

        vector<node> data;
        for (const auto& item : points) {
            node tmp;
            tmp.start = item[0];
            tmp.end = item[1];
            data.push_back(tmp);
        }
        sort(data.begin(), data.end(), compare);

        int sum = 1;
        int start = data[0].start;
        int end = data[0].end;
        for (int i = 1; i < data.size(); ++i) {
            if (data[i].start > end) {
                ++sum;
                start = data[i].start;
                end = data[i].end;
            } else {
                start = max(start, data[i].start);
                end = min(end, data[i].end);
            }
        }

        return sum;
    }
};