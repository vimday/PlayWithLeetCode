/*
 * @Author      :vimday
 * @Desc        :lru缓存机制
 * @Url         :https://leetcode-cn.com/problems/lru-cache/
 * @File Name   :LRU.cpp
 * @Created Time:2020-03-28 22:55:45
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
class LRUCache {
public:
    LRUCache(int capacity) : cap(capacity) {
    }

    int get(int key) {
        auto it = m.find(key);
        if (it == m.end()) return -1;
        int val = it->second->second;
        data.erase(it->second);
        data.push_front({key, val});

        m[key] = data.begin();

        return val;
    }

    void put(int key, int value) {
        auto it = m.find(key);
        if (it != m.end()) {
            data.erase(it->second);
        }
        data.push_front({key, value});
        m[key] = data.begin();
        if (data.size() > cap) {
            int key1 = data.back().first;
            data.pop_back();
            m.erase(key1);
        }
    }

private:
    unordered_map<int, list<pair<int, int>>::iterator> m;
    list<pair<int, int>> data;
    int cap;
};

class LRUCache {
    class DLinkedNode {
    public:
        int key;
        int value;
        DLinkedNode* prev;
        DLinkedNode* next;
    };

    int addNode(DLinkedNode* node) {
        // cout<<"add node:"<<node->value<<endl;
        node->next = head->next;
        head->next = node;
        node->prev = head;
        node->next->prev = node;

        return 0;
    }

    int removeNode(DLinkedNode* node) {
        // cout<<"remove node:"<<node->value<<endl;
        node->prev->next = node->next;
        node->next->prev = node->prev;

        // delete node;
        return node->key;
    }

    int moveToHead(DLinkedNode* node) {
        // node->prev->next = node->next;
        // node->next->prev = node->prev;
        removeNode(node);
        addNode(node);

        return 0;
    }

private:
    unordered_map<int, DLinkedNode*> cache;
    int size;
    int capacity;
    DLinkedNode *head, *tail;

public:
    LRUCache(int capacity) {
        head = new DLinkedNode();
        tail = new DLinkedNode();

        head->next = tail;
        tail->prev = head;
        this->capacity = capacity;
        // cout<<"capacity is "<<capacity<<endl;
        size = 0;
    }

    int get(int key) {
        unordered_map<int, DLinkedNode*>::iterator it = cache.find(key);
        if (it == cache.end()) {
            // cout<<"did not find key "<<key<<endl;
            return -1;
        }
        moveToHead(it->second);

        return it->second->value;
    }

    void put(int key, int value) {
        unordered_map<int, DLinkedNode*>::iterator it = cache.find(key);
        if (it == cache.end()) {
            DLinkedNode* node = new DLinkedNode();
            node->value = value;
            node->key = key;
            addNode(node);

            cache.insert(make_pair(key, node));
            ++size;
            if (size > capacity) {
                // cout<<"delete key "<<tail->prev->key<<endl;
                int key = removeNode(tail->prev);
                cache.erase(key);

                --size;
            }
        } else {
            it->second->value = value;
            moveToHead(it->second);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */