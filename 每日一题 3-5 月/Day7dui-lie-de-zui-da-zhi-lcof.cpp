#include<bits/stdc++.h>
using namespace std;
class MaxQueue {
public:
    queue<int> q;deque<int> s;
    MaxQueue() {

    }
    
    int max_value() {
        if(q.empty())
            return -1;
        return s.front();

    }
    
    void push_back(int value) {
        q.push(value);
        while(!s.empty()&&value>s.back())
            s.pop_back();
        s.push_back(value);
    }
    
    int pop_front() {
        if(q.empty())
            return -1;
        int t=q.front();
        q.pop();if(t==s.front()) s.pop_front();
        return t;
    }
};