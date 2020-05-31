#include<bits/stdc++.h>
using namespace std;
class MyStack {
public:
    /** Initialize your data structure here. */
    queue<int> q,aq;
    MyStack() {

    }
    
    /** Push element x onto stack. */
    void push(int x) {
        while(!q.empty()){
            aq.push(q.front());
            q.pop();
        }
        q.push(x);
        while(!aq.empty()){
            q.push(aq.front());
            aq.pop();
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int t=q.front();
        q.pop();
        return t;
    }
    
    /** Get the top element. */
    int top() {
        return q.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
//java
// class MyStack {
//     private Queue<Integer> a;//输入队列
//     private Queue<Integer> b;//输出队列
    
//     public MyStack() {
//         a = new LinkedList<>();
//         b = new LinkedList<>();
//     }
    
//     public void push(int x) {
//         a.offer(x);
//         // 将b队列中元素全部转给a队列
//         while(!b.isEmpty())
//             a.offer(b.poll());
//         // 交换a和b,使得a队列没有在push()的时候始终为空队列
//         Queue temp = a;
//         a = b;
//         b = temp;
//     }
    
//     public int pop() {
//         return b.poll();
//     }
   
//     public int top() {
//         return b.peek();
//     }
    
//     public boolean empty() {
//         return b.isEmpty();
//     }
// }
//单队列
class MyStack {
private:
    queue<int> q;
    
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        // 反转队列，将新元素插到队头
        
        int size = q.size();
        q.push(x);
        while (size--){
            int temp = q.front();
            q.pop();
            q.push(temp);
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int popEle = q.front();
        q.pop();
        
        return popEle;
    }
    
    /** Get the top element. */
    int top() {
        return q.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }
};