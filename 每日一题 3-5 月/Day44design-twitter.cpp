/*
 * @Author      :vimday
 * @Desc        :day44 设计推特
 * @Url         :https://leetcode-cn.com/problems/design-twitter/
 * @File Name   :Day44design-twitter.cpp
 * @Created Time:2020-04-13 00:31:05
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
class Twitter {
    struct Node {
        // 哈希表存储关注人的 Id
        unordered_set<int> followee;
        // 用链表存储 tweetId
        list<int> tweet;
    };
    // getNewsFeed 检索的推文的上限以及 tweetId 的时间戳
    int recentMax, time;
    // tweetId 对应发送的时间
    unordered_map<int, int> tweetTime;
    // 每个用户存储的信息
    unordered_map<int, Node> user;

public:
    Twitter() {
        time = 0;
        recentMax = 10;
        user.clear();
    }

    // 初始化
    void init(int userId) {
        user[userId].followee.clear();
        user[userId].tweet.clear();
    }

    void postTweet(int userId, int tweetId) {
        if (user.find(userId) == user.end()) {
            init(userId);
        }
        // 达到限制，剔除链表末尾元素
        if (user[userId].tweet.size() == recentMax) {
            user[userId].tweet.pop_back();
        }
        user[userId].tweet.push_front(tweetId);
        tweetTime[tweetId] = ++time;
    }

    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        ans.clear();
        for (list<int>::iterator it = user[userId].tweet.begin(); it != user[userId].tweet.end(); ++it) {
            ans.emplace_back(*it);
        }
        for (int followeeId : user[userId].followee) {
            if (followeeId == userId) continue;  // 可能出现自己关注自己的情况
            vector<int> res;
            res.clear();
            list<int>::iterator it = user[followeeId].tweet.begin();
            int i = 0;
            // 线性归并
            while (i < (int)ans.size() && it != user[followeeId].tweet.end()) {
                if (tweetTime[(*it)] > tweetTime[ans[i]]) {
                    res.emplace_back(*it);
                    ++it;
                } else {
                    res.emplace_back(ans[i]);
                    ++i;
                }
                // 已经找到这两个链表合起来后最近的 recentMax 条推文
                if ((int)res.size() == recentMax) break;
            }
            for (; i < (int)ans.size() && (int)res.size() < recentMax; ++i) res.emplace_back(ans[i]);
            for (; it != user[followeeId].tweet.end() && (int)res.size() < recentMax; ++it) res.emplace_back(*it);
            ans.assign(res.begin(), res.end());
        }
        return ans;
    }

    void follow(int followerId, int followeeId) {
        if (user.find(followerId) == user.end()) {
            init(followerId);
        }
        if (user.find(followeeId) == user.end()) {
            init(followeeId);
        }
        user[followerId].followee.insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        user[followerId].followee.erase(followeeId);
    }
};

struct Node {
    int a;
    int b;
    int c;
    int d;
};
struct cmp {
    bool operator()(const Node& n1, const Node& n2) {
        return n1.d < n2.d;
    }
};
class Twitter {
public:
    /** Initialize your data structure here. */
    unordered_map<int, vector<pair<int, int>>> t;
    unordered_map<int, unordered_set<int>> f;  // 每个人都要对应一个hashset，因为关注和取关时还要查重
    int time = 0;                              // 全局时间
    Twitter() {
    }

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId)  // 其实还应判断tweetId是否重复
    {
        t[userId].push_back({tweetId, time++});
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        priority_queue<Node, vector<Node>, cmp> pq;  // 优先队列，多个有序数组(或链表)合并
        if (!(t[userId].empty())) {
            int i = userId, j = t[i].size() - 1;
            pq.push({i, j, t[i][j].first, t[i][j].second});
        }
        for (auto it = f[userId].begin(); it != f[userId].end(); it++)
            if (!(t[*it].empty())) {
                int i = *it, j = t[i].size() - 1;
                pq.push({i, j, t[i][j].first, t[i][j].second});
            }

        vector<int> ans;
        for (int cnt = 1; cnt <= 10 && !pq.empty(); cnt++) {
            Node node = pq.top();
            pq.pop();
            ans.push_back(node.c);
            (node.b)--;
            if (node.b >= 0)
                pq.push({node.a, node.b, t[node.a][node.b].first, t[node.a][node.b].second});
        }
        return ans;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int a, int b) {
        if (a == b || f[a].count(b)) return;
        f[a].insert(b);
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int a, int b) {
        if (a == b || !(f[a].count(b))) return;
        f[a].erase(b);
    }
};

typedef struct twitter_s {
    int userId;
    int t;
    int twitter_id;
} TW_S;

struct cmp {
    bool operator()(TW_S a, TW_S b) {
        if (a.t < b.t)
            return true;
        else
            return false;
    }
};

class Twitter {
public:
    /** Initialize your data structure here. */
    Twitter() {
        time = 0;
        return;
    }
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        time++;
        tweets[userId].push_front({userId, time, tweetId});
        return;
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;

        users[userId].insert(userId);
        priority_queue<TW_S, vector<TW_S>, cmp> pq;
        for (auto& elm1 : users[userId]) {
            for (auto& elm2 : tweets[elm1]) {
                //cout<< elm2.twitter_id << endl;
                pq.push(elm2);
            }
        }

        while (ans.size() < 10 && !pq.empty()) {
            TW_S it = pq.top();
            //cout<< "get" << it.twitter_id << endl;
            ans.push_back(it.twitter_id);
            pq.pop();
        }
        return ans;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        users[followerId].insert(followeeId);
        return;
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        users[followerId].erase(followeeId);
        return;
    }

    unordered_map<int, unordered_set<int>> users;
    unordered_map<int, list<TW_S>> tweets;
    int time;
};