/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day73min-stack.cpp
 * @Created Time:2020-05-12 00:04:48
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
class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> s, sm;
    MinStack() {
    }

    void push(int x) {
        s.push(x);
        if (sm.empty() || sm.top() > x)
            sm.push(x);
        else
            sm.push(sm.top());
    }

    void pop() {
        s.pop();
        sm.pop();
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return sm.top();
    }
};