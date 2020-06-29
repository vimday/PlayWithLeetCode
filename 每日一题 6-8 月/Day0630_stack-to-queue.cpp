/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day0630_stack-to-queue.cpp
 * @Created Time:2020-06-30 00:10:46
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
static int n = []() {std::ios::sync_with_stdio(false);std::cin.tie(nullptr);return 0; }();
class CQueue {
public:
    stack<int> a, b;
    CQueue() {
    }

    void appendTail(int value) {
        a.push(value);
    }

    int deleteHead() {
        if (b.empty() && a.empty())
            return -1;
        else if (b.empty() && !a.empty()) {
            while (!a.empty()) {
                b.push(a.top());
                a.pop();
            }
        }
        int temp = b.top();
        b.pop();
        return temp;
    }
};
class CQueue {
public:
    stack<int> s, as;
    CQueue() {
    }

    void appendTail(int value) {
        as.push(value);
    }

    int deleteHead() {
        if (s.empty() && as.empty())
            return -1;
        if (s.empty()) {
            while (!as.empty()) {
                s.push(as.top());
                as.pop();
            }
        }
        int t = s.top();
        s.pop();
        return t;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
class CQueue {
public:
    stack<int> s, as;
    CQueue() {
    }

    void appendTail(int val) {
        while (!s.empty()) {
            as.push(s.top());
            s.pop();
        }
        s.push(val);
        while (!as.empty()) {
            s.push(as.top());
            as.pop();
        }
    }

    int deleteHead() {
        if (s.empty())
            return -1;
        int t = s.top();
        s.pop();
        return t;
    }
};
