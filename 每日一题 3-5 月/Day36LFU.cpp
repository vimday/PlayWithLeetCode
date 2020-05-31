/*
 * @Author      :vimday
 * @Desc        :LFU
 * @Url         :https://leetcode-cn.com/problems/lfu-cache/
 * @File Name   :Day36
 * @Created Time:2020-04-05 00:55:47
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

//双向链表解法 O1

// 缓存的节点信息
struct Node {
    int key, val, freq;
    Node(int _key, int _val, int _freq) : key(_key), val(_val), freq(_freq) {}
};
class LFUCache {
    int minfreq, capacity;
    unordered_map<int, list<Node>::iterator> key_table;
    unordered_map<int, list<Node>> freq_table;

public:
    LFUCache(int _capacity) {
        minfreq = 0;
        capacity = _capacity;
        key_table.clear();
        freq_table.clear();
    }

    int get(int key) {
        if (capacity == 0) return -1;
        auto it = key_table.find(key);
        if (it == key_table.end()) return -1;
        list<Node>::iterator node = it->second;
        int val = node->val, freq = node->freq;
        freq_table[freq].erase(node);
        // 如果当前链表为空，我们需要在哈希表中删除，且更新minFreq
        if (freq_table[freq].size() == 0) {
            freq_table.erase(freq);
            if (minfreq == freq) minfreq += 1;
        }
        // 插入到 freq + 1 中
        freq_table[freq + 1].push_front(Node(key, val, freq + 1));
        key_table[key] = freq_table[freq + 1].begin();
        return val;
    }

    void put(int key, int value) {
        if (capacity == 0) return;
        auto it = key_table.find(key);
        if (it == key_table.end()) {
            // 缓存已满，需要进行删除操作
            if (key_table.size() == capacity) {
                // 通过 minFreq 拿到 freq_table[minFreq] 链表的末尾节点
                auto it2 = freq_table[minfreq].back();
                key_table.erase(it2.key);
                freq_table[minfreq].pop_back();
                if (freq_table[minfreq].size() == 0) {
                    freq_table.erase(minfreq);
                }
            }
            freq_table[1].push_front(Node(key, value, 1));
            key_table[key] = freq_table[1].begin();
            minfreq = 1;
        } else {
            // 与 get 操作基本一致，除了需要更新缓存的值
            list<Node>::iterator node = it->second;
            int freq = node->freq;
            freq_table[freq].erase(node);
            if (freq_table[freq].size() == 0) {
                freq_table.erase(freq);
                if (minfreq == freq) minfreq += 1;
            }
            freq_table[freq + 1].push_front(Node(key, value, freq + 1));
            key_table[key] = freq_table[freq + 1].begin();
        }
    }
};

//平衡树解法 logN

struct Node {
    int cnt, time, key, value;

    Node(int _cnt, int _time, int _key, int _value) : cnt(_cnt), time(_time), key(_key), value(_value) {}

    bool operator<(const Node& rhs) const {
        return cnt == rhs.cnt ? time < rhs.time : cnt < rhs.cnt;
    }
};
class LFUCache {
    // 缓存容量，时间戳
    int capacity, time;
    unordered_map<int, Node> key_table;
    set<Node> S;

public:
    LFUCache(int _capacity) {
        capacity = _capacity;
        time = 0;
        key_table.clear();
        S.clear();
    }

    int get(int key) {
        if (capacity == 0) return -1;
        auto it = key_table.find(key);
        // 如果哈希表中没有键 key，返回 -1
        if (it == key_table.end()) return -1;
        // 从哈希表中得到旧的缓存
        Node cache = it->second;
        // 从平衡二叉树中删除旧的缓存
        S.erase(cache);
        // 将旧缓存更新
        cache.cnt += 1;
        cache.time = ++time;
        // 将新缓存重新放入哈希表和平衡二叉树中
        S.insert(cache);
        it->second = cache;
        return cache.value;
    }

    void put(int key, int value) {
        if (capacity == 0) return;
        auto it = key_table.find(key);
        if (it == key_table.end()) {
            // 如果到达缓存容量上限
            if (key_table.size() == capacity) {
                // 从哈希表和平衡二叉树中删除最近最少使用的缓存
                key_table.erase(S.begin()->key);
                S.erase(S.begin());
            }
            // 创建新的缓存
            Node cache = Node(1, ++time, key, value);
            // 将新缓存放入哈希表和平衡二叉树中
            key_table.insert(make_pair(key, cache));
            S.insert(cache);
        } else {
            // 这里和 get() 函数类似
            Node cache = it->second;
            S.erase(cache);
            cache.cnt += 1;
            cache.time = ++time;
            cache.value = value;
            S.insert(cache);
            it->second = cache;
        }
    }
};

class LFUCache {
    class Bucket;
    class Key {
    public:
        int key, val;
        Bucket* pfreq;

        Key *prev, *next;
        Key(int k, int v, Bucket* f) : key(k), val(v), pfreq(f) {}
        Key(Key* p, Key* n) : prev(p), next(n) {}
    };

    class Bucket {
        Key _head = Key(&_head, &_head);
        Key* head = &_head;

    public:
        int refc, sz = 0;
        Bucket() {}

        bool empty() {
            return sz == 0;
        }

        void removeKey(Key* pkey) {
            pkey->prev->next = pkey->next;
            pkey->next->prev = pkey->prev;
            --sz;
        }

        void insertKey(Key* pkey) {
            pkey->next = head->next;
            pkey->prev = head;
            head->next->prev = pkey;
            head->next = pkey;
            ++sz;
        }

        int popLast() {
            Key* rm = head->prev;
            int key = rm->key;
            removeKey(rm);
            delete rm;
            return key;
        }
    };

    unordered_map<int, Bucket> blist;
    unordered_map<int, Key*> cache;

    int cap;
    Bucket *minf = NULL, *pzero = &blist[0];

    void add(int key, int v) {
        minf = pzero;
        Key* newKey = new Key(key, v, pzero);
        pzero->insertKey(newKey);
        cache.insert(make_pair(key, newKey));
    }

    int& val(int key) {
        Key* entry = cache[key];
        Bucket *before = entry->pfreq, *after = &blist[before->refc + 1];
        after->refc = before->refc + 1;
        entry->pfreq = after;

        before->removeKey(entry);
        after->insertKey(entry);
        if (before->empty() && before == minf)
            minf = after;
        if (before->refc && before->empty())
            blist.erase(before->refc);

        return entry->val;
    }

    void pop() {
        int outkey = minf->popLast();
        cache.erase(outkey);
        if (minf->refc && minf->empty())
            blist.erase(minf->refc);
    }

public:
    LFUCache(int capacity) {
        cap = capacity;
        pzero->refc = 0;
    }

    int get(int key) {
        if (!cap || !cache.count(key))
            return -1;
        return val(key);
    }

    void put(int key, int value) {
        if (cap == 0) return;
        if (!cache.count(key)) {
            if (cache.size() == cap)
                pop();
            add(key, value);
        } else {
            val(key) = value;
        }
    }
};

//https://leetcode-cn.com/problems/lfu-cache/solution/java-13ms-shuang-100-shuang-xiang-lian-biao-duo-ji/
// class LFUCache {
//     Map<Integer, Node> cache;
//     DoublyLinkedList firstLinkedList;
//     DoublyLinkedList lastLinkedList;
//     int size;
//     int capacity;

//     public LFUCache(int capacity) {
//         cache = new HashMap<> (capacity);
//         firstLinkedList = new DoublyLinkedList();
//         lastLinkedList = new DoublyLinkedList();
//         firstLinkedList.post = lastLinkedList;
//         lastLinkedList.pre = firstLinkedList;
//         this.capacity = capacity;
//     }

//     public int get(int key) {
//         Node node = cache.get(key);
//         if (node == null) {
//             return -1;
//         }
//         freqInc(node);
//         return node.value;
//     }

//     public void put(int key, int value) {
//         if (capacity == 0) {
//             return;
//         }
//         Node node = cache.get(key);
//         if (node != null) {
//             node.value = value;
//             freqInc(node);
//         } else {
//             if (size == capacity) {
//                 // 如果缓存满了，删除lastLinkedList.pre链表中的tail.pre的Node，如果该链表中的元素删空了，则删掉该链表
//                 cache.remove(lastLinkedList.pre.tail.pre.key);
//                 lastLinkedList.removeNode(lastLinkedList.pre.tail.pre);
//                 size--;
//                 if (lastLinkedList.pre.head.post == lastLinkedList.pre.tail) {
//                     removeDoublyLinkedList(lastLinkedList.pre);
//                 }
//             }
//             Node newNode = new Node(key, value);
//             cache.put(key, newNode);
//             if (lastLinkedList.pre.freq != 1) {
//                 DoublyLinkedList newDoublyLinedList = new DoublyLinkedList(1);
//                 addDoublyLinkedList(newDoublyLinedList, lastLinkedList.pre);
//                 newDoublyLinedList.addNode(newNode);
//             } else {
//                 lastLinkedList.pre.addNode(newNode);
//             }
//             size++;
//         }
//     }

//     void freqInc(Node node) {
//         // 将node从原freq对应的链表里移除, 如果链表空了则删除链表,
//         DoublyLinkedList linkedList = node.doublyLinkedList;
//         DoublyLinkedList preLinkedList = linkedList.pre;
//         linkedList.removeNode(node);
//         if (linkedList.head.post == linkedList.tail) {
//             removeDoublyLinkedList(linkedList);
//         }

//         // 将node加入新freq对应的链表，若该链表不存在，则先创建该链表。
//         node.freq++;
//         if (preLinkedList.freq != node.freq) {
//             DoublyLinkedList newDoublyLinedList = new DoublyLinkedList(node.freq);
//             addDoublyLinkedList(newDoublyLinedList, preLinkedList);
//             newDoublyLinedList.addNode(node);
//         } else {
//             preLinkedList.addNode(node);
//         }
//     }

//     void addDoublyLinkedList(DoublyLinkedList newDoublyLinedList, DoublyLinkedList preLinkedList) {
//         newDoublyLinedList.post = preLinkedList.post;
//         newDoublyLinedList.post.pre = newDoublyLinedList;
//         newDoublyLinedList.pre = preLinkedList;
//         preLinkedList.post = newDoublyLinedList;
//     }

//     void removeDoublyLinkedList(DoublyLinkedList doublyLinkedList) {
//         doublyLinkedList.pre.post = doublyLinkedList.post;
//         doublyLinkedList.post.pre = doublyLinkedList.pre;
//     }
// }

// class Node {
//     int key;
//     int value;
//     int freq = 1;
//     Node pre;
//     Node post;
//     DoublyLinkedList doublyLinkedList;

//     public Node() {}

//     public Node(int key, int value) {
//         this.key = key;
//         this.value = value;
//     }
// }

// class DoublyLinkedList {
//     int freq;
//     DoublyLinkedList pre;
//     DoublyLinkedList post;
//     Node head;
//     Node tail;

//     public DoublyLinkedList() {
//         head = new Node();
//         tail = new Node();
//         head.post = tail;
//         tail.pre = head;
//     }

//     public DoublyLinkedList(int freq) {
//         head = new Node();
//         tail = new Node();
//         head.post = tail;
//         tail.pre = head;
//         this.freq = freq;
//     }

//     void removeNode(Node node) {
//         node.pre.post = node.post;
//         node.post.pre = node.pre;
//     }

//     void addNode(Node node) {
//         node.post = head.post;
//         head.post.pre = node;
//         head.post = node;
//         node.pre = head;
//         node.doublyLinkedList = this;
//     }

// }