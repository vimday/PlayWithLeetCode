/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day1118_gas-station.cpp
 * @Created Time:2020-11-18 16:07:43
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
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int rest = 0, run = 0, start = 0;
        for (int i = 0; i < gas.size(); ++i) {
            run += (gas[i] - cost[i]);
            rest += (gas[i] - cost[i]);
            if (run < 0) {
                start = i + 1;
                run = 0;
            }
        }
        return rest < 0 ? -1 : start;
    }
};
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int size = gas.size(), spare = 0;
        int min_spare = INT_MAX, min_index = 0;
        for (int i = 0; i < size; ++i) {
            spare += (gas[i] - cost[i]);
            if (spare < min_spare) {
                min_spare = spare;
                min_index = i;
            }
        }

        return spare >= 0 ? (min_index + 1) % size : -1;
    }
};