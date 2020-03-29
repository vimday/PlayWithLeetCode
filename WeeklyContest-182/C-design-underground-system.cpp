/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :https://leetcode-cn.com/problems/design-underground-system/
 * @File Name   :C-design-underground-system.cpp
 * @Created Time:2020-03-29 15:49:53
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

class UndergroundSystem {
public:
    unordered_map<int, int> mi;
    unordered_map<int, string> mis;
    unordered_map<string, pair<int, int>> m;
    UndergroundSystem() {
    }

    void checkIn(int id, string sn, int t) {
        mi[id] = t;
        mis[id] = sn;
    }

    void checkOut(int id, string sn, int t) {
        string s = mis[id] + "->" + sn;
        m[s].first += t - mi[id];
        m[s].second++;
    }

    double getAverageTime(string sf, string ed) {
        string s = sf + "->" + ed;
        return (double)m[s].first / m[s].second;
    }
};

class UndergroundSystem {
    unordered_map<int, pair<string, int>> st;
    unordered_map<string, pair<double, int>> m;

public:
    UndergroundSystem() {}

    void checkIn(int id, string st_name, int st_time) {
        st[id] = {st_name, st_time};
    }

    void checkOut(int id, string en_name, int en_time) {
        auto& [st_name, st_time] = st[id];
        auto [sum, cnt] = m[st_name + en_name];
        m[st_name + en_name] = {sum + en_time - st_time, cnt + 1};
    }

    double getAverageTime(string st_name, string en_name) {
        return m[st_name + en_name].first / m[st_name + en_name].second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */